#include "MGraph.h"
#include "LinkQueue.h"
#include "SqStack.h"

int visited[N]; /*���ʱ�ʶ����*/
Edge closedge[N];

/*����һ������ͼ���ڽӾ���*/
Status CreateUDG(MGraph &G)
{
    int i, j, k;
    char v1, v2;
    printf("������ͼG�Ķ������ͱ�����");
    scanf("%d %d", &G.vexnum, &G.arcnum);
    printf("������%d����������(�Կո�����)��", G.vexnum);
    for(i = 0; i < G.vexnum; i++)
        scanf(" %c", &G.vexs[i]);  /*��ע�������ʽ*/
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = 0;
    for(k = 1; k <= G.arcnum; k++)
    {
        printf("�������%d���ߵ���������(���ַ���ʾ���ַ����Կո�����)��", k);
        scanf(" %c %c", &v1, &v2);  /*��ע�������ʽ*/
        i = LocateVex(G, v1);       /*ȷ��v1��v2���±�*/
        j = LocateVex(G, v2);
        if(i >= 0 && j >= 0)        /*�޸��ڽӾ������Ϣ*/
            G.arcs[i][j] = G.arcs[j][i] = 1;
    }
    return OK;
}

/*��д������ͼ���ڽӾ�������ɺ���*/
Status CreateDG(MGraph &G)
{
    int i, j, k;
    char v1, v2;
    printf("������ͼG�Ķ������ͱ�����");
    scanf("%d %d", &G.vexnum, &G.arcnum);
    printf("������%d����������(�Կո�����)��", G.vexnum);
    for(i = 0; i < G.vexnum; i++)
        scanf(" %c", &G.vexs[i]);  /*��ע�������ʽ*/
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = 0;
    for(k = 1; k <= G.arcnum; k++)
    {
        printf("�������%d���ߵ���������(���ַ���ʾ���ַ����Կո�����)��", k);
        scanf(" %c %c", &v1, &v2);  /*��ע�������ʽ*/
        i = LocateVex(G, v1);       /*ȷ��v1��v2���±�*/
        j = LocateVex(G, v2);
        if(i >= 0 && j >= 0)        /*�޸��ڽӾ������Ϣ*/
            G.arcs[i][j] = 1;
    }
    return OK;
}

/*��д�������Ȩͼ���ڽӾ�������ɺ���*/
Status CreateUDN(MGraph &G)
{
    int i, j, k, value;
    char v1, v2;
    printf("������ͼG�Ķ������ͱ�����");
    scanf("%d %d", &G.vexnum, &G.arcnum);
    printf("������%d����������(�Կո�����)��", G.vexnum);
    for(i = 0; i < G.vexnum; i++)
        scanf(" %c", &G.vexs[i]);  /*��ע�������ʽ*/
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MAX;
    for(k = 1; k <= G.arcnum; k++)
    {
        printf("�������%d���ߵ���������(���ַ���ʾ���ַ����Կո�����)��Ȩֵ��", k);
        scanf(" %c %c %d", &v1, &v2, &value);  /*��ע�������ʽ*/
        i = LocateVex(G, v1);       /*ȷ��v1��v2���±�*/
        j = LocateVex(G, v2);
        if(i >= 0 && j >= 0)        /*�޸��ڽӾ������Ϣ*/
            G.arcs[i][j] = G.arcs[j][i] = value;
    }
    return OK;
}

/*��д�������Ȩͼ���ڽӾ�������ɺ���*/
Status CreateDN(MGraph &G)
{
    int i, j, k, value;
    char v1, v2;
    printf("������ͼG�Ķ������ͱ�����");
    scanf("%d %d", &G.vexnum, &G.arcnum);
    printf("������%d����������(�Կո�����)��", G.vexnum);
    for(i = 0; i < G.vexnum; i++)
        scanf(" %c", &G.vexs[i]);  /*��ע�������ʽ*/
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MAX;
    for(k = 1; k <= G.arcnum; k++)
    {
        printf("�������%d���ߵ���������(���ַ���ʾ���ַ����Կո�����)��Ȩֵ��", k);
        scanf(" %c %c %d", &v1, &v2, &value);  /*��ע�������ʽ*/
        i = LocateVex(G, v1);       /*ȷ��v1��v2���±�*/
        j = LocateVex(G, v2);
        if(i >= 0 && j >= 0)        /*�޸��ڽӾ������Ϣ*/
            G.arcs[i][j] = value;
    }
    return OK;
}

/*���Ҷ���v���ڽӾ���洢���е��±�*/
int LocateVex(MGraph G, char v)
{
    int i;
    for(i = 0; i < G.vexnum; i++)
        if(G.vexs[i] == v)
            return i;
    return -1;
}

/*������ȱ���ͼG*/
void DFSTraverse(MGraph G)
{
    int i;
    for(i = 0; i < G.vexnum; i++)
        visited[i] = FALSE;
    for(i = 0; i < G.vexnum; i++)
        if(!visited[i])  DFS(G, i);
    printf("\n");
}

void DFS(MGraph G, int v)
{
    int w;
    visited[v] = TRUE; /*���ʶ���v�� ���÷��ʱ�־������Ӧ����ֵ*/
    printf("%c ", G.vexs[v]);
    for(w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
        if(!visited[w])  DFS(G, w);   /*�ݹ����DFS*/
} /*DFS*/

/*��ͼG�в��Ҷ���v�ĵ�һ���ڽӵ�*/
int FirstAdjVex(MGraph G, int v)
{
    int i;
    for(i = 0; i < G.vexnum; i++)
        if(G.arcs[v][i] != 0)
            return i;
    return -1;
}

/*��ͼG�в��Ҷ���v���ڽӵ�w֮�����һ���ڽӵ�*/
int NextAdjVex(MGraph G, int v, int w)
{
    int i;
    for(i = w + 1 ; i < G.vexnum; i++)
        if(G.arcs[v][i] != 0)
            return i;
    return -1;
}

void  BFSTraverse(MGraph G)
{
    int i, v, u, w;
    LinkQueue Q;
    for(i = 0; i < G.vexnum; i++)     visited[i] = FALSE;
    InitQueue(Q);    /*��ʼ���ն�*/
    for(v = 0; v < G.vexnum; v++)
    {
        if(!visited[v])
        {
            visited[v] = TRUE;
            printf("%c ", G.vexs[v]);
            EnQueue(Q, v);  /* v����*/
            while(!QueueEmpty(Q))
            {
                DeQueue(Q, u);    /*��ͷԪ�س���*/
                for(w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
                    if (!visited[w])
                    {
                        printf("%c ", G.vexs[w]);
                        visited[w] = TRUE;
                        EnQueue(Q, w);
                    }
            }
        }
    }
    printf("\n");
} //BFSTraverse

/*��ͼG����closedge����ĵ�ǰ��Сֵ*/
int Minimum(MGraph G, Edge closedge[])
{
    int i, k, Min;
    for(i = 0; i < G.vexnum; i++)  /*Min����ֵ*/
    {
        if(closedge[i].lowcost != 0)
        {
            Min = closedge[i].lowcost;
            k = i;
            break;
        }
    }
    for(i++; i < G.vexnum; i++)   /*����̨����˼������Сֵ*/
    {
        if(closedge[i].lowcost != 0 && closedge[i].lowcost < Min)
        {
            Min = closedge[i].lowcost;
            k = i;
        }
    }
    return k;
}

/*�Ӷ���u������ ������ķ�㷨������ͨ��G ����С�������� �������������ÿ����*/
void MiniSpanTree_Prim(MGraph G, VertexType u)
{
    int k, i, j, m;
    k = LocateVex(G, u);    /*��λ���u���±�k*/
    closedge[k].lowcost = 0;
    closedge[k].adjvex = -1;
    for(j = 0; j < G.vexnum; j++)  /*closedge���鸳��ֵ*/
    {
        if(j != k)
        {
            if(G.arcs[k][j] != MAX)
            {
                closedge[j].adjvex = k;
                closedge[j].lowcost = G.arcs[k][j];
            }
            else
            {
                closedge[j].adjvex = -1;
                closedge[j].lowcost = MAX;
            }
        }
    }
    for(i = 1; i < G.vexnum; i++)
    {
        k = Minimum(G, closedge);                      /*�ҳ���ǰȨֵ��С�ı�����Ӧ�ĵ�*/
        m = closedge[k].adjvex;                        /*�ñ�����Ӧ���ڽӵ�*/
        printf("%c %c\n", G.vexs[m], G.vexs[k]);       /*����������ĵ�ǰ��С�߶�Ӧ�������ڽӵ���Ϣ*/
        closedge[k].lowcost = 0;                       /*������k����U����*/
        /*�ڶ���v0����U֮�� ����closedge[j] */
        for(j = 0 ; j < G.vexnum; j++)
        {
            if(G.arcs[k][j] < closedge[j].lowcost)
            {
                closedge[j].adjvex = k;
                closedge[j].lowcost = G.arcs[k][j];
            }
        }
    }  //for
}//minispantree_prim

/*��ͼG����v0������������·��*/
 void ShortPath_DIJ(MGraph G, int v0, int *P, int *D)
 {
    int final[N];
    int v, i, w, Min, j;
    for(v = 0; v < G.vexnum; ++v)  /*�������������ʼ��*/
    {
        final[v] = FALSE;
        D[v] = G.arcs[v0][v];
        if(D[v] < MAX) P[v] = v0;
    }//for
    D[v0] = 0; final[v0] = TRUE;  //��Ƕ���v0�ѴӼ���T���뵽����S��
    //��ʼѭ����ÿ�����V0��ĳ��V��������·��������V��S��
    for(i = 1; i < G.vexnum; ++i)
    {
        Min = MAX;
        for(w = 0; w < G.vexnum; ++w)
            if(!final[w])          //��ǰ���·���������Ϣ
                if(D[w] < Min)
                { v = w; Min = D[w];}
        if(Min < MAX)
            final[v] = TRUE; //��Ƕ���V�ѴӼ���T���뵽����S��
        else
            break;   //��ͼ�Ƿ���ͨͼ��������
        //�޸Ĵ�v0�������������̾�������·��
        for(w = 0; w < G.vexnum; ++w)
        {
            if(!final[w] && (Min + G.arcs[v][w] < D[w]))
            {
                D[w] = Min + G.arcs[v][w];
                P[w] = v;
            }//if
        }
      }//for
}

/*���v0������������·��*/
void Printshortpath(MGraph G, int v0, int *P, int *D)
{
    int i, j;
    SqStack s;
    InitStack(s);
    for(i = 0; i < G.vexnum; i++)
    {
        if(i != v0)
        {
            Push(s, i);   /*��ջ��ʵ��·����Ϣ�Ĵ洢*/
            j = P[i];
            while(1)
            {
                Push(s, j);
                if(j == v0)
                    break;
                j = P[j];
            }
            printf("%c��%c�����·��ֵΪ��%d��·����ϢΪ��", G.vexs[v0], G.vexs[i], D[i]);
            while(!StackEmpty(s))
            {
                Pop(s, j);
                printf("%c ", G.vexs[j]);
            }
            printf("\n");
        }

    }

}



