#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

#define MAXN 1000002
int data[MAXN];

/** get the cost with windows size of k **/
long long getCost(int n, int k) {
    long long ans = 0, index = 1;
    priority_queue<int> pq;
    for (int i = 0; i < k - 1; ++i) pq.push(data[i]);

    for (int i = k - 1; i < n; ++i) {
        pq.push(data[i]);
        ans += pq.top() * index++;
        pq.pop();
    }

    while (pq.size() > 0) {
        ans += pq.top() * index++;
        pq.pop();
    }

    return ans;
}

int main() {
    std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    long long Q, N;
    while (cin >> N >> Q) {
        for (int i = 0; i < N; ++i) {
            cin >> data[i];
        }

        int left = 1, right = N;
        while (left < right) {
            int mid = (left + right) >> 1;
            long long sp = getCost(N, mid);
            if (sp > Q) left = mid + 1;
            else right = mid;
        }

        if (getCost(N, left) <= Q) cout << left << endl;
        else cout << -1 << endl;
    }

    return 0;
}
