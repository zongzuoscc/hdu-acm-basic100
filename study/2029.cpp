/*Problem Description
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。
Input
输入包含多个测试实例，输入数据的第一行是一个正整数n,表示测试实例的个数，后面紧跟着是n个字符串。
Output
如果一个字符串是回文串，则输出"yes",否则输出"no".
Sample Input
4
level
abcde
noon
haha
Sample Output
yes
no
yes
no*/
#include <iostream>
#include <string>
using namespace std;

bool huiwen(string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    for (int i = 0; i < n; ++i) 
    {
        string str;
        getline(cin, str);
        if (huiwen(str)) {
            cout << "yes" << endl;
        } 
        else 
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
