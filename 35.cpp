//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ������,�����������е�����Ե�����P��
//����P��1000000007ȡģ�Ľ������� �����P%1000000007��
//��Ŀ��֤�����������û�е���ͬ������
//
//���ݷ�Χ��
//���� % 50������, size <= 10 ^ 4
//���� % 75������, size <= 10 ^ 5
//���� % 100������, size <= 2 * 10 ^ 5
//
//���룺1,2,3,4,5,6,7,0
//�����7

//����ָOffer�����鲢�����˼�롣

#include <vector>
#include <iostream>
using namespace std;

//������������ʱ��
class Solution{
public:
	int InversePairs(vector<int> data){
		if (data.size() <= 1){
			return 0;
		}
		int count = 0;
		for (int i = 0; i < data.size() - 1; ++i){
			for (int j = i + 1; j < data.size(); ++j){
				if (data[i] > data[j]){
					count++;
				}
			}
		}
		return count % 1000000007;
	}
};

int main(int argc, char **argv){
	vector<int> data{ 1, 2, 3, 4, 5, 6, 7, 0 };
	Solution s;
	cout << s.InversePairs(data) << endl;
}