#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int top;
    int* arr;
    
}Stack;

Stack* createstack(int cap){
    Stack* obj=(Stack*)malloc(sizeof(Stack));
    obj->arr=(int*)malloc(sizeof(int)*cap);
    obj->top=-1;
    return obj;
}
void push(Stack* obj,int val){
    obj->arr[++obj->top]=val;
    return;
}
int pop(Stack* obj){
   return  obj->arr[obj->top--];
}
int peek(Stack* obj){
    return obj->arr[obj->top];
}
int postfix(char* s){
    Stack* st=createstack(strlen(s));
    
    if(s[2]=='?') return s[0]-'0';
    int currval=0;
    
    for(int i=0;i<strlen(s)&&s[i]!='?';i++){
    if(s[i+1]=='?') break;
        char currchar=s[i];
//         12 23 + 14 - ?
        if(currchar==' '&&i>0&&s[i-1]>='0'&&s[i-1]<='9'){
            push(st,currval);
            currval=0;
        }
        else if(currchar>='0'&&currchar<='9'){
            currval=currval*10+(currchar-'0');
        }
        else if(currchar=='+'||currchar=='-'||currchar=='/'||currchar=='*'){
         
            // int top1=peek(st);
            int top1=pop(st);
            
            // int top2=peek(st);
            int top2=pop(st);
            
            switch(currchar){
                case '*':
                    push(st,top1*top2);
                    break;
                case '+':
                    push(st,top1+top2);
                    break;
                case '-':
                    push(st,top2-top1);
                    break;
                case '/':
                    push(st,top2/top1);
                    break;
            }
        }
    }
    return pop(st);
}
int main() {
     int n;
    scanf("%d",&n);
    getchar();
    
    for(int i=0;i<n;i++){
        char str[100];
        fgets(str,100,stdin);
        int ans=postfix(str);
        printf("%d\n",ans);
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}