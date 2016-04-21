#include <iostream>
using namespace std;

#define MAXN 51
int A[MAXN], B[MAXN];

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            float a;
            cin >> a >> B[i];
            A[i] = a*2;
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i]%10 == 0) ans = max(ans, B[i]);
            for (int j = i+1; j < N; ++j) {
                if ((A[i]+A[j])%10 == 0) ans = max(ans, B[j]+B[i]);
                for (int k = j+1; k < N; ++k) {
                    if ((A[i]+A[j]+A[k])%10 == 0) ans = max(ans, B[i]+B[j]+B[k]);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}