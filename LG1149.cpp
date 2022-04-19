/*
 * @Description: Âå¹ÈP1149»ð²ñ°ôµÈÊ½
 * @Author: Xu Jiaming
 * @Date: 2022-04-19 15:26:40
 * @LastEditTime: 2022-04-19 16:51:25
 * @LastEditors:  
 * @FilePath: LG1149.cpp
 */
#include<bits/stdc++.h>
using namespace std;
int n;
int single[10] = {6,2,5,5,4,5,6,3,7,6};
vector<int> match[25],match_single[10],ans;


void search(int total,int now,int num)
{
    if(now == 0)
    {
        match[total].push_back(num);
        return;
    }
    for(int i = 1; i <= min(now,9); i++)
    {
        if(match_single[i].size() != 0)
        {
            for(int j = 0; j < match_single[i].size(); j++)
            {
                if(num != 0 || match_single[i][j]!=0) search(total,now-i,num*10+match_single[i][j]);
            }
        }
    }
    return;
}


void init()
{
    for(int i = 0; i < 10; i++)
    {
        match_single[single[i]].push_back(i);
    }
    match[6].push_back(0);
    for(int i = 1; i <= (n-4); i++)
    {
        search(i,i,0);
    }
}
int main()
{
    scanf("%d",&n);
    init();
    /*
    for(int i = 0; i <= n; i++)
    {
        printf("Num = %d\n",i);
        for(int j = 0; j < match[i].size(); j++) cout<<match[i][j]<<' ';
        cout<<endl;
    }
    */
    int tot = 0;
    for(int i = 1; i < (n-4); i++)
    {
        for(int j = 1; j < n-4-i; j++)
        {
            if(match[i].size()!=0&&match[j].size()!=0&&match[n-4-i-j].size()!=0)
            {
                for(int t1 = 0; t1 < match[i].size(); t1++)
                {
                    int num1 = match[i][t1];
                    for(int t2 = 0; t2 < match[j].size(); t2++)
                    {
                        int num2 = match[j][t2];
                        for(int t3 = 0; t3 < match[n-4-i-j].size(); t3++)
                        {
                            int num3 = match[n-4-i-j][t3];
                            if(num1 + num2 == num3)
                            {
                                //printf("%d %d %d\n",i,j,n-4-i-j);
                                //printf("%d+%d=%d\n",num1,num2,num3);
                                tot++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<tot;
}