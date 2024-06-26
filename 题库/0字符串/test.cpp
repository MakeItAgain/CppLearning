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
