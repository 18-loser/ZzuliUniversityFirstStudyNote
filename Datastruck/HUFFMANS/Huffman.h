#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "DS.h"

typedef struct
{
    int weight;/* 用来存放各个结点的权值*/
    int parent, LChild, RChild ;/*指向双亲、 孩子结点的指针*/
}HTNode, *HuffmanTree;  /*动态分配数组， 存储哈夫曼树*/
typedef char  * *HuffmanCode ; /*动态分配数组， 存储哈夫曼编码*/

void CrtHuffmanTree(HuffmanTree &ht , HuffmanCode &hc, int * w,  int n);
void select(HuffmanTree &ht ,int n, int &s1, int &s2);


#endif // SQLIST_H_INCLUDED
