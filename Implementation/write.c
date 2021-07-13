#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include"project.h"
void write(char *username)
{
    //write a code to write data into file
    //but the expired date is important
    char product_name[151];//third column
    int s_no;//first column
    char *s;
    int correct_date=-1;
    int dd,mm,yy;
    char t[20];
    /*time_t T= time(NULL);
    struct  tm tm = *localtime(&T);//stores the present date and time in the tm variable of data type tm*/
    FILE *filepointer=NULL;
    filepointer=fopen(username,"r+");
    if(filepointer==NULL)
    {
        printf("There is an error in database");
        exit(0);
    }
    //used to get s_no
    while(fgets(t,sizeof(t),filepointer))
     {sscanf(s,"%d",&s_no);
         s=strtok(t,",");}
    s_no++;
    while(correct_date==-1)
    {
        printf("Please enter the expired day\n");
        scanf("%3d",&dd);
        printf("Please enter the expired month\n");
        scanf("%3d",&mm);
        printf("Please enter the expired year\n");
        scanf("%5d",&yy);
        correct_date=date(yy,mm,dd);
    }
    printf("enter product name\n");
    scanf("%150s",product_name);
    fprintf(filepointer,"\n %d,%d/%d/%d,%s,",s_no,dd,mm,yy,product_name);
}