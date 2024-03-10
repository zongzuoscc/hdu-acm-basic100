// Problem Description
// Give you two numbers A and B, if A is equal to B, you should print "YES", or print "NO".
// Input
// each test case contains two numbers A and B.
// Output
// for each case, if A is equal to B, you should print "YES", or print "NO".
// Sample Input
// 1 2
// 2 2
// 3 3
// 4 3
// Sample Output
// NO
// YES
// YES
// NO
// #include <iostream>
// using namespace std;
// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     if(a==b)
//     {
//         cout<<"YES"<<endl;
//     }
//     else
//     {
//         cout<<"NO"<<endl;
//     }
//     return 0;
// }
#include <iostream>
#include <cstring>
using namespace std;

char x[100020], y[100020];

void doit(char s[]) 
{
    int l = strlen(s);
    bool p=0;
    //判断字符中是否有小数点
    for(int i = 0; i < l; i++)
    {
        if(s[i] == '.') 
        {
            p = 1;
            break;
        }
    }
    //将字符串中多余的0去除，倒叙循环实现
    if(p) 
    {
        for(int i = l - 1; i >= 0; i--) 
        {
            if(s[i] != '0') break;//当s[i]不等于0时跳出循环。
            else s[i] = '\0';//如果s[i]=0则将它变成\0
        }
        l = strlen(s);
        if(s[l - 1] == '.') s[l - 1] = '\0';
    }
}

int main() 
{
    while(cin >> x >> y) 
    {
        doit(x);
        doit(y);
        if(strcmp(x, y) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}