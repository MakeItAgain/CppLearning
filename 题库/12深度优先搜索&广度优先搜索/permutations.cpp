#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    int ans=0,sum=0,t=0;//ans表示移动次数，t表示要移动的牌数
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)//输入数据
    {
        cin>>a[i];
        sum+=a[i];
    }
    int avg=sum/n;//求平均值
    for(int i=0;i<n-1;i++)//遍历每个牌堆（到最后一堆牌数一定等于平均值）
    {
        if(a[i]+t!=avg)//如果这个牌堆收到移动过来的牌后牌数不等于平均值，就需要移动
        {
            t=a[i]+t-avg;//计算移动的牌数，或正或负。
            ans++;//移动移动次数加一
        }
        else
        {
            t=0;//不用移动就是移动0张且次数不变
        }

    }
    cout<<ans<<endl;
    return 0;
}