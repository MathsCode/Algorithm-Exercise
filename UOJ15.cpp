/*
 * @Description: UOJ #15【NOIP2014】生活大爆炸版石头剪刀布
 * @Author: Xu Jiaming
 * @Date: 2022-04-19 20:44:32
 * @LastEditTime: 2022-04-19 21:23:25
 * @LastEditors:  
 * @FilePath: UOJ15.cpp
 */
#include<bits/stdc++.h>
using namespace std;
int result[5][5]={{0,0,1,1,0},
                  {1,0,0,1,0},
                  {0,1,0,0,1},
                  {0,0,1,0,1},
                  {1,1,0,0,0}};
int A[205],B[205];
int main()
{
    int na,nb,n;
    scanf("%d%d%d",&n,&na,&nb);
    for(int i = 0; i < na; i++) scanf("%d",&A[i]);
    for(int i = 0; i < nb; i++) scanf("%d",&B[i]);
    int tota=0,totb=0;
    for(int i = 0; i <= n-1; i++)
    {
        tota += result[A[i%na]][B[i%nb]];
        totb += result[B[i%nb]][A[i%na]];
        //printf("%d %d %d\n",A[i%na],B[i%nb],result[A[i%na]][B[i%nb]]);
    }
    cout<<tota<<' '<<totb;
}