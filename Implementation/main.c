#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"
int main()
{
    int selected_no,options;
    char username[1000];
    selected_no=0;
    printf("Please select the option which you want to choose\n");
    // print options as given as in switch statement
    printf("1. Signin to your account\n");
    printf("2. Create an account\n");

    scanf("%d",&selected_no);
    for(options=3;options>0;options--)
    {
        switch(selected_no)
        {
            case 1:
            signin(username);
            options=0;
            break;
            case 2:
            signup(username);
            options=0;
            break;
            case 3:
            options=0;
            break;
            default:
            printf("please give valid input you have only %d options left\n",options);
            scanf("%d",&selected_no);
        }
    }
    
    if(options==0)
    {
        printf("You have given invalid input shutting down the system\n");
        exit(0);
    }
    
    printf("Do you want to do any opearions as given below\n");
    printf("1.Read your stock\n");
    printf("2.Add a new entry into your stock\n");
    //print the operations like notify read write
    
    scanf("%d",&selected_no);
    for(options=3;options>0;options--)
    {
        switch (selected_no)
        {
            case 1:
            read(username);
            options=0;
            break;
            case 2:
            write(username);
            options=0;
            break;
            default:
            printf("please give valid input you have only %d options left",options);
            scanf("%d",&selected_no);
            break;
        }
    }
    if(options==0)
    {
        printf("You have given invalid input shutting down the system\n");
        //give some delay
        exit(0);
    }

}