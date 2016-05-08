/**
	NO.246 

	Strobogrammatic Number

	A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

	Write a function to determine if a number is strobogrammatic. The number is represented as a string.

	For example, the numbers "69", "88", and "818" are all strobogrammatic.
**/


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> lut{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int n = num.length();
        for (int l = 0, r = n - 1; l <= r; l++, r--)
            /** the number not occur in num or the number left and right are not matched **/
            if (lut.find(num[l]) == lut.end() || lut[num[l]] != num[r])
                return false; 
        return true; 
    }
};

/**
	NO.247

	A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

	Find all strobogrammatic numbers that are of length = n.

	For example,
	Given n = 2, return ["11","69","88","96"].

	https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/strobogrammatic-number-ii.cpp
	https://leetcode.com/discuss/50412/ac-clean-java-solution

**/


/** a really smart solution **/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }

    vector<string> helper(int n, int m) {
    	if (n == 0)  return vector<string>({""});
    	if (n == 1)  return vector<string>({"0","1","8"});
    	vector<string> list = helper(n - 2, m);
    	vector<string> result;
    	for (int i = 0; i < list.size(); i++) {
    		string s = list[i];
    		/** the most outside can not contains 2 0 both sides
    		  * the inner part can contain both 0
    		**/
    		if ( n != m) result.push_back("0" + s + "0");
    		result.push_back("1" + s + "1");
    		result.push_back("6" + s + "9");
    		result.push_back("9" + s + "6");
    		result.push_back("8" + s + "8");
    	}
    	return result;
    }
};



/**
	NO.248 (hard)

	A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

	Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

	For example,
	Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

	Note:
	Because the range might be a large number, the low and high numbers are represented as string.

**/

