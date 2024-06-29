// https://atcoder.jp/contests/abc351/tasks/abc351_d

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;




// 方向の定義
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int H, W;
vector<string> grid;
vector<vector<int>> f;

// マスの座標
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// 指定した座標がグリッド内かどうかをチェック
bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

// DFSを用いて通路の自由度を計算
int dfs(int x, int y) {
    // 探索済みのマスを表す配列
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int count = 0;

    // スタート地点をキューに追加
    queue<Point> q;
    q.push(Point(x, y));
    visited[x][y] = true;

    // キューが空になるまで探索を続ける
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        count++;

        // 上下左右のマスを調べる
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // グリッド内でかつ通路であれば探索を続ける
            if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                q.push(Point(nx, ny));
            } else if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '-') {
                
            }
        }
    }

    return count;
}

int main() {
    // 入力を受け取る
    cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            f[i][j] = 0;
            if (grid[i][j] != '#' && (grid[i+1][j] == '#' || grid[i-1][j] == '#' || grid[i][j+1] == '#' || grid[i][j-1] == '#'))
            {
                grid[i][j] = '-';
                f[i][j] = 1;
            }
            
        }
        
    }
    

    int max_freedom = 0;

    // 各通路についてDFSを実行し、到達可能なマスの数を求める
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '.') {
                max_freedom = max(max_freedom, dfs(i, j));
            }
        }
    }

    cout << max_freedom << endl;

    return 0;
}