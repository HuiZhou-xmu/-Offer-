#include <iostream>
using namespace std;

//����һ����������������е�����k����㡣

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

//������������
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
		//����k>size���жϾͻᱨ��,��Ϊ(size-k+1)<0ʱ(size-k+1)����������ת����unsigned int���ӽ��������
		//���Ĵ����ѱ���
		//�δ���:���ĳ������δ��󣬿���������Խ�磬��ջ��������磬�ݹ���ò���̫�ࣩ���������
		//caseͨ����Ϊ0.00%
		if (k > size){
			return NULL;
		}
		for (int i = 1; i < (size-k+1); ++i){
			pListHead = pListHead->next;
		}
		return pListHead;
	}
};

//����һ������
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