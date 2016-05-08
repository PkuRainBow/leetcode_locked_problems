/**
	NO.243 shortes word distance

	Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

	For example,
	Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

	Given word1 = “coding”, word2 = “practice”, return 3.
	Given word1 = "makes", word2 = "coding", return 1.

	Note:
	You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

	https://leetcode.com/discuss/50234/ac-java-clean-solution

**/


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size(), idx1 = -1, idx2 = -1, dist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) idx1 = i;
            else if (words[i] == word2) idx2 = i;
            if (idx1 != -1 && idx2 != -1)
                dist = min(dist, abs(idx1 - idx2));
        }
        return dist;
    }
}; 


/**
	NO.244 shortes word distance 2

	This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will 
	be called repeatedly many times with different parameters. How would you optimize it?

	Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 
	and return the shortest distance between these two words in the list.

	For example,
	Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

	Given word1 = “coding”, word2 = “practice”, return 3.
	Given word1 = "makes", word2 = "coding", return 1.

	Note:
	You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


	https://leetcode.com/discuss/50190/java-solution-using-hashmap
**/


class WordDistance { 
public:
    WordDistance(vector<string> words) {
        int n = words.size();
        for (int i = 0; i < n; i++)
            wordInd[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
    	/** The part of finding minimum difference between two sorted lists is important **/
    	/** shortest() : O(m + n) time **/
        vector<int> indexes1 = wordInd[word1];
        vector<int> indexes2 = wordInd[word2];
        int m = indexes1.size(), n = indexes2.size();
        int i = 0, j = 0, dist = INT_MAX;
        while (i < m && j < n) {
            dist = min(dist, abs(indexes1[i] - indexes2[j]));
            if (indexes1[i] < indexes2[j]) i++;
            else j++;
        }
        return dist;
    }
private:
    unordered_map<string, vector<int> > wordInd;
}; 



/**
	NO.245 shortes word distance 3

	This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

	Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

	word1 and word2 may be the same and they represent two individual words in the list.

	For example,
	Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

	Given word1 = “makes”, word2 = “coding”, return 1.
	Given word1 = "makes", word2 = "makes", return 3.

	Note:
	You may assume word1 and word2 are both in the list.

	Show Company Tags
	Show Tags
	Show Similar Problems

	https://leetcode.com/discuss/50715/12-16-lines-java-c
	https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/shortest-word-distance-iii.cpp
**/


class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX, i1 = dist, i2 = -dist;
        for (int i=0; i<words.size(); i++) {
            if (words[i] == word1)
                i1 = i;
            if (words[i] == word2) {
                /** if the word are the same we can update the i1 to point to the last i2 index 
                 *  the difficult lies that how we deal with many duplicate words
                **/
                if (word1 == word2)
                    i1 = i2;
                i2 = i;
            }
            dist = min(dist, abs(i1 - i2));
        }
        return dist;
    }
};

/** 加速版本 **/
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX, i1 = dist, i2 = -dist;
        bool same = word1 == word2;
        for (int i=0; i<words.size(); i++) {
            if (words[i] == word1) {
                i1 = i;
                if (same)
                    swap(i1, i2);
            } else if (words[i] == word2) {
                i2 = i;
            }
            dist = min(dist, abs(i1 - i2));
        }
        return dist;
    }
};
