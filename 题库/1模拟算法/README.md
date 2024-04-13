# 
## 矩阵加法
* 链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1124
* 题目描述：输入两个n行m列的矩阵A和B，输出它们的和A+B。
* 输入：
第一行两个整数m，n，表示矩阵的行数和列数
接下来n行，每行m个整数，表示矩阵A的元素。
接下来n行，每行m个整数，表示矩阵B的元素。
相邻两个整数之间用单个空格隔开，每个元素均在1～1000之间。

* 输出：n行，每行m个整数，表示矩阵加法的结果。相邻两个整数之间用单个空格隔开。
* 输入样例：  
3 3  
1 2 3  
1 2 3  
1 2 3  
1 2 3  
4 5 6  
7 8 9  
* 输出样例：   
2 4 6  
5 7 9  
8 10 12  
* 提示：所谓矩阵相加就是二维数组中每个元素对应相加。 要求使用vector，下面的程序写出了二维vector的语法。
```cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> A,B;
    int n,m;
    cin >> n >>m;
    A.resize(n);// 将A二维数组的行数设置为n
    B.resize(n);// 同上
    for(int i = 0; i < n; ++i)
    {
        A[i].resize(m); //将每个二维数组的行设置为m列
        B[i].resize(m);
    }
    // 在下面下上自己的程序
    return 0;
}
```
