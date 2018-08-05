#include <vector>
#include <iostream>
using namespace std;

//题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


//暴力搜索
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

//最佳方法
//从左下角元素开始查找，右边元素比这个元素大，上边元素比这个元素小。
//于是，target比这个元素小就往上找，比这个元素大就往右找。如果出了边界，则说明二维数组中不存在target元素。
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