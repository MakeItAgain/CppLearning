# 动态规划

## 爬楼梯1
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


## 爬楼梯2




