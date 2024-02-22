/*Problem Description
求n个数的最小公倍数。
Input
输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。
Output
为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。
Sample Input
2 4 6
3 2 5 7
Sample Output
12
70
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    int n;
    while (cin >> n) {
        int result = 1; 
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            result = lcm(result, num); 
        }
        cout << result << endl;
    }
    return 0;
}
