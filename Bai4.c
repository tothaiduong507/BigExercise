#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main()
{
int i,j,count,a,x;
srand(time(NULL));
char chat[4][5]={"Ro","Co","Bich","Tep"};
char so[13][3]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
bool c[13][4];
bool tuquy[13][4];
for(i=0;i<13;i++)
for(j=0;j<4;j++)
{
c[i][j]=false;
tuquy[i][j]=false;
}
for(a=0;a<4;a++)
{
printf("Bai tren tay nguoi choi thu %d la: \n",a+1);
for(count=0;count<13;count++)
{
x=rand()%52;
if(c[x/4][x%4]==false)
{
c[x/4][x%4]=true;
tuquy[x/4][x%4]=true;
}
else
{
while(c[x/4][x%4]==true)
{
if(x==51) x=0;
else x++;
}
c[x/4][x%4]=true;
tuquy[x/4][x%4]=true;
}
printf("%s %s \n",so[x/4],chat[x%4]);
}
{
for (x=0;x<52;x=x+4)
if (tuquy[x/4][x%4]==tuquy[x/4][x%4 +1]&&tuquy[x/4][x%4 +1]==tuquy[x/4][x%4 + 2]&&tuquy[x/4][x%4 + 2]==tuquy[x/4][x%4+3]&&tuquy[x/4][x%4+3]==true)
printf("Nguoi choi thu %d co tu quy %s\n", a+1, so[x/4]);
for (i=0;i<13;i++)
for (j=0;j<4;j++)
tuquy[i][j] = false;
}
}
return 0;
}
