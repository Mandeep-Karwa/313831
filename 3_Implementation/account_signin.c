/**
 * @file account_signin.c
 * @author Mandeep Karwa (mandeepkarwa9@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdlib.h>
#include<string.h>
#include"project.h"
void signin(char *username)
{ 
    //write code to signin
    char password[21];
    FILE *filepointer;
    char readfromfile[100];
    char *store;
    int found;
    char *s;
    filepointer=fopen("usernames.csv","r");
    //include usernames also as usernames so that he can't open the usernames file
    if(filepointer==NULL)
    {
        printf("There is some problem in your databse");
        exit(0);
    }
    printf("Please enter the username\n");
    scanf("%20s",username);
    printf("enter the password\n");
    scanf("%20s",password);
    //check whether the username and password is correct 
    found=-1;
    while(found==-1)
    { 
        //intialize the file pointer to start of the file
        fseek(filepointer,0,SEEK_SET);
        //reading the only first column of the file i.e. the only username and comparing it with the username given
        while(fgets(readfromfile,sizeof(readfromfile),filepointer))
        {
            store=strtok(readfromfile,",");
            if(strcmp(store,username)==0)//to check whether the username exist
            {
                found=0;//if the username is found then found =0 else found =-1
                //while(s!=NULL){
                    s=strtok(NULL,",");
                    if(strcmp(s,password)==0)//checks for the password
                    {
                      found=0;//if password is correct then found=0 else found=-1
                      break;
                    }
                    else{
                      found=-1;
                    }
                //}
                    
            }
            else//if the user name does not exist found=-1
            found=-1;
            if(found==0)
            {
                break;
            }
        }
        if(found==-1)
        {
            printf("Username or password is incorrect\n");
            printf("enter user name\n");
            scanf("%20s",username);
            printf("enter password\n");
            scanf("%20s",password);
        }
        else{
           break;
        }
    }
    strcat(username,".csv\0");
}
