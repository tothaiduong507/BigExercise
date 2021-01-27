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
printf("The student's score is: "); scanf("%.2lf",&(student->score));
FILE *fptr = fopen("student.dat","ab");
fprintf(fptr,"%s\t\t\t\t",(student->name));
fprintf(fptr,"%s\t\t\t\t",(student->id));
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
sinhvien *newstudent;
nhap(newstudent);
break;
}
case(4):
{
return 0;
}
}
}
}
