//
//  main.cpp
//  StarWorkshop
//
//  Created by Silhouette Of on 2024/10/18.
//

#include"intermediate/intermediate.h"
#include <iostream>
#include "algorithms/dp.h"

using namespace std;
//const double PI = 3.1415926;

int main(int argc, const char * argv[]) {

    cout << lengthOfLIS();
    return 0;
}

// 一维vector初始化
// vector<int> nums(n,0); vector<int> nums(n);
// 针对复杂变量名称的命名规则：正方体的体积 cube, volume,
// 驼峰命名法：volumeOfCube
// 下划线命名法：volume_of_cube;
/*
 
 
 
 14
 i    1  2 3 4   5 6  7  8  9  10  11 12 13 14
 nums 13 7 9 16 38 24 37 18 44 19 21 22 63 15
 dp   1  1 2 3  4  4  5  4  5  5  6  7  8  3
 
 
 */
