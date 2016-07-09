//
// Created by pianocoder on 16/5/8.
//

/**
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?
**/

/** solution -1- **/
class Solution {
	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		const int n = nums.size();
		int count = 0;
		/** accumlate the triplet end with k **/
		for (int k = 2; k < n; ++k) {
			int i = 0, j = k - 1;
			/** in fact this is 2-pointer problem find the target value = (target - nums[k]) **/
			while (i < j) {
				if (nums[i] + nums[j] + nums[k] >= target) {
					--j;
				} else {
					/** the triplet contains nums[i] **/
					count += j - i;
					++i;
				}
			}
		}
		return count;
	}
}


/** solution -2- **/
/** this solution is more easy to understand as we refer the idea of the 2 pointers. We just loop to find all the possible combinations, 
to avoid missing some cases, so we should clarify that we loop all the possible start index i, then loop all the possible left options, 
then loop all the possible right index option, to accelerate, we just need to find the first right element satisfy the condition, then 
we get "count + = right - left" **/
class Solution {
	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		const int n = nums.size();
		int count = 0;
		for (int i = 0; i < n - 2; i++) {
			int left = i + 1, right = len - 1;
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] < target) {
					count += right - left;
					left ++;
				} else {
					right --;
				}
			}
		}
		return count;
	}
}