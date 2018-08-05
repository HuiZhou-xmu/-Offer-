//�������������ҳ����ǵĵ�һ��������㡣
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

//�����й����ڵ㣬��ô�����ڵ�->next����ͬ����ô�϶��й���β����
class Solution{
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
		int len1 = getListLength(pHead1);
		int len2 = getListLength(pHead2);
		if (len1 > len2){
			pHead1 = walkStep(pHead1, len1 - len2);
		}
		else{
			pHead2 = walkStep(pHead2, len2 - len1);
		}
		while (pHead1){
			if (pHead1 == pHead2)return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return NULL;
	}
	//�ֲ�����lenһ��Ҫ��ʼ�����������д���
	int getListLength(ListNode* p){
		int len = 0;
		while (p){
			len++;
			p = p->next;
		}
		return len;
	}
	ListNode* walkStep(ListNode* p, int step){
		while (step--){
			p = p->next;
		}
		return p;
	}
};



