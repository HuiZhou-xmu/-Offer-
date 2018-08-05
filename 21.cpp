#include <vector>
#include <stack>

using namespace std;

//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�

class Solution{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV){
		if (pushV.empty() || popV.empty()){
			return false;
		}
		if (pushV.size() != popV.size()){
			return false;
		}
		stack<int> sTemp;
		int idx = 0;
		for (int i = 0; i < pushV.size(); ++i){
			sTemp.push(pushV[i]);
			while (!sTemp.empty() && (sTemp.top() == popV[idx])){
				sTemp.pop();
				idx++;
			}
		}
		return sTemp.empty();
	}
};