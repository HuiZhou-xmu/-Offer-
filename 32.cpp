//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	string PrintMinNumber(vector<int> numbers){
		sort(numbers.begin(), numbers.end(), [](const int& a, const int& b){return to_string(a) + to_string(b) < to_string(b) + to_string(a); });
		string res;
		for (auto num : numbers){
			res += to_string(num);
		}
		return res;
	}
};

int main(int argc, char **argv){
	vector<int> vec{ 3, 4, 2, 5, 1, 76, 34, 12, 6754, 113 };
	sort(vec.begin(), vec.end(), [](const int& a, const int& b){return a > b; });
	for (auto v : vec){
		cout << v << " ";
	}
	cout << endl;
}