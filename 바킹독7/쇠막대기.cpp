#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int pipenum = 0, rasernum =0, cnt =0;
	string s;
	cin >> s;
	stack <char> pipe;
	for (auto a : s) {
		if (a == '(') {
			pipe.push(a);
		}
		else if (a == ')') {
			if (pipe.top() == '(') { // raser;
				pipe.pop();
				cout << pipe.size() << "\n";
				cnt += pipe.size();
			}
		}
	}
	cout << cnt << "\n";
	
}