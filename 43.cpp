//汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
	string LeftRotateString(string str, int n){
		string res;
		if (str.empty() || n < 0)return res;
		int lefPos = n % str.size();
		string moveStr(str, 0, n);
		str.erase(0, n);
		res = str + moveStr;
		return res;
	}
};

int main(int argc, char **argv){
	string s = "abcXYZdef";
	Solution sol;
	cout << sol.LeftRotateString(s, 3) << endl;
}