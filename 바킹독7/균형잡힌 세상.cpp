#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string world;
	while (true) {
		bool no = true;
		stack<char> str;
		getline(cin, world);
		if (world == ".") {
			break;
		}
		for (auto a : world) {
			if (a == '(') {
				str.push(a);
			}
			else if (a == '[') {
				str.push(a);
			}
			else if (a == ')') {
				if (str.empty() || str.top() != '(') {
					no = false;
					break;
				}
				str.pop();
				
			}
			else if (a == ']') {
				if (str.empty() || str.top() != '[') {
					no = false;
					break;
				}
				str.pop();
				
			}
		}
		if (!str.empty()) {
			no = false;
		}
		if (no) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
		
	}
	return 0;
}