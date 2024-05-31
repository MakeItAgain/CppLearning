#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



struct Patient
{
    string id; // bianhao
    int age; //年龄 
    int idx; //次序
};
// 
bool compare(Patient & p1, Patient & p2)
{
    if((p1.age <= 60 && p2.age <= 60 )|| p1.age == p2.age)
        return p1.idx < p2.idx;
    else return p1.age > p2.age;

}
int main()
{
    int n;
    cin >>n;
    vector<Patient> patients(n);//
    for (int i = 0; i < n; i++)
    {
        cin >> patients[i].id;
        cin >> patients[i].age;
        patients[i].idx = i;
    }
    
    sort(patients.begin(), patients.end(), compare);// 如果patients是c++数组，那么应该写成sort(patients, patients + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << patients[i].id <<endl;
    }
    
    return 0;
}

















struct Client
{
    string id;
    int age;
    int index;
    /* data */
};
/*
cmp函数怎么写？
1. 返回值为bool类型
2. 接受两个待排序数组的元素类型
3. 函数中返回的类型应为：在a和b两个参数在什么样的情况下使得a和b在最终的数组中，a在前b在后是合理的
*/
bool cmp(Client c1, Client c2)  
{
    if((c1.age <= 60 && c2.age <=60) ||c1.age == c2.age)
    {
        return c1.index < c2.index;
    }
    else 
        return c1.age > c2.age;
}
int main()
{
    int n;
    cin>>n;
    vector<Client> clients(n);
    for(int i = 0; i< n;i++)
    {
        cin >> clients[i].id >> clients[i].age;
        clients[i].index = i;
    }
    sort(clients.begin(), clients.end(),cmp);
    for (int i = 0; i < n; i++)
    {
        cout << clients[i].id << endl;
    }
    
    return 0;
}