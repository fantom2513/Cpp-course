#include <iostream>
#include <string>
using namespace std;
#include "isPeriodic.h"


int main()
{
	int k;
	string str;
	cout << "Vvedite stroku i K" << endl;
	cin >> str >> k;

	if (isKperiodic(str, str.length(), k))
		cout << "==>is periodic \n" << endl;
	else 
		cout << "==>is not periodic \n" << endl;
	return 0;
}