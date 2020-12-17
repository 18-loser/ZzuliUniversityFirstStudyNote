#include "MGraph.h"

int main()
{
    MGraph G;
    VertexType u;
    int i, j, v0;
    int D[N], P[N] = {-1};/* ��P[v]==w����w�Ǵ�v0��v��ǰ������·���ϵĵ� */

    printf("����ͼ�Ļ���������\n");
    CreateUDG(G);
    printf("ͼ�еĶ�����ϢΪ��\n");
    for(i = 0; i < G.vexnum; i++)
        printf("%c ", G.vexs[i]);
    printf("\n");
    printf("�ڽӾ���Ϊ��\n");
    for(i = 0; i < G.vexnum; i++)
    {
        for(j = 0; j < G.vexnum; j++)
            printf("%d ", G.arcs[i][j]);
        printf("\n");
    }

    printf("��������������У�");
    DFSTraverse(G);
    printf("��������������У�");
    BFSTraverse(G);

    printf("��Ȩ����ͼ����С��������\n");
    CreateUDN(G);
    printf("��С����������ϢΪ��\n");
    u = G.vexs[0];
    MiniSpanTree_Prim(G, u);

    printf("��Ȩ����ͼ�����·����\n");
    CreateDN(G);
    printf("��������㣺");
    scanf(" %c", &u);
    v0 = LocateVex(G, u);
    ShortPath_DIJ(G, v0, P, D);
    Printshortpath(G, v0, P, D);

    return 0;
}
