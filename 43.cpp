//�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
//����һ���������ַ�����S���������ѭ������Kλ������������
//���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����

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