//ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
//HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��
//Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
//ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,
//��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
//������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)

#include <iostream>
#include <list>
#include <vector>
using namespace std;

//list�ĵ�����֧��������֧�ּ�,++iter�ǶԵģ�����iter=iter+1�򱨴�
class Solution{
public:
	int LastRemaining_Solution(int n, int m){
		if (n < 1 || m < 1)return -1;
		list<int> list_n;
		for (int i = 0; i < n; ++i){
			list_n.push_back(i);
		}
		list<int>::iterator curIter = list_n.begin();
		list<int>::iterator nextIter;
		while (list_n.size() > 1){
			for (int i = 1; i < m; ++i){
				++curIter;
				if (curIter == list_n.end())curIter = list_n.begin();
			}
			nextIter = ++curIter;
			if (nextIter == list_n.end())nextIter = list_n.begin();
			--curIter;
			list_n.erase(curIter);
			curIter = nextIter;
		}
		return list_n.front();
	}
};

int main(int argc, char **argv){
	Solution s;
	cout << s.LastRemaining_Solution(11, 3) << endl;
}