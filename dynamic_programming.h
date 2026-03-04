#pragma once

#include <vector>

std::vector<int> memo(100, -1);



int fib(int n) {
	if (memo[n] != -1) {
		return memo[n];
	}
	if (n == 0 || n == 1) {
		return n;
	}
	memo[n] =  fib(n - 1) + fib(n - 2);
	return memo[n];
}



int fibI(int n) {
	std::vector<int> fibList;
	fibList.push_back(0);
	fibList.push_back(1);

	for (size_t index = 2; index <= n; index++)
	{
		fibList[index] = fibList[index - 1] + fibList[index - 2];
	}

	return fibList[n];
}
