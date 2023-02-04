#include"calculate.h"

int Add(int x, int y)
{
    int sum = x + y;
    return sum;
}

int Sub(int x, int y)
{
    int res = x - y;
    return res;
}

int Mul(int x, int y) {
    int res = x * y;
    return res;
}

float Division(int x, float y) {
    float res = x / y;
    return res;
}

long long Factorial(int x) {
    if (x == 1) {
        return 1;
    }
    else {
        return x * Factorial(x - 1);
    }
}

long long Pow(int x, int y) {
    if (y == 1) {
        return x;
    }
    else {
        return x * Pow(x, y - 1);
    }
}