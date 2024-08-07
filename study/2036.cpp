/*Problem Description
“ 改革春风吹满地,
不会AC没关系;
实在不行回老家，
还有一亩三分地。
谢谢!（乐队奏乐）”
话说部分学生心态极好，每天就知道游戏，这次考试如此简单的题目，也是云里雾里，而且，还竟然来这么几句打油诗。
好呀，老师的责任就是帮你解决问题，既然想种田，那就分你一块。
这块田位于浙江省温州市苍南县灵溪镇林家铺子村，多边形形状的一块地，原本是linle 的，现在就准备送给你了。不过，任何事情都没有那么简单，

你必须首先告诉我这块地到底有多少面积，如果回答正确才能真正得到这块地。
发愁了吧？就是要让你知道，种地也是需要AC知识的！以后还是好好练吧...
Input
输入数据包含多个测试实例，每个测试实例占一行，每行的开始是一个整数n(3<=n<=100)，它表示多边形的边数（当然也是顶点数），
然后是按照逆时针顺序给出的n个顶点的坐标（x1, y1, x2, y2... xn, yn）,为了简化问题，这里的所有坐标都用整数表示。
输入数据中所有的整数都在32位整数范围内，n=0表示数据的结束，不做处理。
Output
对于每个测试实例，请输出对应的多边形面积，结果精确到小数点后一位小数。
每个实例的输出占一行。
Sample Input
3 0 0 1 0 0 1
4 1 0 0 1 -1 0 0 -1
0
Sample Output
0.5
2.0*/
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

struct Point 
{
    int x;
    int y;
};

// 使用叉积计算多边形面积
double calculateArea(const vector<Point>& p) 
{
    int n = p.size();
    double area = 0;
    for (int i = 0; i < n; i++) 
    {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(area) / 2.0; // 返回面积的绝对值
}

int main() {
    int n;
    while (cin >> n && n != 0) 
    {
        vector<Point> p(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> p[i].x >> p[i].y;
        }
        double area = calculateArea(p);
        cout << fixed <<setprecision(1) << area << endl;
    }
    return 0;
}