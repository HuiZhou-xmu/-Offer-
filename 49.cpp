//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
//��������������һ���ַ���,����������ĸ����,����Ϊ��
//�������������ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0

#include <string>
#include <iostream>
using namespace std;

//�ַ�0~9�ֱ��Ӧasciiֵ��ʮ����48~57��
//���Ǳ߽߱ǽǣ�һ���������⣡����
class Solution{
public:
	int StrToInt(string str){
		int res = 0;
		int len = str.size();
		bool flag = true;
		for (int i = 0; i < str.size(); ++i){
			if (str[i] == 43){
				--len;
				flag = true;
				continue;
			}
			if (str[i] == 45){
				--len;
				flag = false;
				continue;
			}
			if (str[i] < 48 || str[i]>57)return 0;
			res += (str[i] - 48)*pow(10, --len);
		}
		return flag ? res : -res;
	}
};

int main(int argc, char **argv){
	string s = "23333";
	cout << s[0] << endl;
	cout << '-'-0 << endl;
	Solution sss;
	cout << sss.StrToInt("21313") << endl;
}