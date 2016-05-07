//
// Created by pianocoder on 16/5/7.
//
/**
Implement an iterator to flatten a 2d vector.

For example,
        Given 2d vector =

[
[1,2],
[3],
[4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

 https://leetcode.com/discuss/50292/7-9-lines-added-java-and-c-o-1-space
 https://leetcode.com/discuss/52614/2-short-c-solution
**/

#include <vector>
using namespace std;

class Vector2D {
    vector<vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
};