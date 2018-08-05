//���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�

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

class Solution{
public:
	vector<vector<int>> Print(TreeNode* pRoot){
		vector<vector<int>> res;
		if (pRoot == NULL)return res;
		queue<TreeNode*> tmp;
		tmp.push(pRoot);
		while (tmp.size()){
			vector<int> level;
			int s = tmp.size();
			while (s--){
				TreeNode* cur = tmp.front();
				level.push_back(cur->val);
				tmp.pop();
				if (cur->left)tmp.push(cur->left);
				if (cur->right)tmp.push(cur->right);
			}
			res.push_back(level);
		}
		return res;
	}
};