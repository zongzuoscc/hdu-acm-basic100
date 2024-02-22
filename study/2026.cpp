/*Problem Description
输入一个英文句子，将每个单词的第一个字母改成大写字母。
Input
输入数据包含多个测试实例，每个测试实例是一个长度不超过100的英文句子，占一行。
Output
请输出按照要求改写后的英文句子。
Sample Input
i like acm
i want to get an accepted
Sample Output
I Like Acm
I Want To Get An Accepted*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[500];
    int i, k;
    while (cin.getline(a, 500)) 
    {
        k = strlen(a);
        a[0] -= 32;//小写字母和大写字母的ASCII编码差32，所以减去32即可实现变为大写。
        for (i = 0; i < k; i++) 
        {
            if (a[i] == ' ') 
            {
                a[i + 1] -= 32;
            }
        }
        cout << a << endl;
    }
    return 0;
}
