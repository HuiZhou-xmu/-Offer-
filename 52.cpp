//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

//多思考思考

#include <iostream>
using namespace std;

class Solution{
public:
	bool match(char* str, char* pattern){
		char cur;
		char pat;
		while (*str!='\0'){
			cur = *str;
			pat = *pattern;
			if (pat == '\0')return false;
			str++;
			pattern++;
			if (cur == pat)continue;
			if (pat == '.')continue;
			if (cur != pat){
				if (*pattern == '*'){
					++pattern;
					--str;
					continue;
				}else return false;
			}
		}
		if (*pattern == '*')return true;
		if (*pattern != '\0')return false;
		return true;
	}
};

class Solution{
public:
	bool match(char* str, char *pattern){
		if (*str == '\0' && *pattern == '\0')return true;
		if (*str != '\0' && *pattern == '\0')return false;
		if (*(pattern + 1) == '*'){
			if (*str == *pattern || (*str != '\0' && *pattern == '.')){
				return match(str + 1, pattern) || match(str, pattern + 2);
			}
			else{
				return match(str, pattern + 2);
			}
		}
		else{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))return match(str + 1, pattern + 1);
			else return false;
		}
	}
};

int main(int argc, char **argv){
	//后面有个隐身的'\0'
	char* str = "aaa";
	char* pat1 = "a.a";
	char* pat2 = "ab*ac*a";
	char* pat3 = "aa.a";
	char* pat4 = "ab*a";
	Solution s;
	cout << s.match(str, pat1) << endl;
	cout << s.match(str, pat2) << endl;
	cout << s.match(str, pat3) << endl;
	cout << s.match(str, pat4) << endl;
	cout << *(str+1) << endl;
}