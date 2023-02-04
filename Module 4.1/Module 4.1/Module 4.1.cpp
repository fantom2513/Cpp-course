#include<iostream>
#include"calculate.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    char s;//переменная отвечающая за знак операции
    cout << "Введите знак операции +, -, *, /, !, ^." << endl;
    cin >> s;
    switch (s) {
    case '+': {
        cout << "Введите 2 целых числа." << endl;
        cin >> a >> b;
        cout << a << " + " << b << " = " << Add(a, b) << endl;
        break;
    }
    case '-': {
        cout << "Введите 2 целых числа." << endl;
        cin >> a >> b;
        cout << a << " - " << b << " = " << Sub(a, b) << endl;
        break;
    }
    case '*': {
        cout << "Введите 2 целых числа." << endl;
        cin >> a >> b;
        cout << a << " * " << b << " = " << Mul(a, b) << endl;
        break;
    }
    case '/': {
        cout << "Введите 2 целых числа." << endl;
        float c;
        cin >> a >> c;
        if (c != 0)
            cout << a << " / " << c << " = " << Division(a, c) << endl;
        else
            cout << "Ошибка: деление на 0." << endl;
        break;
    }
    case '!': {
        cout << "Введите целое число." << endl;
        cin >> a;
        cout << a << "! = " << Factorial(a) << endl;
        break;
    }
    case '^': {
        cout << "Введите 2 целых числа." << endl;
        cin >> a >> b;
        cout << a << " ^ " << b << " = " << Pow(a, b) << endl;
        break;
    }
    default:
        break;
    }
    return 0;
}