//����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

//���ַ�����1.ʹ�ö������Ĳ��������2.�ݹ顣
//ʹ�ö������Ĳ����������ȡ����������ȡ�
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