#include <iostream>
#include <vector>
using namespace std;

//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

//ͷ������
class Solution1{
public:
	int minNumberInRotateArray(vector<int> rotateArray){
		if (rotateArray.size() == 0){
			return 0;
		}
		int min = rotateArray[0];
		for (int i = 1; i < rotateArray.size(); ++i){
			if (min > rotateArray[i]){
				min = rotateArray[i];
			}
		}
		return min;
	}
};

//���ַ�
class Solution{
public:
	int minNumberInRotateArray(vector<int> rotateArray){
		if (rotateArray.size() == 0){
			return 0;
		}
		int low = 0, high = rotateArray.size() - 1;
		int mid = 0;
		while (low < high){
			mid = low + (high - low) / 2;
			if (rotateArray[mid] < rotateArray[high]){
				high = mid;
			}
			else if (rotateArray[mid] > rotateArray[high]){
				low = mid + 1;
			}
			else{
				high = high - 1;
			}
		}
		return rotateArray[low];
	}
};

int main(int argc, char **argv){
	vector<int> vec{ 3, 4, 5, 1, 2 };
	Solution s;
	cout << s.minNumberInRotateArray(vec) << endl;
}

