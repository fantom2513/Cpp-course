#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");

    char op = 'q';
    char c = 's';
    while (true) {
        cout << "Выберите операцию: 'e'-кодирование, 'd'-декодирование." << endl;
        cin >> op;
        if (op != 'e' and op != 'd')
            continue;
        cout << "Введите размер строки:" << endl;
        int size;
        cin >> size;
        char *str = new char[size];
        cout << "Введите строку для кодирования" << endl;
        cin >> str;
        cout << "Введите сдвиг" << endl;
        int k;
        cin >> k;
        if (op == 'e') {

            for (int i = 0;i < size;i++) {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] = ((str[i] - 'a' + k) % 26) + 'a';
                else if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = ((str[i] - 'A' + k) % 26) + 'A';
            }
            cout << "Закодированная строка: " << str << endl
                << "Для выхода из прогираммы введите 'q', для продолжения введите 'c'" << endl;
            while (c != 'c' and c != 'q')
                cin >> c;
            if (c == 'q')
                return 0;
        } else {
            for (int i = 0;i < size;i++) {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] = ((str[i] - 'a' - k + 26) % 26) + 'a';
                else if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = ((str[i] - 'A' - k + 26) % 26) + 'A';
            }
            cout << "Декодированная строка: " << str << endl
                << "Для выхода из прогираммы введите 'q', для продолжения введите 'c'" << endl;
            while (c != 'c' and c != 'q')
                cin >> c;
            if (c == 'q')
                return 0;
        }
        c = '0';
        op = '0';
    }
    return 0;
}