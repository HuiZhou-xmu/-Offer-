//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
//例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
//因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

#include <vector>
#include <iostream>
using namespace std;

//回溯法
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)return false;
		bool *visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);
		int pathLength = 0;
		for (int row = 0; row < rows; ++row) {
			for (int col = 0; col < cols; ++col) {
				if (hasPathCore(matrix, rows, cols, row, col, pathLength, str, visited)) {
					return true;
				}
			}
		}
		delete[] visited;
		return false;
	}
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, int pathLength, char* str, bool *visited) {
		if (str[pathLength] == '\0')return true;
		bool hasPath = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]) {
			++pathLength;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, pathLength, str, visited) ||
				hasPathCore(matrix, rows, cols, row - 1, col, pathLength, str, visited) ||
				hasPathCore(matrix, rows, cols, row, col + 1, pathLength, str, visited) ||
				hasPathCore(matrix, rows, cols, row + 1, col, pathLength, str, visited);
			if (!hasPath) {
				--pathLength;
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
};


//八皇后问题
int n = 8;
int total = 0;
int *c = new int(n);

bool is_ok(int row) {
	for (int i = 0; i != row; ++i) {
		if ((c[row] == c[i]) || (abs(c[row] - c[i]) == row - i)) {
			return false;
		}
	}
	return true;
}

void queen(int row) {
	if (row == n) {
		total++;
	}
	else {
		for (int col = 0; col < n; ++col) {
			c[row] = col;
			if (is_ok(row)) {
				queen(row + 1);
			}
		}
	}
}

int main(int argc, char **argv) {
	queen(0);
	cout << total << endl;
}
