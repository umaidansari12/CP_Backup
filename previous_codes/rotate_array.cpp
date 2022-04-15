class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++)
        {
            pre[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++)
            nums[i] = pre[i];
    }
};

/*Summary
We have to rotate the elements of the given array k times to the right.

Solution
Approach 1: Brute Force
The simplest approach is to rotate all the elements of the array in kk steps by rotating the elements by 1 unit in each step.
class Solution {
  public void rotate(int[] nums, int k) {
    // speed up the rotation
    k %= nums.length;
    int temp, previous;
    for (int i = 0; i < k; i++) {
      previous = nums[nums.length - 1];
      for (int j = 0; j < nums.length; j++) {
        temp = nums[j];
        nums[j] = previous;
        previous = temp;
      }
    }
  }
}

Complexity Analysis

Time complexity: \mathcal{O}(n \times k)O(n×k). All the numbers are shifted by one step(\mathcal{O}(n)O(n)) k times.

Space complexity: \mathcal{O}(1)O(1). No extra space is used.



Approach 2: Using Extra Array
Algorithm

We use an extra array in which we place every element of the array at its correct position i.e. the number at index ii in the original array is placed at the index (i + k) \% \text{ length of array}(i+k)% length of array. Then, we copy the new array to the original one.

class Solution {
  public void rotate(int[] nums, int k) {
    int[] a = new int[nums.length];
    for (int i = 0; i < nums.length; i++) {
      a[(i + k) % nums.length] = nums[i];
    }
    for (int i = 0; i < nums.length; i++) {
      nums[i] = a[i];
    }
  }
}Complexity Analysis

Time complexity: \mathcal{O}(n)O(n). One pass is used to put the numbers in the new array. And another pass to copy the new array to the original one.

Space complexity: \mathcal{O}(n)O(n). Another array of the same size is used.

Approach 3: Using Cyclic Replacements
Algorithm

We can directly place every number of the array at its required correct position. But if we do that, we will destroy the original element. Thus, we need to store the number being replaced in a temptemp variable. Then, we can place the replaced number(\text{temp}temp) at its correct position and so on, nn times, where nn is the length of array. We have chosen nn to be the number of replacements since we have to shift all the elements of the array(which is nn). But, there could be a problem with this method, if n \% k = 0n%k=0 where k = k \% nk=k%n (since a value of kk larger than nn eventually leads to a kk equivalent to k \% nk%n). In this case, while picking up numbers to be placed at the correct position, we will eventually reach the number from which we originally started. Thus, in such a case, when we hit the original number's index again, we start the same process with the number following it.

Now let's look at the proof of how the above method works. Suppose, we have nn as the number of elements in the array and kk is the number of shifts required. Further, assume n \%k = 0n%k=0. Now, when we start placing the elements at their correct position, in the first cycle all the numbers with their index ii satisfying i \%k = 0i%k=0 get placed at their required position. This happens because when we jump k steps every time, we will only hit the numbers k steps apart. We start with index i = 0i=0, having i \% k = 0i%k=0. Thus, we hit all the numbers satisfying the above condition in the first cycle. When we reach back the original index, we have placed \frac{n}{k}
k
n
​
  elements at their correct position, since we hit only that many elements in the first cycle. Now, we increment the index for replacing the numbers. This time, we place other \frac{n}{k}
k
n
​
  elements at their correct position, different from the ones placed correctly in the first cycle, because this time we hit all the numbers satisfy the condition i \% k = 1i%k=1. When we hit the starting number again, we increment the index and repeat the same process from i = 1i=1 for all the indices satisfying i \% k == 1i%k==1. This happens till we reach the number with the index i \% k = 0i%k=0 again, which occurs for i=ki=k. We will reach such a number after a total of kk cycles. Now, the total count of numbers exclusive numbers placed at their correct position will be k \times \frac{n}{k} = nk×
k
n
​
 =n. Thus, all the numbers will be placed at their correct position.

Look at the following example to clarify the process:

nums: [1, 2, 3, 4, 5, 6]
k: 2

class Solution {
  public void rotate(int[] nums, int k) {
    k = k % nums.length;
    int count = 0;
    for (int start = 0; count < nums.length; start++) {
      int current = start;
      int prev = nums[start];
      do {
        int next = (current + k) % nums.length;
        int temp = nums[next];
        nums[next] = prev;
        prev = temp;
        current = next;
        count++;
      } while (start != current);
    }
  }
}
Complexity Analysis

Time complexity: \mathcal{O}(n)O(n). Only one pass is used.

Space complexity: \mathcal{O}(1)O(1). Constant extra space is used.

Approach 4: Using Reverse
Algorithm

This approach is based on the fact that when we rotate the array k times, k%nk elements from the back end of the array come to the front and the rest of the elements from the front shift backwards.

In this approach, we firstly reverse all the elements of the array. Then, reversing the first k elements followed by reversing the rest n-kn−k elements gives us the required result.

Let n = 7n=7 and k = 3k=3.

Original List                   : 1 2 3 4 5 6 7
After reversing all numbers     : 7 6 5 4 3 2 1
After reversing first k numbers : 5 6 7 4 3 2 1
After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result

class Solution {
  public void rotate(int[] nums, int k) {
    k %= nums.length;
    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);
  }
  public void reverse(int[] nums, int start, int end) {
    while (start < end) {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
    }
  }
}

Complexity Analysis

Time complexity: \mathcal{O}(n)O(n). nn elements are reversed a total of three times.

Space complexity: \mathcal{O}(1)O(1). No extra space is used.*/