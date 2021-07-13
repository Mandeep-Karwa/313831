#include<stdio.h>
#include<time.h>
#include"project.h"
int date(int yy,int mm,int dd)
{
    int correct_date;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);//stores the present date and time in the tm variable of data type tm
    if(yy>tm.tm_year+1900)//check whether the year given is more than the present year 
        {
            correct_date=-1;
            printf("You have entered the wrong date\n");
            return correct_date;;
        }
        else
        { 
            if(mm>tm.tm_mon+1&&yy==tm.tm_year+1900)//checks whether the month is more than the present month or not
            {
                correct_date=-1;
                printf("You have entered the wrong date\n");
                return correct_date;;
            }
            else
            {
                if(mm==tm.tm_mon+1&&yy==tm.tm_year&&dd>tm.tm_mday)//checks whether the date is more than the present date or not
                {
                    correct_date=-1;
                    printf("You have entered the wrong date\n");
                    return correct_date;;
                }
            }
        }
        if(mm==2)//checking for leap year condition date
        {
            if(dd<=29&&dd>=1&&yy%4==0)
            {
                correct_date=0;
                return correct_date;
            }
            else if(dd<=28&&dd>=1)
            {
                correct_date=0;
                return correct_date;
            }
            else
            {
                correct_date=-1;
                printf("You have entered the wrong date\n");
                return correct_date;;
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
                return correct_date;;
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
                return correct_date;;
            }
        }
        else 
        {
            correct_date=-1;
            printf("You have entered the wrong date\n");
            return correct_date;;
        }  
}