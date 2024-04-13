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
    string id;
    double scores;
};
//定义一个cmp函数，该函数作为 sort函数的第三个参数，告知cmp函数如何对student结构体数据进行排序
//该函数返回bool值，传入两个student的参数，当s1.scores > s2.scores; 返回true否则返回false
//也就是说该函数对score进行降序排序，如果不确定是大于号还是小于号可以观察一下输出
bool cmp(student s1, student s2)
{
    // if(s1.scores > s2.scores)
    //     return true;   
    // else if(s1. scores == s2.scores)
    //     return s1.id > s2.id;
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

## 明明的随机数
* 题目链接： http://ybt.ssoier.cn:8088/problem_show.php?pid=1184
* 题目描述： 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
* 输入描述： 
有2行，第1行为1个正整数，表示所生成的随机数的个数：N；  
第2行有N个用空格隔开的正整数，为所产生的随机数。   
* 输出描述： 
也是2行，第1行为1个正整数M，表示不相同的随机数的个数。第2行为M个用空格隔开的正整数，为从小到大排好序的不相同的随机数。  
* 输入样例：   
10  
20 40 32 67 40 20 89 300 400 15   
* 输出样例：   
8    
15 20 32 40 67 89 300 400   


* 题目分析： 题目中有个关键信息：1到1000之间的随机整数，也就是说数字最大不会超过1000，言外之意提醒我们可以使用空间换时间的做法，不使用sort函数即可进行排序，利用桶排序的思想，对其进行排序。构建一个大小为1000初始值都为0的数组，每当输入一个数，如果没输入过也就是，则将该下标对应的数组元素值为1，如果输入过，即该下标对应的值已为1，就什么也不做。

* 代码示例：
```cpp
#include<iostream>
#include<vector>
using namespace std;
vector<int> nums(101,0);
int main()
{
    int n;
    cin >>n;
    int m;
    for(int i = 0; i< N;++i){
        cin >> m;
        if(nums[m] == 0) nums[m]++;
    }
    for(int i = 1;i <=100; i++)
    {
        if(nums[i] == 1) cout << i << ' ';
    }
    return 0;
}
```

## 单词排序
* 题目链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1185
* 题目描述： 输入一行单词序列，相邻单词之间由1个或多个空格间隔，请按照字典序输出这些单词，要求重复的单词只输出一次。（区分大小写）
* 输入描述： 一行单词序列，最少1个单词，最多100个单词，每个单词长度不超过50，单词之间用至少1个空格间隔。数据不含除字母、空格外的其他字符。
* 输出描述： 按字典序输出这些单词，重复的单词只输出一次。
* 输入样例： She  wants  to go to Peking University to study  Chinese
* 输出样例： 
Chinese  
Peking  
She  
University  
go  
study  
to  
wants  
* 题目解析：本题比较简单，直接使用sort函数即可，主要是想讲解一下vector和string的联合使用
* 代码示例：
```cpp
#include<iostream>
#include<vector>
#include<string>
#include <sstream>

using namespace std;

int main()
{
    string input; 
    getline(cin, input); // 读取一行输入

    vector<string> words; // 存储单词的容器
    // 使用 istringstream 可以根据空格分割字符串 
    isstringstream iss(input);

    //下面的函数将字符串根据空格分开，然后存入iss，再由iss分别一次输入word中
    string word;
    while(iss >> word){
        words.push_back(word);
    }

    sort(words.begin(), words.end());
    for(int i = 0; i< words.size(); ++i)
        cout<< words[i] << endl;
    return 0;
}

```

## 出现次数超过一半的数
* 题目链接：http://ybt.ssoier.cn:8088/problem_show.php?pid=1186
* 题目描述： 给出一个含有n（0 < n <= 1000）个整数的数组，请找出其中出现次数超过一半的数。数组中的数大于-50且小于50。
* 输入描述：第一行包含一个整数n，表示数组大小；  

第二行包含n个整数，分别是数组中的每个元素，相邻两个元素之间用单个空格隔开。  
* 输出描述：  如果存在这样的数，输出这个数；否则输出no。
* 输入样例： 
3  
1 2 2  
* 输出样例：  
2    
* 题目分析： 依旧是使用下标作为输入对应数字的对应，每次输入一个数，就将该数字对应的下标处的值加1，最终统计有哪一个数字的出现次数大于了一半的输入  
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    const int array_size = 100;
    vector<int> counts(array_size, 0); // 初始全部为0的长度为100的数组

    int n;
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        if (input > -50 && input < 50)// 输入在范围内时才统计
            counts[input + 50]++; // 将输入加50作为索引，统计输入个数
    }

    // 依次判断数组中的每个元素，如果个数大于一半就输出
    for (int i = 0; i < array_size; ++i) {
        if (counts[i] > n/2) {
            cout << i -50;
        }
    }

    return 0;
}

```

## 排队接水
* 链接： http://ybt.ssoier.cn:8088/problem_show.php?pid=1319
* 题目描述：有n个人在一个水龙头前排队接水，假如每个人接水的时间为Ti，请编程找出这n个人排队的一种顺序，使得n个人的平均等待时间最小
* 输入：共两行，第一行为n(1≤n≤1000)；第二行分别表示第1个人到第n个人每人的接水时间T1，T2，…，Tn，每个数据之间有1个空格。  
* 输出：有两行，第一行为一种排队顺序，即1到n的一种排列；第二行为这种排列方案下的平均等待时间(输出结果精确到小数点后两位)。   
* 输入样例： 
10				  			
56 12 1 99 1000 234 33 55 99 812  
* 输出样例：    
3 2 7 8 1 4 9 6 10 5      
291.90      

 
