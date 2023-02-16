#include <iostream>
#include "Electronic.h"

Device::Device(int batteryLife) : _batteryLife(batteryLife) {}

void Device::Show()
{
	std::cout << "Бренд " << _brand << std::endl
		<< "Время работы батареи: " << _batteryLife << " часов" << std::endl;
}


Appliances::Appliances(int weight) : _weight(weight) {}

void Appliances::Show()
{
	std::cout << " Продукт компании " << _brand << std::endl
		<< "Масса : " << _weight << " грамм" << std::endl;
}


Tablet::Tablet(int weight, int batteryLife, float diag, std::string brand) : Appliances(weight),
Device(batteryLife), _diag(diag), IElectronics(brand) {
	type = "tablet";
}

Tablet::Tablet() : Appliances(0), Device(0), _diag(0), IElectronics("none") { type = "tablet"; }

void Tablet::Show()
{
	std::cout << " Продукт компании " << _brand << std::endl
		<< "Масса : " << _weight << " грамм" << std::endl
		<< "Время работы аккумулятора : " << _batteryLife << " часов" << std::endl
		<< "Диагональ: " << _diag << " дюймов" << std::endl;
}

std::istream& operator >> (std::istream& in, Tablet* tablet)
{
	tablet->type = "tablet";
	std::cout << "Производитель: " << std::endl;
	in >> tablet->_brand;
	std::cout << "масса (Грамм): " << std::endl;
	in >> tablet->_weight;
	std::cout << "Диагональ (дюйм): " << std::endl;
	in >> tablet->_diag;
	std::cout << "Время работы от аккумулятора (часов): " << std::endl;
	in >> tablet->_batteryLife;
	return in;
}


Fridge::Fridge(int weight, float a, float b, std::string brand) :Appliances(weight), IElectronics(brand)
{
	type = "fridge";
	_camsize[0] = a;
	_camsize[1] = b;
}

Fridge::Fridge() :Appliances(0),
IElectronics("none")
{
	type = "fridge";
	_camsize[0] = 0;
	_camsize[1] = 0;
}

void Fridge::Show()
{
	std::cout << " Продукт компании " << _brand << std::endl
		<< "Масса : " << _weight << " килограмм" << std::endl
		<< "Размер холодильной камеры: " << _camsize[0] << "x" << _camsize[1] << " сантиметров" << std::endl;
}

std::istream& operator >> (std::istream& in, Fridge* fridge)
{
	fridge->type = "fridge";
	std::cout << "Производитель: " << std::endl;
	in >> fridge->_brand;
	std::cout << "масса (килограмм): " << std::endl;
	in >> fridge->_weight;
	std::cout << "Высота (см): " << std::endl;
	in >> fridge->_camsize[0];
	std::cout << "Ширина (см): " << std::endl;
	in >> fridge->_camsize[1];
	return in;
}


Laptop::Laptop(int weight, int batteryLife, float diag, std::string brand, std::string CPU_model) : Appliances(weight),
Device(batteryLife), _diag(diag), _CPU_model(CPU_model), IElectronics(brand) {
	type = "laptop";
}

Laptop::Laptop() : Appliances(0),
Device(0), _diag(0), _CPU_model("none"), IElectronics("none") {
	type = "laptop";
}

void Laptop::Show()
{
	std::cout << " Продукт компании " << _brand << std::endl
		<< "Масса : " << _weight << " грамм" << std::endl
		<< "Время работы аккумулятора : " << _batteryLife << " часов" << std::endl
		<< "Диагональ: " << _diag << " дюймов" << std::endl
		<< "Млдель процессора: " << _CPU_model << std::endl;
}

std::istream& operator >> (std::istream& in, Laptop* laptop)
{
	laptop->type = "laptop";
	std::cout << "Производитель: " << std::endl;
	in >> laptop->_brand;
	std::cout << "масса (Грамм): " << std::endl;
	in >> laptop->_weight;
	std::cout << "Диагональ (дюйм): " << std::endl;
	in >> laptop->_diag;
	std::cout << "Время работы от аккумулятора (часов): " << std::endl;
	in >> laptop->_batteryLife;
	std::cout << "Модель процессора: " << std::endl;
	in >> laptop->_CPU_model;
	return in;
}
