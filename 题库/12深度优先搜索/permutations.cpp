#include <iostream>
using namespace std;
int dfs(int n, int k, int divisions, int sum, int start)
{
    int ans = 0;
    // 如果划分次数到了目标值的话
    if(divisions == k)
    {
        //如果总和到目标值，则这次划分是正确的，直接返回1 
        if(sum == n) return 1;
        //如果划分次数到了但是总和不够或者超了，这次划分无效所以返回0
        else return 0;
    }
    // 对于不同的start，开始一次划分，并且sum加上i，划分次数加1
    for(int i = start; i <= n; ++i)
        ans += dfs(n, k, divisions + 1, sum + i, i);
    return ans;

}
int num_division(int n, int k)
{
    return dfs(n, k, 0, 0, 1);
}
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= k;++i) ans += num_division(n,i);
    cout << ans;
}