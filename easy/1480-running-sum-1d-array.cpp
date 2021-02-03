#include <bits/stdc++.h>

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> r;
        r.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            r.push_back(r[i-1] + nums[i]);
        }
        return r;
    }
};
