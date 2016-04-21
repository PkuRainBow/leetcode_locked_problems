#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define x first
#define y second
using namespace std;

int dp[51][51][51][4][4][4];
void update(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                dp[0][0][0][i][j][k] = -min(j - i, k);
            }
        }
    }
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            for (int k = 0; k <= 50; k++) {
                if (i + j + k == 0) continue;
                for (int p1 = 0; p1 <= 3; p1++) {
                    for (int p2 = 1; p2 < 4; p2++) {
                        for (int p3 = 1; p3 < 4; p3++) {
                            dp[i][j][k][p1][p2][p3] = 1000000000;
                            if (i) {
                                for (int l = 0; l <= p1; l++) {
                                    if (l == 0) update(dp[i][j][k][p1][p2][p3], dp[i - 1][j][k][1][1][min(3, p2 + 1)] + p1 + 1);
                                    else if (l == 1){
                                        update(dp[i][j][k][p1][p2][p3], dp[i - 1][j][k][1][1][p2] + p1);
                                    }
                                    else update(dp[i][j][k][p1][p2][p3], dp[i - 1][j][k][l - 2][p2][1] + p1 - l + 2);
                                }
                            }
                            if (j) {
                                for (int l = 0; l <= p1; l++) if (p3 + p1 - l >= 2){
                                    if (l == 0) update(dp[i][j][k][p1][p2][p3], dp[i][j - 1][k][2][2][min(3, p2 + 1)] + p1 + 1);
                                    else if (l <= 2) update(dp[i][j][k][p1][p2][p3], dp[i][j - 1][k][3 - l][2][p2] + p1);
                                    else update(dp[i][j][k][p1][p2][p3], dp[i][j - 1][k][l - 3][p2][2] + p1 - l + 3);
                                }
                            }
                            if (k) {
                                for (int l = 0; l <=p1; l++) if (p3 + p1 - l >= 3) {
                                    if (l == 0) update(dp[i][j][k][p1][p2][p3], dp[i][j][k - 1][3][3][min(3, p2 + 1)] + p1 + 1);
                                    else if (l <= 3) update(dp[i][j][k][p1][p2][p3], dp[i][j][k - 1][4 - l][3][p2] + p1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        if (m + n + k == 0) {
            printf("0\n");
        }else 
        printf("%d\n", dp[n][m][k][0][3][3]);
    }
}
