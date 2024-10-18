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



