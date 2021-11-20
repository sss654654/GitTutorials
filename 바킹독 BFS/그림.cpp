#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

int board[501][501];
bool vis[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0,0 }); 
	// (0, 0) 초기화

	int max = 0;
	int drawcount = 1; // 이미 (0,0)을 방문했기 때문에 0이 아니라 1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] != 1) {
				// 그림판을 전부 돌며 방문하지않은 파란칸을 체크
				vis[i][j] = 1;
				Q.push({ i,j });
				drawcount++;
			}
			int count =0; // 가장 넓은 그림의 넓이
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				count++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			if (max < count) {
				max = count;
			}
		}
	}

	cout << drawcount << "\n";
	cout << max << "\n";

}