// Problem Description
// 对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
// Input
// 输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
// Output
// 对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。
// Sample Input
// 0 1
// 0 0
// Sample Output
// OK
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num) 
{
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main() 
{
    int x, y;
    while (cin >> x >> y && !(x == 0 && y == 0)) 
    {
        bool allPrime = true;
        for (int n = x; n <= y; ++n) 
        {
            int value = n * n + n + 41;
            if (!isPrime(value)) 
            {
                allPrime = false;
                break;
            }
        }
        if (allPrime)
        {
            cout << "OK" << endl;
        }
        else 
        {
            cout << "Sorry" << endl;
        }
    }
    return 0;
}
