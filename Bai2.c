#include<stdio.h>

typedef struct Object
{
    char name;
    int weight;
    int value;
    float rating;
    int count;
} object;


int main()
{
    FILE *fptr = fopen("BAG.INP","r");
    int N,W;
    int i,j,max=0;
    fscanf(fptr,"%d %d",&N,&W);
    object A[N],tmp;
    for(i=0;i<N;i++)
    {
        fscanf(fptr,"%d %d %c",&A[i].weight,&A[i].value,&A[i].name);
        A[i].rating=(float) (A[i].value)/(A[i].weight);
    }
    fclose(fptr);
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        if(A[i].rating<A[j].rating)
        {
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    for(i=0;i<N;i++)
    {
        A[i].count=W/(A[i].weight);
        W-=(A[i].count)*(A[i].weight);
        max+=(A[i].count)*(A[i].value);
    }
    printf("%d\n",max);
    for(i=0;i<N;i++)
    {
        if(A[i].count!=0)
            printf("%d %c\n",A[i].count,A[i].name);
    }
    return 0;
}
