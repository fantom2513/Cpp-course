#include<iostream>
#include<string>
#include"Vending.h"

VendingMachine::VendingMachine(int slots_num)
{
	this->slots_num = slots_num;
	position = 0;
	SnackSlot* slot = new SnackSlot[slots_num];
	this->slot = slot;
}

VendingMachine::~VendingMachine()
{
	delete[] slot;
}


void VendingMachine::addSlot(SnackSlot* slot)
{
	this->slot[position] = *slot;
	++position;
}

void VendingMachine::setSlot(int position, SnackSlot* slot)
{
	this->slot[position - 1] = *slot;
}

int VendingMachine::getEmptySlotsCount()
{
	int counter = 0;
	for (int i = 0; i < slots_num; ++i)
	{
		if (this->slot[i].getSlotSize() == 0)
		{
			counter++;
		}
	}
	return counter;
}

std::ostream& operator << (std::ostream& out, const VendingMachine* machine)
{
	for (int i = 0; i < machine->slots_num; ++i)
	{
		out << "" << i + 1 << "" << machine->slot[i].getSlotSize() << std::endl;
	}
	std::cout << std::endl;
	return out;
}

Snack::Snack(string name, float price)
{
	this->name = name;
	this->price = price;
}
Snack::Snack(string name)
{
	this->name = name;
}

Snack::Snack()
{
	name = "empty";
	price = 0.0;
}

string Snack::getName()
{
	return name;
}

SnackSlot::SnackSlot(int SlotSize, Snack* snacks)
{
	snack = snacks;
	this->SlotSize = SlotSize;
	position = 0;

}

SnackSlot::SnackSlot(int SlotSize)
{
	this->SlotSize = SlotSize;
	position = 0;
	Snack* snack = new Snack[SlotSize];
	this->snack = snack;
}

SnackSlot::SnackSlot()
{
	this->SlotSize = 0;
	this->position = 0;
	Snack* snack = new Snack[1];
	this->snack = snack;
}

SnackSlot::~SnackSlot()
{
	delete[] snack;
}

void SnackSlot::addSnack(Snack* snack)
{
	while (this->snack[position].getName() != "empty")
	{
		++position;
	}
	this->snack[position] = *snack;
	++position;
}
int SnackSlot::getSlotSize()
{
	return this->SlotSize;
}