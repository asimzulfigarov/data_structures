#pragma once

#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace sta{

template<typename T>
class vector {
public:
	vector(std::initializer_list<T> data)
	{
		data_ = new T[capacity_];

		auto it = data.begin();
		size_t i{ 0 };


		while (it != data.end())
		{
			if (size_ >= capacity_)
				Resize();
			data_[i] = (*it);
			it += 1;
			i++;
			size_++;
		}
	}

	vector()
	{
		data_ = new T[capacity_];
	}

	vector(uint32_t size, const T& data = {})
	{
		CreateVector(size, data);
	}

	~vector()
	{
		delete[] data_;
	}

	vector& operator=(const vector& rhs)
	{
		if (*this == rhs)
			return *this;
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;  //edge case - lhs has less capacity than right hand side
		
		if(!data_)
			data_ = new T[capacity_];

		for (size_t i = 0; i < size_; i++) // should be size
		{
			data_[i] = rhs.data_[i];
		}
		return *this;
	}

	bool operator==(const vector& rhs)
	{
		return data_ == rhs.data_;
	}

	// ELEMENT ACCESS

	T& at(uint32_t idx)
	{
		if (idx <= size_ - 1)
		{
			return data_[idx];
		}
		else
		{
			throw std::out_of_range("Index out of range");
		}
	}

	T& operator[](uint32_t idx)
	{
		return data_[idx];
	}

	T& front()
	{
		if (!empty())
		{
			return data_[0];
		}
	}

	T& back()
	{
		if (!empty())
		{
			return data_[size_ - 1];
		}
	}

	T* data()
	{
		if (!empty())
		{
			return data_;
		}
	}

	// ITERATORS

	T* begin()
	{
		return data_;
	}

	T* end()
	{
		T* ptr = data_;
		for (int i = 0; i < size_; ++i) {
			++ptr;
		}
		return ptr;
	}


	// CAPACITY

	bool empty()
	{
		return data_ == nullptr;
	}

	size_t size()
	{
		return size_;
	}

	void reserve(size_t new_cap)
	{
		if (new_cap > capacity_)
		{
			Resize(new_cap);
		}
	}

	size_t capacity()
	{
		return capacity_;
	}

	// just my hack
	void ReturnData() const
	{
		std::cout << "RETURN DATA\n";
		for (size_t i = 0; i < size_; i++) // should be size 
		{
			std::cout << data_[i] << std::endl;
		}
		std::cout << "RETURN DATA END\n";
	}

private:
	void Resize()
	{
		capacity_ = capacity_ * 2;
		T* NewData = new T[capacity_];

		for (size_t i = 0; i < size_; i++)
		{
			NewData[i] = data_[i];
		}
		delete[] data_;
		data_ = NewData;
	}

	void Resize(size_t new_cap)
	{
		capacity_ = new_cap;
		T* NewData = new T[capacity_];

		for (size_t i = 0; i < size_; i++)
		{
			NewData[i] = data_[i];
		}
		delete[] data_;
		data_ = NewData;
	}

	T* CreateVector(uint32_t size, const T& data) 
	{
		data_ = new T[size];
		size_ = size;
		capacity_ = size;
		for (size_t i = 0; i < size; i++)
		{
			data_[i] = data;
		}
		return data_;
	}

private:
	size_t capacity_{ 3 };
	size_t size_{ 0 };
	T* data_{ nullptr };
};




} //sta