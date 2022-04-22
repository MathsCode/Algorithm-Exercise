/*
 * @Description: ����OJ 3750 ħ������
 * @Author: Xu Jiaming
 * @Date: 2022-04-21 11:28:59
 * @LastEditTime: 2022-04-22 10:05:10
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
    int oppo_soldier = 0;
}red,blue;

struct  soldier
{
    int hp,force;
    int id;
    int loc = 0;
    char name;
    int status; // 0:live 1:dead;
}s_class[5],red_s[100],blue_s[100];

struct City
{
    int id;
    int hp = 0;
    char flag = 'n'; // r : red 1bblue,n:null
    int s_tot = 0;
    int id_red = 0;
    int id_blue = 0;
    char last_win = 'n'; // r:red,b:blue,n:null
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
        bool pd = true;
        for(int i = 1; i <= n; i++)
        {
            city[i].id = i;
        }
        while(hour*60+minu < t and pd)
        {
            minu = 0;
            // ��ʿ����
            if(red.hp >= s_class[red.tot_soldier % red.T_serial].hp)
            {
                red.tot_soldier++;
                red_s[red.tot_soldier].hp = s_class[red.tot_soldier % red.T_serial].hp;
                red_s[red.tot_soldier].force = s_class[red.tot_soldier % red.T_serial].force;
                red_s[red.tot_soldier].id = red.tot_soldier;
                red.hp -= s_class[red.tot_soldier % red.T_serial].hp;
                red_s[red.tot_soldier].name = s_name[red.tot_soldier % red.T_serial];
                red_s[red.tot_soldier].status = 0;
            }
            if(blue.hp >= s_class[blue.tot_soldier % blue.T_serial].hp)
            {
                blue.tot_soldier++;
                blue_s[blue.tot_soldier].hp = s_class[blue.tot_soldier % red.T_serial].hp;
                blue_s[blue.tot_soldier].force = s_class[blue.tot_soldier % red.T_serial].force;
                blue_s[blue.tot_soldier].id = blue.tot_soldier;
                blue_s[blue.tot_soldier].name = s_name[blue.tot_soldier % red.T_serial];
                blue.hp -= s_class[blue.tot_soldier % red.T_serial].hp;
                blue_s[blue.tot_soldier].status = 0;
            }

            //������ʿǰ��
            minu += 10;
            for(int i = 1; i <= red.tot_soldier&&red_s[i].status == 0; i++)
            {
                city[red_s[i].loc].s_tot--;
                city[red_s[i].loc].id_red = 0;
                red_s[i].loc++;
                if(red_s[i].loc <= n)
                {
                    city[red_s[i].loc].s_tot++;
                    city[red_s[i].loc].id_red = red_s[i].id;
                }
                if(red_s[i].loc == n+1)
                {
                    blue.oppo_soldier++;
                    if(blue.oppo_soldier == 2)
                    {
                        pd = false;
                    }
                }
            }
            for(int i = 1; i <= blue.tot_soldier&&blue_s[i].status == 0; i++) 
            {
                city[blue_s[i].loc].s_tot--;
                city[blue_s[i].loc].id_blue = 0;
                blue_s[i].loc--;
                if(blue_s[i].loc == 0)
                {
                    red.oppo_soldier++;
                    if(red.oppo_soldier == 2)
                    {
                        pd = false;
                    }
                }
            }
            // ���в�������Ԫ&&��ʿȡ������Ԫ
            minu += 10;
            for(int i = 1; i <= n; i++)
            {
                city[i].hp +=10;
            }
            minu += 10;
            for(int i = 1; i <= n; i++)
            {
                if(city[i].s_tot == 1)
                {
                    if(city[i].id_blue != 0)
                    {
                        blue.hp+=city[i].hp;
                        city[i].hp = 0;
                    }
                    else
                    {
                        red.hp+=city[i].hp;
                        city[i].hp = 0;
                    }
                }
            }
            vector<int> red_win_city,blue_win_city;
            //ս��&&��¼ս��ʤ����Ϣ
            for(int i = 1; i <= n; i++)
            {
                if(city[i].s_tot == 2)
                {
                    if(city[i].flag == 'r' || (city[i].flag == 'n'&&i % 2 == 1))
                    {
                        blue_s[city[i].id_blue].hp -= red_s[city[i].id_red].force;
                        if(blue_s[city[i].id_blue].hp <= 0)
                        {
                            red_win_city.push_back(i);
                            if(city[i].last_win =='r')
                            {
                                city[i].flag = 'r';
                            }
                            else
                            {
                                city[i].last_win = 'r';
                            }
                        }
                        else
                        {
                            red_s[city[i].id_red].hp -= blue_s[city[i].id_blue].force/2;
                            if(red_s[city[i].id_red].hp <= 0)
                            {
                                blue_win_city.push_back(i);
                                if(city[i].last_win == 'b')
                                {
                                    city[i].flag = 'b';
                                }
                                else
                                {
                                    city[i].last_win = 'b';
                                }
                            }
                        }
                    }
                    else
                    {
                        if(city[i].flag == 'b' ||(city[i].flag == 'n'&&i % 2 == 0))
                        {
                            red_s[city[i].id_red].hp -= blue_s[city[i].id_blue].force;
                            if(red_s[city[i].id_red].hp <= 0)
                            {
                                blue_win_city.push_back(i);
                                if(city[i].last_win=='b')
                                {
                                    city[i].flag = 'b';
                                }
                            }
                        }
                    }
                    
                }
            }
            

        }
        
    }
}