//������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
//���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
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