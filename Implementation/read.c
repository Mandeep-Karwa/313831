#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"project.h"
void read(char *filename)
{
    FILE *fp;
    char t[680];
    char *s;
    fp=fopen(filename,"r");
    if(!fp)
    {
        printf("Not able to open file\n");
        exit(0);
    }
    printf("S.No                  Expiry-Date                  Product-Name\n");
    while(fgets(t,sizeof(t),fp))
    {
       // printf("%s",t);
        s=strtok(t,",");
        while(s!=NULL)
        {
            printf("%-30s",s);
            s=strtok(NULL,",");
        }
        printf("\n");
    }
}