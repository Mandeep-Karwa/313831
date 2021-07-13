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
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);//stores the present date and time in the tm variable of data type tm
    FILE *filepointer=NULL;
    fopen_s(&filepointer,username,"r+");
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
        scanf("%d",&dd);
        printf("Please enter the expired month\n");
        scanf("%d",&mm);
        printf("Please enter the expired year\n");
        scanf("%d",&yy);
        if(yy>tm.tm_year+1900)//check whether the year given is more than the present year 
        {
            correct_date=-1;
            printf("You have entered the wrong date\n");
            continue;
        }
        else
        { 
            if(mm>tm.tm_mon+1&&yy==tm.tm_year+1900)//checks whether the month is more than the present month or not
            {
                correct_date=-1;
                printf("You have entered the wrong date\n");
                continue;
            }
            else
            {
                if(mm==tm.tm_mon+1&&yy==tm.tm_year&&dd>tm.tm_mday)//checks whether the date is more than the present date or not
                {
                    correct_date=-1;
                    printf("You have entered the wrong date\n");
                    continue;
                }
            }
        }
        if(mm==2)//checking for leap year condition date
        {
            if(dd<=29&&dd>=1&&yy%4==0)
            {
                correct_date=0;
            }
            else if(dd<=28&&dd>=1)
            {
                correct_date=0;
            }
            else
            {
                correct_date=-1;
                printf("You have entered the wrong date\n");
                continue;
            }
            
        }
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)//check whether the date is valid for the month
        {
            if(dd<=31&&dd>=1)
            {
                correct_date=0;
            }
            else
            {
                correct_date=-1;
                printf("You have entered the wrong date\n");
                continue;
            }
        }
        else if(mm>=1&&mm<=12)
        {
            if(dd<=30&&dd>=1)
            {
                correct_date=0;
            }
            else
            {
                correct_date=-1;
                printf("You have entered the wrong date\n");
                continue;
            }
        }
        else 
        {
            correct_date=-1;
            printf("You have entered the wrong date\n");
            continue;
        }  
    }
    printf("enter product name\n");
    scanf_s("%150s",product_name);
    fprintf(filepointer,"\n %d,%d/%d/%d,%s,",s_no,dd,mm,yy,product_name);
}