// 13-roman-to-integer.cpp
// 2021-01-04

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// For example, 2 is written as II in Roman numeral, just two one's added
// together. 12 is written as XII, which is simply X + II. The number 27 is
// written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to
// right. However, the numeral for four is not IIII. Instead, the number four is
// written as IV. Because the one is before the five we subtract it making
// four. The same principle applies to the number nine, which is written as
// IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.  X can be placed
// before L (50) and C (100) to make 40 and 90.  C can be placed before D (500)
// and M (1000) to make 400 and 900.  Given a roman numeral, convert it to an
// integer.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int romanToInt(string s)
	{
		int sum = 0;
		char lookahead = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			switch (s[i]) {
			case 'I':
				if (i+1 < (int)s.size() &&
					((lookahead = s[i+1]) == 'V' || lookahead == 'X')) {
					sum += romanToInt(string(1, lookahead)) - 1;
					i++;
				}
				else {
					sum += 1;
				}
				break;
			case 'V':
				sum += 5;
				break;
			case 'X':
				if (i+1 < (int)s.size() &&
					((lookahead = s[i+1]) == 'L' || lookahead == 'C')) {
					sum += romanToInt(string(1, lookahead)) - 10;
					i++;
				}
				else {
					sum += 10;
				}
				break;
			case 'L':
				sum += 50;
				break;
			case 'C':
				if (i+1 < (int)s.size() &&
					((lookahead = s[i+1]) == 'D' || lookahead == 'M')) {
					sum += romanToInt(string(1, lookahead)) - 100;
					i++;
				}
				else {
					sum += 100;
				}
				break;
			case 'D':
				sum += 500;
				break;
			case 'M':
				sum += 1000;
				break;
			default:
				return -1;
			}
		}
		return sum;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.romanToInt("MCMXCIV") << endl;
	return 0;
}
