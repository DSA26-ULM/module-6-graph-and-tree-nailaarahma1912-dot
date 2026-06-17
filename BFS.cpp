#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int r;
    int c;
    int dist;
};
int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];
    int sr, sc;
    int fr, fc;
    cin >> sr >> sc;
    cin >> fr >> fc;
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    queue<Node> q;
    q.push({sr, sc, 0});
    vis[sr][sc] = true;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        if (cur.r == fr && cur.c == fc) {
            cout << cur.dist << '\n';
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if (grid[nr][nc] == 1)
                continue;
            if (vis[nr][nc])
                continue;
            vis[nr][nc] = true;
            q.push({nr, nc, cur.dist + 1});
        }
    }
    cout << -1 << '\n';
    return 0;
}