#pragma once

#include <initializer_list>
#include <ostream>

namespace sta {

	class string
	{
	public:
		string(const char* data)
		{
			data_ = new char[capacity_];
			size_t i{ 0 };

			while (data[i] != '\0')
			{
				if (size_ >= capacity_)
					Resize();
				data_[i] = (data[i]);
				i++;
				size_++;
			}
		}

		char& operator[](uint32_t idx)
		{
			return data_[idx];
		}

		size_t size() const
		{
			return size_;
		}

		/*
		string(std::initializer_list<const char*> data)
		{
			data_ = new char[capacity_];

			auto it = data.begin();
			size_t i{ 0 };


			while (it != data.end())
			{
				if (size_ >= capacity_)
					Resize();
				data_[i] = (**it);
				it += 1;
				i++;
				size_++;
			}
		}*/
	private:
		void Resize()
		{
			capacity_ = capacity_ * 2;
			char* NewData = new char[capacity_];

			for (size_t i = 0; i < size_; i++)
			{
				NewData[i] = data_[i];
			}
			delete[] data_;
			data_ = NewData;
		}
	private:
		size_t capacity_{ 10 };
		size_t size_{ 0 };
		char* data_{ nullptr };
	};

	std::ostream& operator<<(std::ostream& ostream, string string) 
	{
		for (size_t i = 0; i < string.size(); i++)
		{
			ostream << string[i];
		}
		return ostream;
	}


} // sta