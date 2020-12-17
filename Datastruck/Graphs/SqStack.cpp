/*����ջ�Ļ�����������*/

#include "SqStack.h"

/*��ʼ��һ����ջ*/
Status  InitStack (SqStack &S){
    S.base = (SElemType *)malloc (STACK_INIT_SIZE *sizeof(SElemType));
    if (! S.base)  exit (OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

/*�ж�ջ�Ƿ�Ϊ��*/
Status StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return OK;
    else
        return ERROR;
}

/*ȡջ��Ԫ��*/
Status GetTop(SqStack S, SElemType &e){
    if (S.top == S.base)  return  ERROR;
    e= * (S.top-1);
    return OK;
}

/*��ջ*/
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

/*��ջ*/
Status Pop(SqStack &S, SElemType &e){
    if( S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
