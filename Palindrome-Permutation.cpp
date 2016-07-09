//
// Created by pianocoder on 16/5/8.
//

/**
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
 */

#include <string>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
    	bitset<256> b;
    	for (char c : s)
    		b.flip(c);
    	return b.count() < 2;
    }
};