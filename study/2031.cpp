/*Problem Description
输入一个十进制数N，将它转换成R进制数输出。
Input
输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。
Output
为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。
Sample Input
7 2
23 12
-4 3
Sample Output
111
1B
-11*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string turn(int n,int r)
{
    string result="";
    bool negative=false;
    if(n<0)
    {
        negative=true;
        n=-n;
    }
    while (n> 0) {
        int remainder = n % r; // 求余数
        char digit; // 用于存储当前位的数字字符

        // 将余数转换为对应的字符表示
        if (remainder < 10) 
        {
            digit = remainder + '0'; // 如果余数小于10，直接使用对应的数字字符
        }
        else 
        {
            digit = remainder - 10 + 'A'; // 如果余数大于等于10，使用对应的字母表示
        }

        result = digit + result; // 将当前位的字符插入到结果字符串的最前面
        n /= r; // 更新N为除以R的结果
    }

    // 如果是负数，在结果字符串最前面添加负号
    if (negative) 
    {
        result = '-' + result;
    }

    return result;

}
int main()
{
    int n;//10进制的数字
    int r;//需要转换的进制
    while(cin>>n>>r)
    {
        cout<<turn(n,r)<<endl;
    }
    return 0;
}