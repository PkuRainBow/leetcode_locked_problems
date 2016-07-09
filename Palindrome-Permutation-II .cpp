//
// Created by pianocoder on 16/5/8.
//

/**

 Palindrome Permutation II

 Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint : If a palindromic permutation exists, we just need to generate the first half of the string

 **/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
    	if(s.empty()) {
    		return {};
    	}
    	unordered_map<char, int> cnt;
    	for (const auto& c : s) {
    		++ cnt[c];
    	}
    	string mid, chars;
    	for (cosnt auto& kvp : cnt) {
    		if (kvp.second % 2) {
    			if (mid.empty()) {
    				mid.push_back(kvp.first);
    			} else { // the count of the odd number chars can only be of odd count
    				return {};
    			}
    		}
    		chars.append(kvp.second/2, kvp.first);
    	}
    	return permuteUnique(mid, chars);
    }

    vector<string>  permuteUnique(const string& mid, string& chars) {
    	vector<string> result;
    	sort(chars.begin(), chars.end());
    	do {
    		string reverse_chars(chars.crbegin(), chars.crend());
    		result.emplace_back(chars + mid + reverse_chars);
    	} while (next_permutations(chars.begin(), chars.end()));
    	return result;
    }
};