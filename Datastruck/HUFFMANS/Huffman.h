#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "DS.h"

typedef struct
{
    int weight;/* ������Ÿ�������Ȩֵ*/
    int parent, LChild, RChild ;/*ָ��˫�ס� ���ӽ���ָ��*/
}HTNode, *HuffmanTree;  /*��̬�������飬 �洢��������*/
typedef char  * *HuffmanCode ; /*��̬�������飬 �洢����������*/

void CrtHuffmanTree(HuffmanTree &ht , HuffmanCode &hc, int * w,  int n);
void select(HuffmanTree &ht ,int n, int &s1, int &s2);


#endif // SQLIST_H_INCLUDED
