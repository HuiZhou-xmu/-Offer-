#include <iostream>
#include <string>
using namespace std;

//��Ŀ����ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

class Solution{
public:
	void replaceSpace(char *str, int length){
		for (int i = 0; i < length; ++i){
			if (*(str + i) == ' '){
				length += 2;
				int j = length - 1;
				while (j > i+2){
					*(str + j) = *(str + j - 2);
					j--;
				}
				*(str + i) = '%';
				*(str + i + 1) = '2';
				*(str + i + 2) = '0';
			}
		}
		
	}
};

class Solution1{
public:
	void replaceSpace(char *str, int length) {
		for (int i = 0; i < length; i++){
			if (*(str + i) == ' '){
				length += 2;
				int j = length - 1;
				while (j - 2 > i){
					*(str + j) = *(str + j - 2);
					j--;
				}
				*(str + i) = '%';
				*(str + i + 1) = '2';
				*(str + i + 2) = '0';
			}
		}
	}
};

int main(int argc, char **argv){
	char *str = "We Are Happy";
	int length = 12;
	Solution s;
	s.replaceSpace(str, 12);
	while (*str){
		cout << *str;
		str++;
	}
	cout << endl;
	
}


//py
//# -*- coding:utf-8 -*-
//class Solution :
//	# s Դ�ַ���
//	def replaceSpace(self, s) :
//	return s.replace(" ", "%20")
//	# write code here