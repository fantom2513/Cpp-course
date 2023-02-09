#pragma once
using namespace std;
class Snack
{
private:
	std::string name;
	float price;
public:
	Snack(std::string, float);
	Snack(std::string);
	Snack();
	std::string getName();
};

class SnackSlot
{
private:
	int SlotSize;
	int position;
	Snack* snack;
public:
	SnackSlot(int, Snack*);
	SnackSlot(int);
	SnackSlot();
	~SnackSlot();
	void addSnack(Snack*);
	int getSlotSize();
};

class VendingMachine
{

private:
	SnackSlot* slot = new SnackSlot;
	int position;
	int slots_num;
public:
	VendingMachine(int);
	~VendingMachine();
	void addSlot(SnackSlot*);
	int getEmptySlotsCount();
	friend std::ostream& operator << (std::ostream&, const VendingMachine*);
	void setSlot(int, SnackSlot*);
};






