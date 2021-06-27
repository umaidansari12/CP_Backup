class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1])
                return i;
        }
        if (nums[n - 2] < nums[n - 1])
            return n - 1;
        // if(nums[0]<nums[1])
        //     return 1;

        return 0;
    }
};