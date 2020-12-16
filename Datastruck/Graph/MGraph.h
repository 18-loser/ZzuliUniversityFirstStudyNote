#include "DS.h"

#ifndef MGRAPH_H_INCLUDED
#define MGRAPH_H_INCLUDED

#define MAX 3000
#define  N  10  /*最多顶点数*/
typedef  char  VertexType; /*顶点类型*/
typedef  struct{
     VertexType vexs[N]; /*存顶点的数组*/
     int  arcs[N][N];/*存边信息的矩阵*/
     int vexnum, arcnum;  /*顶点数,边数 */
}MGraph;

typedef struct{
    VertexType  adjvex;  /*邻接点的下标*/
    int      lowcost;    /*边的权值*/
}Edge;

#endif // MGRAPH_H_INCLUDED

Status CreateUDG(MGraph &G); /*无向图的邻接矩阵生成函数*/
Status CreateDG(MGraph &G);  /*有向图的邻接矩阵生成函数*/
Status CreateUDN(MGraph &G); /*无向带权图的邻接矩阵生成函数*/
Status CreateDN(MGraph &G); /*有向带权图的邻接矩阵生成函数*/

int LocateVex(MGraph G, char v); /*查找顶点v在邻接矩阵存储法中的下标*/
int FirstAdjVex(MGraph G, int v);  /*在图G中查找顶点v的第一个邻接点*/
int NextAdjVex(MGraph G, int v, int w); /*在图G中查找顶点v的邻接点w之后的下一个邻接点*/
void DFSTraverse(MGraph G);     /*深度优先搜索图G*/
void DFS(MGraph G, int v);
void BFSTraverse(MGraph G);     /*广度优先搜索图G*/

int Minimum(MGraph G, Edge closedge[]);  /*求closedge数组的最小值*/
void MiniSpanTree_Prim(MGraph G, VertexType u); /*PRIM算法求最小生成树*/

void ShortPath_DIJ(MGraph G, int v0, int *P, int *D); /*在图G中求v0到其他点的最短路径*/
void Printshortpath(MGraph G, int v0, int *P, int *D); /*输出v0到其他点的最短路径*/
