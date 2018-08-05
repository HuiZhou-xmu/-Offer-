//��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

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
				//������
				list<TreeNode*>::iterator beg = tmp.begin();
				list<TreeNode*>::iterator end = tmp.end();
				for (; beg != end; ++beg)level.push_back((*beg)->val);
			}
			else{
				//���ҵ���
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