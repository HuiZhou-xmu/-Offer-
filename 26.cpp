#include <iostream>
using namespace std;
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode* Convert(TreeNode* pRootOfTree){
		ConvertList(pRootOfTree);
		return realHead;
	}
	void ConvertList(TreeNode* pRootOfTree){
		if (pRootOfTree == NULL){
			return;
		}
		ConvertList(pRootOfTree->left);
		if (head == NULL){
			head = pRootOfTree;
			realHead = pRootOfTree;
		}
		else{
			head->right = pRootOfTree;
			pRootOfTree->left = head;
			head = head->right;
		}
		ConvertList(pRootOfTree->right);
	}
private:
	TreeNode* head = NULL;
	TreeNode* realHead = NULL;
};

class test{
public:
	void change(){
		a = 100;
		//b = &a;
	}
	int getB(){
		return *b;
	}
private:
	int a = 10;
	int* b = &a;
};

int main(int argc, char **argv){
	test t;
	t.change();
	cout << t.getB() << endl;
	test t1;
	cout << t1.getB() << endl;
}