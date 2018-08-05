//����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
//ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣

#include <iostream>
using namespace std;

struct TreeLinkNode{
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode){
		if (pNode == NULL)return NULL;
		if (pNode->right){
			pNode = pNode->right;
			while (pNode->left){
				pNode = pNode->left;
			}
			return pNode;
		}
		while (pNode->next){
			if (pNode->next->left == pNode)return pNode->next;
			pNode = pNode->next;
		}
		return NULL;
	}
};