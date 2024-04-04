# 模拟算法
## 统计字符个数
![alt text](pics/image.png)
* 程序示例：
```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<int> analysis(26,0);
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        int index = str[i]-'a';
        analysis[index] ++;
    }
    int max = 0, k = 0;
    for (int i = 0; i < 26; i++)
    {
        if (analysis[i] > max)
        {
            max = analysis[i];
            k = i;
        }
        
    }
    cout << char('a' + k) << ' ' << max;
    
    
    return 0;
}
```
## 出现次数超过一半的数
![alt text](image.png)
* 程序示例：
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