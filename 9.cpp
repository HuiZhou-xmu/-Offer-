#include <iostream>
#include <math.h>
using namespace std;

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
//�����������һ��n����̨���ܹ��ж�����������

class Solution{
public:
	int jumpFloorII(int number){
		if (number < 1){
			return 0;
		}
		return pow(2, number - 1);
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.jumpFloorII(4) << endl;
}