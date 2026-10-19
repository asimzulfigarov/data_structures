#pragma once

#include <initializer_list>
#include <iostream>

namespace sta{

template<typename T>
class vector {
public:
	vector(std::initializer_list<T> data)
	{
		m_Data = new T[m_Capacity];
		PopulateVector(data);
	}

	vector()
	{
		m_Data = new T[m_Capacity];
	}

	~vector()
	{
		delete[] m_Data;
	}

	vector& operator=(const vector& rhs)
	{
		if (*this == rhs)
			return *this;
		m_Size = rhs.m_Size;
		m_Capacity = rhs.m_Capacity;  //edge case - lhs has less capacity than right hand side
		
		if(!m_Data)
			m_Data = new T[m_Capacity];

		for (size_t i = 0; i < m_Size; i++) // should be size
		{
			m_Data[i] = rhs.m_Data[i];
		}
		return *this;
	}

	T& operator[](uint32_t idx)
	{
		return m_Data[idx];
	}

	bool operator==(const vector& rhs)
	{
		return m_Data == rhs.m_Data;
	}

	void ReturnData() const
	{
		for (size_t i = 0; i < m_Size; i++) // should be size 
		{
			std::cout << m_Data[i] << std::endl;
		}
	}

private:
	void PopulateVector(std::initializer_list<T>& data)
	{
		auto it = data.begin();
		size_t i{ 0 };
		
		
		while (it != data.end())
		{
			if (m_Size == m_Capacity)
				Resize();
			m_Data[i] = (*it);
			it += 1;
			i++;
			m_Size++;
		}
	}

	void Resize()
	{
		T* NewData = new T[m_Capacity * 2];

		for (size_t i = 0; i < m_Size; i++)
		{
			NewData[i] = m_Data[i];
		}
		delete[] m_Data;
		m_Data = NewData;
	}

private:
	size_t m_Capacity{ 3 };
	size_t m_Size{ 0 };
	T* m_Data{ nullptr };
};




} //sta