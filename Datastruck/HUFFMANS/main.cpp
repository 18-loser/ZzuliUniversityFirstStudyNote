#include "Huffman.h"78

int main()
{
    HuffmanTree ht;
    HuffmanCode hc;
    int n, i;
    int *weight;
    printf("please input the number of weight:");  /*����Ȩֵ�ĸ���*/
    scanf("%d", &n);
    weight = (int *)malloc((n+1)*sizeof(int));    /*����Ȩֵ����*/
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);                  /*����Ȩֵ��Ϣ*/
    CrtHuffmanTree(ht, hc, weight, n);            /*���ɹ������������й���������*/
    for(i = 1; i <= n; i++)
        printf("%d-->%s\n", ht[i].weight, hc[i]);   /*���ÿ��Ȩֵ��Ӧ�Ĺ���������*/

    return 0;
}
