#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

int buf[8][9] = {
    {4,9,2,3,5,7,8,1,6},
    {4,3,8,9,5,1,2,7,6},
    {8,3,4,1,5,9,6,7,2},
    {2,9,4,7,5,3,6,1,8},
    {6,1,8,7,5,3,2,9,4},
    {6,7,2,1,5,9,8,3,4},
    {8,1,6,3,5,7,4,9,2},
    {2,7,6,9,5,1,4,3,8}
};

int main() {
    int input[9];
    for (int i = 0; i < 9; ++i) cin >> input[i];

    int index = -1;
    for (int i = 0; i < 8; ++i) {
        bool ok = true;
        for (int j = 0; j < 9; ++j) {
            if (input[j] == 0) continue;
            if (buf[i][j] != input[j]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            /** find the solution for first time **/
             if (index < 0) index = i;
             /** find the second solution **/
             else {
                 index = -1;
                 break;
             }
        }
    }

    if (index < 0) cout << "Too Many" << endl;
    else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << buf[index][i*3+j];
                if (j != 2) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
