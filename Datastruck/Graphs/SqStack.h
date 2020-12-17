/*头文件中包括数据类型的定义，常量的定义，函数声明等，函数的定义在同名的源文件中*/

#include "DS.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;

typedef struct {
    SElemType  * base;    //栈底指针
    SElemType  *top;      //栈顶指针
    int    stacksize;      //栈可使用的最大容量
} SqStack;

Status InitStack (SqStack &S);
Status GetTop(SqStack S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
Status StackEmpty(SqStack S);


