#include <iostream>
#include "Electronic.h"

int main(int arac, char* argv) {
	setlocale(LC_ALL, "Russian");

	IElectronics* store[100];

	store[0] = new Tablet(400, 20, 10.5, "Ipad");
	store[1] = new Fridge(30, 180, 100, "Hier");
	store[2] = new Laptop(1700, 18, 16.6, "Mac Air", "M1");
	store[3] = new Tablet(600, 24, 10, "Lenovo");

	int pointer = 4;
	int button = 1;
	while (button)
	{
		std::cout << "Выберите действие:" << std::endl << "1. Вывести содержимое" << std::endl <<
			"2. Вывести объекты одного типа" << std::endl << "3. Добавть объект" << std::endl << "0. Выход" << std::endl;
		std::cin >> button;
		switch (button)
		{
		case 1:
		{
			for (int i = 0; i < pointer; ++i)
			{
				std::cout << i + 1 << "#####################" << std::endl;
				store[i]->Show();
				std::cout << std::endl;
			}
			break;
		}
		case 2:
		{
			std::string type;
			int counter = 0;
			std::cout << "Выберите объект: fridge, tablet, laptop}" << std::endl;
			std::cin >> type;
			for (int i = 0; i < pointer; ++i)
			{
				if (store[i]->getType() == type)
				{
					std::cout << i + 1 << "#####################" << std::endl;
					store[i]->Show();
					std::cout << std::endl;
					++counter;
				}
			}
			if (counter == 0)
			{
				std::cout << "Нет объектов такого типа" << std::endl;
			}
			break;
		}
		case 3:
		{
			int button2;
			std::cout << "Что добавляется?" << std::endl << "1. Laptop" << std::endl <<
				"2. Tablet" << std::endl << "3. Frige" << std::endl;
			std::cin >> button2;
			switch (button2)
			{
			case 1:
			{
				Laptop* laptop = new Laptop();
				std::cin >> laptop;
				store[pointer] = laptop;
				++pointer;
				break;
			}
			case 2:
			{
				Tablet* tablet = new Tablet();
				std::cin >> tablet;
				store[pointer] = tablet;
				++pointer;
				break;
			}
			case 3:
			{
				Fridge* fridge = new Fridge();
				std::cin >> fridge;
				store[pointer] = fridge;
				++pointer;
				break;
			}
			default:
			{
				std::cout << "нельзя добавть объект такого типа" << std::endl;
				button = -1;
				break;
			}
			}
			break;
		}
		case 0:
		{
			std::cout << "Выход" << std::endl;
			break;
		}
		default:
			std::cout << "Нет такого действия" << std::endl;
			break;
		}
	}

	for (int i = 0; i < pointer; ++i)
	{
		delete store[i];
	}
	return 0;
}