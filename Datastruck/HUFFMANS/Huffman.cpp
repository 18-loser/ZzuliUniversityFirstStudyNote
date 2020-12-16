#include "Huffman.h"

void menu();
/*��ht�����д�1����n�ķ�Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����
�ŷֱ�ֵ��s1��s2����*/
void select(HuffmanTree &ht ,int n, int &s1, int &s2)
{
    int i;
    for(i = 1; i <= n; i++)   /*�����һ��˫��Ϊ0�ĵ�Ϊ��Сֵ*/
    {
        if(ht[i].parent == 0)
        {
            s1 = i;
            break;
        }
    }
    for(i++; i <= n; i++)      /*����ڶ���˫��Ϊ0�ĵ�Ϊ��Сֵ*/
    {
        if(ht[i].parent == 0)
        {
            s2 = i;
            break;
        }
    }
    for(i = 1; i <= n; i++)      /*����̨����˼����Ȩֵ��С���������*/
    {
        if(ht[i].parent == 0 && ht[i].weight < ht[s1].weight)  /*�ҵ���ǰ��Сֵ������ǰ����Сֵ��Ϊ��Сֵ*/
        {
            s2 = s1;
            s1 = i;
        }
        else if(ht[i].parent == 0 && i != s1 && ht[i].weight < ht[s2].weight) /*�����Ȩֵ����Сֵ�󣬱ȴ�СֵС�����Ϊ��Сֵ*/
            s2 = i;
    }

}

void CrtHuffmanTree(HuffmanTree &ht , HuffmanCode &hc, int * w,  int n)
{/*w���n��Ȩֵ, �����������ht, ���������������hc */
    int m, i, s1, s2, start, c, f;
    char *cd;
    if (n <= 1) return;
    m = 2 * n - 1;
    ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); /*0�ŵ�Ԫδʹ��*/
    for(i = 1; i <= n; i++)
    {
        ht[i].weight = w[i];
        ht[i].parent = ht[i].LChild = ht[i].RChild = 0;    /*Ҷ�ӽ���ʼ��*/
    }
    for(i = n + 1; i <= m; i++)
        ht[i].weight = ht[i].parent = ht[i].LChild = ht[i].RChild = 0; /*��Ҷ�ӽ���ʼ��*/
    for(i = n + 1; i <= m; i++) /*������Ҷ�ӽ��, ����������*/
    {
        select(ht, i-1, s1, s2);
        ht[s1].parent = i;  ht[s2].parent = i;
        ht[i].LChild = s1;  ht[i].RChild = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }  /*���������������*/

    for(i = 1; i <= m; i++)   /*�������������Ӧ�ľ�̬�������飩��������齨�������Ƿ���ȷ*/
    {
        printf("%d %d %d %d\n",ht[i].weight,ht[i].parent,ht[i].LChild,ht[i].RChild);
    }
    /*��Ҷ�ӽ�㵽���� ������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������*/
    hc = (HuffmanCode)malloc((n + 1) * sizeof(char *));   /*����n�������ͷָ��*/
    cd = (char * )malloc(n * sizeof(char ));   /*������ǰ����Ĺ����ռ�*/
    cd[n-1] = '\0';   /*����������λ��ű��룬 ���ȴ�ű��������*/
    for(i = 1; i <= n; i++)  /*��n��Ҷ�ӽ���Ӧ�Ĺ���������*/
    {
        start = n - 1; /*��ʼ��������ʼָ��*/
        for(c = i,f = ht[i].parent; f != 0; c = f, f = ht[f].parent)/*��Ҷ�ӵ�����������*/
            if(ht[f].LChild == c) cd[--start]= '0'; /*���֧��0*/
            else cd[--start]= '1'; /*�ҷ�֧��1*/
        hc[i] = (char *)malloc(( n - start) * sizeof(char)); /*Ϊ��i���������ռ�*/
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
}
