#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

#define MAXN 1002

int A[MAXN], B[MAXN], C[MAXN], D[MAXN];

bool overlap(int i, int j) {
    if (A[i] >= C[j] || C[i] <= A[j] || B[i] >= D[j] || D[i] <= B[j]) return false;
    return true;
}

bool isPointInRec(int x, int y, int j) {
    return x > A[j] && x < C[j] && y > B[j] && y < D[j];
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int ans = 0, index = 0;
    for (int i = 0; i < N; ++i) {
        if (ans >= N-i) break;

        bool ok1 = true, ok2 = true, ok3 = true, ok4 = true;
        for (int j = i+1; j < N; ++j) {
            if (ok1 && isPointInRec(A[i], B[i], j)) ok1 = false;
            if (ok2 && isPointInRec(C[i], D[i], j)) ok2 = false;
            if (ok3 && isPointInRec(A[i], D[i], j)) ok3 = false;
            if (ok4 && isPointInRec(C[i], B[i], j)) ok4 = false;
        }
        if (ok1 == false && ok2 == false && ok3 == false && ok4 == false) continue;

        unordered_set<int> visited;
        queue<int> q;
        q.push(i);
        int now = 1;
        visited.insert(i);

        while (q.size() > 0) {
            int cur = q.front(); q.pop();
            for (int j = cur+1; j < N; ++j) {
                if (visited.find(j) == visited.end() && overlap(cur, j)) {
                    q.push(j);
                    visited.insert(j);
                    now++;
                }
            }
        }

        if (now > ans) {
             ans = now;
             index = i;
        }
    }

    cout << ans << " " << index+1 << endl;

    return 0;
}
