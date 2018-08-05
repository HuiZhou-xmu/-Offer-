#include <iostream>
using namespace std;

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
//�����������һ��n����̨���ܹ��ж�����������

//�𰸴���:���ύ�ĳ���û��ͨ�����еĲ�������
//caseͨ����Ϊ47.37%
class Solution1{
public:
	int jumpFloor(int number){
		if (number < 1){
			return 0;
		}
		if (number == 1){
			return 1;
		}
		if (number == 2){
			return 2;
		}
		int count = 0;
		int x = 0;
		float y = 0;
		for (; x <= number; ++x){
			y = (number - x) / 2.0;
			if (y == int(y)){
				count += fact_part(x + y, y) / fact(y);
			}
		}
		return count;
	}

	int fact(int n){
		if (n == 0){
			return 1;
		}
		int result = 1;
		for (int i = 1; i <= n; ++i){
			result *= i;
		}
		return result;
	}

	int fact_part(int n, int m){
		int result = 1;
		for (int i = 0; i < m; ++i){
			result *= n;
			--n;
		}
		return result;
	}
};

class Solution{
public:
	int jumpFloor(int number){
		if (number < 1){
			return 0;
		}
		int a = 1;
		int b = 2;
		if (number == 1){
			return a;
		}
		if (number == 2){
			return b;
		}
		int result = 0;
		for(int i = 2; i < number; ++i){
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};


int main(int argc, char **argv){
	Solution s;
	cout << s.jumpFloor(5) << endl;
}

