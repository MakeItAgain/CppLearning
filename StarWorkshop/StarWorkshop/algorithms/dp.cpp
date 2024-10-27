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
    vector<vector<int> > dp(N+1), a(N+1);//dp和a都是二维数组
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

//最长上升子序列 http://ybt.ssoier.cn:8088/problem_show.php?pid=1281
/*
给定一个整数数组nums，找出其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除或不删除数组中的元素而不改变其余元素的顺序。 例如，3，6，2，7 是数组 0，3，1，6，2，2，7的子序列
 
 构建一个dp数组，其中每个元素表示：以当前元素为最后一个元素的时候，最长上升子序列的长度。
 于是对于每一个i（0，n-1）对于每一个j（0，i-1）如果nums[j] < nums[i]那么dp[i] = max(dp[i], dp[j]+1)
*/

int lengthOfLIS()
{
    int n,x;
    cin >> n;
    if (n==0||n==1) return n;
    vector<int>nums(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >>x;
        nums[i] = x;
    }
    vector<int> dp(n+1, 1);
    int maxLength = 1;
    for (int i= 1; i <= n;i++)
    {
        for (int j = 1; j<i; ++j)
            if(nums[j] < nums[i] && dp[j] +1 <dp[i] )   dp[i] = max(dp[i], dp[j]+1);
        
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}
/*
求最长不下降序列 http://ybt.ssoier.cn:8088/problem_show.php?pid=1259

给定一个整数数组nums，找出其中最长不下降子序列的长度以及输出这个序列（不唯一输出一个就好）。
子序列是由数组派生而来的序列，删除或不删除数组中的元素而不改变其余元素的顺序。 例如，3，6，2，7 是数组 0，3，1，6，2，2，7的子序列
 
构建一个dp数组，其中每个元素表示：以当前元素为最后一个元素的时候，最长不下降子序列的长度。
于是对于每一个i（0，n-1）对于每一个j（0，i-1）如果nums[j] <= nums[i]那么dp[i] = max(dp[i], dp[j]+1)
输入： 第一行为n,第二行为用空格隔开的n个整数。
输出：第一行为输出最大个数max(形式见样例)；  第二行为max个整数形成的不下降序列,答案可能不唯一，输出一种就可以了，本题进行特殊评测。

例如：
输入：
14
13 7 9 16 38 24 37 18 44 19 21 22 63 15
输出：
max=8
7 9 16 18 19 21 22 63
 
 
解题思路：需要构造一个二维数组，用来记录以当前元素为最后一个元素的时候，上一个元素是什么。

*/
void lengthOfLNDS()
{
    int n,x;
    cin >> n;
    if (n==0)   //处理特殊情况
    {
        cout << "max=" << n;
    }
    vector<int>nums(n+1);
    //构造输入
    for (int i = 1; i <= n; i++) {
        cin >>x;
        nums[i] = x;
    }
    //构造二维矩阵
    vector<vector<int> > dp(n+1);
    for (int i = 1; i <= n; i++) 
    {
        dp[i].push_back(1);
        dp[i].push_back(0);
    }
    int maxLength = 1, end = 0;
    for (int i= 1; i <= n;i++)
    {
        for (int j = 1; j<i; ++j)
        {
            if(nums[j] <= nums[i])  
            {
                // 改变最大值的同时，记录上一个元素的下标
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
                dp[i][1] = j;
            }
        }
        // 记录最大length以及末尾的位置
        if (dp[i][0] > maxLength) {
            maxLength = dp[i][0];
            end = i;
        }


    }
    //构造一个下标数组，因为我们是逆序输入所以应该逆序输出
    vector<int> indexList;
    while(end != 0)
    {
        indexList.push_back(end);
        end = dp[end][1];
    }
    cout << "max=" << maxLength <<endl ;
    for (int i=int(indexList.size())-1; i>=0; --i) {
        cout << nums[indexList[i]] << ' ';
    }

}

/*
 最大上升子序列和 http://ybt.ssoier.cn:8088/problem_show.php?pid=1285

给定一个整数数组nums，找出其中最长上升子序列的和。
子序列是由数组派生而来的序列，删除或不删除数组中的元素而不改变其余元素的顺序。 例如，3，6，2，7 是数组 0，3，1，6，2，2，7的子序列
 
构建一个dp数组，其中每个元素表示：以当前元素为最后一个元素的时候，最长不下降子序列的长度。
于是对于每一个i（0，n-1）对于每一个j（0，i-1）如果nums[j] <= nums[i]那么dp[i] = max(dp[i], dp[j]+1)
输入： 第一行为n,第二行为用空格隔开的n个整数。
输出：第一行为输出最大个数max(形式见样例)；  第二行为max个整数形成的不下降序列,答案可能不唯一，输出一种就可以了，本题进行特殊评测。

例如：
输入：
14
13 7 9 16 38 24 37 18 44 19 21 22 63 15
输出：
max=8
7 9 16 18 19 21 22 63
 
 
解题思路：需要构造一个二维数组，用来记录以当前元素为最后一个元素的时候，上一个元素是什么。

*/
void sumOfLIS()
{
    int n,x;
    cin >> n;
    if (n==0)   //处理特殊情况
    {
        cout << "max=" << n;
    }
    vector<int>nums(n+1);
    //构造输入
    for (int i = 1; i <= n; i++) {
        cin >>x;
        nums[i] = x;
    }
    //构造二维矩阵
    vector<vector<int> > dp(n+1);
    for (int i = 1; i <= n; i++)
    {
        dp[i].push_back(1);
        dp[i].push_back(nums[i]);
    }
    int maxLength = 1;
    for (int i= 1; i <= n;i++)
    {
        int maxIndex = 0;
        int currentMaxLength = 1;
        for (int j = 1; j<i; ++j)
        {
            if(dp[j][0] > currentMaxLength)
            {
                currentMaxLength = dp[j][0];
                maxIndex = j;
            }
//            if(nums[j] <= nums[i])
//            {
//                // 改变最大值的同时，记录上一个元素的下标
//                maxIndex =
//                dp[i][0] = max(dp[i][0], dp[j][0]+1);
//                dp[i][1] = j;
//            }
        }
        dp[i][1] += dp[maxLength][1];
        // 记录最大length以及末尾的位置
//        if (dp[i][0] > maxLength) {
//            maxLength = dp[i][0];
//            end = i;
//        }


    }
    //构造一个下标数组，因为我们是逆序输入所以应该逆序输出
//    vector<int> indexList;
//    while(end != 0)
//    {
//        indexList.push_back(end);
//        end = dp[end][1];
//    }
//    cout << "max=" << maxLength <<endl ;
//    for (int i=int(indexList.size())-1; i>=0; --i) {
//        cout << nums[indexList[i]] << ' ';
//    }
    int ans = 0;
    for (int i =1; i <= n; ++i) {
        if(maxLength < dp[i][0])
        {
            ans = dp[i][1];
            maxLength = dp[i][0];
        }
    }
    cout << ans;

}

/*
 登山 http://ybt.ssoier.cn:8088/problem_show.php?pid=1283
 
五一到了，ACM队组织大家去登山观光，队员们发现山上一共有N个景点，并且决定按照顺序来浏览这些景点，即每次所浏览景点的编号都要大于前一个浏览景点的编号。同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，并且一旦开始下山，就不再向上走了。队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？
 
 输入：
 第一行：N (2 <= N <= 1000) 景点数;

 第二行：N个整数，每个景点的海拔。
 
 输出：
 最多能浏览的景点数。
 
 8
 186 186 150 200 160 130 197 220
 */
int climbMountains()
{
    int n,x;
    cin >> n;
    if (n==0) return 0;
    vector<int>nums(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        nums[i] = x;
    }
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

void longestPalindrome(string s)
{
    
    int n = int(s.length());
    
    vector<vector<bool> >dp(n);
    for(auto d:dp) d.resize(n);
    
    //初始化
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = false;
        }
    }
    int start = 0, maxLength = 1;
    for (int i =0 ; i< n; ++i) {
        dp[i][i] = true;
    }
    for (int len = 2; len <= n; ++len) { //从小区间开始逐渐扩大
        for (int i = 0; i<= n-len; ++i) { //起始点的位置不能越界，因为要构建len的字符串
            int j = i +len -1;
            if (s[i] == s[j]) {
                if(len < 3 )dp[i][j] =true;
                else dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j] && len > maxLength)
            {
                start = i;
                maxLength = len;
            }
        }
    }
    cout << s.substr(start, maxLength);
}


