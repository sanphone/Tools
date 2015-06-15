// kuofucheck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


//�їp??�I����?? 
struct stacknode 
{ 
    char bracket; 
    struct stacknode *next; 
}; 
typedef struct 
{ 
    struct stacknode *top; 
}linkstack; 
 
/**
 * Description:���n��??
 */ 
void initstack(linkstack *s) 
{ 
    s -> top = NULL; 
} 
 
/**
 * Description;���f?����?��
 */ 
int stackempty(linkstack *s) 
{ 
    int flag; 
 
    flag = (s -> top == NULL)? 1 : 0; 
 
    return flag; 
} 
 
/**
 * Description:��?����
 */ 
void push(linkstack *s, char str) 
{ 
    struct stacknode *p; 
    p = (struct stacknode *)malloc(sizeof(struct stacknode)); 
    p -> bracket = str; 
    p -> next = s -> top; 
    s -> top = p; 
} 
 
/**
 * Description:�o?����
 */ 
char pop(linkstack *s) 
{ 
    char str; 
    struct stacknode *p = s -> top; 
    str = p -> bracket; 
    s -> top = p -> next; 
    free(p); 
    return str; 
} 


int _tmain(int argc, _TCHAR* argv[])
{
	    char input[101]; 
    char flag[101]; 
    char ch; 
    int i, len, j, k; 
    linkstack *s; 
    s = (linkstack *)malloc(sizeof(linkstack)); 
 
    while(scanf("%s",input) != EOF) 
    { 
        len = strlen(input); 
        initstack(s); 
        for(i = 0; i < len; i ++) 
        { 
            switch(input[i]) 
            { 
                case '(': 
                    //��������? 
                    push(s,input[i]); 
                    flag[i] = ' '; 
                    break; 
                case ')': 
                    //���f?�� 
                    if(stackempty(s)) 
                    { 
                        flag[i] = '?'; 
                    }else 
                    { 
                        flag[i] = ' '; 
                        ch = pop(s); 
                    } 
                    break; 
                default: 
                    flag[i] = ' '; 
                    break; 
            } 
        } 
        initstack(s); 
        for(i = len - 1; i >= 0; i --) 
        { 
            switch(input[i]) 
            { 
                case ')': 
                    //�E������? 
                    push(s,input[i]); 
                    break; 
                case '(': 
                    //���f?�� 
                    if(stackempty(s)) 
                    { 
                        flag[i] = '$'; 
                    }else 
                    { 
                        flag[i] = ' '; 
                        ch = pop(s); 
                    } 
                    break; 
                default: 
                    break; 
            } 
        } 
 
        //�ň�?�o 
        printf("%s\n%s\n",input,flag); 
        memset(input,'\0',sizeof(input)); 
        memset(flag,'\0',sizeof(flag)); 
    } 
 
    return 0; 
}

