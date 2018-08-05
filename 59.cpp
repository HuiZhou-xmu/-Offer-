//请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

#include <iostream>
#include <vector>
#include <list>
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
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot == NULL)return res;
		list<TreeNode*> tmp;
		tmp.push_back(pRoot);
		int flag = 1;
		while (tmp.size()){
			vector<int> level;
			if (flag % 2){
				//从左到右
				list<TreeNode*>::iterator beg = tmp.begin();
				list<TreeNode*>::iterator end = tmp.end();
				for (; beg != end; ++beg)level.push_back((*beg)->val);
			}
			else{
				//从右到左
				list<TreeNode*>::reverse_iterator beg = tmp.rbegin();
				list<TreeNode*>::reverse_iterator end = tmp.rend();
				for (; beg != end; ++beg)level.push_back((*beg)->val);
			}
			res.push_back(level);
			flag++;
			int s = tmp.size();
			while (s--){
				TreeNode* cur = tmp.front();
				tmp.pop_front();
				if (cur->left)tmp.push_back(cur->left);
				if (cur->right)tmp.push_back(cur->right);
			}
		}
		return res;
	}
};