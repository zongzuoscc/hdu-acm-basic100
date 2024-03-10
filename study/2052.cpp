// Problem Description
// Give you the width and height of the rectangle,darw it.
// Input
// Input contains a number of test cases.For each case ,
// there are two numbers n and m (0 < n,m < 75)indicate the width and height of the rectangle.Iuput ends of EOF.
// Output
// For each case,you should draw a rectangle with the width and height giving in the input.
// after each case, you should a blank line.
// Sample Input
// 3 2
// Sample Output
// +---+
// |   |
// |   |
// +---+
#include <iostream>
using namespace std;

// 函数：绘制矩形
void draw(int width, int height) 
{
    // 绘制上边框
    cout << "+";
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << "+" << endl;

    // 绘制中间部分
    for (int i = 0; i < height; i++) 
    {
        cout << "|";
        for (int j = 0; j < width; j++)
            cout << " ";
        cout << "|" << endl;
    }

    // 绘制下边框
    cout << "+";
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << "+" << endl;

    // 输出空行
    cout << endl;
}

int main() 
{
    int width, height;
    while (cin >> width >> height)
    {
        draw(width, height);
    }
    return 0;
}
