// kuofucheck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


//采用??的数据?? 
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
 * Description:初始化??
 */ 
void initstack(linkstack *s) 
{ 
    s -> top = NULL; 
} 
 
/**
 * Description;判断?是否?空
 */ 
int stackempty(linkstack *s) 
{ 
    int flag; 
 
    flag = (s -> top == NULL)? 1 : 0; 
 
    return flag; 
} 
 
/**
 * Description:入?操作
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
 * Description:出?操作
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
                    //左括号入? 
                    push(s,input[i]); 
                    flag[i] = ' '; 
                    break; 
                case ')': 
                    //判断?空 
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
                    //右括号入? 
                    push(s,input[i]); 
                    break; 
                case '(': 
                    //判断?空 
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
 
        //打印?出 
        printf("%s\n%s\n",input,flag); 
        memset(input,'\0',sizeof(input)); 
        memset(flag,'\0',sizeof(flag)); 
    } 
 
    return 0; 
}

