// recursive solution

class Solution {
public:
    // the approach make use of recursion , in which we are trying every possible steps from 1 index to number of steps we can move from that index and checking if we are reaching to the last index through any of the current index
    bool solve(vector<int>nums, int index, int _size) {
        if (index >= nums.size() - 1)
            return true;
        bool ans = false;


        for (int steps = 1; steps <= min((int)nums.size(), nums[index]); steps++) {
            int new_index = index + steps;
            ans = ans or solve(nums, new_index, _size);
        }

        return ans;



    }
    bool canJump(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }
};

// greedy solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        // in this approach we are going to start from current index and take farthest steps and if some point of time , the farthest index is less than the current index that means in last iteration we have not taken any single step otherwise we would have move forward
        for (int index = 0; index < nums.size(); index++) {
            if (farthest < index)
                return false;
            farthest = max(farthest, index + nums[index]);
        }
        // checking if we have moved beyond the last index or not
        return farthest >= nums.size() - 1;
    }
};