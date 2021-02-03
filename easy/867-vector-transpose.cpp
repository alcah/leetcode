#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> r(A[0].size() vector<int>(A.size(), 0));

        for (int i = 0; i < A[0].size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                r[i][j] = A[j][i];
            }
        }
        return r;
    }
};
