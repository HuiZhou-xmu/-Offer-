#include <vector>
#include <iostream>

using namespace std;

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution{
public:
	bool VerifySquenceOfBST(vector<int> sequence){
		if (sequence.size() == 0){
			return false;
		}
		if (sequence.size() == 1){
			return true;
		}
		return judge(sequence, 0, sequence.size() - 1);
	}

	bool judge(vector<int> &sequence, int begin, int end){
		if (begin >= end){
			return true;
		}
		int i = begin;
		while (sequence[i] < sequence[end]){
			i++;
		}
		for (int j = i + 1; j < end; ++j){
			if (sequence[j] < sequence[end]){
				return false;
			}
		}
		return judge(sequence, begin, i - 1) && judge(sequence, i, end - 1);
	}
};

int main(int argc, char **argv){
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 8 };
	Solution s;
	cout << s.VerifySquenceOfBST(vec) << endl;
}