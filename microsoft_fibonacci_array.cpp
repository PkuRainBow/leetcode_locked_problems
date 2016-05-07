//
// Created by pianocoder on 16/4/9.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
vector<int> fib;
map<int, int> f_map;
map<int, int> index_map;
const int MOD = 1000000007;

void init_fib(int n) {
    fib.clear();
    fib.push_back(1);
    fib.push_back(1);
    int size = 2;
    while(fib.back() <= n) {
        fib.push_back(fib[size-1]+fib[size-2]);
        size++;
    }
    for(int i = 1; i < fib.size(); i++) {
        f_map[fib[i]] = 0;
        index_map[fib[i]] = i;
    }
}

int main() {
    init_fib(100000);
    int n = 0;
    int cur = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> cur;
        if(f_map.find(cur) != f_map.end()) {
            if(cur == 1) {
                f_map[1]++;
            }
            else if(cur == 2) {
                if(f_map[1] >= 2) {
                    f_map[2] += f_map[1]*(f_map[1]-1)/2;
                }
            }
            else {
                //previous fib count
                int pre = index_map[cur] - 1;
                f_map[cur] += f_map[fib[pre]];
            }
        }
    }
    int result = 0;
    if(f_map[1] < 2)
        result = 0;
    else {
        result += f_map[1] + (f_map[1]*(f_map[1]-1)/2);
        for(int i = 2; i < fib.size(); i++) {
            result += f_map[fib[i]];
            result %= MOD;
        }
    }
    cout << result << endl;
    return 0;
}
*/