#include <iostream>
#include  <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, count=0;
	cin >> N;
	string s;
	while (N--) {

		bool NO = true;
		cin >> s;
		stack <char>gword;

		for (auto a : s) {
			if (gword.empty()) {
				if (a == 'A' || a == 'B') {
					gword.push(a);
				}
			}
			else {
				if (a == 'A' || a == 'B') {
					if (gword.top() == a) {
						gword.pop();
					}
					else {
						gword.push(a);
					}
				}
			}
		}
		if (!gword.empty()) {
			NO = false;
		}

		if (NO) {
			count++;
		}
	}
	cout << count;
	return 0;
}