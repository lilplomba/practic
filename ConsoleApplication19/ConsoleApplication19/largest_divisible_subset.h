#pragma once
#include <vector>
#include <algorithm>

std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    if (nums.empty()) return {};

    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    std::vector<int> dp(n, 1); // dp[i] = size of largest subset ending with nums[i]
    std::vector<int> prev(n, -1); // to reconstruct the subset

    int max_index = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[max_index]) {
            max_index = i;
        }
    }

    std::vector<int> result;
    for (int i = max_index; i != -1; i = prev[i]) {
        result.push_back(nums[i]);
    }

    std::reverse(result.begin(), result.end());
    return result;
}