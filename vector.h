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

		for (size_t i = 0; i < m_Capacity; i++) // should be size
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
		for (size_t i = 0; i < m_Capacity; i++) // should be size 
		{
			std::cout << m_Data[i] << std::endl;
		}
	}

private:
	void PopulateVector(std::initializer_list<T>& data)
	{
		for (size_t i = 0; i < m_Capacity; i++) // should be size 
		{
			m_Data[i] = *(data.begin() + i);
			m_Size++;
		}
	}

private:
	size_t m_Capacity{ 3 };
	size_t m_Size{ 0 };
	T* m_Data;
};




} //sta