//��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
//���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
//���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
//��������������ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���

#include <sstream>
#include <iostream>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	//char��int����ͨ��asciiֵת��
	string s;
	char hash[256] = { 0 };
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (int i = 0; i < s.size(); ++i){
			if (hash[s[i]] == 1)return s[i];
		}
		return '#';
	}
};

int main(int argc, char **argv){
	Solution s;
	char hash[256] = { 0 };
	for (int i = 0; i < 256; ++i){
		cout << hash[i]+1 << '\n';
	}
	cout << endl;
}