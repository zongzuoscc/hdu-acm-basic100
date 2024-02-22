/*Problem Description
输入一个字符串，判断其是否是C的合法标识符。
Input
输入数据包含多个测试实例，数据的第一行是一个整数n,表示测试实例的个数，然后是n行输入数据，每行是一个长度不超过50的字符串。
Output
对于每组输入数据，输出一行。如果输入数据是C的合法标识符，则输出"yes"，否则，输出“no”。
Sample Input
3
12ajf
fi8x_a
ff  ai_2
Sample Output
no
yes
no*/
#include <iostream>
using namespace std;

bool isValidIdentifier(const char* str) 
{
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_')) 
    {
        return false;
    }

    for (int i = 1; str[i] != '\0'; ++i) 
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_')) 
        {
            return false;
        }
    }

    return true;
}

int main() 
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) 
    {
        char str[51]; // 长度为50的字符串需要额外的一个字符存储'\0'
        cin.getline(str, 51);
        if (isValidIdentifier(str)) 
        {
            cout << "yes" << endl;
        } 
        else 
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
