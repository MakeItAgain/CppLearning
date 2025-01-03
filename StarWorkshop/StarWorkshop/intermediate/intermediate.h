//
//  Intermediate.h
//  StarWorkshop
//  
//  Created by Silhouette Of on 2024/10/18.
//
#ifndef INTERMEDIATE
#define INTERMEDIATE

/*const double PI = 3.1214926;*/ //程序中具体使用的数叫做常量，给常量取名字叫做符号常量，一般在主函数外面，见名知意
void Factorization();  //分解质因数，无参数无返回值

//冒泡排序
void bubbleSort(int arr[], int n);

// 桶排序， 在规定了最大数值以后，桶排序要比冒泡排序效率高
void bucketSort(int arr[], int n, int minValue, int maxVlaue);
#endif //INTERMEDIATE
