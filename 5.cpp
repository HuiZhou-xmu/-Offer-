#include <stack>
#include <iostream>
using namespace std;

//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(int argc, char **argv){
	Solution s;
	//cout << s.pop() << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
}