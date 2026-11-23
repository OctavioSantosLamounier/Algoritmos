#include <bits/stdc++.h>
using namespace std;

bool subsetSum(const vector<int>& nums, int target) {
    vector<bool> dp(target+1, false);

    dp[0] = true;
    for (int num: nums) 
        for (int i=target; i>=num; i--) 
            dp[i] = dp[i] || dp[i - num];

            
    return dp[target];
}
 
int main() {
    vector<int> nums = {2, 3, 7, 8, 10};
    int target = 15;

    int ans = subsetSum(nums, target);

    cout << ans << endl;
    return 0;
}