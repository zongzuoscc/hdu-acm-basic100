/*Problem Description
有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，
每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.
以上就是著名的RPG难题.
Input
输入数据包含多个测试实例,每个测试实例占一行,由一个整数N组成，(0<n<=50)。
Output
对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。
Sample Input
1
2
Sample Output
3
6*/
#include <iostream>
using namespace std;

int main() {
    int n;
    long long array[51];
    array[1] = 3;
    array[2] = 6;
    array[3] = 6;
    for (int i = 4; i < 51; i++)
        array[i] = array[i - 2] * 2 + array[i - 1];
    while (cin >> n)
        cout << array[n] << endl;
    return 0;
}
