#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"
int main()
{
    int selected_no,options;
    char username[1000];
    printf("Please select the option which you want to choose\n1. Signin to your account\n2. Create an account\n");
    scanf("%d",&selected_no);
    for(options=3;options>0;options--)
    {
        if(selected_no==1)
        signin(username);
        else if(selected_no==2)
        signup(username);
        else
        {
            printf("please give valid input you have only %d options left\n",options);
            scanf("%d",&selected_no);
            continue;
        }
        break;
    }
    if(selected_no==2)
    {
        printf("You are left with only one option that is write in your databse\n1.Write your first entry in your databse\nIf you select other options you will be logged out\n");
        scanf("%d",&selected_no);
        if(selected_no==1)
            write(username);
        else
        {
            goto shutdown;
        }
    }
    if(options==0)
    {
        shutdown:printf("You have given invalid input shutting down the system\n");
        exit(0);
    }
    printf("Do you want to do any opearions as given below\n1.Read your stock\n2.Add a new entry into your stock\n");
    scanf("%d",&selected_no);
    for(options=3;options>0;options--)
    {
        if(selected_no==1)
        read(username);
        else if(selected_no==2)
        write(username);
        else
        {
            printf("please give valid input you have only %d options left\n",options);
            scanf("%2d",&selected_no);
            continue;
        }
        break;
    }
    if(options==0)
    {
        goto shutdown;
    }
}