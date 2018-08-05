#include <iostream>
#include <vector>
using namespace std;

//输入一个链表，从尾到头打印链表每个节点的值

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	vector<int> printListFromTailToHead(ListNode* head){
		vector<int> vec;
		while (head){
			vec.push_back(head->val);
			head = head->next;
		}
		vector<int> vec_reverse;
		auto beg = vec.rbegin();
		auto end = vec.rend();
		while (beg != end){
			vec_reverse.push_back(*beg);
			++beg;
		}
		return vec_reverse;
	}
};