//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

#include <string>
#include <iostream>
#include <map>
using namespace std;

//时间复杂度O(n^2)
class Solution{
public:
	int FirstNotRepeatingChar(string str){
		for (char& c : str){
			int pos = str.find(c);
			if (pos == str.rfind(c)){
				return pos;
			}
		}
		return -1;
	}
};

//

int main(int argc, char **argv){
	string s = "google";
	int pos = s.find( 'g');
	int pos_1 = s.rfind('g');
	cout << pos << endl;
	cout << pos_1 << endl;
}