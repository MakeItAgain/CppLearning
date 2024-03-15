# 考察内容
1. 最简单的做法就是将c3直接一位变四位，然后转为2进制下的结果，然后进行相加， 也就是110010 + 11000011 结果是二进制下的11110101
2. 第二题两个整数通过/进行除法运算的时候结果只保留整数位，小数点全部抹去
3. 两个条件同时成立的相反是至少有一个条件不成立，在该例子中，！表示取反，所以我们只要看是否有条件满足两个条件同时成立的对立面https://zh.wikipedia.org/wiki/%E5%BE%B7%E6%91%A9%E6%A0%B9%E5%AE%9A%E5%BE%8B

-(p 且 q) = -p 或 -q 也就是说p和q同时发生的对立面就是p的相反或者q的相反 
4. 使用char a[] = "SOME THING"定义的是字符串，不是普通的字符串数组， 所以要加上'\0'，所以应该是字符数加一，空格和特殊字符也要算进去。
5. 参考答案是15，首先数组名就是一个指针，其次，对数组名和指针进行加减操作的时候，实际上是元素的移动，默认情况下，如果*p = a；那么p和a作为指针都指向了数组中的第一个元素，而 *(p) = (a +3) 所以，p指向了a[3]也就是8 ，随后下面的语句做的事情就是 a[3] -- + a[3] 那么 ，首先将a[3]--然后使用a[3]--之前的值作为运算数也就是8加上改变之后的值7 ，得到了15

1. 
```cpp
#include<iostream>
using namespace std;
int main()
{
    cin >> n >> m;
    if(n %m == 0) cout << n/m;
    else cout << n/m +1;
    return 0;
}

```
2. 回文数的判断是否正确
3. string以及set还有map容器的使用方法，set就是一个集合，同一类的对象只存储一个，
```cpp
#include <iostream>
#include <string>

using namespace std;
string getSubstrWithoutUsingSubstr(string& str, int i) {
    string result;
    // 确保从i开始的位置至少还有3个字符，且i不超过字符串长度
    if (i + 3 <= str.length()) {
        for (size_t j = i; j < i + 3; ++j) {
            result += str[j];
        }
    }
    return result;
}

int main() {
    string myString = "Hello, World!";
    size_t startIndex = 7; // 从下标7开始获取子串
    string substring = getSubstrWithoutUsingSubstr(myString, startIndex);
    cout << "Substring: " << substring << endl;
    return 0;
}
```
4. 模拟算法
5. C++的string库中，有一个计算给定上一个排列的函数，prev_permutation 可以计算比他小的那种排列，因此只需要使用字符串接受输入然后获取就可以了
6. 



# 本次考试总结
1. 本次考试同学们反应难度较大，其实仔细观察题目，除了最后两个大题还没有讲到对应的算法和STL库函数，难以下手之外，其他的题目对于之前我们训练的题目不算难。当然这次考试的主要目的还是让同学们感受一下考试的难度和时间的把控，总体来说，试题题量较大，较难的题目需要花时间和技巧，这就要求在做选择题和基础题目上速度快一些。本次讲完以后，同学们也不要气馁。首先是我们内容还没有讲完，有很多技巧性的东西或者工具函数还没有讲到，如果掌握的话，将会大大加快我们做题的时间，扩展我们做题的思路。
2. 试题的解析中，出现了很多STL库的容器和函数，如果熟练掌握的话，将会大大提高做题的速度。 这也是我们接下来的任务之一。