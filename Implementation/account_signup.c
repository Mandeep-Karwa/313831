#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"project.h"
void signup(char *username)
{
    //write a code to signup create a new account
    //check whether the include usenames also as an username username exist or not if the username exist give him options and then exit
    //give threshold value to user length and password length
    char password[25];
    FILE *filepointer;
    char readfromfile[25];
    char *store;
    int found=0;
    char *s;
    s=NULL;
    filepointer=fopen("usernames.csv","r+"); 
    //check whether the append option is write or not and the remove the comment
    printf("Please enter the username and its length should be less than 20 and you cannot take the username as usernames\n");
    scanf("%22s",username);
    //code to check whether the user name exist and the length below 90
    printf("Please enter password and its length should be less than 20\n");
    scanf("%22s",password);
    //check the password length below 20
    while(strlen(password)>21)
    {
        printf("username length greater than 20\n");
        scanf("%22s",password);
    }
    //checking whether the username is unique
    found=-1; //to make the while loop run atleast once
    while(found==-1)
    { 
        //intialize the file pointer to start of the file
        fseek(filepointer,0,SEEK_SET);
        //reading the only first column of the file i.e. the only username and comparing it with the username given
        while(fgets(readfromfile,sizeof(readfromfile),filepointer))
        {   
            store=strtok(readfromfile,",");
            //printf("welcome");
            while(s!=NULL)//reading
        {
            s=strtok(NULL,",");
        }
            if(strcmp(store,username)==0)
            {   
                found=-1;
                break;//if the username is not unique or length more than 20 then found=-1 else found =0
            }
            else{
                found=0;
            }
        }
        if(found==-1)
        {
            printf("Choose different username as this username already exist or the  username length is above 20 and we will be not changing your password\n");
            scanf("%22s",username);
        }
        else{
           break;
        }
    }
    //write the username in the csv file
    //create the file name of the username
    fprintf(filepointer,"\n%s,%s,",username,password);
    fclose(filepointer);
    strcat(username,".csv");
    filepointer=fopen(username,"a+");
    fprintf(filepointer,"\n%d,",0);
    fclose(filepointer);
}