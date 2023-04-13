#include <iostream>
#include <exception>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "FileArray.h"
#include "sort.h"
#include <string>
const size_t SIZE = 1000000000;
int main()
{
    srand(time(nullptr));
	std::string filename = "array_data.txt";
	std::ifstream file(filename);

	if (file.good())
	{
		std::cout << filename << " allready exists." << std::endl;
	}
	else
	{
		std::cout << "Creating " << filename << "..." << std::endl;
		FileArray array(filename, OUT);

		for (size_t i = 0; i < SIZE; ++i)
		{
			array.push((2 * (rand() % 2) - 1) * rand());
		}
	}

	std::cout << "Sorting " << filename << "..." << std::endl;
	sort(filename);
	std::cout << filename << " sorted." << std::endl;
}


