//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ� 
//���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
//��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

#include <vector>
#include <iostream>
using namespace std;

//���ݷ�
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


//�˻ʺ�����
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
