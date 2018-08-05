//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		map<int, int> num_count;
		for (int num : numbers){
			num_count[num]++;
			if (num_count[num] > numbers.size() / 2.0){
				return num;
			}
		}
		return 0;
	}
};

int main(int argc, char **argv){
	map<int, int> num;
	num[1] = 1;
	num[2] = 3;
	for (auto n : num){
		cout << n.first << " " << n.second << endl;
	}
}