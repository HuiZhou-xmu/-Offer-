//��ʵ�������������ֱ��������л��ͷ����л�������
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
}
};
//c_str()����const char*,���ܸ�ֵ��char*,����ָ�벻��ת��Ϊ�ǳ���ָ�롣return res.c_str()�ᱨ��ͨ��strcpy��ֵ��char*��return�Ϳ�������
class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (root == NULL)return NULL;
		string res;
		Serialize_(root, res);
		char* c = new char[res.size() + 1];
		strcpy(c, res.c_str());
		return c;
	}
	void Serialize_(TreeNode *root, string &res){
		if (root == NULL){
			res += "#,";
			return;
		}
		res += to_string(root->val);
		res += ',';
		Serialize_(root->left, res);
		Serialize_(root->right, res);
	}
	TreeNode* Deserialize(char *str) {
		if (str == NULL)return NULL;
		return Deserialize_(&str);
	}
	TreeNode* Deserialize_(char **str){
		if (**str == '#'){
			*str += 2;
			return NULL;
		}
		int val = 0;
		while (**str != ',' && **str != '\0'){
			val = val * 10 + (**str - '0');
			++(*str);
		}
		TreeNode* root = new TreeNode(val);
		if (**str == '\0')return root;
		//++(**str)ͨ����,++(*str)ͨ��,��ϸ������Ҫ�ƴ�ָ�롣����
		++(*str);
		root->left = Deserialize_(str);
		root->right = Deserialize_(str);
		return root;
	}
};