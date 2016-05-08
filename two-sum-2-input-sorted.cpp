/**
   NO.167.  Two Sum II - Input array is sorted

   Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
	Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2

**/


/** Binary  Search  BASED solution **/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) return {};
        
        for(int i=0; i<numbers.size()-1; i++) {
            int start=i+1, end=numbers.size()-1, gap=target-numbers[i];
            while(start <= end) {
                int m = start+(end-start)/2;
                if(numbers[m] == gap) return {i+1,m+1};
                else if(numbers[m] > gap) end=m-1;
                else start=m+1;
            }
        }
    }
};


/** typical two pointers solution **/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if(numbers.size() <= 1)  return result;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            } else if(sum > target){
                right --;
            } else {
                left ++;
            }
        }
        return result;
    }
};