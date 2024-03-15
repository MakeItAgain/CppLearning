# 题目汇总
本文件夹下的习题主要按照算法类型分类，每个子文件夹下有该类型题目的典型例题，多数子文件夹都有自己的README文件，该文件列出了该种算法的基本思想或者常见答题模版。



int x = 12321;

int n = 0;

while(n!=0)
{
    int i = x % 10;
    n = n * 10 + i;
    x /= 10;
}

bool isHuiWen(string str)
{
    string str = "12321";
    int len = str.size();

    for(int i = 0; i < len/2; ++i)
    {
        if(str[i] != str[len-i-1]) return false;
    }
    return true;
}

bool 
