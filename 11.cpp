#include <iostream>
#include <list>
using namespace std;

//����һ��������������������Ʊ�ʾ��1�ĸ�����
//���и����ò����ʾ��

class Solution1{
public:
	int NumberOf1(int n){
		int count = 0;
		if (n >= 0){
			while (n != 0){
				if (n % 2 == 1){
					count += 1;
				}
				n /= 2;
			}
		}
		else{
			n = -n;
			list<int> n_list;
			while (n != 0){
				n_list.push_front(n % 2);
				n /= 2;
			}
			list<int>::iterator beg = n_list.begin();
			*beg = 1;
			while (++beg != n_list.end()){
				*beg = ~(*beg);
			}

		}
		
	}
};

class Solution{
public:
	int NumberOf1(int n){
		int num = 0;
		if (n < 0){
			n = n & 0x7FFFFFFF;
			++num;
		}
		while (n != 0){
			if (n & 1 == 1){
				num++;
			}
			n = n >> 1;
		}
		return num;
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.NumberOf1(16) << endl;
	cout << s.NumberOf1(-16) << endl;
	cout << sizeof(int) << endl;
	cout << (7 & 4) << endl;
}