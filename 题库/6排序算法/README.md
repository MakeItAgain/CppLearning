# 排序算法

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