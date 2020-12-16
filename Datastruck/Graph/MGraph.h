#include "DS.h"

#ifndef MGRAPH_H_INCLUDED
#define MGRAPH_H_INCLUDED

#define MAX 3000
#define  N  10  /*��ඥ����*/
typedef  char  VertexType; /*��������*/
typedef  struct{
     VertexType vexs[N]; /*�涥�������*/
     int  arcs[N][N];/*�����Ϣ�ľ���*/
     int vexnum, arcnum;  /*������,���� */
}MGraph;

typedef struct{
    VertexType  adjvex;  /*�ڽӵ���±�*/
    int      lowcost;    /*�ߵ�Ȩֵ*/
}Edge;

#endif // MGRAPH_H_INCLUDED

Status CreateUDG(MGraph &G); /*����ͼ���ڽӾ������ɺ���*/
Status CreateDG(MGraph &G);  /*����ͼ���ڽӾ������ɺ���*/
Status CreateUDN(MGraph &G); /*�����Ȩͼ���ڽӾ������ɺ���*/
Status CreateDN(MGraph &G); /*�����Ȩͼ���ڽӾ������ɺ���*/

int LocateVex(MGraph G, char v); /*���Ҷ���v���ڽӾ���洢���е��±�*/
int FirstAdjVex(MGraph G, int v);  /*��ͼG�в��Ҷ���v�ĵ�һ���ڽӵ�*/
int NextAdjVex(MGraph G, int v, int w); /*��ͼG�в��Ҷ���v���ڽӵ�w֮�����һ���ڽӵ�*/
void DFSTraverse(MGraph G);     /*�����������ͼG*/
void DFS(MGraph G, int v);
void BFSTraverse(MGraph G);     /*�����������ͼG*/

int Minimum(MGraph G, Edge closedge[]);  /*��closedge�������Сֵ*/
void MiniSpanTree_Prim(MGraph G, VertexType u); /*PRIM�㷨����С������*/

void ShortPath_DIJ(MGraph G, int v0, int *P, int *D); /*��ͼG����v0������������·��*/
void Printshortpath(MGraph G, int v0, int *P, int *D); /*���v0������������·��*/
