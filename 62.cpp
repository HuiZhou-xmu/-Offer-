//����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬��5��3��7��2��4��6��8���У��������ֵ��С˳�����С����ֵΪ4��

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