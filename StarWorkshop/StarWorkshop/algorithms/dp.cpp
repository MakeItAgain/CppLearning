//
//  dp.cpp
//  StarWorkshop
//
//  Created by Silhouette Of on 2024/10/20.
//

#include"dp.h"
#include <iostream>
#include <vector>

using namespace std;

//树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数。
//例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级，也可以第一次走两级，第二次走一级，一共3种方法。
void climbStairsI()
{
    cout << "输入需要爬的楼梯数";
    int n ;
    cin >> n;
    if(n<=1) {
        cout << n;
        return;
    }
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <=n ; i++) {
        dp[i] = dp[i-1] + dp[i+1];
    }
    cout << dp[n];
    return;
}

 //上台阶问题，树老师上台阶，走到每一级台阶都有一定的花费或者损失，他每一步可以实现单级台阶和两级台阶的跨域，计算从最底层走到最顶层的最少花费。其中最底层和最顶层不需要花费。
//构建dp数组，第n个索引对应的元素是，到达第n级台阶后所需要的最少花费。
//用 dp[i] 表示走到第i级台阶的最小花费，考虑最后一步即第i级台阶，有可能是一步跨一个台阶到第i级台阶，那么 dp[i] = dp[i - 1] + cost[i - 1]，也有可能是一步跨两个台阶到第 i 级台阶，那么有 dp[i] = dp[i - 2] + cost[i - 1]，所以得到状态转移方程：dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1]。
void climbStairsII()
{
    cout << "本次一共有多少个台阶呢";
    int n;
    cin >> n;
    vector<int>cost(n); // 记录到达每一层的消耗
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    
    vector<int>dp(n+1, 0); //记录整个数组
    
    dp[1] = cost[0];//边界值
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i-1];// 前两级台阶的较小值加上上一级台阶的cost
    }
    cout <<  min(dp[n], dp[n-1]);
    
}

// 数字三角形，观察下面的数字金字塔，写一个程序查找最高点到最底部任意路径处的路径使得经过数字的和是最大的。每一步可以走到左下方的点也可以到达 右下方的点。
/*
                7
            3       8
        8       1       0
    2       7       4       4
 4      5       2       6       5
 从7-3-8-7-5 的路径产生了最大权值
 首先用下三角矩阵存储三角形，然后构建一个相同大小的dp数组，保存到该点的路径最大和。状态转移方程就是
 */
void triangleOfNums()
{
    int N = 1000;
    vector<vector<int>> dp(N+1), a(N+1);//dp和a都是二维数组
    for (int i = 0; i<=N; i++) {
        dp[i].resize(N+1); // 将dp[i]这个一维数组长度变成N+1
        a[i].resize(N+1);
    }

//    for(auto x: dp) x.resize(N + 1);
//    for(auto x: a) a.resize(N + 1);
    
    int n, ans = 0;
    cout << "一共有多少级台阶呢";
    cin >> n;
    for (int i =1; i <=n; i++)
        for (int j =1; j<=i; j++)
            cin >> a[i][j];//continue


    for (int i =1; i <=n; i++)
        for (int j =1; j<=i; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
    for (int j = 1; j <=n; j++)
        ans = max(ans, dp[n][j]);
    cout << ans;
}

//最长上升自序列
/*
给定一个整数数组nums，找出其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除或不删除数组中的元素而不改变其余元素的顺序。 例如，3，6，2，7 是数组 0，3，1，6，2，2，7的子序列
 
 构建一个dp数组，其中每个元素表示以当前元素为最后一个元素的时候，最长上升子序列的长度。
 于是对于每一个i（0，n-1）对于每一个j（0，i-1）如果nums[j] < nums[i]那么dp[i] = max(dp[i], dp[j]+1)
*/

int lengthOfLIS()
{
    int n,x;
    cin >> n;
    vector<int>nums;
    for (int i = 0; i < n; i++) {
        cin >>x;
        nums.push_back(x);
    }
    if (n==0) return 0;
    vector<int> dp(n, 1);
    int maxLength = 1;
    for (int i= 1; i < n;i++)
    {
        for (int j = 0; j<i; ++j)
            if(nums[j] < nums[i])   dp[i] = max(dp[i], dp[j]+1);
        
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

//====================区间动态规划=====================


/*
回文子串
给定一个字符串s，找出s中的最长回文子串，如果一个字符串逆序和原始字符串相同，则为回文子串。

 使用动态规划的思想：
 1. 从一个回文子串扩展到左右两边的字符
 2. 确定状态和状态变量：定义 dp[i][j] 表示子串 S[i...] 是否为一个回文串，用来保存状态
 其中i和j是子串的起始和结束索引 （包含i和j）。如果 S[i...j] 是回文，那么dp[i][j]=true否则dp[i][j]=false
 3. 确定决策并写出状态转移方程：
 当s[i]==s[j]时，如果j-i<2（即相邻的两个一样的字符是回文） 或者dp[i+1][j-1]是回文 （即去掉两端后依然是回文），那么s[i..j]是回文，即dp[i][j]=true
  否，dp[i][j]=false
4.边界条件： 所有单字符子串都是回文，所以dp[i][i]=true
5.找到最长的 dp[i][j]=true， 记录其长度和起始索引时间复杂度为 O（n2）。
*/
