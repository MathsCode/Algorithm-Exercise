/*
 * @Description: 百练OJ 3750 魔兽世界
 * @Author: Xu Jiaming
 * @Date: 2022-04-21 11:28:59
 * @LastEditTime: 2022-04-21 20:53:52
 * @LastEditors:  
 * @FilePath: BLOJ3750.cpp
 */
#include<bits/stdc++.h>
using namespace std;

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
    int loc = 0;
    char name;
}s_class[5],red_s[100],blue_s[100];

struct City
{
    int id;
    int hp = 0;
    int flag = 0; // -1 : red 1:blue
    int s_tot = 0;
    int id_red = 0;
    int id_blue = 0;
}city[25];

char s_name[5]={'d','n','i','l','w'};
// 0:dragon,1:ninja,2:iceman,3:lion,4:wolf
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
        red.hp = m;
        blue.hp = m;

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
            if(red.hp >= s_class[red.tot_soldier % red.T_serial].hp)
            {
                red.tot_soldier++;
                red_s[red.tot_soldier].hp = s_class[red.tot_soldier % red.T_serial].hp;
                red_s[red.tot_soldier].force = s_class[red.tot_soldier % red.T_serial].force;
                red_s[red.tot_soldier].id = red.tot_soldier;
                red.hp -= s_class[red.tot_soldier % red.T_serial].hp;
                red_s[red.tot_soldier].name = s_name[red.tot_soldier % red.T_serial];
            }
            if(blue.hp >= s_class[blue.tot_soldier % blue.T_serial].hp)
            {
                blue.tot_soldier++;
                blue_s[blue.tot_soldier].hp = s_class[blue.tot_soldier % red.T_serial].hp;
                blue_s[blue.tot_soldier].force = s_class[blue.tot_soldier % red.T_serial].force;
                blue_s[blue.tot_soldier].id = blue.tot_soldier;
                blue_s[blue.tot_soldier].name = s_name[blue.tot_soldier % red.T_serial];
                blue.hp -= s_class[blue.tot_soldier % red.T_serial].hp;
            }

            //所有武士前进
            minu += 10;
            for(int i = 1; i <= red.tot_soldier; i++) red_s[i].loc++;
            for(int i = 1; i <= blue.tot_soldier; i++) blue_s[i].loc++;
            
            //

        }
        
    }
}