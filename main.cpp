#include <iostream>

#include "vector.h"




int main() {
	
	sta::vector<int> vec{ 1, 2, 3 };
	
	vec.ReturnData();
	
	std::cout << vec[0] << std::endl;

	sta::vector<int> vec1;

	vec1 = vec;
	vec1.ReturnData();


	std::cin.get();
}