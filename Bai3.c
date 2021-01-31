#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "student.h"

typedef struct Student sinhvien;
void nhap(sinhvien *student)
{
printf("The name is: "); fflush(stdin); gets(student->name);
printf("The student ID is (Full format): "); scanf("%d",&(student->id));
printf("The student's score is: "); scanf("%lf",&(student->score));
FILE *fptr = fopen("SV2021.dat","ab");
fprintf(fptr,"%s\t\t\t\t",(student->name));
fprintf(fptr,"%d\t\t\t\t",(student->id));
fprintf(fptr,"%.2lf\n",(student->score));
fclose(fptr);
printf("Successfully add new student!\n");
}

void view()
{
FILE *fptr = fopen("SV2021.dat","rb");
char info;
while(1)
{
info = getc(fptr);
if(info==EOF) break;
printf("%c",info);
}
fclose(fptr);
}

void look_up()
{
FILE *fptr1 = fopen("SV2021.dat","rb"), *fptr2 = fopen("output.txt","w+");
char info[100],c[100];
fflush(stdin);
gets(c);
int found=0;
while(fgets(info,100,fptr1)!=NULL)
    if(strstr(info,c)!=NULL)
    {
        printf("%s",info);
        fprintf(fptr2,"%s",info);
        found=1;
    }
if (found==0) printf("Can't find the student!\n");
fclose(fptr1);
fclose(fptr2);
return 1;
}

int main()
{
while(1)
{
printf("Students managing program\n--------------------------\n");
printf("1. View list of students\n");
printf("2. Add student\n");
printf("3. Look up student by name\n");
printf("4. Exit\n");
int x;
scanf("%d",&x);
switch(x)
{
case(1):
{
view();
break;
}
case(2):
{
sinhvien newstudent;
nhap(&newstudent);
break;
}
case(3):
{
printf("Enter the name of the student you are looking for:");
look_up();
break;
}
case(4):
{
printf("Good bye!");
return 0;
}
}
}
return 0;
}
