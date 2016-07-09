//
// Created by pianocoder on 16/5/8.
//

/**
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.


 Example:
 Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

    TicTacToe toe = new TicTacToe(3);

    toe.move(0, 0, 1); -> Returns 0 (no one wins)
    |X| | |
    | | | |    // Player 1 makes a move at (0, 0).
    | | | |

    toe.move(0, 2, 2); -> Returns 0 (no one wins)
    |X| |O|
    | | | |    // Player 2 makes a move at (0, 2).
    | | | |

    toe.move(2, 2, 1); -> Returns 0 (no one wins)
    |X| |O|
    | | | |    // Player 1 makes a move at (2, 2).
    | | |X|

    toe.move(1, 1, 2); -> Returns 0 (no one wins)
    |X| |O|
    | |O| |    // Player 2 makes a move at (1, 1).
    | | |X|

    toe.move(2, 0, 1); -> Returns 0 (no one wins)
    |X| |O|
    | |O| |    // Player 1 makes a move at (2, 0).
    |X| |X|

    toe.move(1, 0, 2); -> Returns 0 (no one wins)
    |X| |O|
    |O|O| |    // Player 2 makes a move at (1, 0).
    |X| |X|

    toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
    |X| |O|
    |O|O| |    // Player 1 makes a move at (2, 1).
    |X|X|X|

Follow up:
Could you do better than O(n2) per move() operation?

Hint
 Could you trade extra space such that move() operation can be done in O(1)?
 You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
*/

class TicTacToe {
    vector<int> rows, cols;
    int diagonal, anti_diagonal;
    int sz;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = anti_diagonal = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int toAdd = player = 1 ? 1 : -1;
        rows[row] += toAdd;
        cols[col] += toAdd;
        if (row == col) 
        {
            diagonal += toAdd;
        }
        if (col == (cols.size() - row - 1)) 
        {
            anti_diagonal += toAdd;
        }
        int size = rows.size();
        if (abs(rows[row]) == size ||
            abs(cols[col]) == size ||
            abs(diagonal) == size ||
            abs(anti_diagonal) == size)
        {
            return player;
        }
        return 0;
    }
};


class TicTacToe_2 {
public:
    TicTacToe(int n) : sz(n) {
        rows.resize(n, 0), cols.resize(n, 0);
        diagonal = anti_diagonal = 0;
    }

    int move(int row, int col, int player) {
        if (player == 1) {
            ++rows[row], ++cols[col];
            if (row == col)
                ++diagonal;
            if (row == sz - 1 - col)
                ++anti_diagonal;
            if (rows[row] == sz || cols[col] == sz || diagonal == sz || anti_diagonal == sz)
                return 1;
        }
        else {
            --rows[row], --cols[col];
            if (row == col)
                --diagonal;
            if (row == sz - 1 - col)
                --anti_diagonal;
            if (rows[row] == -sz || cols[col] == -sz || diagonal == -sz || anti_diagonal == -sz)
                return 2;
        }
        return 0;
    }

private:
    vector<int> rows, cols;
    int diagonal, anti_diagonal;
    int sz;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

