# 题目汇总
本文件夹下主要按照算法类型分类，每个子文件夹下有该类型题目的典型例题。



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
