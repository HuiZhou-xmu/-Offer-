//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

//两种方法，1.使用二叉树的层序遍历；2.递归。
//使用二叉树的层序遍历，获取二叉树的深度。
class Solution{
public:
	int TreeDepth(TreeNode* pRoot){
		if (pRoot == NULL){
			return 0;
		}
		queue<TreeNode*> q;
		int depth = 0;
		q.push(pRoot);
		while (q.size()){
			depth++;
			int s = q.size();
			while (s--){
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->left)q.push(tmp->left);
				if (tmp->right)q.push(tmp->right);
			}
		}
		return depth;
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
	cout << s.TreeDepth(l1) << endl;
}