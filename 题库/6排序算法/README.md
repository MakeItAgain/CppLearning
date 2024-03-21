# 排序算法
本次作业主要是排序算法，接下来我们布置的作业都会是按照模块来布置的 ，这样的效果会好一些。1176和1178题涉及了结构体进行排序，这部分同学们比较陌生，我将这个题的分析和答案发不到了我们的代码仓库中，地址是 https://gitee.com/makeitagain/cpp-teaching/tree/main/%E9%A2%98%E5%BA%93/6%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95， 请同学们学习该代码然后完成1178， 1177不涉及结构题的排序，同学们自行完成。
## 谁考了第k名
* 试题链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1176
* 题目描述：在一次考试中，每个学生的成绩都不相同，现知道了每个学生的学号和成绩，求考第k名学生的学号和成绩。
* 输入： 第一行有两个整数，分别是学生的人数n（1≤n≤100）。和求第k名学生的k（1≤k≤n）其后有n行数据，每行包括一个学号（整数）和一个成绩（浮点数），中间用一个空格分隔。
* 输入样例：  
5 3    
90788001 67.8  
90788002 90.3  
90788003 61  
90788004 68.4  
90788005 73.9  
* 输出样例： 
90788004 68.4  

* 题目分析： 之前做的题目都是对于成绩进行排序而没有加入学号，这次加入了学号，提醒我们要使用结构体struct，将不同的数据类型汇合在一起，然后对其进行排序。    
* 程序示例：  
```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 定义一个学生的结构体，单纯定义不开辟内存
struct student
{
    int id;
    double scores;
};
//定义一个cmp函数，该函数作为 sort函数的第三个参数，告知cmp函数如何对student结构体数据进行排序
//该函数返回bool值，传入两个student的参数，当s1.scores > s2.scores; 返回true否则返回false
//也就是说该函数对score进行降序排序，如果不确定是大于号还是小于号可以观察一下输出
bool cmp(student s1, student s2)
{
    return s1.scores > s2.scores;   
}

int main()
{
    int n,k;
    cin >> n >>k;
    // 使用了vector代替了student数组
    vector<student> students(n);
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].id >> students[i].scores;
    }
    sort(students.begin(), students.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if(n == k-1)
            cout << students[i].id << ' ' <<students[i].scores <<endl; 
    }
    
    return 0;

}

```

## 奇数单增序列
* 题目描述：给定一个长度为N（不大于500）的正整数序列，请将其中的所有奇数取出，并按升序输出。
* 输入： 
第一行为N   
第二行为N个整数，其间用空格隔开  
* 输出： 增序输出的奇数序列，数据之间以逗号间隔。数据保证至少有一个奇数。  
* 输入样例： 
10   
1 3 2 6 5 4 9 8 7 10   
* 输出样例：   
1,3,5,7,9   

* 题目分析：本题的关键在于长度不大于500， 也就是我们可以使用一个预定义的数组来存储这些奇数，可以将该数组的初始值都设置为0， 如果输入的数字中出现一个奇数，就将该奇数下标对应的数组元素值设置为1，arr[i] = 1,表示该值出现过了。然后从1开始遍历整个数组，如果该值为1表示出现过该值，将其输出并输出“，”  这样的算法不需要排序，时间效率更高一些，实际上是空间换时间的效果，对于程序而言，500int值的数组的空间大小换取时间成本是非常可观的。 通常来讲，如果题目中明确表示数据量不大时，往往采用空间换取时间的方法
* 代码示例：
```cpp
#include<iostream>
#include<vector>
using namespace std;
vector<int> arr(501,0); // 第一个参数表示数据量为501，第二个参数表示初始值为0 
int main()
{
    int N ;
    cin >> N;
    for(int i = 0; i < N;i++)
        cin >> arr[i];
    int j = 500;  
    for(;arr[j]!=1;j--);  // 由于题目要求输入一个数后输出一个逗号，而最后一个数字不需要输出逗号，所以需要一个变量记录最后一个奇数的位置下标是多少，用一个j来计数
    for(int i = 1; i<=j; i++)
    {
        if(arr[i] == 1)
        {
            if(i!=j) cout << i << ',';
            else cout << i;
        }
    }
    return 0;
}
```