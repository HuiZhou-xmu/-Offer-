//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
//���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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
		//����ÿһ���ڵ�����Ӧ�Ľڵ����
		while (curNode){
			RandomListNode* node = new RandomListNode(curNode->label);
			node->next = curNode->next;
			curNode->next = node;
			curNode = node->next;
		}
		//����ÿһ���ڵ��random�ڵ�
		curNode = pHead;
		while (curNode){
			if (curNode->random){
				curNode->next->random = curNode->random->next;
			}
			curNode = curNode->next->next;
		}
		//���
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