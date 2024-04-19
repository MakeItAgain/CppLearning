# 递归算法

## 阿克曼(Ackmann)函数
* 链接： http://ybt.ssoier.cn:8088/problem_show.php?pid=1163
* 题目描述：    ![alt text](images/image.png)
* 输入： m和n
* 输出： 函数值。
* 输入样例： 2 3 
* 输出样例： 9  


```cpp
#include<iostream>
using namespace std;
int akm(m, n)
{
    if(m == 0) return n +1 ;
    else if(m > 0 && n==0)return akm(m-1, 1);
    else if(m > 0 && n >0)return ajm(m-1, akm(m,n-1));
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << akm(m,n);

    return 0;
}
```

```cpp


int main()
{
    cout << fab(5);
    return 0;
}
```