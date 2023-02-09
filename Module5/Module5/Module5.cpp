// Module5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string.h>
#include"Vending.h"
using namespace std;
enum slot_parametrs
{
    slotCount = 10
};
int main()
{
    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    SnackSlot* slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
    slot->addSnack(bounty); //Добавляем батончик в слот
    slot->addSnack(snickers);
    VendingMachine* machine = new VendingMachine(slotCount /*Количество слотов для снеков*/);
    machine->addSlot(slot); // Помещаем слот обратно в аппарат
    cout << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков
    delete machine;
    delete slot;
    delete snickers;
    delete bounty;
}

