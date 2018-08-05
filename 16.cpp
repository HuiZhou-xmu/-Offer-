#include <iostream>

using namespace std;

//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

//遇到问题先思考清楚，再下手，不要盲目下手，容易把自己弄晕。
//如果想法过于复杂，试着寻找简单方法。
class Solution1{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
		if (!pHead1 && !pHead2){
			return NULL;
		}
		if (pHead1 == NULL){
			return pHead2;
		}
		if (pHead2 == NULL){
			return pHead1;
		}
		ListNode* pHead = (pHead1->val < pHead2->val) ? pHead1 : pHead2;
		ListNode* tmp1;
		ListNode* tmp2;
		while (pHead2){
			tmp1 = pHead2->next;
			while (pHead1){
				tmp2 = pHead1->next;
				if (pHead2->val < pHead1->val){
					pHead2->next = pHead1;
					break;
				}
				else{
					if (pHead1->next == NULL){
						pHead1->next = pHead2;
						pHead1 = pHead2;
						break;
					}
					else if (pHead2->val <= pHead1->next->val){
						pHead1->next = pHead2;
						pHead2->next = tmp2;
						pHead1 = tmp2;
						break;
					}
				}
				pHead1 = pHead1->next;	
			}
			pHead2 = tmp1;
		}
		return pHead;
	}
};

//递归
//运行时间：5ms
//占用内存：456k
class Solution{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
		if (pHead1 == NULL){
			return pHead2;
		}
		if (pHead2 == NULL){
			return pHead1;
		}
		if (pHead1->val < pHead2->val){
			pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		}
		else{
			pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
	}
};

//非递归
//运行时间：3ms
//占用内存：472k
class Solution{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
		if (pHead1 == NULL){
			return pHead2;
		}
		if (pHead2 == NULL){
			return pHead1;
		}
		ListNode* newHead = new ListNode(-1);
		ListNode* curHead = newHead;
		while (pHead1 && pHead2){
			if (pHead1->val < pHead2->val){
				curHead->next = pHead1;
				pHead1 = pHead1->next;
				curHead = curHead->next;
			}
			else{
				curHead->next = pHead2;
				pHead2 = pHead2->next;
				curHead = curHead->next;
			}
		}
		if (pHead1 == NULL){
			curHead->next = pHead2;
		}
		if (pHead2 == NULL){
			curHead->next = pHead1;
		}
		return newHead->next;
	}
};

int main(int argc, char **argv){
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(3);
	ListNode* l3 = new ListNode(5);
	ListNode* l4 = new ListNode(7);
	ListNode* l5 = new ListNode(9);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	ListNode* l6 = new ListNode(0);
	ListNode* l7 = new ListNode(2);
	ListNode* l8 = new ListNode(4);
	ListNode* l9 = new ListNode(6);
	ListNode* l10 = new ListNode(8);
	l6->next = l7;
	l7->next = l8;
	l8->next = l9;
	l9->next = l10;

	ListNode* p;
	Solution s;
	p = s.Merge(l1, l6);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	
}