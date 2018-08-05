#include <vector>
using namespace std;

//����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
//(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber){
		if (root == NULL){
			return res;
		}
		temp.push_back(root->val);
		if (!root->left && !root->right){
			if (temp.back() == expectNumber){
				res.push_back(temp);
			}
		}
		if (root->left){
			FindPath(root->left, expectNumber - root->val);
		}
		if (root->right){
			FindPath(root->right, expectNumber - root->val);
		}
		temp.pop_back();	
		return res;
	}
private:
	vector<vector<int>> res;
	vector<int> temp;
};