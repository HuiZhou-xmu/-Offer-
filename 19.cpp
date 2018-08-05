#include <iostream>
#include <vector>

using namespace std;

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

class Solution{
public:
	vector<int> printMatrix(vector<vector<int>> matrix){
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> res;
		if (row == 0 || col == 0){
			return res;
		}
		// 定义四个关键变量，表示左上和右下的打印范围
		int left = 0, top = 0, right = col - 1, bottom = row - 1;
		while (left <= right && top <= bottom){
			//left to right
			for (int i = left; i <= right; ++i){
				res.push_back(matrix[left][i]);
			}
			//top to bottom
			for (int i = top + 1; i <= bottom; ++i){
				res.push_back(matrix[i][right]);
			}
			//right to left
			if (top != bottom){
				for (int i = right - 1; i >= left; --i){
					res.push_back(matrix[bottom][i]);
				}
			}
			//bottom to top
			if (left != right){
				for (int i = bottom - 1; i > top; --i){
					res.push_back(matrix[i][left]);
				}
			}
			++left; --right; ++top; --bottom;
		}
		return res;
	}
};

int main(int argc, char **argv){
	vector<vector<int>> matrix;
	vector<int> vec1{ 1, 2, 3, 4 };
	vector<int> vec2{ 5, 6, 7, 8 };
	vector<int> vec3{ 9, 10, 11, 12 };
	vector<int> vec4{ 13, 14, 15, 16 };

	matrix.push_back(vec1);
	matrix.push_back(vec2);
	matrix.push_back(vec3);
	matrix.push_back(vec4);

	Solution s;
	vector<int> res = s.printMatrix(matrix);
	for (auto r : res){
		cout << r << " ";
	}
	cout << endl;

}