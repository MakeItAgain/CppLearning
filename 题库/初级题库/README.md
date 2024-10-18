



## 9.13 
1. 1089数字反转
```cpp
#include<iostream>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
 
	if (n < 0)
	{
		cout << '-';
		n = 0 - n;
	}
 
	while (n % 10 == 0)
	{
		n /= 10;
        //这里是为了避免反转后首数字为0的出现
	}
 
	while (n!=0)
	{
		cout << n % 10;
		n /= 10;
	}
 
}
```
2. 1090
```cpp
#include<iostream>
using namespace std;
int main()
{
	int m,k,s=0;
	cin >> m >>k;
 
	if(m%19!=0)
	{
		cout << "NO";
		return 0;
	}
 
	while(m/10!=0)
	{	
		if(m%10==3)
		{
			s++;
		}
		m=m/10;
	}
	if(m==3)s++;
 
	if(s==k)
		cout << "YES";
	else cout << "NO";
 
    return 0;
}
```
3. 2033阶乘之和
```cpp

```


## 9.20

1. 1096：数字统计
```cpp
#include<iostream>
int main() {
	int n,m;
	cin >> n >>m;
	int count = 0;
	for (int i = n; i <= m; i++) {
		for (int j = i; j > 0; j /= 10) {
			if (j % 10 == 2)count++;
		}
	}
	cout << count;
	return 0;
}
```

2. 1100：金币
```cpp
#include <iostream>
 
using namespace std;
 
int main()
{
    int a,b,c;
    b=0;
    cin>>a;
    c=0;
    for(int i=1;i<=a;i++)   // 金币数目 
    {  
         for(int j=1;j<=i;j++)
         {
             c=c+1;    // 天数
             b=b+i;     //金钱数目
             if(c==a)
             {
                 cout<<b;
             }
         }
        
    }
  
    return 0;
}
```