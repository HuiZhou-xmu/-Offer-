//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

//第一次提交：case通过率为90.00%
//第二次提交，加上左右子树深度相等判断，case通过率依然是90.00%
class Solution{
public:
	bool isSymmetrical(TreeNode* pRoot){
		if (pRoot == NULL)return true;
		if (pRoot->left == NULL && pRoot->right != NULL)return false;
		if (pRoot->left != NULL && pRoot->right == NULL)return false;
		if (TreeDepth(pRoot->left) != TreeDepth(pRoot->right))return false;
		//根左右遍历
		preLeftRight(pRoot);
		//根右左遍历
		preRightLeft(pRoot);
		for (int i = 0; i < preLR.size(); ++i){
			if (preLR[i]->val != preRL[i]->val)return false;
		}
		return true;
	}
	void preLeftRight(TreeNode* pRoot){
		if (pRoot == NULL)return;
		preLR.push_back(pRoot);
		if (pRoot->left){
			preLeftRight(pRoot->left);
		}
		if (pRoot->right){
			preLeftRight(pRoot->right);
		}
	}
	void preRightLeft(TreeNode* pRoot){
		if (pRoot == NULL)return;
		preRL.push_back(pRoot);
		if (pRoot->right){
			preRightLeft(pRoot->right);
		}
		if (pRoot->left){
			preRightLeft(pRoot->left);
		}
	}
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
private:
	vector<TreeNode*> preLR;
	vector<TreeNode*> preRL;
};

class Solution{
public:
	bool isSymmetrical(TreeNode* pRoot){
		if (pRoot == NULL)return true;
		return compare(pRoot->left, pRoot->right);
	}
	bool compare(TreeNode* left, TreeNode* right){
		if (left == NULL) return right == NULL;
		if (right == NULL)return false;
		if (left->val != right->val)return false;
		return compare(left->left, right->right) && compare(left->right, right->left);
	}
};