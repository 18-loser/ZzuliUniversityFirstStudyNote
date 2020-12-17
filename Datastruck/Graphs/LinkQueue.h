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

Status InitQueue(LinkQueue &Q);  /*��ʼ������*/
Status QueueEmpty(LinkQueue Q);  /*�ж϶����Ƿ�Ϊ��*/
Status DestroyQueue(LinkQueue &Q); /*���ٶ���*/
Status EnQueue(LinkQueue &Q, QElemType e); /*�����*/
Status DeQueue(LinkQueue &Q, QElemType &e); /*������*/
