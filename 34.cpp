//��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.

#include <string>
#include <iostream>
#include <map>
using namespace std;

//ʱ�临�Ӷ�O(n^2)
class Solution{
public:
	int FirstNotRepeatingChar(string str){
		for (char& c : str){
			int pos = str.find(c);
			if (pos == str.rfind(c)){
				return pos;
			}
		}
		return -1;
	}
};

//

int main(int argc, char **argv){
	string s = "google";
	int pos = s.find( 'g');
	int pos_1 = s.rfind('g');
	cout << pos << endl;
	cout << pos_1 << endl;
}