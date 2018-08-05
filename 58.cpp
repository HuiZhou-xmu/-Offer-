//��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�

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

//��һ���ύ��caseͨ����Ϊ90.00%
//�ڶ����ύ���������������������жϣ�caseͨ������Ȼ��90.00%
class Solution{
public:
	bool isSymmetrical(TreeNode* pRoot){
		if (pRoot == NULL)return true;
		if (pRoot->left == NULL && pRoot->right != NULL)return false;
		if (pRoot->left != NULL && pRoot->right == NULL)return false;
		if (TreeDepth(pRoot->left) != TreeDepth(pRoot->right))return false;
		//�����ұ���
		preLeftRight(pRoot);
		//���������
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