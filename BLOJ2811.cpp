/*
 * @Description: Bailian P2811 œ®µ∆Œ Ã‚
 * @Author: Xu Jiaming
 * @Date: 2022-04-18 22:28:44
 * @LastEditTime: 2022-04-21 17:00:25
 * @LastEditors:  
 * @FilePath: BLOJ2811.cpp
 */

#include<bits/stdc++.h>
using namespace std;
int press[8][8],lamp[8][8],lamp_ori[8][8];
int dx[6]={-1,0,0,0,1},dy[6] = {0,-1,0,1,0};
void change(int x,int y)
{
    for (int i = 0; i <= 4; i++)
    {
        if((x+dx[i])>= 0 && (x+dx[i] <= 4)&&(y+dy[i])>=0&&(y+dy[i])<=5)
        {
            lamp[x+dx[i]][y+dy[i]] = !lamp[x+dx[i]][y+dy[i]];
        }
    }
}
void update(int row)
{
    for(int i = 0; i <= 5; i++)
    {
        if(press[row][i] == 1)
        {
            change(row,i);
        }
    }
}
bool check()
{
    for(int i = 0; i <= 5; i++)
    {
        if(lamp[4][i] == 1) return false;
    }
    return true;
}

int main()
{
    for(int i = 0; i <= 4; i++)
        for(int j = 0; j <= 5; j++)
            scanf("%d",&lamp_ori[i][j]);
    for(int i = 0; i < 64; i++)
    {
        for(int i = 0; i <= 4; i++)
            for(int j = 0; j <= 5; j++)
                lamp[i][j] = lamp_ori[i][j];
        memset(press,0,sizeof(press));
        int x = i;
        int now = 5;
        while(x > 0)
        {
            press[0][now] = x % 2;
            x /= 2;
            now--;
        }
        /*
        for(int k = 0; k <= 5; k++)
        {
            printf("%d ",press[0][k]);
        }
        printf("\n");
        */
        update(0);
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 0; k <= 5; k++)
            {
                if(lamp[j-1][k] == 1)
                {
                    press[j][k] = 1;
                }
            }
            update(j);
        }
        if(check())
        {
            for(int j = 0; j <= 4; j++)
            {
                for(int k = 0; k <= 5; k++)
                {
                    printf("%d ",press[j][k]);
                }
                printf("\n");
            }
            
        }
    }
}