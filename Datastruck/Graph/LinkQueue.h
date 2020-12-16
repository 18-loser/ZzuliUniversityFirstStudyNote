#include "DS.h"

typedef int QElemType;

typedef struct QNode{
        QElemType  data;
        struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
        QueuePtr  front;
        QueuePtr  rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);  /*初始化队列*/
Status QueueEmpty(LinkQueue Q);  /*判断队列是否为空*/
Status DestroyQueue(LinkQueue &Q); /*销毁队列*/
Status EnQueue(LinkQueue &Q, QElemType e); /*入队列*/
Status DeQueue(LinkQueue &Q, QElemType &e); /*出队列*/
