#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		bool NO = true;
		string s;
		cin >> s;
		stack<int> ps;
		for (auto a : s) {
			if (a == '(') {
				ps.push(a);
			}
			else if (a == ')') {
				if (ps.empty() || ps.top() != '(') {
					NO = false;
					break;
				}
				ps.pop();
			}
		}
		if (!ps.empty()) {
			NO = false;
		}

		if (NO) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}