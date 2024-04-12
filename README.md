# CppLearning
C++和算法的学习资料

## 文件夹分类
* 学习库：包含了常见STL的用法以及课上的重点笔记
* 往期学案：包含了学案的pdf版本
* 试卷&作业题：包含了往期整套考试卷子以及整套的作业题
* 题库：按照算法种类对一些经典习题进行了分类

## 刷题网址
* 信息学奥赛一本通（ACM模式）：http://ybt.ssoier.cn:8088/index.php
* 洛谷（ACM模式）：https://www.luogu.com.cn/
* Leetcode（核心代码模式）建议有一定基础：https://leetcode.cn/problemset/


## ACM模式和核心代码模式
ACM模式是指：题目不给任何辅助代码，所有的输入输出需要自己构造  
核心代码模式是指，只需要专注算法的实现部分，而程序的输入和输出代码程序自动帮忙完成。  

目前竞赛中使用的大多是ACM模式，这就要求对输入和输出格式熟练于心，如果一直使用核心代码模式刷题，到考场上后无法有效的输入输出导致拿不上分数。以“岛屿数量”这个题为例子，列出了ACM模式和核心代码模式的不同；200
题目描述： 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。此外，你可以假设该网格的四条边均被水包围。
示例 2：  
输入：grid = [  
  ["1","1","0","0","0"],  
  ["1","1","0","0","0"],  
  ["0","0","1","0","0"], 
  ["0","0","0","1","1"]  
]  
输出：3    
核心代码模式： 
```CPP
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
```
而ACM模式：
```CPP
#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
int main()
{
    int m,n; 
    cin >> m >>n;
    vector<vector<char>> grid(m);
    for(int i = 0; i <m ;++i)
    {
        grid[i].resize(n);
    }
    for(int i = 0; i < m;++m)
    {
        for(int j = 0; j <n;++j)
        {
            cin >> grid[i][j];
        }
            
    }
    solution = Solution();
    cout << solution.numIslands(grid);
    return 0;
} 
```
git push gitee main 
gitee.com/makeitagain/cpp-teaching/tree/main/