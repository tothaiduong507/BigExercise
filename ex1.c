#include <stdio.h>
#include <stdlib.h>

#define ull unsigned long long int
ull combination(ull n,ull k)
{
    if (k==0||k==n)
        return 1;
    if (k==1)
        return n;
    int result=combination(n-1,k)+combination(n-1,k-1);
    return result;
}
int main()
{
    FILE *input_file,*output_file;
    input_file = fopen("TOHOP.INP.txt", "r");
    output_file = fopen("TOHOP.OUT.txt", "w+");
    if(input_file==NULL||output_file==NULL)
    {
    printf("Error! Can't open file!");
    exit(1);
    }
    int num1;
    int num2;

    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF)
    {
        ull *result;
        result = (ull *)malloc(sizeof(ull));
        *result=combination(num1,num2);
        fprintf(output_file, "%llu \n", *result);
        free(result);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Done !");
    return 0;
}
