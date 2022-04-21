/*
 * @Description: 百练OJ 3750 魔兽世界
 * @Author: Xu Jiaming
 * @Date: 2022-04-21 11:28:59
 * @LastEditTime: 2022-04-21 11:59:05
 * @LastEditors:  
 * @FilePath: BLOJ3750.cpp
 */
#include<bits/stdc++.h>
using namespace std;
// 0:dragon,1:ninja,2:iceman,3:lion,4:wolf
struct headquarters
{
    int seq[5];
    int hp = 0;
    int tot_soldier = 0;
    int T_serial = 5;
}red,blue;
struct  soldier
{
    int hp,force;
    int id;
}s_class[5],red_s[100],blue_s[100];
int main()
{
    int T;
    scanf("%d",&T);
    red.seq[0]=2;red.seq[1]=3;red.seq[2]=4;red.seq[3]=1;red.seq[4]=0;
    blue.seq[0]=3;blue.seq[1]=0;blue.seq[2]=1;blue.seq[3]=2;blue.seq[4]=4;
    while(T--)
    {
        int m,n,t,hour= 0,minu = 0;
        scanf("%d%d%d",&m,&n,&t);
        for(int i = 0; i < 5; i++)
        {
            scanf("%d",&s_class[i].hp);
        }
        for(int i = 0; i < 5; i++)
        {
            scanf("%d",&s_class[i].force);
        }
        while(hour*60+minu < t)
        {
            minu = 0;
            // 武士降生
            if()
            red.tot_soldier++;
            red_s[red.tot_soldier] = 

        }
        
    }
}