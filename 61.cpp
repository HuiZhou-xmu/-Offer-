//请实现两个函数，分别用来序列化和反序列化二叉树
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
//c_str()返回const char*,不能赋值给char*,常量指针不能转换为非常量指针。return res.c_str()会报错，通过strcpy赋值给char*再return就可以啦。
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
		//++(**str)通不过,++(*str)通过,仔细看，不要移错指针。。。
		++(*str);
		root->left = Deserialize_(str);
		root->right = Deserialize_(str);
		return root;
	}
};