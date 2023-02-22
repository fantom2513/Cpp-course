#include"IntArray.h"
#include<iostream>
#include<exception>


int main()
{
    int size;
    std::cout << "Input array size: " << '\n';
    try
    {
        std::cin >> size;

        // 1)Declare an array

        IntArray array(size);

        // Fill the array with numbers 1 through 10
        for (int i = 0; i < array.getLength(); ++i)
            array[i] = i + 1;
        std::cout << "array: ";
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << '\n';

        // 2)Copy

        IntArray array1{ array };
        std::cout << "array1: ";
        for (int i{ 0 }; i < array1.getLength(); ++i)
            std::cout << array1[i] << ' ';
        std::cout << '\n';

        // 3)Access the index
        try
        {
            std::cout << "array[10]= " << array[10] << ' ';
            std::cout << '\n';
        }
        catch (Bad_range err)
        {
            std::cout << err.what() << std::endl;
        }
        // 4)Resize the array to 8 elements
        array.resize(8);
        std::cout << "New array size= " << array.getLength() << ' ' << "(";
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << ")" << '\n';

        // 5)Insert the number 20 before element with index 5
        array.insertBefore(20, 5);
        std::cout << "array after insert: ";
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << '\n';

        // 6)Remove the element with index 3
        array.remove(3);
        std::cout << "array after delete index: ";
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << '\n';

        // 7)Add 30 and 40 to the end and beginning
        array.insertAtEnd(2);
        array.insertAtBeginning(2);
        std::cout << "array after add: ";
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';
        std::cout << '\n';

        // 8)Search
        int num;
        std::cout << "Input number for search:" << "\n";
        std::cin >> num;
        for (int i{ 0 }; i < array.getLength(); ++i)
        {
            if (array[i] == num)
            {
                std::cout << "Array index " << i << " = " << array[i] << "\n";
            }
        }
        std::cout << "Array does not contain such data.";
    }
    catch (Bad_lenght err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}