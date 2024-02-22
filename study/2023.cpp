/*Problem Description
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
Input
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。
Output
对于每个测试实例，输出3行数据，第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；
第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。
Sample Input
2 2
5 10
10 20
Sample Output
7.50 15.00
7.50 15.00
1*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int n, m;
    while (cin >> n >> m&&n<=50&&n>0&&m<=5&&m>0) 
    {
        int scores[n][m];
        double studentavg[n] = {0};
        double subjectavg[m] = {0};

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                cin >> scores[i][j];
                studentavg[i] += scores[i][j];
                subjectavg[j] += scores[i][j];
            }
        }

        for (int i = 0; i < n; i++) 
        {
            studentavg[i] /= m;
        }

        for (int j = 0; j < m; j++) 
        {
            subjectavg[j] /= n;
        }

        for (int i = 0; i < n; i++) 
        {
            cout << fixed << setprecision(2) << studentavg[i] << " ";
        }
        cout << endl;

        for (int j = 0; j < m; j++) 
        {
            cout << fixed << setprecision(2) << subjectavg[j] << " ";
        }
        cout << endl;

        // 计算各科成绩均大于等于平均成绩的学生数量
        int aboveavgcount = 0;
        for (int i = 0; i < n; i++) 
        {
            bool aboveavg = true;
            for (int j = 0; j < m; j++) 
            {
                if (scores[i][j] < subjectavg[j]) 
                {
                    aboveavg = false;
                    break;
                }
            }
            if (aboveavg) 
            {
                aboveavgcount++;
            }
        }

        cout << aboveavgcount << endl;
        cout << endl; 
    }  
    return 0;
}