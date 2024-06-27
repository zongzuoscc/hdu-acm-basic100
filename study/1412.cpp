// Problem Description
// 给你两个集合，要求{A} + {B}.
// 注:同一个集合中不会有两个相同的元素.
// Input
// 每组输入数据分为三行,第一行有两个数字n,m(0<n,m<=10000),分别表示集合A和集合B的元素个数.
//后两行分别表示集合A和集合B.每个元素为不超出int范围的整数,每个元素之间有一个空格隔开.
// Output
// 针对每组数据输出一行数据,表示合并后的集合,要求从小到大输出,每个元素之间有一个空格隔开.
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;
    int n, m;
    vector<int> C;
    while (cin >> n >> m) {
        C.resize(n + m);
        for (int i = 0; i < n + m; ++i) {
            cin >> C[i];
        }
        sort(C.begin(),C.end());
        cout << C[0];
        for (int i = 1; i < n + m; ++i) {
            if (C[i] != C[i - 1]) {
                cout << " " << C[i];
            }
        }
        cout << endl;
    }
    return 0;
}