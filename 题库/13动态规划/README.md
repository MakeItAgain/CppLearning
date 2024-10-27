# 动态规划
基本思想：  
可以把动态规划理解为：通过把原问题分解为相对简单的子问题的方式来求解复杂问题的方法。  
动态规划背后的基本思想非常简单。一般，若要求解一个问题，需要分解成不同部分 （即子问题），再根据子问题的解以得出原问题的解通常许多子问题非常相似，动态规划法试图仅仅解决每个子问题一次，从而减少计算量：  
一旦某个给定子问题的解已经算出，则将其存储到表中，以便下次需要同一个子问题解之时直接查表  
动态规划常常适用于有最优子结构性质和重叠子问题性质的问题，动态规划万法所耗时间往往远少补素解法。
## 做题技巧：
1. 定义dp数组或矩阵，思考dp数组中元素的含义是什么。
2. 写出状态转移方程和边界值。
3. 思考如何优化。


## 题目
### 爬楼梯1
* 题目链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1204
* 题目描述：
树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数。  
例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级，也可以第一次走两级，第二次走一级，一共3种方法。  
* 输入格式： 一个数字表示需要爬多少层楼梯。
* 输出格式： 不同的走法数。
* 题目解析：除了第一级和第二级阶梯，后面的每一级阶梯都可以从前两层跳上来，也可以从前一层跳上来，也就是都是前面两个阶梯的方法数加起来。而我们已知爬到第一层有一种方式，爬到第二层有两种方式。
* 代码示例：
```cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums(31);
    nums[1] = 1;
    nums[2] = 2;
    int len = nums.size();
    // 从第三层开始，每一级阶梯都是前面两个阶梯方法数相加。
    for(int i = 3; i< len; ++i) nums[i] = nums[i-1] + nums[i-2];
    int n;
    cin >> n;
    cout << nums[n];
    return 0;
}
```


### 爬楼梯2
上台阶问题，树老师上台阶，走到每一级台阶都有一定的花费或者损失，他每一步可以实现单级台阶和两级台阶的跨域，计算从最底层走到最顶层的最少花费。其中最底层和最顶层不需要花费。  
构建dp数组，第n个索引对应的元素是，到达第n级台阶后所需要的最少花费。   
用 dp[i] 表示走到第i级台阶的最小花费，考虑最后一步即第i级台阶，有可能是一步跨一个台阶到第i级台阶，那么 dp[i] = dp[i - 1] + cost[i - 1]，也有可能是一步跨两个台阶到第 i 级台阶，那么有 dp[i] = dp[i - 2] + cost[i - 1]，所以得到状态转移方程：dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1]。
* 代码示例：
```cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
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
```

### 数字三角形
观察下面的数字金字塔，写一个程序查找最高点到最底部任意路径处的路径使得经过数字的和是最大的。每一步可以走到左下方的点也可以到达 右下方的点。  
                7   
            3       8  
        8       1       0   
    2       7       4       4  
 4      5       2       6       5  
 从7-3-8-7-5 的路径产生了最大权值   
 首先用下三角矩阵存储三角形，然后构建一个相同大小的dp数组，保存到该点的路径最大和。状态转移方程就是


```cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
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
    cout << "一共有多少级梯子呢";
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
```

## 最长上升子序列
* 链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1281
最长上升子序列的长度。
给定一个整数数组nums，找出其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除或不删除数组中的元素而不改变其余元素的顺序。 例如，3，6，2，7 是数组 0，3，1，6，2，2，7的子序列
 
 构建一个dp数组，其中每个元素表示：以当前元素为最后一个元素的时候，最长上升子序列的长度。
 于是对于每一个i（0，n-1）对于每一个j（0，i-1）如果nums[j] < nums[i]那么dp[i] = max(dp[i], dp[j]+1)

```cpp

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
            if(nums[j] < nums[i])   dp[i] = max(dp[i], dp[j]+1);
        
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

```

## 登山 
* 链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1283
 
五一到了，ACM队组织大家去登山观光，队员们发现山上一共有N个景点，并且决定按照顺序来浏览这些景点，即每次所浏览景点的编号都要大于前一个浏览景点的编号。同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，并且一旦开始下山，就不再向上走了。队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？
 
 输入：
 第一行：N (2 <= N <= 1000) 景点数;

 第二行：N个整数，每个景点的海拔。
 
 输出：
 最多能浏览的景点数。
 
 8
 186 186 150 200 160 130 197 220
```cpp
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
```

## 最长不下降子序列
* 链接求最长不下降序列 http://ybt.ssoier.cn:8088/problem_show.php?pid=1259

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
```cpp
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
```