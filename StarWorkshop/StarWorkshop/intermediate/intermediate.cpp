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
    constexpr int N = 100;
    int arr[N]; //不要用变量，是非常不好的习惯，元素通过下标来引用，引用必须是常量
    //数组在主函数之外定义的话，初始值是0，在主函数之内，初始值随机
    //数组的初始化可以在声明时完成 int a[5] = {1, 2, 3, 4, 5};
    //数组开辟在主函数之外可以拥有很大的空间
    //数组的拷贝需要一个个元素进行，因为数组名是一个指针
}

void bubbleSort(int arr[], const int n) {
    // 外层循环控制排序的轮数
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        // 内层循环进行相邻元素的比较和交换
        for (int j = 0; j < n - 1 - i; ++j) {
            // 如果前一个元素大于后一个元素，则交换它们
            if (arr[j] > arr[j + 1]) {
                // 使用临时变量进行交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }

        }

        // 如果在某一轮中没有发生交换，说明数组已经有序，提前退出
        if (!swapped) {
            break;
        }
    }
}



void bucketSort(int arr[], const int n, int minValue, int maxValue) {
    int bucket[1000] = {};
    for (int i = 0; i < n; ++i) {
        bucket[arr[i]] ++;
    }
    for (int i =0; i <= maxValue; ++i) {
        for (int j = 1; j <= bucket[i]; ++j) {
            cout << i << " ";
        }
    }
}
