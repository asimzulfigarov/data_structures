#pragma once

#include <iostream>
#include <vector>

class stack
{
private:
	std::vector<int> stackVector;

public:
	void push(int value)
	{
		stackVector.push_back(value);
	}

	void pop()
	{
		if (stackVector.empty()) return;
		stackVector.pop_back();
	}
};
