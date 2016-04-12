#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*
 * DP solution
 */
//int main_dp_solution() {
//    int row, col;
//    std::cin >> row >> col;
//    vector<vector<char>> matrix(row, vector<char>(col));
//    for(int i = 0; i < row; i++) {
//        for(int j = 0; j < col; j++) {
//            std::cin >> matrix[i][j];
//        }
//    }
//    /** dp_down[i][j]  : choose go down in pos [i,j] **/
//    /** dp_right[i][j] : choose go right in pos [i,j] **/
//    vector<vector<int>> dp_down(row, vector<int>(col, 0));
//    vector<vector<int>> dp_right(row, vector<int>(col, 0));
//
//    for(int i = 0; i < row; i++) {
//        for(int j = 0; j < col; j++) {
//            if(i==0 && j==0) {
//                /** we prefer to go right **/
//                dp_right[0][0] = (matrix[0][0] == 'b' ? 1 : 0);
//                dp_down[0][0] = (matrix[0][1] == 'b' ? 0 : 1) + (matrix[0][0] == 'b' ? 1 : 0);
//            }
//            else if(i==0) {
//                dp_down[i][j] = dp_right[i][j-1] + (matrix[i][j] == 'b' ? 1 : 0) + ((j==col-1 || matrix[i][j+1] == 'b') ? 0 : 1);
//                dp_right[i][j] = dp_right[i][j-1] + (matrix[i][j] == 'b' ? 1 : 0);
//            }
//            else if(j==0) {
//                dp_right[i][j] = dp_down[i-1][j] + (matrix[i][j] == 'b' ? 1 : 0) + ((i==row-1 || matrix[i+1][j] == 'b') ? 0 : 1);
//                dp_down[i][j] = dp_down[i-1][j] + (matrix[i][j] == 'b' ? 1 : 0);
//            }
//            else {
//                int down = dp_down[i-1][j];
//                int right = dp_right[i][j-1];
//                dp_down[i][j] = (matrix[i][j] == 'b' ? 1 : 0) + min(down, dp_right[i-1][j]+(((j==col-1) || (matrix[i-1][j+1]=='b')) ? 0 : 1) );
//                dp_right[i][j] = (matrix[i][j] == 'b' ? 1 : 0) + min(right, dp_down[i][j-1]+(((i==row-1) || (matrix[i+1][j-1]=='b')) ? 0 : 1) );
//            }
//        }
//    }
//    std::cout <<  min(dp_down[row-1][col-1], dp_right[row-1][col-1]) << endl;
//    return 0;
//}

/**
 *  DFS solution : which is more readable and easy to implement
 */

vector<vector<int>> dirs = { { 1, 0 }, { 0, 1 } }; //down / right

void dfs(vector<vector<char>>& matrix, int cur_flip, int& min_flip, int x, int y, int row, int col, bool flag) {
    cur_flip += (matrix[x][y] == 'b' ? 1 : 0);
    if ((x == (row-1)) && (y == (col-1))) {
        min_flip = min(cur_flip, min_flip);
        return;
    }
    /* move right*/
    else if (x == (row - 1)) {
        dfs(matrix, cur_flip, min_flip, x, y + 1, row, col, false);
        return;
    }
    /* move down */
    else if (y == (col - 1)) {
        dfs(matrix, cur_flip, min_flip, x + 1, y, row, col, true);
        return;
    }

    /*previous down */
    if(flag) {
        int down_x = x + dirs[0][0], down_y = y + dirs[0][1];
        int right_x = x + dirs[1][0], right_y = y + dirs[1][1];
        /* move down again */
        dfs(matrix, cur_flip, min_flip, down_x, down_y, row, col, flag);
        /* change to move right */
        if (matrix[down_x][down_y] == '.') {
            dfs(matrix, cur_flip + 1, min_flip, right_x, right_y, row, col, !flag);
        }
        else {
            dfs(matrix, cur_flip, min_flip, right_x, right_y, row, col, !flag);
        }
    }

    else {
        int down_x = x + dirs[0][0], down_y = y + dirs[0][1];
        int right_x = x + dirs[1][0], right_y = y + dirs[1][1];
        /* move right again */
        dfs(matrix, cur_flip, min_flip, right_x, right_y, row, col, flag);
        /* change to move down */
        if (matrix[right_x][right_y] == '.') {
            dfs(matrix, cur_flip + 1, min_flip, down_x, down_y, row, col, !flag);
        }
        else {
            dfs(matrix, cur_flip, min_flip, down_x, down_y, row, col, !flag);
        }
    }
}

int main_dfs()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M));
    char ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    int min_flip = INT_MAX;
    dfs(matrix, 0, min_flip, 0, 0, N, M, false);
    cout << min_flip << endl;
    return 0;
}
