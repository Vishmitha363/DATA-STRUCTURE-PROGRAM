#include<stdio.h>
#include<string.h>
#define max 20
char s[max];
int top=-1;
void push(char c){
    if(top==max-1){
        printf("stack is full\n");
    }
    else{
      s[++top]=c;
    }
}  
char pop(){
    if(top==-1){
        printf("the stack is empty");
        return '\0';
    }
    else{
        return s[--top];
    }
    return 0;
 } 
int main(){
    char s[max];
    printf("enter the string to reverse:");
    gets(s);
    for(int i=0;i<=strlen(s);i++){
        push(s[i]);
    }
    for(int i=0;i<=strlen(s);i++){
        s[i]=pop();
    }
    printf("string after the reversal:%s",s);
    return 0;
}
