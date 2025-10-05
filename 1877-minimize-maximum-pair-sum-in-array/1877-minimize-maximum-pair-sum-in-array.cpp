class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int result=0;
        int sum=0;
        sort(nums.begin(),nums.end());
        while(l<r)
        {
            sum=nums[l]+nums[r];
            result=max(result,sum);
            l++;
            r--;
        }
        return result;
        
    }
};