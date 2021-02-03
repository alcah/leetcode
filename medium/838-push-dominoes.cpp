// There are N dominoes in a line, and we place each domino vertically upright.

// In the beginning, we simultaneously push some of the dominoes either to the
// left or to the right.

// After each second, each domino that is falling to the left pushes the
// adjacent domino on the left.

// Similarly, the dominoes falling to the right push their adjacent dominoes
// standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays
// still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino
// expends no additional force to a falling or already fallen domino.

// Given a string "S" representing the initial state. S[i] = 'L', if the i-th
// domino has been pushed to the left; S[i] = 'R', if the i-th domino has been
// pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

// Return a string representing the final state.
// STARTTIME = 15:05:30
// ENDTIME =

#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// dumb, very dumb ahhhhhhhhh (but it was accepted)
// class Solution {
// public:
//	string pushDominoes(string forces)
//	{
//		string state(forces.size(), '.');
//		int size = forces.size();
//		string nextstate = state;
//		string nextforces = forces;

//		while (forces.find('R') != string::npos ||
//			   forces.find('L') != string::npos) {
//			for (int i = 0; i < size; i++) {
//				switch (forces[i]) {
//				case 'L':
//					nextforces[i] = '.';
//					if (state[i] != '.') { break; }
//					nextstate[i] = 'L';
//					if (i - 1 >= 0 && forces[i-1] != 'R') { nextforces[i-1] = 'L'; }
//					if (i - 2 >= 0 && forces[i-2] == 'R') { nextforces[i-1] = '.'; }
//					break;
//				case 'R':
//					nextforces[i] = '.';
//					if (state[i] != '.') { break; }
//					nextstate[i] = 'R';
//					if (i + 1 < size) { nextforces[i+1] = 'R'; }
//					if (i + 2 < size && forces[i+2] == 'L') { nextforces[i+1] = '.'; }
//					break;
//				default:
//					break;
//				}
//			}
//			forces = nextforces;
//			state = nextstate;
//		}
//		return state;
//	}
// };

// insanely clever, whew
class Solution {
public:
	string pushDominoes(string dominoes)
	{
		vector<int> forces(dominoes.size(), 0);
		int size = dominoes.size();
		int force = 0;

		// ltr
		for (int i = 0; i < size; ++i) {
			switch (dominoes[i]) {
			case 'R':
				force = size;
				break;
			case 'L':
				force = 0;
				break;
			default:
				force = max(force-1, 0);
				break;
			}
			forces[i] += force;
		}

		// rtl
		force = 0;
		for (int i = size-1; i >= 0; --i) {
			switch (dominoes[i]) {
			case 'L':
				force = size;
				break;
			case 'R':
				force = 0;
				break;
			default:
				force = max(force-1, 0);
				break;
			}
			forces[i] -= force;
		}

		for (int i = 0; i < size; ++i) {
			dominoes[i] = (forces[i] > 0 ? 'R' : (forces[i] < 0 ? 'L' : '.'));
		}
		return dominoes;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.pushDominoes("R..RL") << endl;
	return 0;
}
