#include <vector>
#include <iostream>
using namespace std;

//��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������


//��������
class Solution{
public:
	bool Find(int target, vector<vector<int>> array){
		for (int i = 0; i < array.size(); ++i){
			for (int j = 0; j < array[i].size(); ++j){
				if (array[i][j] == target){
					return true;
				}
			}
		}
		return false;
	}
};

//��ѷ���
//�����½�Ԫ�ؿ�ʼ���ң��ұ�Ԫ�ر����Ԫ�ش��ϱ�Ԫ�ر����Ԫ��С��
//���ǣ�target�����Ԫ��С�������ң������Ԫ�ش�������ҡ�������˱߽磬��˵����ά�����в�����targetԪ�ء�
class Solution{
public:
	bool Find(int target, vector<vector<int>> array){
		int rows = array.size() - 1;
		int cols = array[0].size() - 1;
		int i = rows;
		int j = 0;
		while (i >= 0 & j <= cols){
			if (target < array[i][j]){
				--i;
			}
			else if (target > array[i][j]){
				++j;
			}
			else{
				return true;
			}

		}
		return false;
	}

};

int main(int argc, char **argv){
	int target = 3;
	vector<int> vec1 = { 1, 2, 3, 4, 5 };
	vector<vector<int>> vec2(5);
	for (int i = 0; i < vec2.size(); ++i){
		vec2[i] = vec1;
	}
	for (int i = 0; i < vec2.size(); ++i){
		for (int j = 0; j < vec2[i].size(); ++j){
			cout << vec2[i][j] << " ";
		}
		cout << endl;
	}
	Solution s;
	cout << s.Find(target, vec2) << endl;
}