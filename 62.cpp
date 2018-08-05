//给定一棵二叉搜索树，请找出其中的第k小的结点。例如，（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (k <= 0 || pRoot == NULL)return nullptr;
		preOrder(pRoot);
		sort(node.begin(), node.end(), [](TreeNode* a, TreeNode* b){return a->val < b->val; });
		if (k > node.size())return nullptr;
		return node[k - 1];
	}
	void preOrder(TreeNode* pRoot){
		if (pRoot == NULL)return;
		node.push_back(pRoot);
		if (pRoot->left)preOrder(pRoot->left);
		if (pRoot->right)preOrder(pRoot->right);
	}
private:
	vector<TreeNode*> node;
};