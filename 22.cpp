#include <vector>
#include <queue>
using namespace std;

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<int> PrintFromTopToBottom(TreeNode* root){
		if (root == NULL){
			return;
		}
		printVec.push_back(root->val);
		if (root->left){
			printVec.push_back(root->left->val);
		}
		if (root -> right){
			printVec.push_back(root->right->val);
		}
		return printVec;
	}
private:
	vector<int> printVec;
}; 

class Solution{
public:
	vector<int> PrintFromTopToBottom(TreeNode* root){
		vector<int> res;
		if (root == NULL){
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()){
			res.push_back(q.front()->val);
			if (q.front()->left){
				q.push(q.front()->left);
			}
			if (q.front()->right){
				q.push(q.front()->right);
			}
			q.pop();
		}
		return res;
	}
};

