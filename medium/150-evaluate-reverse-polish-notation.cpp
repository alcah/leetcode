// 150-evaluate-reverse-polish-notation.cpp
// 2021-01-06

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another
// expression.

// Note:
// Division between two integers should truncate toward zero.  The given RPN
// expression is always valid. That means the expression would always evaluate
// to a result and there won't be any divide by zero operation.

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		int arg1 = 0;
		int arg2 = 0;
		for (auto t : tokens) {
			switch (t[0]) {
			case '+':
				arg1 = s.top();
				s.pop();
				arg2 = s.top();
				s.pop();
				s.push(arg1 + arg2);
				break;
			case '*':
				arg1 = s.top();
				s.pop();
				arg2 = s.top();
				s.pop();
				s.push(arg1 * arg2);
				break;
			case '-':
				// either a negation or a negative number
				if (t.size() > 1) {
					s.push(stoi(t));
				}
				else {
					arg1 = s.top();
					s.pop();
					arg2 = s.top();
					s.pop();
					s.push(arg2 - arg1);
				}
				break;
			case '/':
				arg1 = s.top();
				s.pop();
				arg2 = s.top();
				s.pop();
				s.push(floor(arg2 / arg1));
				break;
			default:
				s.push(stoi(t));
				break;
			}
		}
		return s.top();
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> t = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << s.evalRPN(t);
	return 0;
}
