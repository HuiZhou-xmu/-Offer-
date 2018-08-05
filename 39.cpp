//输入一棵二叉树，判断该二叉树是否是平衡二叉树。

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	//判断是否为平衡二叉树
	bool IsBalanced_Solution(TreeNode* pRoot){
		if (pRoot == NULL){
			return true;
		}
		int leftDepth = getDepth(pRoot->left);
		int rightDepth = getDepth(pRoot->right);
		if (abs(leftDepth - rightDepth) > 1)return false;
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
	//获取二叉树的深度
	int getDepth(TreeNode* node){
		if (node == NULL){
			return 0;
		}
		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);
		return max(leftDepth, rightDepth) + 1;
	}
};

int main(int argc, char **argv){
	TreeNode* l1 = new TreeNode(2);
	TreeNode* l2 = new TreeNode(2);
	TreeNode* l3 = new TreeNode(2);
	TreeNode* l4 = new TreeNode(2);
	TreeNode* l5 = new TreeNode(2);
	TreeNode* l6 = new TreeNode(2);

	l1->left = l2;
	l1->right = l3;
	l2->left = l4;
	l2->right = l5;
	l4->left = l6;
	Solution s;
	cout << s.IsBalanced_Solution(l1) << endl;
}