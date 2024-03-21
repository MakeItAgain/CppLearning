# string 字符串
参考链接：https://blog.csdn.net/qq_50285142/article/details/114156051

string是一个字符串类，和char型字符串类似。

可以把string理解为一个字符串类型，像int一样可以定义

1. 初始化及自定义：
```CPP
//头文件
#include<string>

//1.
string str1; //生成空字符串

//2.
string str2("123456789"); //生成"1234456789"的复制品 

//3.
string str3("12345", 0, 3);//结果为"123" ，从0位置开始，长度为3

//4.
string str4("123456", 5); //结果为"12345" ，长度为5

//5.
string str5(5, '2'); //结果为"22222" ,构造5个字符'2'连接而成的字符串

//6.
string str6(str2, 2); //结果为"3456789"，截取第三个元素（2对应第三位）到最后

```

2. 访问单个字符：
```CPP
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s = "xing ma qi!!!";
	for(int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	return 0;
}
```

3. string数组的使用：
```CPP
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s[10];
	for(int i = 1; i < 10; i++) {
		s[i] = "loading...  " ;
		cout << s[i] << i << "\n";
	} 
	return 0;
}

//结果： 
// loading...  1
// loading...  2
// loading...  3
// loading...  4
// loading...  5
// loading...  6
// loading...  7
// loading...  8
// loading...  9


```
4. string的特性
    * 支持比较运算符：string字符串支持常见的比较操作符（>,>=,<,<=,==,!=），支持string与C-string的比较（如 str < "hello"）。  
    在使用>,>=,<,<=这些操作符的时候是根据“当前字符特性”将字符按 字典顺序 进行逐一得 比较。字典排序靠前的字符小， 比较的顺序是从前向后比较，遇到不相等的字符就按这个位置上的两个字符的比较结果确定两个字符串的大小（前面减后面）。  
    同时，string ("aaaa") <string(aaaaa)。
    * 支持+运算符，代表拼接字符串  
    string字符串可以拼接，通过"+"运算符进行拼接
    ```CPP
    string s1 = "123";
    string s2 = "456";
    string s = s1 + s2;
    cout << s;   //123456
    ```
5. 方法函数：   
    * 获取字符串长度：  

    |代码|含义|
    |----|----|
    |s.size()和s.length()|返回string对象的字符个数，他们执行效果相同|
    |s.max_size()|返回string对象最多包含的字符数，超出会抛出length_error异常|
    |s.capacity()|重新分配内存之前，string对象能包含的最大字符数|
    * 插入：   

    |代码|含义|
    |----|----|
    |s.push_back(element)|在末尾插入例：s.push_back('a')末尾插入一个字符a|
    |s.insert(pos,element)|在pos位置插入element，例：s.insert(s.begin(),'1')，在第一个位置插入1字符|
    |s.append(str)|在s字符串结尾添加str字符串，例：s.append("abc"），在s字符串末尾添加字符串“abc”|

    * 删除

    |代码|含义|
    |----|----|
    |erase(iterator p)|删除字符串中p所指的字符|
    |erase(iterator first, iterator last)|删除字符串中迭代器区间[first,last)上所有字符|
    |erase(pos, len)|删除字符串中从索引位置pos开始的len个字符|
    |clear()|删除字符串中所有字符|

    * 分割 
    |代码|含义|
    |----|----|
    |s.substr(pos,n)|截取从pos索引开始的n个字符|

    * 查找： 

    |代码|含义|
    |----|----|
    |s.find (str, pos) |在当前字符串的pos索引位置（默认为0）开始，查找子串str，返回找到的位置索引，-1表示查找不到子串 |
    |s.find (c, pos)| 在当前字符串的pos索引位置（默认为0）开始，查找字符c，返回找到的位置索引，-1表示查找不到字符 |
    |s.rfind (str, pos) |在当前字符串的pos索引位置开始，反向查找子串s，返回找到的位置索引，-1表示查找不到子串 |
    |s.rfind (c,pos)| 在当前字符串的pos索引位置开始，反向查找字符c，返回找到的位置索引，-1表示查找不到字符 |
    |s.find_first_of (str, pos) |在当前字符串的pos索引位置（默认为0）开始，查找子串s的字符，返回找到的位置索引，-1表示查找不到字符 |
    |s.find_first_not_of (str,pos)| 在当前字符串的pos索引位置（默认为0）开始，查找第一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到字符 |
    |s.find_last_of(str, pos) |在当前字符串的pos索引位置开始，查找最后一个位于子串s的字符，返回找到的位置索引，-1表示查找不到字符 |
    |s.find_last_not_of ( str, pos) |在当前字符串的pos索引位置开始，查找最后一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到子串
    ```CPP
    #include<string>
    #include<iostream>
    int main() {
        string s("dog bird chicken bird cat");
    //字符串查找-----找到后返回首字母在字符串中的下标
    // 1. 查找一个字符串
        cout << s.find("chicken") << endl;// 结果是：9
        
    // 2. 从下标为6开始找字符'i'，返回找到的第一个i的下标
        cout << s.find('i',6) << endl;// 结果是：11
        
    // 3. 从字符串的末尾开始查找字符串，返回的还是首字母在字符串中的下标
        cout << s.rfind("chicken") << endl;// 结果是：9
        
    // 4. 从字符串的末尾开始查找字符
        cout << s.rfind('i') << endl;// 结果是：18因为是从末尾开始查找，所以返回第一次找到的字符
        
    // 5. 在该字符串中查找第一个属于字符串s的字符
        cout << s.find_first_of("13br98") << endl;// 结果是：4---b
        
    // 6. 在该字符串中查找第一个不属于字符串s的字符------先匹配dog，然后bird匹配不到，所以打印4
        cout << s.find_first_not_of("hello dog 2006") << endl; // 结果是：4
        cout << s.find_first_not_of("dog bird 2006") << endl;  // 结果是：9
        
    // 7. 在该字符串最后中查找第一个属于字符串s的字符
        cout << s.find_last_of("13r98") << endl;// 结果是：19

    // 8. 在该字符串最后中查找第一个不属于字符串s的字符------先匹配t--a---c，然后空格匹配不到，所以打印21
        cout << s.find_last_not_of("teac") << endl;// 结果是：21
    }

    ```

    * 排序： `sort(s.begin(),s.end());  //按ASCII码排序`
    * 大小写转换（注意是单个字符）： 
    |代码|含义|
    |----|----|
    |tolower(s[i])|转换为小写|
    |toupper(s[i])|转换为大写|
    法2：
    通过stl的transform算法配合tolower 和toupper 实现。
    有4个参数，前2个指定要转换的容器的起止范围，第3个参数是结果存放容器的起始位置，第4个参数是一元运算。
    ```CPP
    string s;
    transform(s.begin(),s.end(),s.begin(),::tolower);//转换小写
    transform(s.begin(),s.end(),s.begin(),::toupper);//转换大写
    ```



