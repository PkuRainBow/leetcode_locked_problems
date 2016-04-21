#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

typedef long long lld;
const lld INF = 1LL<<61;
const int N = 1e4 + 5;

int n, m, k, t;
lld a[N];
lld b[N];
lld dp[N * 2];

void work() {
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    lld ans = 0;
    for (int I = 1; I <= n; I++) {
        int fg = 0;
        for (int i = 1; i <= m; i++) {
            if (b[i] != 0) {
                fg = 1;
            }
        }
        if (!fg) {
            puts("No Answer");
            return ;
        }
        for (int i = 0; i <= k + k; i++) dp[i] = INF;
        dp[0] = 0;
        for (int i = 1; i <= m; i++) {
            lld val = min(k * 1LL, b[i]), cost = a[i];
            for (int j = val; j <= k + k; j++) {
                dp[j] = min(dp[j], dp[j - val] + cost);
            }
        }
        lld s = INF;
        for (int i = k; i <= k + k; i++) s = min(dp[i], s);
        ans += s;
        for (int i = 1; i <= m; i++) b[i] /= t;
    }
    printf("%lld\n", ans);
    return ;

}

int main() {
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int T;
    cin >> T
    for (int cas = 1; cas <= T; cas++) {
        work();
    }
    return 0;
}
