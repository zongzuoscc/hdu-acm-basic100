/*Problem Description
作为杭电的老师，最盼望的日子就是每月的8号了，因为这一天是发工资的日子，养家糊口就靠它了，呵呵
但是对于学校财务处的工作人员来说，这一天则是很忙碌的一天，财务处的小胡老师最近就在考虑一个问题：
如果每个老师的工资额都知道，最少需要准备多少张人民币，才能在给每位老师发工资的时候都不用老师找零呢？
这里假设老师的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。
Input
输入数据包含多个测试实例，每个测试实例的第一行是一个整数n（n<100），表示老师的人数，然后是n个老师的工资。
n=0表示输入的结束，不做处理。
Output
对于每个测试实例输出一个整数x,表示至少需要准备的人民币张数。每个输出占一行。
Sample Input
3
1 2 3
0
Sample Output
4*/
#include <iostream>
using namespace std;

int main() 
{
    int n;
    while (cin >> n && n != 0) 
    {
        int salary;
        int total_notes = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> salary;
            int notes = 0;
            while (salary > 0) 
            {
                if (salary >= 100) 
                {
                    notes += salary / 100;
                    salary %= 100;
                } 
                else if (salary >= 50) 
                {
                    notes += salary / 50;
                    salary %= 50;
                } 
                else if (salary >= 10) 
                {
                    notes += salary / 10;
                    salary %= 10;
                } 
                else if (salary >= 5) 
                {
                    notes += salary / 5;
                    salary %= 5;
                } 
                else if (salary >= 2) 
                {
                    notes += salary / 2;
                    salary %= 2;
                } 
                else
                {
                    notes += salary;
                    salary = 0;
                }
            }
            total_notes += notes;
        }

        cout << total_notes << endl;
    }
    return 0;
}
