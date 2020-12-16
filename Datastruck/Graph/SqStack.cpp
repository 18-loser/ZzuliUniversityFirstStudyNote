/*关于栈的基本操作定义*/

#include "SqStack.h"

/*初始化一个空栈*/
Status  InitStack (SqStack &S){
    S.base = (SElemType *)malloc (STACK_INIT_SIZE *sizeof(SElemType));
    if (! S.base)  exit (OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

/*判断栈是否为空*/
Status StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return OK;
    else
        return ERROR;
}

/*取栈顶元素*/
Status GetTop(SqStack S, SElemType &e){
    if (S.top == S.base)  return  ERROR;
    e= * (S.top-1);
    return OK;
}

/*入栈*/
Status Push(SqStack &S, SElemType e){
    if (S.top - S.base>= S.stacksize){
        S.base=(SElemType*)realloc(S.base,
        (S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) exit(OVERFLOW);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++ = e;
     return OK;
}

/*出栈*/
Status Pop(SqStack &S, SElemType &e){
    if( S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
