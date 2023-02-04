#include <iostream>

using namespace std;

int main()
{
int *a = new int[10];
a[0] = 10;
a[1] = 20;
for(int i=0;i<10;i++)  
cout << a[i];
delete[] a;

    return 0;
}