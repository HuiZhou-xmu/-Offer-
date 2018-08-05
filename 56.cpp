//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode* deleteDuplication(ListNode* pHead){
		if (pHead == NULL)return NULL;
		if (pHead->next == NULL)return pHead;
		ListNode* curNode = pHead;
		ListNode* preNode = new ListNode(0);
		preNode->next = curNode;
		bool head = false;
		while (curNode && curNode->next){
			if (curNode->val != curNode->next->val){
				if (!head){
					pHead = curNode;
					head = true;
				}
			}
			else{
				curNode = curNode->next;
				while (curNode->next && (curNode->val == curNode->next->val)){
					curNode = curNode->next;
				}
				curNode = curNode->next;
				preNode->next = curNode;
				continue;
			}
			curNode = curNode->next;
			preNode = preNode->next;
		}
		//����1->1->1->1->1,����NULL,����1->1->1->1->2,���ؽڵ�2,�ۺϷ���preNode->next��
		if (head) return pHead;
		return preNode->next;
	}
};

int main(int argc, char **argv){
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(3);
	ListNode* l5 = new ListNode(3);
	ListNode* l6 = new ListNode(4);
	ListNode* l7 = new ListNode(4);
	ListNode* l8 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;
	Solution s;
	ListNode* head = s.deleteDuplication(l1);
}