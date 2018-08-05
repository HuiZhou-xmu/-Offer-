#include <stack>
#include <iostream>
using namespace std;

//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

class Solution1{
public:
	void push(int node){
		stack1.push(node);
	}

	int pop(){
		if (stack1.empty() & stack2.empty()){
			throw exception("queue is empty.");
		}
		while (!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		int pop_val = stack2.top();
		stack2.pop();
		while (!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return pop_val;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//最佳解法
class Solution{
public:
	void push(int node){
		stack1.push(node);
	}

	int pop(){
		//手撕代码记得加边界条件的判断，在线编程加了可能报错。
		if (stack1.empty()&stack2.empty()){
			throw exception("the queue is empty.");
		}
		int pop_val;
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
			pop_val = stack2.top();
			stack2.pop();
			return pop_val;
		}
		pop_val = stack2.top();
		stack2.pop();
		return pop_val;
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