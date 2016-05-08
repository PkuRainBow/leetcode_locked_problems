/**
	NO/186    Reverse Words in a String 2

	Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

	The input string does not contain leading or trailing spaces and the words are always separated by a single space.

	For example,
	Given s = "the sky is blue",
	return "blue is sky the".

	Could you do it in-place without allocating extra space?

**/


/** Solution 1
	reverse all the string firstly, then reverse word by word

	Here are 2 similar implementations which uses isspace() and isblank() to check the null char 
**/

class Solution { 
public:
    void reverseWords_1(string &s) {
        reverse(s.begin(), s.end());
        int n = s.length(), l = 0, r = 0;
        while (r < n) {
            while (r < n && !isspace(s[r])) r++;
            reverse(s.begin() + l, s.begin() + r); 
            l = ++r;
        }
    } 

    void reverseWords_2(string &s) {
    reverse(s.begin(), s.end());
    for (int i = 0, j = 0; i < s.size(); i = j + 1) {
        for (j = i; j < s.size() && !isblank(s[j]); ++j);
        reverse(s.begin()+i, s.begin()+j);
    }
}
};