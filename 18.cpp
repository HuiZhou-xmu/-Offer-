#include <iostream>

using namespace std;

//操作给定的二叉树，将其变换为源二叉树的镜像。
//输入描述:
//二叉树的镜像定义：源二叉树 
//    	    8
//    	   /  \
//    	  6   10
//    	 / \  / \
//    	5  7 9 11
//    	镜像二叉树
//    	    8
//    	   /  \
//    	  10   6
//    	 / \  / \
//    	11 9 7  5

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	void Mirror(TreeNode *pRoot){
		if (pRoot == NULL){
			return;
		}
		if (pRoot->left || pRoot->right){
			TreeNode *temp;
			temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
		}
		if (pRoot->left){
			Mirror(pRoot->left);
		}
		if (pRoot->right){
			Mirror(pRoot->right);
		}	
	}
};

int main(int argc, char **argv){
	TreeNode* tree1 = new TreeNode(8);
	tree1->left = new TreeNode(6);
	tree1->left->left = new TreeNode(5);
	tree1->left->right = new TreeNode(7);
	tree1->right = new TreeNode(10);
	tree1->right->left = new TreeNode(9);
	tree1->right->right = new TreeNode(11);

	Solution s;
	s.Mirror(tree1);
	cout << tree1->val << " " << tree1->left->val << " " << tree1->left->left->val << " ";
	cout << tree1->left->right->val << " " << tree1->right->val << endl;

	s.Mirror(NULL);
}
