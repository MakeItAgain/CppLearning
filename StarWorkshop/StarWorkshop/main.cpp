
//  main.cpp
//  StarWorkshop
//
//  Created by Silhouette Of on 2024/10/18.
//

#include"intermediate/intermediate.h"
#include <iostream>
#include "algorithms/dp.h"
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include<cmath>
using namespace std;


bool isPrime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) return false; // 出现一个数可以被x整除，直接return
    }
    return true;// 没有一个数可以被x整除
}

bool is_pal(int x) { // 回文数
    int x_copy = x;
    int sum = 0;
    while(x != 0) {
        sum *= 10;
        sum += x % 10;
        x /= 10;
    }
    return sum == x_copy;
}
bool is_ps(int x) {// 完全平方数
    int root = sqrt(x);
    return root * root == x;
}
// 1.3 用函数写一个冒泡排序
// 桶排序，前提是：数据有明显的范围，用数字作为下标，优点是效率高，快
// 排序库函数，头文件algorithm，原型sort(a+m,a+n)，cmp 函数如何写？ 当满足什么条件的时候第一个参数在第二个参数之前，头尾之间的范围限定在哪里。
// 字符变量与字符常量
// 输出字母，for循环怎么写，可以直接使用char类型作为循环变量的初始化，大小写转换
// 字符数组和字符串的区别？
int main() {

    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)  cin >> arr[i];

    bucketSort(arr, n , 0, 100);

    return 0;
}


 
 
