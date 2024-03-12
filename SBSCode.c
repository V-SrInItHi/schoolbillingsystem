#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct dat {
 int d,m;
};
int clscanf();
struct student {
 struct dat dt;
 float f,fine,tot,adv,due;
 char n[50];
 int r,c;
} stud,s;
struct teacher {
 struct dat dt;
 char n[50];
 float sal,adv,tot;
 int id,no;
} tech,t;
int chkdat(int
,int);
void addrec(int);
void modrec(int
)
;
void searchrec(int);
void delrec(int);
void salary(int);
FILE *fs,*ft;
int mm,dd;
void ext();
void main(void
)
{
 int i,j,k;
 for(i=
0; i<80; i++)

{
 printf(
"
\
xdb");

}
 printf(
"
\
n
");
 for(i=
0; i<80; i++)

{
 printf(
"
\
xdb");

}

 for(i=
0; i<
5; i++)

{
 printf("."
)
;

}
 getch();
 system("cls");
 printf(
"
\
n
");
 for(i=
0; i<80; i++)
5 SOURCE CODE
8
 {
 printf("\xdb");
 }
 system("color 6b");
 printf("\n\n\t** WELCOME TO C PROGRAM SCHOOL BILLING SYSTEM PROJECT **\n\n\n");
 for(i=0; i<80; i++)
 {
 printf("\xdb");
 }
 printf("\nPLEASE ENTER ANY KEY TO START\n");
 for(i=0; i<5; i++)
 {
 printf(".");
 Sleep(500);
 }
 fflush(stdin);
 getch();
 system("cls");
 system("color 0f");
 printf("\n\t\tPLEASE ENTER CURRENT DATE\nmm dd\n ");
 scanf("%d%d",&mm,&dd);
 mm=chkdat(mm,dd);
 start();
}
void start()
{
 int i,j;
 system("cls");
 printf("\n\t\tPLEASE ENTER ACCOUNT TYPE");
 printf("\n\t\t1:: Student");
 printf("\n\t\t2:: Teachers and Staffs");
 printf("\n\t\t3:: Exit");
 printf("\n\t\tAccount type choice ");
 fflush(stdin);
 scanf("%d",&j);
 switch (j)
 {
 case 3:
 ext();
 case 1:
 {
 system("cls");
 printf("\n\t\tPLEASE ENTER THE CHOICE");
 printf("\n\t\t1:: Add record");
 printf("\n\t\t2:: Search record");
 printf("\n\t\t3:: Modify record");
 printf("\n\t\t4:: Delete record");
 printf("\n\t\t5:: Calculate fee");
 printf("\n\t\t6:: Exit");
 printf("\n\n Enter choice ");
 fflush(stdin);
 scanf("%d",&i);
 switch (i)
 {
 case 1:
 addrec(j);
 start();
9
 case 2:
 searchrec(j);
 start();
 case 3:
 modrec(j);
 start();
 case 4:
 delrec(j);
 start();
 case 5:
 fee(mm);
 start();
 case 6:
 ext();
 default :
 {
 printf("\n\n\tInvalid entry!!");
 printf("\n\nTo Account Type\n\n\t");
 system("pause");
 start();
 }
 }
 }
 case 2:
 {
 system("cls");
 printf("\n\t\tPLEASE ENTER THE CHOICE");
 printf("\n\t\t1:: Add record");
 printf("\n\t\t2:: Search record");
 printf("\n\t\t3:: Modify record");
 printf("\n\t\t4:: Delete record");
 printf("\n\t\t5:: Calculate Salary");
 printf("\n\t\t6:: Exit");
 printf("\n\n Enter choice ");
 fflush(stdin);
 scanf("%d",&i);
 switch (i)
 {
 case 1:
 addrec(j);
 start();
 case 2:
 searchrec(j);
 start();
 case 3:
 modrec(j);
 start();
 case 4:
 delrec(j);
 case 5:
 salary(mm);
 start();
 case 6:
 ext();
 default :
 {
 printf("\n\n\tInvalid entry!!");
10
 printf("\n\nTo Account Type\n\n\t");
 system("pause");
 start();
 }
 }
 }
 default :
 {
 printf("\n\n\tInvalid entry!!");
 printf("\n\nTo Account Type\n\n\t");
 system("pause");
 start();
 }
 }
}
void addrec(int j)
{
 int dif,cdat,ddat,month=0;
 float ff;
 char c='y';
 if (j==1)
 {
 while(c=='y'||c=='Y')
 {
 int a=1;
 printf("\n\nEnter the name of student: ");
 fflush(stdin);
 scanf("%[^\n]",stud.n);
 printf("\nEnter the class: ");
 fflush(stdin);
 stud.c=clscanf();
 printf("\nEnter the Roll No.:");
 fflush(stdin);
 scanf("%2d",&stud.r);
 printf("\nEnter month and day till which fee is paid:");
 fflush(stdin);
 scanf("%2d%2d",&cdat,&ddat);
 cdat=chkdat(cdat,ddat);
 stud.dt.m=cdat;
 ff=stud.c/10.0;
 stud.f=1000*(1+ff);
 dif=mm-stud.dt.m;
 stud.fine=(dif*stud.f)*1/100;
 stud.due=(dif)*stud.f;
 if(dif==1)
 {
 stud.tot=stud.f;
 stud.fine=0;
 }
 else
 {
 stud.tot=stud.fine+stud.due;
 }
 fs=fopen("student","ab+");
 fwrite(&stud,sizeof(stud),1,fs);
11
 fclose(fs);
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
 }
 if (j==2)
 {
 while(c=='y'||c=='Y')
 {
 int a=1;
 printf("\n\nEnter name of teacher/staff:" );
 fflush(stdin);
 scanf("%[^\n]",tech.n);
 printf("\nEnter teacher/staff id: ");
 fflush(stdin);
 scanf("%d",&tech.id);
 printf("\nEnter number of class/shift per month:: ");
 scanf("%d",&tech.no);
 fflush(stdin);
 printf("\nEnter month and day till which salary is paid::");
 scanf("%d %d",&tech.dt.m,&tech.dt.d);
 cdat=chkdat(cdat,ddat);
 tech.dt.m=cdat;
 tech.sal=tech.no*500;
 tech.adv=(tech.dt.m-mm-1)*tech.sal;
 if (tech.adv<0) tech.adv=0;
 tech.tot=tech.sal;
 ft=fopen("teacher","ab+");
 fwrite(&tech,sizeof(tech),1,ft);
 fclose(ft);
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 fflush(stdin);
 printf("\n\n");
 system("pause");
 }
}
void searchrec(int j)
{
 char name[50],namet[50];
 int a=1,choice;
 char c='y';
 if (j==1)
 {
 while(c=='y'||c=='Y')
 {
 int a=1;
 printf("\n\n\t\tPLEASE CHOOSE SEARCH TYPE::");
 printf("\n\n\t\t1::Search by name::");
 printf("\n\n\t\t2::Search by class::");
 printf("\n\n\t\t3::Search by rollno::");
 printf("\n\n\t\t4::Exit");
12
 printf("\n\n\t\t::Enter your choice:: ");
 fflush(stdin);
 scanf("%d",&choice);
 if (choice==1)
 {
 a=1;
 printf("\n\nEnter name of student to search: ");
 fflush(stdin);
 scanf("%[^\n]",name);
 fs=fopen("student","rb");
 while(fread(&stud,sizeof(stud),1,fs)==1)
 {
 if (strcmpi(name,stud.n)==0)
 {
 a=0;
 printf("\nname = %s",stud.n);
 printf("\nclass = %d",stud.c);
 printf("\nroll no = %d",stud.r);
 printf("\nmonthy fee =%.2f",stud.f);
 printf("\nlast fee paid in month =%2d",stud.dt.m);
 printf("\n due=%.2f",stud.due);
 printf("\n fine=%.2f",stud.fine);
 printf("\n total=%.2f\n\n",stud.tot);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(fs);
 }
 else if (choice==2)
 {
 int cl;
 a=1;
 printf("\n\nEnter class of student to search: ");
 fflush(stdin);
 cl=clscanf();
 fs=fopen("student","rb");
 while(fread(&stud,sizeof(stud),1,fs)==1)
 {
 if (stud.c==cl)
 {
 a=0;
 printf("\nname = %s",stud.n);
 printf("\nclass = %d",stud.c);
 printf("\nroll no = %d",stud.r);
 printf("\nmonthy fee =%.2f",stud.f);
 printf("\nlast fee paid in month =%2d",stud.dt.m);
 printf("\n due=%.2f",stud.due);
 printf("\n fine=%.2f",stud.fine);
 printf("\n total=%.2f",stud.tot);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
13
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(fs);
 }
 else if (choice==3)
 {
 int rll;
 a=1;
 printf("\n\nEnter roll of student to search: ");
 fflush(stdin);
 rll=clscanf();
 fs=fopen("student","rb");
 while(fread(&stud,sizeof(stud),1,fs)==1)
 {
 if (strcmpi(name,stud.n)==0)
 {
 a=0;
 printf("\nname = %s",stud.n);
 printf("\nclass = %d",stud.c);
 printf("\nroll no = %d",stud.r);
 printf("\nmonthy fee =%.2f",stud.f);
 printf("\nlast fee paid in month =%2d",stud.dt.m);
 printf("\n due=%.2f",stud.due);
 printf("\n fine=%.2f",stud.fine);
 printf("\n total=%.2f",stud.tot);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(fs);
 }
 else if(choice==4)
 {
 ext();
 }
 else
 {
 printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
 system("pause");
 searchrec(1);
 }
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
 }
 if (j==2)
 {
 while(c=='y'||c=='Y')
 {
 int a=1;
 printf("\n\nname of teacher/staff to search: ");
14
 fflush(stdin);
 scanf("%[^\n]",namet);
 ft=fopen("teacher","rb");
 while(fread(&tech,sizeof(tech),1,ft)==1)
 {
 if (strcmp(namet,tech.n)==0)
 {
 a=0;
 printf("\nname = %s",tech.n);
 printf("\nteacher/staff id = %d",tech.id);
 printf("\nmonth till when salary is paid =%d",tech.dt.m);
 printf("\nmonthy salary = %.2f",tech.sal);
 printf("\nadvance paid = %.2f",tech.adv);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(ft);
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
 }
}
void modrec(int j)
{
 char name[50];
 int a=1,choice,cl,rolno;
 char c='y';
 if (j==1)
 {
 while(c=='y'||c=='Y')
 {
 printf("\n\n\t\tPLEASE CHOOSE MODIFY TYPE::");
 printf("\n\n\t\t1::Modify by name::");
 printf("\n\n\t\t2::Modify by name &class::");
 printf("\n\n\t\t3::Modify by name,class & rollno::");
 printf("\n\n\t\t4::Exit");
 printf("\n\n\t\t::Enter your choice:: ");
 fflush(stdin);
 scanf("%d",&choice);
 if (choice==1)
 {
 int a=0;
 printf("\n\nenter name of student to modify: ");
 fflush(stdin);
 scanf("%[^\n]",name);
 fs=fopen("student","rb+");
 while(fread(&stud,sizeof(stud),1,fs)==1)
 {
15
 a=1;
 if (strcmpi(name,stud.n)==0)
 {
 a=0;
 printf("\nenter new name of student: ");
 fflush(stdin);
 scanf("%[^\n]",stud.n);
 printf("\nenter new class of student: ");
 fflush(stdin);
 stud.c=clscanf();
 printf("\nenter new roll of student: ");
 fflush(stdin);
 scanf("%d",&stud.r);
 fseek(fs,-sizeof(stud),SEEK_CUR);
 fwrite(&stud,sizeof(stud),1,fs);
 fclose(fs);
 }
 }
 if (a==1)
 printf("\n\nRECORDS NOT FOUND");
 else
 printf("\n\nRECORDS SUCCESSFULLY MODIFIED");
 printf("\n\n");
 system("pause");
 }
 else if (choice==2)
 {
 int a=0;
 printf("\n\nenter name of student to modify: ");
 fflush(stdin);
 scanf("%[^\n]",name);
 printf("\n\nenter class of student to modify: ");
 fflush(stdin);
 cl=clscanf();
 fs=fopen("student","rb+");
 while(fread(&stud,sizeof(stud),1,fs)==1)
 {
 a=1;
 if (strcmpi(name,stud.n)==0 && cl==stud.c)
 {
 a=0;
 printf("\nenter new name of student: ");
 fflush(stdin);
 scanf("%[^\n]",stud.n);
 printf("\nenter new class of student: ");
 fflush(stdin);
 stud.c=clscanf();
 printf("\nenter new roll of student: ");
 fflush(stdin);
 scanf("%d",&stud.r);
 fseek(fs,-sizeof(stud),SEEK_CUR);
 fwrite(&stud,sizeof(stud),1,fs);
 fclose(fs);
 }
 }
 if (a==1)
 printf("\n\nRECORDS NOT FOUND");
16
 else
 printf("\n\nRECORDS SUCCESSFULLY MODIFIED");
 printf("\n\n");
 system("pause");
 }
 else if (choice==3)
 {
 int a=0;
 printf("\n\nenter name of student to modify: ");
 fflush(stdin);
 scanf("%[^\n]",name);
 printf("\n\nenter class of student to modify: ");
 fflush(stdin);
 cl=clscanf();
 printf("\n\nenter roll of student to modify: ");
 fflush(stdin);
 scanf("%d",&rolno);
 fs=fopen("student","rb+");
 while(fread(&stud,sizeof(stud),1,fs)==1)
 {
 a=1;
 if (strcmpi(name,stud.n)==0 && cl==stud.c &&rolno==stud.r)
 {
 a=0;
 printf("\nenter new name of student: ");
 fflush(stdin);
 scanf("%[^\n]",stud.n);
 printf("\nenter new class of student: ");
 fflush(stdin);
 stud.c=clscanf();
 printf("\nenter new roll of student: ");
 fflush(stdin);
 scanf("%d",&stud.r);
 fseek(fs,-sizeof(stud),SEEK_CUR);
 fwrite(&stud,sizeof(stud),1,fs);
 fclose(fs);
 }
 }
 if (a==1)
 printf("\n\nRECORDS NOT FOUND");
 else
 printf("\n\nRECORDS SUCCESSFULLY MODIFIED");
 printf("\n\n");
 system("pause");
 }
 else if (choice==4) ext();
 else
 {
 printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
 system("pause");
 modrec(1);
 }
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
17
 getch();
 }
 if (j==2)
 {
 while(c=='y'||c=='Y')
 {
 int a=1;
 printf("enter name of teacher to modify: ");
 fflush(stdin);
 scanf("%[^\n]",name);
 ft=fopen("teacher","rb+");
 while(fread(&tech,sizeof(tech),1,ft)==1)
 {
 if (strcmpi(name,tech.n)==0)
 {
 a=0;
 printf("\nenter new name of teacher: ");
 fflush(stdin);
 scanf("%[^\n]",tech.n);
 printf("\nenter new id of teacher: ");
 fflush(stdin);
 scanf("%d",&tech.id);
 fseek(ft,-sizeof(tech),SEEK_CUR);
 fwrite(&tech,sizeof(tech),1,ft);
 fclose(ft);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 else
 printf("\n\nRECORD SUCCESSFULLY MODIFIED");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
 }
}
void delrec(int j)
{
 int a=1;
 char name[50],c='y';
 if (j==1)
 {
 while(c=='y'||c=='Y')
 {
 int a=1;
 printf("\n\nenter name of student to delete: ");
 fflush(stdin);
 scanf("%[^\n]",name);
18
 fs=fopen("student","rb");
 temp=fopen("tempfile","wb");
 while (fread(&stud,sizeof(stud),1,fs)==1)
 {
 if (strcmp(stud.n,name)==0)
 {
 a=0;
 continue;
 }
 else
 {
 fwrite(&stud,sizeof(stud),1,temp);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 else
 printf("\n\nRECORD SUCCESSFULLY DELETED");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(fs);
 fclose(temp);
 system("del student");
 system("ren tempfile, student");
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
 }
 if (j==2)
 {
 a=1;
 char namet[50];
 while(c=='y'||c=='Y')
 {
 printf("\n\nEnter name of teacher to delete record: ");
 fflush(stdin);
 scanf("%[^\n]",namet);
 ft=fopen("teacher","rb");
 t1=fopen("tempfile1","wb");
 while (fread(&tech,sizeof(tech),1,ft)==1)
 {
 if (strcmp(tech.n,namet)==0)
 {
 a=0;
 continue;
 }
 else
 {
 fwrite(&tech,sizeof(tech),1,t1);
 }
 }
19
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 else
 printf("\n\nRECORD SUCCESSFULLY DELETED");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(ft);
 fclose(t1);
 system("del teacher");
 system("ren tempfile1, teacher");
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
 }
}
void salary(int mm)
{
 int a=1,day;
 char name[50],c='y';
 int month,dif,id;
 while(c=='y'||c=='Y')
 {
 int a=1;
 fflush(stdin);
 printf("\n\nEnter name:: ");
 scanf("%[^\n]",name);
 printf("\n\nEnter ID:: ");
 scanf("%d",&id);
 f=fopen("teacher","rb+");
 t=fopen("te","wb+");
 while(fread(&tech,sizeof(tech),1,f)==1)
 {
 if(strcmp(tech.n,name)==0 )
 {
 float lsal;
 a=0;
 printf("\n\nEnter the month till which salary is to be paid:: ");
 fflush(stdin);
 scanf("%d",&month);
 month=chkdat(month,day);
 tech.adv=(month-mm-1)*tech.sal;
 if (tech.adv<0) tech.adv=0;
 lsal=mm-tech.dt.m;
 if(lsal<0) lsal=0;
 tech.tot=tech.adv+tech.sal*(1+lsal);
 if(month==tech.dt.m) tech.tot=0;
 printf("\nmonthy salary left to be paid:: %.2f",lsal);
 printf("\ntotal :: %.2f",tech.tot);
 printf("\nadvance :: %.2f",tech.adv);
 tech.dt.m=month;
 fwrite(&tech,sizeof(tech),1,t);
 fclose(f);
20
 fclose(t);
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 system("del teacher");
 system("ren te, teacher");
 }
 }
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
}
 int a=0;
 char name[50],c='y';
 int clas, roll,month,dif;
 while(c=='y'||c=='Y')
 {
 int a=1,day=0;
 fflush(stdin);
 printf("\n\nEnter name:: ");
 scanf("%[^\n]",name);
 printf("\n\nEnter class:: ");
 fflush(stdin);
 clas=clscanf();
 printf("\n\nEnter roll:: ");
 fflush(stdin);
 scanf("%d",&roll);
 f=fopen("student","rb+");
 t=fopen("te","wb");
 while(fread(&stud,sizeof(stud),1,f)==1)
 {
 if(strcmp(stud.n,name)==0 && clas==stud.c && roll==stud.r)
 {
 a=0;
 printf("\n\nEnter the month till which fee to be paid:: ");
 fflush(stdin);
 scanf("%d",&month);
 month=chkdat(month,day);
 dif=mm-stud.dt.m;
 stud.fine=(dif*stud.f)*0.01;
 stud.due=(dif)*stud.f;
 if (stud.fine<0) stud.fine=0;
 if (stud.due<0) stud.due=0;
 if (stud.tot<0) stud.tot=0;
 stud.tot=stud.fine+stud.due+stud.adv;
 printf("\nfine :: %.2f",stud.fine);
 printf("\ndue :: %.2f",stud.due);
 printf("\ntotal :: %.2f",stud.tot);
 printf("\nadvance :: %.2f",stud.adv);
 stud.dt.m=month;
 stud.tot=0;
 stud.fine=0;
21
 stud.due=0;
 fwrite(&stud,sizeof(stud),1,t);
 }
 }
 if (a==1)
 printf("\n\nRECORD NOT FOUND");
 printf("\n\n");
 system("pause");
 fflush(stdin);
 fclose(f);
 fclose(t);
 system("del student");
 system("ren te, student");
 printf("\n\nDo you want to continue with the process(press y or Y");
 fflush(stdin);
 c=getch();
 }
 getch();
}
void ext()
{
 int i;
 printf("\n\n\t\t\t Exiting\n\n");
 for(i=1; i<=80; i++)
 exit(0);
}
int chkdat(int mnt,int dnt)
{
 int mon,day;
 if (mnt>12 || mnt<1 || dnt<1 || dnt>32)
 {
 MessageBox(0,"Invalid Date!\nEnter Again","Error!",0);
 fflush(stdin);
 scanf("%d%d",&mon,&day);
 mon=chkdat(mon,day);
 }
 else
 return (mnt);
}
int clscanf()
{
 int mnt,mon;
 fflush(stdin);
 scanf("%d",&mnt);
 if (mnt>12 ||mnt<1)
 {
 MessageBox(0,"Invalid Class!\nEnter Class","Error!!",0);
 fflush(stdin);
 mon=clscanf();
 }
 else
 return mnt;
}
