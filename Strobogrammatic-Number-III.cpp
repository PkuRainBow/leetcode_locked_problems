//
// Created by pianocoder on 16/5/7.
//

/**
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.

 https://leetcode.com/discuss/55468/clear-java-ac-solution-using-strobogrammatic-number-method

**/
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int count = 0;
        for(int len = low.length(); len <= high.length(); len++) {
            string temp(len, '0');
            dfs(low, high, temp, 0, len - 1, count, mp);
        }
        return count;
    }
    void dfs(string low, string high, string str, int left, int right, int &count, map<char, char> &mp) {
        if(left > right) {
            /** filter all the numbers that are not in the [low, upper] **/
            if((str.length() == low.length() && str.compare(low) < 0) ||
               (str.length() == high.length() && str.compare(high) > 0)) return;
            count++;
            return;
        }
        /** loop for all the possible cases **/
        for(auto p : mp) {
            str[left] = p.first;
            str[right] = p.second;
            /** pass the illegal cases **/
            if(str.size() != 1 && str[0] == '0') continue;
            if(left < right || left == right && p.first == p.second) dfs(low, high, str, left + 1, right - 1, count, mp);
        }
    }
};