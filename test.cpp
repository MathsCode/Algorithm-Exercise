/*
 * @Description: test.cpp
 * @Author: Xu Jiaming
 * @Date: 2022-04-22 16:10:39
 * @LastEditTime: 2022-05-07 20:10:19
 * @LastEditors:  
 * @FilePath: test.cpp
 */
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000+5];
int binary_search(int l,int r,int dst)
{
    int mid = (l+r)/2;
    if(a[mid] == dst)
    {
        return mid;
    }
    else
    {
        if(l >= r)
        {
            return -1;
        }
        else
        {
            if(dst > a[mid]) return binary_search(mid+1,r,dst);
            if(dst < a[mid]) return binary_search(l,mid-1,dst);
        }
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    bool pd = true;
    for(int i = 0; i < n; i++)
    {
        int t = binary_search(0,n-1,m-a[i]);
        if(t != -1)
        {
            pd = false;
            printf("%d %d",a[i],a[t]);
            break;
        }
    }
    if(pd)
    {
        printf("No Solution");
    }
}