#include<stdio.h>
#include<time.h>
#include"project.h"
int date(int yy,int mm,int dd)
{
    int correct_date;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);//stores the present date and time in the tm variable of data type tm
    int sp,sg,v;
    sp=((yy*100)+mm)*100+dd;//givent date
    sg=((((tm.tm_year+1900)*100)+(tm.tm_mon+1))*100)+tm.tm_mday;//present day 
    if(sg-sp<0)//checks whether the date given is future or not
    {
        correct_date=-1;
        printf("You have entered the wrong date\n");
        return correct_date;
    }
        if(mm==2&&dd<=29&&dd>=1&&yy%4==0)//checking for leap year condition date
        {
                correct_date=0;
                return correct_date;
        }
            //}
            else if(dd<=28&&dd>=1&&yy%4!=0)
            {
                correct_date=0;
                return correct_date;
            }
            
            
        if((mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)&&dd<=31&&dd>=1)//check whether the date is valid for the month
        {
                correct_date=0;
                return correct_date;           
        }
        else if(mm>=1&&mm<=12&&dd<=30&&dd>=1&&mm!=2)
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