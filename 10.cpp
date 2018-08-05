#include <iostream>
using namespace std;

//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

class Solution{
public:
	int rectCover(int number){
		if (number <= 0){
			return 0;
		}
		int a = 1, b = 2;
		if (number == 1){
			return a;
		}
		if (number == 2){
			return b;
		}
		int result;
		for (int i = 2; i < number; ++i){
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};