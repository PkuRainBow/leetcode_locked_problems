/** NO.161 

	One Edit Distance

	Given two strings S and T, determine if they are both one edit distance apart.

**/


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        /** swap the string s and t to ensure the size of s is smaller than t**/
        if(m > n) return isOneEditDistance(t, s);
        if(n - m > 1) return false;
        /** check if there exist mismatch char only one time **/
        bool mismatch = false;
        for(int i = 0; i < m; i++) {
            if(s[i] != t[i]) {
                if(m == n)  s[i] = t[i];
                else s.insert(i, 1, t[i]);
                mismatch = true;
                break;
            }
        }
        /** 2 cases 
         *  1) all the m char are matched, so we just check to delete the one char rebundant
         *  2) find the mismatch char, so we replace it and check (s == t)
         **/
        return (!mismatch && n-m==1) || (mismatch && s == t);
    }
};