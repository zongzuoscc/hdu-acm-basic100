/*Problem Description
网上流传一句话:"常在网上飘啊，哪能不挨刀啊～"。其实要想能安安心心地上网其实也不难，学点安全知识就可以。
首先，我们就要设置一个安全的密码。那什么样的密码才叫安全的呢？一般来说一个比较安全的密码至少应该满足下面两个条件：
(1).密码长度大于等于8，且不要超过16。
(2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。
这四个字符类别分别为：
1.大写字母：A,B,C...Z;
2.小写字母：a,b,c...z;
3.数字：0,1,2...9;
4.特殊符号：~,!,@,#,$,%,^;
给你一个密码，你的任务就是判断它是不是一个安全的密码。
Input
输入数据第一行包含一个数M，接下有M行，每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。
Output
对于每个测试实例，判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。
Sample Input
3
a1b2c3d4
Linle@ACM
^~^@^@!%
Sample Output
NO
YES
NO*/
#include <iostream>
#include <string>

using namespace std;

bool isSafePassword(const string& password) 
{
    int length = password.length();
    // 检查密码长度是否符合要求
    if (length < 8 || length > 16) 
    {
        return false;
    }

    // 初始化四组字符类别的标志
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    // 遍历密码中的每个字符，检查其所属的字符类别
    for (char ch : password) 
    {
        if (ch >= 'A' && ch <= 'Z') 
        {
            hasUpper = true;
        } 
        else if (ch >= 'a' && ch <= 'z') 
        {
            hasLower = true;
        } 
        else if (ch >= '0' && ch <= '9') 
        {
            hasDigit = true;
        } 
        else if (ch == '~' || ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^') 
        {
            hasSpecial = true;
        }
    }

    // 检查四组字符类别的标志是否至少有三个为true
    int count = (hasUpper ? 1 : 0) + (hasLower ? 1 : 0) + (hasDigit ? 1 : 0) + (hasSpecial ? 1 : 0);
    return count >= 3;
}

int main() 
{
    int M;
    cin >> M;
    cin.ignore(); // 忽略换行符
    while (M--) 
    {
        string password;
        getline(cin, password);
        if (isSafePassword(password)) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
