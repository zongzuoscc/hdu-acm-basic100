/*Problem Description
求实数的绝对值。
Input
输入数据有多组，每组占一行，每行包含一个实数。
Output
对于每组输入数据，输出它的绝对值，要求每组数据输出一行，结果保留两位小数。
Sample Input
123
-234.00
Sample Output
123.00
234.00*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double s;
    while(cin>>s)
    {
        double i=abs(s);
        cout<<fixed<<setprecision(2)<<i<<endl;
    }
    return 0;
}