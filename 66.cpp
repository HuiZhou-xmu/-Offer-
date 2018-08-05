//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (rows < 1 || cols < 1 || threshold < 0)return 0;
		bool *visited = new bool[rows*cols];
		for (int i = 0; i < rows*cols; ++i)visited[i] = false;
		return movingCountCore(threshold, rows, cols, 0, 0, visited);
	}
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited) {
		int count = 0;
		if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row*cols + col] && (getDigitSum(row) + getDigitSum(col) <= threshold)) {
			visited[row*cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited);
		}
		return count;
	}
	int getDigitSum(int number) {
		int sum = 0;
		while (number > 0) {
			sum += (number % 10);
			number /= 10;
		}
		return sum;
	}
};
int main(int argc, char **argv) {
	int k = 6;
	Solution s;
	cout << s.movingCount(k, 5, 4) << endl;
}