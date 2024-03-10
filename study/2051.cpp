// Problem Description
// Give you a number on base ten,you should output it on base two.(0 < n < 1000)
// Input
// For each case there is a postive number n on base ten, end of file.
// Output
// For each case output a number on base two.
// Sample Input
// 1
// 2
// 3
// Sample Output
// 1
// 10
// 11
#include <iostream>
using namespace std;
int tentotwo(int n) 
{
    if (n == 0) return 0;
    int binary = 0;
    int base = 1; // 二进制位值的基数
    while (n > 0) 
    {
        int yushu = n % 2;//余数
        binary += yushu * base;
        n /= 2;
        base *= 10;
    }
    return binary;
}

int main() 
{
    int n;
    while (cin >> n) 
    {
        cout << tentotwo(n) << endl;
    }
    return 0;
}
