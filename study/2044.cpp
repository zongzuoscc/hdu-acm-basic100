/*Problem Description
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示。
Input
输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。
Output
对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。
Sample Input
2
1 2
3 6
Sample Output
1
3*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long t[51];//由int改为long long结果变成了accepted，说明int型不能完全存储
    t[0]=0,t[1]=1,t[2]=2;
    for(int i=3;i<50;i++)
    {
        t[i]=t[i-1]+t[i-2];
    }
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<t[b-a]<<endl;
    }
    return 0;
}
