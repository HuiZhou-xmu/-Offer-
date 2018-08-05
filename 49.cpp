//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0。
//输入描述：输入一个字符串,包括数字字母符号,可以为空
//输出描述：如果是合法的数值表达则返回该数字，否则返回0

#include <string>
#include <iostream>
using namespace std;

//字符0~9分别对应ascii值中十进制48~57。
//考虑边边角角，一般出错就在这！！！
class Solution{
public:
	int StrToInt(string str){
		int res = 0;
		int len = str.size();
		bool flag = true;
		for (int i = 0; i < str.size(); ++i){
			if (str[i] == 43){
				--len;
				flag = true;
				continue;
			}
			if (str[i] == 45){
				--len;
				flag = false;
				continue;
			}
			if (str[i] < 48 || str[i]>57)return 0;
			res += (str[i] - 48)*pow(10, --len);
		}
		return flag ? res : -res;
	}
};

int main(int argc, char **argv){
	string s = "23333";
	cout << s[0] << endl;
	cout << '-'-0 << endl;
	Solution sss;
	cout << sss.StrToInt("21313") << endl;
}