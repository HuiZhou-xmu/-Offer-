//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��

//��˼��˼��

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
	//�����и������'\0'
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