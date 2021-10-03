class NumArraySolutionBrute {
public:
	vector<int> arr;
	NumArray(vector<int>& nums) {
		arr = nums;
	}

	void update(int index, int val) {
		arr[index] = val;
	}

	int sumRange(int left, int right) {
		int sum = 0;
		for (int i = left; i <= right; i++)
			sum += arr[i];
		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class NumArrayBetter {
public:
	vector<int> arr, pre;
	NumArray(vector<int>& nums) {
		arr = nums;
		pre = nums;
		pre[0] = arr[0];
		for (int i = 1; i < nums.size(); i++) {
			pre[i] = arr[i] + pre[i - 1];
		}

	}

	void update(int index, int val) {
		arr[index] = val;
		pre[index] = val;
		for (int i = 1; i < arr.size(); i++) {
			pre[i] = arr[i] + pre[i - 1];
		}
	}

	int sumRange(int left, int right) {
		if (left == 0)
			return pre[right];
		else
			return pre[right] - pre[left - 1];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */