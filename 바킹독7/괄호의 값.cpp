//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	string s;
//	cin >> s;
//	stack <int> str;
//	int no = 0;
//	int temp, count =0;
//	for (auto a : s) {
//		if (a == '[' || a == '(') {
//			str.push(a);
//		}
//		else if (!str.empty() && a == ']') {
//		    if (str.top() == '[') {
//				str.pop();
//				str.push(3);
//				//count *= 3;
//			}
//			else { 
//				if (str.top() == '(') {
//					no = 1;
//					break;
//				}
//				temp = 0;
//				while (str.top() != '[') {
//					temp += str.top();
//					str.pop();
//					if (str.empty()) {
//						no = 1;
//						break;
//					}
//				}
//				if (str.empty()) {
//					no = 1;
//					break;
//				}
//				str.pop();
//				str.push(temp*3);
//			}
//		}
//		else if (!str.empty() && a == ')') {
//			if (str.top() == '(') {
//				str.pop();
//				str.push(2);
//			}
//			else  {
//				if (str.top() == '[') {
//					no = 1;
//					break;
//				}
//				temp = 0;
//				while (str.top() != '(') {
//					temp += str.top();
//					str.pop();
//					if (str.empty()) {
//						no = 1;
//						break;
//					}
//				}
//				if (str.empty()) {
//					no = 1;
//					break;
//				}
//				str.pop();
//				str.push(temp * 2);
//			}
//		}
//		else{
//			no = 1;
//			break;
//		}
//	}
//
//	while (!str.empty()) {
//		count += str.top();
//		str.pop();
//	}
//	if (!no && str.empty()) {
//		cout << count << "\n";
//	}
//	else {
//		cout << 0 << "\n";
//	}
//}