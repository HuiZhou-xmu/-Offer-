#include <iostream>
#include <vector>
using namespace std;

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

//头铁方法
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

//二分法
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

