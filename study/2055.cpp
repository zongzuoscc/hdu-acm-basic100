// Problem Description
// we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
// Give you a letter x and a number y , you should output the result of y+f(x).
// Input
// On the first line, contains a number T.then T lines follow, each line is a case.each case contains a letter and a number.
// Output
// for each case, you should the result of y+f(x) on a line.
// Sample Input
// 6
// R 1
// P 2
// G 3
// r 1
// p 2
// g 3
// Sample Output
// 19
// 18
// 10
// -17
// -14
// -4
#include <iostream>
using namespace std;

int f(char x) {
    int result;
    if (x >= 'A' && x <= 'Z') {
        result = x - 'A' + 1;
        return result;
    } else if (x >= 'a' && x <= 'z') {
        result = -(x - 'a' + 1);
        return result;
    }
    return 0; // 如果输入不是字母，则返回0
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char x;
        int y;
        cin >> x >> y;
        cout << y + f(x) << endl;
    }
    return 0;
}