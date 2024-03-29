/*Problem Description
今年的ACM暑期集训队一共有18人，分为6支队伍。其中有一个叫做EOF的队伍，由04级的阿牛、
XC以及05级的COY组成。在共同的集训生活中，大家建立了深厚的友谊，阿牛准备做点什么来纪念这段激情燃烧的岁月，想了一想，
阿牛从家里拿来了一块上等的牛肉干，准备在上面刻下一个长度为n的只由"E" "O" "F"三种字符组成的字符串
（可以只有其中一种或两种字符，但绝对不能有其他字符）,
阿牛同时禁止在串中出现O相邻的情况，他认为，"OO"看起来就像发怒的眼睛，效果不好。
你，NEW ACMer,EOF的崇拜者，能帮阿牛算一下一共有多少种满足要求的不同的字符串吗？
PS: 阿牛还有一个小秘密，就是准备把这个刻有 EOF的牛肉干，作为神秘礼物献给杭电五十周年校庆，
可以想象，当校长接过这块牛肉干的时候该有多高兴！这里，请允许我代表杭电的ACMer向阿牛表示感谢！
再次感谢！
Input
输入数据包含多个测试实例,每个测试实例占一行,由一个整数n组成，(0<n<40)。
Output
对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。
Sample Input
1
2
Sample Output
3
8
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    long long p[40];
    p[0]=0,p[1]=3,p[2]=8;
    for(int i=3;i<40;i++)
    {
        p[i]=(p[i-1]+p[i-2])*2;//p[i-1]是以E,O,F任意一个字符结尾的可以直接添加E或F但是不能直接加O，//p[i-2]是以O结尾的只能添加E或F
    }
    while(cin>>n)
    {
        cout<<p[n]<<endl;
    }
    return 0;
}


//EEE EEO EEF EOE EFE EOF EFO EFF
//OEE OEO OEF OFE OFO OFF 
//FEE FEO FEF FOE FOF FFE FFO FFF  22