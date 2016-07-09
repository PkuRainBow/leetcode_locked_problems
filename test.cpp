#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>

using namespace std;

void solve(string cur) {
	cout << cur << ", hello world ! " << endl;
	return;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string cur_str;
		cout << "case #" << i + 1 << ": ";
		cin >> cur_str;
		solve(cur_str);
	}
}

#include <fstream>
#include　<map>
#include <iostream>
#include <vector>

void solve() {

}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i ++) {
		/** deal with the input **/
		solve();
	}
}


