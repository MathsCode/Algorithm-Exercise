/*
 * @Description: 百练OJ 3750 魔兽世界
 * @Author: Xu Jiaming
 * @Date: 2022-04-21 11:28:59
 * @LastEditTime: 2022-04-22 21:53:58
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
    int oppo_id = 0;
}red,blue;

struct  soldier
{
    int hp,force;
    int id;
    int loc = 0;
    int name_id;
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
char all_name[5][10]={"dragon","ninja","iceman","lion","wolf"};
// 0:dragon,1:ninja,2:iceman,3:lion,4:wolf
int main()
{
    int T;
    scanf("%d",&T);
    red.seq[0]=2;red.seq[1]=3;red.seq[2]=4;red.seq[3]=1;red.seq[4]=0;
    blue.seq[0]=3;blue.seq[1]=0;blue.seq[2]=1;blue.seq[3]=2;blue.seq[4]=4;
    while(T--)
    {
        printf("Case:%d",T);
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
        while(hour*60+minu <= t && pd)
        {
            minu = 0;
            // 武士降生
            if(red.hp >= s_class[red.tot_soldier % red.T_serial].hp)
            {
                int now = red.seq[red.tot_soldier % red.T_serial];
                red.tot_soldier++;
                red_s[red.tot_soldier].hp = s_class[now].hp;
                red_s[red.tot_soldier].force = s_class[now].force;
                red_s[red.tot_soldier].id = red.tot_soldier;
                red.hp -= s_class[now].hp;
                red_s[red.tot_soldier].name_id = now;
                red_s[red.tot_soldier].status = 0;
                printf("%03d:%02d red %s %d born\n",hour,minu,all_name[now],red_s[red.tot_soldier].id);
            }
            if(blue.hp >= s_class[blue.tot_soldier % blue.T_serial].hp)
            {
                int now = blue.seq[blue.tot_soldier % red.T_serial];
                blue.tot_soldier++;
                blue_s[blue.tot_soldier].hp = s_class[now].hp;
                blue_s[blue.tot_soldier].force = s_class[now].force;
                blue_s[blue.tot_soldier].id = blue.tot_soldier;
                blue_s[blue.tot_soldier].name_id = now;
                blue.hp -= s_class[now].hp;
                blue_s[blue.tot_soldier].status = 0;
                printf("%03d:%02d blue %s %d born\n",hour,minu,all_name[now],blue_s[blue.tot_soldier].id);
            }

            //所有武士前进
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
                    //printf("%03d:%02d red %s %d marched to city %d with %d elements and force %d",hour,minu,all_name[red_s[i].name_id],red_s[i].loc,red_s[i].hp,red_s[i].force);
                }
                if(red_s[i].loc == n+1)
                {
                    //printf("%03d:%02d red %s %d reached blue headquarter with %d elements and force %d",hour,minu,all_name[red_s[i].name_id],red_s[i].loc,red_s[i].hp,red_s[i].force);
                    blue.oppo_soldier++;
                    if(blue.oppo_soldier == 2)
                    {
                        blue.oppo_id = i;
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
                        red.oppo_id = i
                        pd = false;
                    }
                }
            }

            if(red.oppo_soldier != 0)
            {
                printf("%03d:%02d blue %s %d reached red headquarter with %d elements and force %d",hour,minu,all_name[red_s[i].name_id],red_s[i].loc,red_s[i].hp,red_s[i].force);
            }
            for(int i = 1; i <= n; i++)
            {
                if(city[i].s_tot > 0)
                {
                    if(city[i].id_red != 0)
                    {
                        printf("%03d:%02d red %s %d marched to city %d with %d elements and force %d\n",hour,minu,all_name[red_s[city[i].id_red].name_id],city[i].id_red,i,red_s[city[i].id_red].hp,red_s[city[i].id_red].force);
                    }
                    if(city[i].id_blue != 0)
                    {
                        printf("%03d:%02d blue %s %d marched to city %d with %d elements and force %d\n",hour,minu,all_name[blue_s[city[i].id_blue].name_id],city[i].id_blue,i,blue_s[city[i].id_blue].hp,blue_s[city[i].id_blue].force);
                    }
                }
            }
            // 城市产生生命元
            minu += 10;
            for(int i = 1; i <= n; i++)
            {
                city[i].hp +=10;
            }
            
            // &&武士取走生命元
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
            //战斗&&记录战斗胜利信息
            minu += 10;
            for(int i = 1; i <= n; i++)
            {
                if(city[i].s_tot == 2)
                {
                    // 红方战士主动出击
                    if(city[i].flag == 'r' || (city[i].flag == 'n'&&i % 2 == 1))
                    {
                        blue_s[city[i].id_blue].hp -= red_s[city[i].id_red].force;
                        if(blue_s[city[i].id_blue].hp <= 0)
                        {
                            red_win_city.push_back(i);
                            blue_s[city[i].id_blue].status = 1;
                            city[i].s_tot--;
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
                            // 蓝方战士进行反击
                            red_s[city[i].id_red].hp -= blue_s[city[i].id_blue].force/2;
                            if(red_s[city[i].id_red].hp <= 0)
                            {
                                blue_win_city.push_back(i);
                                red_s[city[i].id_red].status = 1;
                                city[i].s_tot--;
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
                        // 蓝方战士主动出击
                        if(city[i].flag == 'b' ||(city[i].flag == 'n'&&i % 2 == 0))
                        {
                            red_s[city[i].id_red].hp -= blue_s[city[i].id_blue].force;
                            if(red_s[city[i].id_red].hp <= 0)
                            {
                                blue_win_city.push_back(i);
                                red_s[city[i].id_red].status = 1;
                                city[i].s_tot--;
                                if(city[i].last_win=='b')
                                {
                                    city[i].flag = 'b';
                                }
                                else
                                {
                                    city[i].last_win = 'b';
                                }
                            }
                            else
                            {
                                //红方战士进行反击
                                blue_s[city[i].id_blue].hp -= red_s[city[i].id_red].force/2;
                                if(blue_s[city[i].id_blue].hp <= 0)
                                {
                                    red_win_city.push_back(i);
                                    blue_s[city[i].id_blue].status = 1;
                                    city[i].s_tot--;
                                    if(city[i].last_win == 'r')
                                    {
                                        city[i].flag = 'r';
                                    }
                                    else
                                    {
                                        city[i].last_win = 'r';
                                    }
                                }
                            }
                        }
                    }
                    
                }
            }
            
            //战斗结束，进行战利品分配。
            //红方进行加血
            for(int i = 0; i < red_win_city.size() && red.hp >=8; i++)
            {
                red_s[city[red_win_city[i]].id_red].hp +=8 ;
                red.hp -= 8;
            }
            //蓝方进行加血
            for(int i = blue_win_city.size(); i >= 0 && blue.hp >= 8; i--)
            {
                blue_s[city[blue_win_city[i]].id_blue].hp += 8;
                blue.hp -= 8;
            }
            //红方收取战利品
            for(int i = 0; i < red_win_city.size(); i++)
            {
                red.hp += city[red_win_city[i]].hp;
                city[red_win_city[i]].hp = 0;
            }
            //蓝方收取战利品
            for(int i = 0; i < blue_win_city.size(); i++)
            {
                blue.hp += city[blue_win_city[i]].hp;
                city[blue_win_city[i]].hp = 0;   
            }
            
            // 司令部报告生命元数量
            
            minu += 10;
            hour += 1;
            minu = 0;
        }
        
    }
}