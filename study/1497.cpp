// // After AC all the hardest problems in the world , the ACboy 8006 now has nothing to do . 
// //One day he goes to an old library to find a part-time job .
// //It is also a big library which has N books and M users.The user's id is from 1 to M , 
// //and the book id is from 1 to N . According to the library rules , 
// //every user are only allowed to borrow 9 books .
// //But what surprised him is that there is no computer in the library , and everything is just recorded in paper ! How terrible , 
// //I must be crazy after working some weeks , he thinks .So he wants to change the situation .
// // In the other hand , after 8006's fans know it , they all collect money and buy many computers for the library .
// // Besides the hardware , the library needs a management program . Though it is just a piece of cake for 8006 , 
// //the library turns to you , a excellent programer,for help .
// // What they need is just a simple library management program . It is just a console program , 
// //and have only three commands : Borrow the book , Return the book , Query the user .
// // 1.The Borrow command has two parameters : The user id and the book id
// // The format is : "B ui bi" (1<=ui<=M , 1<=bi<=N)
// // The program must first check the book bi wether it's in the library . If it is not ,
// // just print "The book is not in the library now" in a line .
// // If it is , then check the user ui .
// // If the user has borrowed 9 books already, print "You are not allowed to borrow any more" .
// // Else let the user ui borrow the book , and print "Borrow success".

// // 2.The Return command only has one parameter : The book id
// // The format is : "R bi" (1<=bi<=N)
// // The program must first check the book bi whether it's in the library . If it is , 
// //just print "The book is already in the library" . Otherwise , you can return the book , and print "Return success".

// // 3.The Query command has one parameter : The user id
// // The format is : "Q ui" (1<=ui<=M)
// // If the number of books which the user ui has borrowed is 0 ,just print "Empty" , 
// // otherwise print the books' id which he borrows in increasing order in a line.Seperate two books with a blank.
// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <algorithm>
// using namespace std;
// const int N=100010;
// const int M=100010;
// int u[N];//用于存储用户借书的数目
// int ub[N][9];//存储每个用户借了哪几本书
// int ubi[N];////相当于指针，往后指
// bool b[M];//用于记录图书是否被借走

// void sortRow(int u[][9], int row, int totalRows)//row表示要排序的行，totalrow是总行数 
// {
//     // if (row < 0 || row >= totalRows) {
//     //     cerr << "Invalid row index" << endl;
//     //     return;
//     // }
//     // 使用sort函数对指定行进行排序，greater<int>()实现从大到小排序
//     sort(u[row], u[row] + 9, greater<int>());
// }

// int main()
// {
//     memset(ub,0,sizeof ub);
//     memset(ubi,0,sizeof ubi);
//     memset(u,0,sizeof u);
//     memset(b,1,sizeof b);//初始化所有图书都在 为真
//     int n,m;//用户数和图书数
//     int x;//命令的数量
//     cin>>n>>m;
//     cin>>x;
//     while(x--)
//     {
//         char s;
//         cin>>s;
//         if(s=='B')//借书命令
//         {
//             int ui,bi;
//             cin>>ui>>bi;
//             if(!b[bi])
//             {
//                 cout<<"The book is not in the library now"<<endl;
//             }
//             else
//             {
//                 if(u[ui]>=9)
//                 {
//                     cout<<"You are not allowed to borrow any more"<<endl;
//                 }
//                 else
//                 {
//                     cout<<"Borrow success"<<endl;
//                     u[ui]++;//借书的数量+1
//                     b[bi]=0;//将状态修改为不在图书馆
//                     ub[ui][ubi[ui]++]=bi;//将用户借的书存储进来,并且将用户借书数量的指针后移一位
//                 }
//             }
//         }
//         else if(s=='R')
//         {
//             int bi;
//             cin>>bi;
//             if(b[bi])
//             {
//                 cout<<"The book is already in the library"<<endl;
//             }
//             else
//             {
//                 cout<<"Return success"<<endl;
//                 b[bi]=1;//将图书的状态修改为在图书馆
//                 for(int i=0;i<n;i++)
//                 {
//                     for(int j=0;j<9;j++)
//                     {
//                         if(ub[i][j]==bi)
//                         {
//                             ub[i][j]=0;//将用户借的图书改为表示已经归还了
//                             sortRow(ub,i,n);//这一行我要对这个用户借走的图书进行从大到小排序，这样才能让指针--，输出的时候逆序输出就好
//                             ubi[i]--;
//                         }
//                     }
//                 }
//             }
//         }
//         else if(s=='Q')
//         {
//             int ui;
//             cin>>ui;
//             if(u[ui]==0)
//             {
//                 cout<<"Empty"<<endl;
//             }
//             else
//             {
//                 for(int i=8;i>=0;i++)
//                 {
//                     if(ub[ui][i]!=0)
//                     {
//                         cout<<ub[ui][i]<<" ";
//                     }
//                 }
//                 cout<<endl;
//             }
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXM 1001
#define MAXN 100001

using namespace std;

int un[MAXM];//用于记录每个用户借书的数量  un[ui] 表示用户 ui 借了多少本书。
int ub[MAXM];//数组 ub 用于记录每个用户借了哪几本书。  ub[ui] 是一个链表的头指针，指向用户 ui 借的第一本书在数组 v 中的位置。
int v[MAXN];//数组 v 用于记录每本书的状态，即是否还在图书馆以及被哪个用户借走
int ne[MAXN];//用于构建用户借书的链表结构。ne里面存储的才是用户借走了哪几本书

int main() 
{
    int m, n, t;
    int ui, bi;
    vector<int> bid(11);//用于临时存储某用户借的书的编号，用于排序和输出查询结果。
    string cmd;

    while (cin >> m >> n) 
    {
        cin >> t;
        memset(un, 0, sizeof(un));
        memset(ub, 0, sizeof(ub));
        memset(v, 0, sizeof(v));
        
        while (t--) 
        {
            cin >> cmd;
            if (cmd == "B") //借书命令
            {
                // borrow ui bi
                cin >> ui >> bi;
                if (v[bi]) //这本书被用户借走了
                {
                    cout << "The book is not in the library now" << endl;
                } 
                else if (un[ui] == 9) //如果用户借书的数量达到9本
                {
                    cout << "You are not allowed to borrow any more" << endl;
                } 
                else 
                {
                    v[bi] = ui;//让这本书变成用户的id表示被这名用户借走
                    ne[bi] = ub[ui];//bi的下一本书改为ub[ui]
                    ub[ui] = bi;//然后将头指针ub[ui]改为新的bi这本书，相当于实现了头插法
                    un[ui]++;//用户借书的数量+1
                    cout << "Borrow success" << endl;
                }
            } 
            else if (cmd == "R") 
            {
                // return bi
                cin >> bi;
                if (v[bi] == 0) 
                {
                    cout << "The book is already in the library" << endl;
                }
                else 
                {
                    ui = v[bi];//因为只输入了是哪本图书，所以要根据图书找用户
                    int i = 0, j = ub[ui];
                    if (j == bi) 
                    {
                        ub[ui] = ne[j];
                    } 
                    else 
                    {
                        while (i < un[ui] && bi != ne[j]) //只要还没找到这本书，那么就循环找
                        {
                            j = ne[j];
                            ++i;
                        }
                        ne[j] = ne[bi];//将bi的上一本书指向bi的下一本书
                    }
                    un[ui]--;//用户借书总量-1
                    v[bi] = 0;//状态改为在图书馆
                    cout << "Return success" << endl;
                }
            } 
            else if (cmd == "Q") 
            {
                // query ui
                cin >> ui;
                if (un[ui]) //如果说用户借过书
                {
                    int i = 0, j = ub[ui];
                    while (i < un[ui])
                    {
                        bid[i++] = j;
                        j = ne[j];
                    }
                    sort(bid.begin(), bid.begin() + un[ui]);
                    for (i = 0; i < un[ui] - 1; ++i)
                        cout << bid[i] << " ";
                    cout << bid[i] << endl;
                } 
                else 
                {
                    cout << "Empty" << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}