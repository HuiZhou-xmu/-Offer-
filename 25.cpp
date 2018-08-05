//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
//返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
#include <iostream>
using namespace std;

struct RandomListNode{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL){}
};

class Solution{
public:
	RandomListNode* Clone(RandomListNode* pHead){
		if (pHead == NULL){
			return NULL;
		}
		RandomListNode* curNode = pHead;
		//复制每一个节点至相应的节点后面
		while (curNode){
			RandomListNode* node = new RandomListNode(curNode->label);
			node->next = curNode->next;
			curNode->next = node;
			curNode = node->next;
		}
		//处理每一个节点的random节点
		curNode = pHead;
		while (curNode){
			if (curNode->random){
				curNode->next->random = curNode->random->next;
			}
			curNode = curNode->next->next;
		}
		//拆分
		curNode = pHead;
		RandomListNode* cloneHead = pHead->next;
		RandomListNode* tmp;
		while (curNode->next){
			tmp = curNode->next;
			curNode->next = curNode->next->next;
			curNode = tmp;;
		}
		return cloneHead;
	}
};