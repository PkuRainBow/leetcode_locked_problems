/**
NO.163

Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

Solution : 

The idea is just to keep record the next number we need. Then just loop to check it, if we find the next number , we 
can continue, if we miss it, then we need to push the missing range [next, a[i]-1] into our ranges.

**/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        int next = lower;
        for (int i = 0; i < nums.size(); i++ ) {
            //if (nums[i] < next)  continue;
            if (nums[i] == next) {
                next ++;
                continue;
            }
            ranges.push_back(getRange(next, nums[i] - 1));
            next = nums[i] + 1;
        }
        if(next <= upper)  ranges.push_back(getRange(next, upper));
        return ranges;
    }
    
    string getRange(const int lower, const int upper) {
        if (lower == upper) {
            return to_string(lower);
        } else {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};

/**
Here is the similar problem 

NO.228  Summary ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

**/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int size_n = nums.size();
        vector<string> result;
        if (0 == size_n)  return result;
        for (int i = 0; i < size_n;) {
            /** use 2 pointers to record the continue range index
             *  the start and end record the range start and end index
             **/
            int start = i, end = i;
            /** continue to find the continue ranges **/
            while (end + 1 < size_n && nums[end + 1] == nums[end] + 1) end++;
            /** push the range into the result **/
            if(end > start)
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else 
                result.push_back(to_string(nums[start]));
            /** update the next start index **/
            i = end + 1;
        }
        return result;
    }
};
