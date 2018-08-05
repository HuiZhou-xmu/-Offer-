#include <iostream>

using namespace std;

//输入两棵二叉树A，B，判断B是不是A的子结构。
//（ps：我们约定空树不是任意一个树的子结构）

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution1{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot1 == NULL || pRoot2 == NULL){
			return false;
		}
		TreeNode* pRoot2_pos = findNode(pRoot1, pRoot2);

	}
	TreeNode* findNode(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot1->val == pRoot2->val){
			return pRoot1;
		}
		if (pRoot1->left){
			findNode(pRoot1->left, pRoot2);
		}
		if (pRoot1->right){
			findNode(pRoot1->right, pRoot2);
		}
	}
};

class Solution{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		bool flag = false;
		//当pRoot1和pRoot2都不为空的时候，才进行比较。否则直接返回false
		if (pRoot1 != NULL && pRoot2 != NULL){
			//如果找到了对应Tree2的根节点的点
			if (pRoot1->val == pRoot2->val){
				//以这个根节点为起点判断是否包含Tree2
				flag = DoesTree1HasTree2(pRoot1, pRoot2);
			}
			//如果找不到，那么就再去root1的左儿子当作起点，去判断是否包含Tree2
			if (!flag){
				flag = HasSubtree(pRoot1->left, pRoot2);
			}
			//如果还找不到，那么就再去root1的右儿子当作起点，去判断是否包含Tree2
			if (!flag){
				flag = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		//返回结果
		return flag;
	}

	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
		//如果Tree2已经遍历完了都能对应的上，返回true
		if (pRoot2 == NULL){
			return true;
		}
		//如果Tree2还没有遍历完，Tree1却遍历完了。返回false
		if (pRoot1 == NULL){
			return false;
		}
		//如果其中有一个结点没有对应上，返回false
		if (pRoot1->val != pRoot2->val){
			return false;
		}
		//如果根节点对应的上，那么就分别去子节点里面匹配
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};

int main(int argc, char **argv){
	TreeNode* tree1 = new TreeNode(1);
	tree1->left = new TreeNode(2);
	tree1->left->left = new TreeNode(4);
	tree1->left->right = new TreeNode(5);
	tree1->right = new TreeNode(3);

	TreeNode* tree2 = new TreeNode(2);
	tree2->left = new TreeNode(4);
	tree2->left->left = new TreeNode(7);
	tree2->left->right = new TreeNode(8);
	tree2->right = new TreeNode(5);

	Solution s;
	cout << s.HasSubtree(tree1, tree2) << endl;
}