//
//  intermediate.cpp
//  StarWorkshop
//
//  Created by Silhouette Of on 2024/10/18.
//



#include "intermediate.h"
#include <iostream>
using namespace std;

// 分解质因数原始版本，输入和输出在函数内完成
void Factorization()
{
    cout << "你需要输入一个合数：";
    int n;
    cin >>n;
    cout << n << "=";
    int i = 2;
    do
    {
        while(n%i == 0) // 当可以除尽i的时候就一直除
        {
            cout << i;
            n /= i;
            if(n != 1)   //只有最后一个数的后面不需要加*
            {
                cout << "*";
            }
        }
        i++;  // 除i结束，接下来需要换一个数了
    }while(n!=1);
    cout << endl;
    
}



// 数组的定义
void arrayDefinition()
{
    const int N = 100;
    int arr[N]; //不要用变量，是非常不好的习惯，元素通过下标来引用，引用必须是常量
    //数组在主函数之外定义的话，初始值是0，在主函数之内，初始值随机
    //数组的初始化可以在声明时完成 int a[5] = {1, 2, 3, 4, 5};
    //数组开辟在主函数之外可以拥有很大的空间
    //数组的拷贝需要一个个元素进行，因为数组名是一个指针
}
