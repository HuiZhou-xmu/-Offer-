//小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
//但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
//没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

//输出描述：输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<vector<int>> FindContinuousSequence(int sum){
		vector<vector<int>> res;
		if (sum <= 2){
			return res;
		}
		int pos = sum / 2;
		for (int i = 1; i <= pos; ++i){
			if (i + i + 1 > sum)break;
			int tmp = i;
			vector<int> equalSum;
			equalSum.push_back(i);
			for (int j = i + 1; ; ++j){
				tmp += j;
				if (tmp > sum)break;
				equalSum.push_back(j);
				if (tmp == sum){
					res.push_back(equalSum);
					break;
				}
			}
		}
		return res;
	}
};

int main(int argc, char **argv){
	Solution s;
	int sum = 21;
	vector<vector<int>> res;
	res = s.FindContinuousSequence(sum);
	for (auto s1 : res){
		for (auto s2 : s1){
			cout << s2 << " ";
		}
		cout << endl;
	}
}