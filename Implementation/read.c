#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"project.h"
void read(char *username)
{
    FILE *fp;
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