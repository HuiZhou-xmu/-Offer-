#include <iostream>
#include <vector>
using namespace std;

//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//借用vector辅助空间，时间复杂度为O(n),空间复杂度为O(n)。
class Solution{
public:
	void reOrderArray(vector<int> &array){
		int odd_count = 0;
		for (int i = 0; i < array.size(); ++i){
			if (array[i] % 2){
				++odd_count;
			}
		}
		int odd_idx = 0;
		int eve_idx = odd_count;
		vector<int> arr_temp(array.size());
		for (int i = 0; i < array.size(); ++i){
			if (array[i] % 2){
				arr_temp[odd_idx++] = array[i];
			}
			else{
				arr_temp[eve_idx++] = array[i];
			}
		}
		array = arr_temp;
	}
};

//尾插，删除之后，其实vector内部的代码实现是把后面的所有数据都往前移动，时间复杂度为O(n^2)，空间复杂度为O(1)。
class Solution{
public:
	void reOrderArray(vector<int> &array){
		int temp;
		int size = array.size();
		vector<int>::iterator arr_beg = array.begin();
		while (size){
			if (*arr_beg % 2 == 0){
				temp = *arr_beg;
				arr_beg = array.erase(arr_beg);
				array.push_back(temp);
			}
			else{
				++arr_beg;
			}
			--size;
		}
	}
};

int main(int argc, char **argv){
	Solution s;
	vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	s.reOrderArray(array);
}