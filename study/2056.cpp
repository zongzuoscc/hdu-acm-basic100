// Problem Description
// Given two rectangles and the coordinates of two points on the diagonals of each rectangle,
// you have to calculate the area of the intersected part of two rectangles. its sides are parallel to OX and OY .
// Input
// Input The first line of input is 8 positive numbers which indicate the coordinates of four points that must be on each diagonal.
// The 8 numbers are x1,y1,x2,y2,x3,y3,x4,y4.
// That means the two points on the first rectangle are(x1,y1),(x2,y2);the other two points on the second rectangle are (x3,y3),(x4,y4).
// Output
// Output For each case output the area of their intersected part in a single line.accurate up to 2 decimal places.
// Sample Input
// 1.00 1.00 3.00 3.00 2.00 2.00 4.00 4.00
// 5.00 5.00 13.00 13.00 4.00 4.00 12.50 12.50
// Sample Output
// 1.00
// 56.25
// #include <iostream>
// using namespace std;
// int main()
// {

// }
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main() 
{
    double x1, y1, x2, y2, x3, y3, x4, y4, t;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) 
    {
        if (x1 > x2) swap(x1, x2); // 确保 x1 存储左下角矩形的 x 坐标，x2 存储右上角矩形的 x 坐标
        if (y1 > y2) swap(y1, y2); // 确保 y1 存储左下角矩形的 y 坐标，y2 存储右上角矩形的 y 坐标
        if (x3 > x4) swap(x3, x4); // 确保 x3 存储左下角矩形的 x 坐标，x4 存储右上角矩形的 x 坐标
        if (y3 > y4) swap(y3, y4); // 确保 y3 存储左下角矩形的 y 坐标，y4 存储右上角矩形的 y 坐标

        if (x2 < x3 || x1 > x4 || y2 < y3 || y1 > y4) // 检查两个矩形是否相交
            cout << "0.00\n"; // 如果不相交，输出交集面积为0
        else 
        {
                x1 = max(x1, x3); // 计算交集部分的左下角 x 坐标
                y1 = max(y1, y3); // 计算交集部分的左下角 y 坐标
                x2 = min(x2, x4); // 计算交集部分的右上角 x 坐标
                y2 = min(y2, y4); // 计算交集部分的右上角 y 坐标
                cout<<fixed<<setprecision(2)<<(x2 - x1) * (y2 - y1)<<endl; // 输出交集部分的面积，保留两位小数
        }
    }
    return 0;
}