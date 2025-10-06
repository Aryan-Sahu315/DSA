#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  
        int n = nums.size();
        int closestsum = nums[0] + nums[1] + nums[2]; 

        for (int k = 0; k < n - 2; k++) {
            int left = k + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[k] + nums[left] + nums[right];

                
                if (abs(target - sum) < abs(target - closestsum)) {
                    closestsum = sum;
                }

                
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else
                    return sum;  
            }
        }
        return closestsum;
    }
};
