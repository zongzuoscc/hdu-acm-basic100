// Problem Description
// Given a sequence 1,2,3,......N, your job is to calculate all the possible sub-sequences that the sum of the sub-sequence is M.
// Input
// Input contains multiple test cases. each case contains two integers N, M( 1 <= N, M <= 1000000000).
// input ends with N = M = 0.
// Output
// For each test case,
// print all the possible sub-sequence that its sum is M.The format is show in the sample below.
// print a blank line after each test case.
// Sample Input
// 20 10
// 50 30
// 0 0
// Sample Output
// [1,4]
// [10,10]

// [4,8]
// [6,9]
// [9,11]
// [30,30]
// 给定一个序列1, 2, 3, ..., N，你的任务是计算所有可能的子序列，使得子序列的和为M。
// 输入
// 输入包含多个测试用例。每个用例包含两个整数N和M（1 <= N, M <= 1000000000）。输入以N = M = 0结束。
// 输出
// 对于每个测试用例，打印所有可能的子序列，其和为M。格式如下所示。每个测试用例后打印一个空行。
// 样例输入
// 20 10
// 50 30
// 0 0
// 样例输出
// [1,4]
// [10,10]

// [4,8]
// [6,9]
// [9,11]
// [30,30]
/*
#include <iostream>
using namespace std;

int main() 
{
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) 
    {
        for (int i = 1; i <= n; ++i) 
        {
            int sum = 0;
            for (int j = i; j <= n; ++j) 
            {
                sum += j;
                if (sum == m) 
                {
                    cout << "[" << i << "," << j << "]" << endl;
                    break; // 找到一个满足条件的子序列后，跳出内层循环
                } 
                else if (sum > m) 
                {
                    break; // 当和超过目标值时，跳出内层循环，因为后续的和只会更大
                }
            }
        }
        cout << endl; // 每个测试用例后打印一个空行
    }
    return 0;
}
*/   //这段代码超时了 time limit exceeded
// #include <iostream>
// using namespace std;

// int main() {
//     int n, m;
//     while (cin >> n >> m && n != 0 && m != 0) {
//         int left = 1, right = 1, sum = 0;
//         while (right <= n) {
//             sum += right;
//             while (sum > m && left < right) {
//                 sum -= left;
//                 ++left;
//             }
//             if (sum == m) {
//                 cout << "[" << left << "," << right << "]" << endl;
//             }
//             ++right;
//         }
//         cout << endl;
//     }
//     return 0;
// }
//采用指针依旧超时。
