//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	vector<int> multiply(const vector<int>& A){
		vector<int> B;
		if (A.size() < 2)return B;
		for (int i = 0; i < A.size(); ++i){
			int tmp = 1;
			for (int j = 0; j < A.size(); ++j){
				if (j != i){
					tmp *= A[j];
				}
			}
			B.push_back(tmp);
		}
		return B;
	}
};

int main(int argc, char **argv){
	Solution s;
	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<int>& A = a;
	vector<int> res = s.multiply(A);

	//放多个条件出错
	for (int i = 0; i < 10; ++i){
		if (i != 5){
			cout << i << " ";
		}
	}
	cout << endl;
}