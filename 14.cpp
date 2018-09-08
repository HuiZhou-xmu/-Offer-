#include <iostream>
using namespace std;

//输入一个链表，输出该链表中倒数第k个结点。

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

//遍历两次链表
class Solution1{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
		if (pListHead == NULL || k == 0){
			return NULL;
		}
		int size = 0;
		ListNode* pos = pListHead;
		while (pos){
			++size;
			pos = pos->next;
		}
		//不加k>size的判断就会报错,因为(size-k+1)<0时(size-k+1)的运算结果会转换成unsigned int，接近正无穷大。
		//您的代码已保存
		//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
		//case通过率为0.00%
		if (k > size){
			return NULL;
		}
		for (int i = 1; i < (size-k+1); ++i){
			pListHead = pListHead->next;
		}
		return pListHead;
	}
};

//遍历一次链表
class Solution{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
		if (pListHead == NULL || k == 0){
			return NULL;
		}
		ListNode* pre = pListHead;
		ListNode* last = pListHead;
		for (int i = 1; i < k; ++i){
			if (pre->next){
				pre = pre->next;
			}
			else{
				return NULL;
			}
		}
		while (pre){
			pre = pre->next;
			if (pre){
				last = last->next;
			}
		}
		return last;
	}
};

int main(int argc, char **argv){
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	Solution s;
	ListNode* p = s.FindKthToTail(l1, 1);
	cout << p->val << endl;

	int size = 5;
	unsigned int k = 100;
	cout << size - k << endl;
}