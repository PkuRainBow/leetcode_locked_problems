//
// Created by pianocoder on 16/5/8.
//
/*
You are playing the following Flip Game with your friend: Given a string that contains
 only these two characters: + and -, you and your friend take turns to flip two consecutive
 "++" into "--". The game ends when a person can no longer make a move and therefore the
 other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]
If there is no valid move, return an empty list [].
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {

    }
};

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> moves;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                moves.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return moves;
    }
};
