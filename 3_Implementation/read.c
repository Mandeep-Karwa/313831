/**
 * @file read.c
 * @author Mandeep Karwa (mandeepkarwa9@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"
void read(char *username)
{
    FILE *fp=NULL;
    char t[680];
    char *s;
    s=NULL;
    fp=fopen(username,"r");
    if(!fp)
    {
        printf("Not able to open file\n");
        exit(0);
    }
    printf("S.No                  Expiry-Date                  Product-Name\n");
    while(fgets(t,sizeof(t),fp))
    {
        s=strtok(t,",");
        while(s!=NULL)
        {
            printf("%-30s",s);
            s=strtok(NULL,",");
        }
        printf("\n");
    }
}