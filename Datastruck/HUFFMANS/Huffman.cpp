#include "Huffman.h"

void menu();
/*在ht数组中从1——n的范围内选择两个parent为0且weight最小的结点，其序
号分别赋值给s1、s2返回*/
void select(HuffmanTree &ht ,int n, int &s1, int &s2)
{
    int i;
    for(i = 1; i <= n; i++)   /*假设第一个双亲为0的点为最小值*/
    {
        if(ht[i].parent == 0)
        {
            s1 = i;
            break;
        }
    }
    for(i++; i <= n; i++)      /*假设第二个双亲为0的点为次小值*/
    {
        if(ht[i].parent == 0)
        {
            s2 = i;
            break;
        }
    }
    for(i = 1; i <= n; i++)      /*用擂台赛的思想找权值最小的两个结点*/
    {
        if(ht[i].parent == 0 && ht[i].weight < ht[s1].weight)  /*找到当前最小值，则以前的最小值成为次小值*/
        {
            s2 = s1;
            s1 = i;
        }
        else if(ht[i].parent == 0 && i != s1 && ht[i].weight < ht[s2].weight) /*如果该权值比最小值大，比次小值小，则称为次小值*/
            s2 = i;
    }

}

void CrtHuffmanTree(HuffmanTree &ht , HuffmanCode &hc, int * w,  int n)
{/*w存放n个权值, 构造哈夫曼树ht, 并求出哈夫曼编码hc */
    int m, i, s1, s2, start, c, f;
    char *cd;
    if (n <= 1) return;
    m = 2 * n - 1;
    ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); /*0号单元未使用*/
    for(i = 1; i <= n; i++)
    {
        ht[i].weight = w[i];
        ht[i].parent = ht[i].LChild = ht[i].RChild = 0;    /*叶子结点初始化*/
    }
    for(i = n + 1; i <= m; i++)
        ht[i].weight = ht[i].parent = ht[i].LChild = ht[i].RChild = 0; /*非叶子结点初始化*/
    for(i = n + 1; i <= m; i++) /*创建非叶子结点, 建哈夫曼树*/
    {
        select(ht, i-1, s1, s2);
        ht[s1].parent = i;  ht[s2].parent = i;
        ht[i].LChild = s1;  ht[i].RChild = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }  /*哈夫曼树建立完毕*/

    for(i = 1; i <= m; i++)   /*输入哈夫曼树对应的静态链表（数组），帮助检查建立过程是否正确*/
    {
        printf("%d %d %d %d\n",ht[i].weight,ht[i].parent,ht[i].LChild,ht[i].RChild);
    }
    /*从叶子结点到根， 逆向求每个叶子结点对应的哈夫曼编码*/
    hc = (HuffmanCode)malloc((n + 1) * sizeof(char *));   /*分配n个编码的头指针*/
    cd = (char * )malloc(n * sizeof(char ));   /*分配求当前编码的工作空间*/
    cd[n-1] = '\0';   /*从右向左逐位存放编码， 首先存放编码结束符*/
    for(i = 1; i <= n; i++)  /*求n个叶子结点对应的哈夫曼编码*/
    {
        start = n - 1; /*初始化编码起始指针*/
        for(c = i,f = ht[i].parent; f != 0; c = f, f = ht[f].parent)/*从叶子到根结点求编码*/
            if(ht[f].LChild == c) cd[--start]= '0'; /*左分支标0*/
            else cd[--start]= '1'; /*右分支标1*/
        hc[i] = (char *)malloc(( n - start) * sizeof(char)); /*为第i个编码分配空间*/
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
}
