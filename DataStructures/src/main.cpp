#include <iostream>
#include "Array.h"
#include "Strings.h"

int main(){


	Array<char> array{ 5 };
	array.fill();
	std::cout << array;
	array.insert(2, 'y');
	std::cout << array;
	std::cout << array.LinearSearch('r') << std::endl;
	return 0;

}