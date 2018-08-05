//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��

#include <iostream>
#include <map>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead){
		if (pHead == NULL)return NULL;
		map<ListNode*, int> node;
		while (pHead){
			if (++node[pHead] == 2) return pHead;
			pHead = pHead->next;
		}
		return NULL;
	}
};