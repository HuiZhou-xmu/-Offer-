//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
	vector<int> vec;
	void push(int value){
		vec.push_back(value);
	}
	void pop(){
		vec.erase(vec.end() - 1);
	}
	int top(){
		return *(vec.end() - 1);
	}
	int min(){
		if (vec.empty()){
			return NULL;
		}
		int min = vec[0];
		for (int v : vec){
			if (min > v){
				min = v;
			}
		}
		return min;
	}
};

class Solution{
public:
	stack<int> stack1;
	stack<int> stack2;
	void push(int value){
		stack1.push(value);
		if (stack2.empty()){
			stack2.push(value);
		}
		else if (value <= stack2.top()){
			stack2.push(value);
		}
	}
	void pop(){
		if (stack1.top() == stack2.top()){
			stack2.pop();
		}
		stack1.pop();
	}
	int top(){
		return stack1.top();
	}
	int min(){
		return stack2.top();
	}
};