//С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
//���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
//û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!

//���������������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<vector<int>> FindContinuousSequence(int sum){
		vector<vector<int>> res;
		if (sum <= 2){
			return res;
		}
		int pos = sum / 2;
		for (int i = 1; i <= pos; ++i){
			if (i + i + 1 > sum)break;
			int tmp = i;
			vector<int> equalSum;
			equalSum.push_back(i);
			for (int j = i + 1; ; ++j){
				tmp += j;
				if (tmp > sum)break;
				equalSum.push_back(j);
				if (tmp == sum){
					res.push_back(equalSum);
					break;
				}
			}
		}
		return res;
	}
};

int main(int argc, char **argv){
	Solution s;
	int sum = 21;
	vector<vector<int>> res;
	res = s.FindContinuousSequence(sum);
	for (auto s1 : res){
		for (auto s2 : s1){
			cout << s2 << " ";
		}
		cout << endl;
	}
}