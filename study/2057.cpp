// Problem Description
// There must be many A + B problems in our HDOJ , now a new one is coming.
// Give you two hexadecimal integers , your task is to calculate the sum of them,and print it in hexadecimal too.
// Easy ? AC it !
// Input
// The input contains several test cases, please process to the end of the file.
// Each case consists of two hexadecimal integers A and B in a line seperated by a blank.
// The length of A and B is less than 15.
// Output
// For each test case,print the sum of A and B in hexadecimal in one line.
// Sample Input
// +A -A
// +1A 12
// 1A -9
// -1A -12
// 1A -AA
// Sample Output
// 0
// 2C
// 11
// -2C
// -90
#include <iostream>
#include <iomanip> 
using namespace std;
 
int main()
{
	long long m, n;
	long long result;
	while(cin>>hex>>m>>n)
    {
		result=m+n;
		if(result<0)
        {
			cout<<"-";
			cout<<hex<<uppercase<<-result<<endl;
		}
		else
			cout<<hex<<uppercase<<result<<endl;
    }
}


/*if(result<0)
        {
			cout<<"-";
			cout<<hex<<uppercase<<-result<<endl;
		}
关于这一段代码，为什么不直接输出result而是先输出-再输出result的绝对值，是因为
在C++中，当你使用 cout 以十六进制格式输出一个负数时，hex 操纵符会将整个数值（包括符号位）视为无符号整数来处理。
这意味着，如果你直接输出一个负数，hex 操纵符不会按照预期工作，因为它不会输出负数的十六进制表示，而是输出一个无符号整数的十六进制表示，
这个无符号整数的值可能与原始的负数值完全不同。
例如，如果你有一个8位的有符号整数 -1，在二进制中表示为 11111111（因为它是用补码表示的），
当你尝试以十六进制输出时，cout 会将其解释为 0xFF，这是一个无符号整数的十六进制表示，其值等于255，而不是-1。
为了避免这个问题，代码首先输出负号，然后输出结果的绝对值。这样做可以确保 hex 操纵符只处理无符号整数，
从而正确地以十六进制形式输出负数的绝对值。然后，通过在输出流中插入一个负号，可以在视觉上表示原始数值是负的。*/

/*这里是一个简化的例子来说明这个问题：

int main() {
    int negativeValue = -1;
    cout << hex << negativeValue << endl; // 输出将是 "FF" 而不是 "-1"
    return 0;
}
*/

//以下为本题失败代码
// #include <iostream>
// #include <string>
// #include <iomanip>
// using namespace std;

// // 将十六进制字符转换为对应的整数值
// int hex_char_to_int(char c) {
//     if (c >= '0' && c <= '9') return c - '0';
//     else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
//     else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
//     else return 0;
// }

// // 将十六进制字符串转换为整数
// int hex_string_to_int(const string& hex_str) {
//     int result = 0;
//     for (char c : hex_str) {
//         result = result * 16 + hex_char_to_int(c);
//     }
//     return result;
// }

// int main() {
//     string A, B;
//     while (cin >> A >> B) 
//     { // 读入两个十六进制数

//         int sum = hex_string_to_int(A) + hex_string_to_int(B); // 将十六进制字符串转换为整数相加
//         cout << hex << uppercase << sum << endl; // 输出和，以十六进制形式显示
//     }
//     return 0;
// }
/*总结：学到了新的输出方式即
cout<<hex<<....;这是将计算结果按16进制输出
cout<<uppercase是指将输出结果中的字母全部都变成大写*/
