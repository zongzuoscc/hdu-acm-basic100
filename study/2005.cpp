// Problem Description
// 给定一个日期，输出这个日期是该年的第几天。
// Input
// 输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。
// Output
// 对于每组输入数据，输出一行，表示该日期是该年的第几天。
// Sample Input
// 1985/1/20
// 2006/3/12
// Sample Output
// 20
// 71
#include <iostream>
using namespace std;


bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dayOfYear(int year, int month, int day) {

    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear(year)) {
        days[2] = 29;
    }
    
    int totalDays = 0;
    for (int i = 1; i < month; ++i) {
        totalDays += days[i];
    }
    totalDays += day;
    
    return totalDays;
}

int main()
{
    int year, month, day;
    char separator;
    while (cin >> year >> separator >> month >> separator >> day) 
    {
        cout << dayOfYear(year, month, day) << endl;
    }
    return 0;
}