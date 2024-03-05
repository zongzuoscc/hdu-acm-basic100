/*Problem Description
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
Input
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
Output
对于每个测试实例，请输出不同走法的数量
Sample Input
2
2
3
Sample Output
1
2
*/
#include <iostream>
using namespace std;
const int MAX = 45;
long long step[MAX]; // 使用long long 类型存储结果，避免溢出

void calculateWays() {
    step[2] = 1;
    step[3] = 2;
    for (int i = 4; i < MAX; ++i) {
        step[i] = step[i - 1] + step[i - 2];
    }
}
int main()
{
    int n;
    cin>>n;
    calculateWays();
    while(n--)
    {
        int m;
        cin>>m;
        cout<<step[m]<<endl;
    }
}