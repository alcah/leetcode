// fibonacci-number.cpp
// 2021-01-05

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
// Fibonacci sequence, such that each number is the sum of the two preceding
// ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

#import <cmath>

class dynamicSolution {
public:
	int fib(int n) {
		int a = 0;
		int b = 1;
		int tmp = 0;
		if (n == 0) { return 0; }
		for (int i = 1; i < n; i++) {
			tmp = b;
			b = a + b;
			a = tmp;
		}
		return b;
	}
};

class goldenRatioSolution {
public:
	int fib(int n) {
		double phi = (1 + sqrt(5)) / 2;
		return round(pow(phi, n)/sqrt(5));
	}
};
