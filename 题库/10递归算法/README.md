# 递归算法

## 复杂函数问题 
1. 阿克曼(Ackmann)函数
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
2. Pell 函数
Pell数列a1,a2,a3,...的定义是这样的，a1=1,a2=2,...,an=2an−1+an−2(n>2)。   
给出一个正整数 k，要求Pell数列的第 k项模上 32767是多少。
```cpp
#include<iostream>
using namespace std;

int pell(int n)
{
    if(n <=2) return n;
    return 2 * pell(n-1) + pell(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout  << pell(n);  
}

```
## 数学函数问题
1. 分数求和 
* 题目链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1209
* 题目描述： 输入n个分数并对他们求和，并用最简形式表示。所谓最简形式是指：分子分母的最大公约数为1；若最终结果的分母为1，则直接用整数表示。 如：5/6、10/3 均是最简形式，而3/6 需要化简为1/2,3/1 需要化简为3。分子和分母均不为0，也不为负数。

* 输入描述：第一行是一个整数n，表示分数个数，1≤n≤10；  
接下来n行，每行一个分数，用"p/q"的形式表示，不含空格，p，q均不超过10。  
* 输出描述：输出只有一行，即最终结果的最简形式。若为分数，用"p/q"的形式表示。

* 输入样例：
2  
1/2   
1/3   
* 输出样例： 
5/6  
* 本题模拟数学上求解两分数之和的步骤，利用了递归版的辗转相除法求解分子和分母的最大公约数，然后同除。
* 代码示例： 
```cpp
#include <iostream>
using namespace std;
// 辗转相除法求两个数的最大公约数
int gcd(int m, int n)
{
    if(m%n == 0) return n;
    else return gcd(n, m%n);
}
int main()
{
    int n, num;
    int p, q;
    char c; // p c q 分别用来循环接受 p '/' q，p和q分别是分子分母
    int a, b; //用来存储第一个数，保证乘法顺利进行，a，b分别表示分子分母上的值
    cin >> n;
    cin >> a >> c >> b;
    while(--n != 0)
    {
        cin >> p >> c >> q;
        // 下面两行是求两数之和的过程
        a = a * q + p * b;// 合并之后的分子
        b = b * q;//合并之后的分母
        num = gcd(a, b); //求分子分母的最大公约数
        a /= num;
        b /= num;
    }
    if(a == 1) cout << 1;
    else cout << a<<'/' <<b;
    
}
```