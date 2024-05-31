#include <iostream>
#include <vector>

using namespace std;

// 从当前位置到右下角需要多少步
int dfs(vector<vector<int> >& maze, int r, int c, int m, int n) {
    if (r == m - 1 && c == n - 1) return 0; // 已经到达右下角位置，步数为0

    maze[r][c] = 1; // 标记当前位置为已访问

    int dx[4] = {1, 0, -1, 0}; // 四个方向的行偏移量
    int dy[4] = {0, -1, 0, 1}; //四个方向的列偏移量
    int tx, ty;
    int min_steps = -1; // 初始化最小步数为-1

    for(int i =0; i< 4;++i){  //探索四个方向
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == 0) {
            int steps = dfs(maze, nr, nc, m, n); // 递归调用DFS
            if (steps >= 0 && (min_steps == -1 || steps < min_steps)) {
                min_steps = steps; // 更新最小步数
            }
        }
    }

    maze[r][c] = 0; // 恢复当前位置为未访问状态
    if (min_steps == -1) return -1; // 如果所有方向都无法到达右下角，则返回-1
    return min_steps + 1; // 返回最小步数加上当前步数1
}

int shortestPathInMaze(vector<vector<int> >& maze) {
    int m = maze.size();
    if (m == 0) return -1;
    int n = maze[0].size();
    return dfs(maze, 0, 0, m, n); // 从左上角位置开始深度优先搜索
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > maze(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    int shortest_path_length = shortestPathInMaze(maze);
    cout << shortest_path_length << endl;
    return 0;
}
/*
1 0 0 1
0 1 0 1


*/