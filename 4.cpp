#include <iostream>
#include <vector>
using namespace std;

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归版本一
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode* root;
		int preEnd = pre.size() - 1;
		int vinEnd = vin.size() - 1;
		root = reConstructBinaryTreeCore(pre, 0, preEnd, vin, 0, vinEnd);
		return root;
	}
	TreeNode* reConstructBinaryTreeCore(vector<int> &pre, int preStart, int preEnd, vector<int> &vin, int vinStart, int vinEnd) {
		if (preStart > preEnd || vinStart > vinEnd)return NULL;
		TreeNode* root = new TreeNode(pre[preStart]);
		for (int i = vinStart; i < vin.size(); ++i) {
			if (vin[i] == pre[preStart]) {
				root->left = reConstructBinaryTreeCore(pre, preStart + 1, preStart + i - vinStart, vin, vinStart, i - 1);
				root->right = reConstructBinaryTreeCore(pre, preStart + i - vinStart + 1, preEnd, vin, i + 1, vinEnd);
				break;
			}
		}
		return root;
	}
};

//递归版本二
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())return NULL;
		TreeNode* root = new TreeNode(pre[0]);
		int equal_idx = 0;
		for (int i = 0; i < vin.size(); ++i) {
			if (vin[i] == pre[0]) {
				equal_idx = i;
				break;
			}
		}
		vector<int> left_pre, right_pre, left_vin, right_vin;
		for (int i = 0; i < equal_idx; ++i) {
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (int i = equal_idx + 1; i < vin.size(); ++i) {
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		root->left = reConstructBinaryTree(left_pre, left_vin);
		root->right = reConstructBinaryTree(right_pre, right_vin);
		return root;
	}
};