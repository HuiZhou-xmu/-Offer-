#include <iostream>

using namespace std;

//输入一个链表，反转链表后，输出链表的所有元素。

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode* ReverseList(ListNode* pHead){
		if (pHead == NULL){
			return NULL;
		}
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (pHead){
			next = pHead->next;
			pHead->next = pre;
			pre = pHead;
			pHead = next;
		}
		return pre;
	}
};

//错误
class Solution{
public:
	ListNode* ReverseList(ListNode* pHead){
		if (pHead == NULL){
			return NULL;
		}
		while (pHead->next){
			ListNode* tempNode = pHead->next->next;
			if (tempNode != NULL){
				pHead->next->next = pHead;
				pHead->next = NULL;
				pHead = pHead->next;
				pHead->next = tempNode;
			}
			else{
				pHead->next->next = pHead;
				pHead->next = NULL;
				pHead = pHead->next;
				break;
			}
		}
		return pHead;
	}
};