#include <iostream>

using namespace std;

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ��
//��ps������Լ��������������һ�������ӽṹ��

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution1{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot1 == NULL || pRoot2 == NULL){
			return false;
		}
		TreeNode* pRoot2_pos = findNode(pRoot1, pRoot2);

	}
	TreeNode* findNode(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot1->val == pRoot2->val){
			return pRoot1;
		}
		if (pRoot1->left){
			findNode(pRoot1->left, pRoot2);
		}
		if (pRoot1->right){
			findNode(pRoot1->right, pRoot2);
		}
	}
};

class Solution{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		bool flag = false;
		//��pRoot1��pRoot2����Ϊ�յ�ʱ�򣬲Ž��бȽϡ�����ֱ�ӷ���false
		if (pRoot1 != NULL && pRoot2 != NULL){
			//����ҵ��˶�ӦTree2�ĸ��ڵ�ĵ�
			if (pRoot1->val == pRoot2->val){
				//��������ڵ�Ϊ����ж��Ƿ����Tree2
				flag = DoesTree1HasTree2(pRoot1, pRoot2);
			}
			//����Ҳ�������ô����ȥroot1������ӵ�����㣬ȥ�ж��Ƿ����Tree2
			if (!flag){
				flag = HasSubtree(pRoot1->left, pRoot2);
			}
			//������Ҳ�������ô����ȥroot1���Ҷ��ӵ�����㣬ȥ�ж��Ƿ����Tree2
			if (!flag){
				flag = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		//���ؽ��
		return flag;
	}

	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
		//���Tree2�Ѿ��������˶��ܶ�Ӧ���ϣ�����true
		if (pRoot2 == NULL){
			return true;
		}
		//���Tree2��û�б����꣬Tree1ȴ�������ˡ�����false
		if (pRoot1 == NULL){
			return false;
		}
		//���������һ�����û�ж�Ӧ�ϣ�����false
		if (pRoot1->val != pRoot2->val){
			return false;
		}
		//������ڵ��Ӧ���ϣ���ô�ͷֱ�ȥ�ӽڵ�����ƥ��
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};

int main(int argc, char **argv){
	TreeNode* tree1 = new TreeNode(1);
	tree1->left = new TreeNode(2);
	tree1->left->left = new TreeNode(4);
	tree1->left->right = new TreeNode(5);
	tree1->right = new TreeNode(3);

	TreeNode* tree2 = new TreeNode(2);
	tree2->left = new TreeNode(4);
	tree2->left->left = new TreeNode(7);
	tree2->left->right = new TreeNode(8);
	tree2->right = new TreeNode(5);

	Solution s;
	cout << s.HasSubtree(tree1, tree2) << endl;
}