#include "Huffman.h"78

int main()
{
    HuffmanTree ht;
    HuffmanCode hc;
    int n, i;
    int *weight;
    printf("please input the number of weight:");  /*输入权值的个数*/
    scanf("%d", &n);
    weight = (int *)malloc((n+1)*sizeof(int));    /*生成权值数组*/
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);                  /*输入权值信息*/
    CrtHuffmanTree(ht, hc, weight, n);            /*生成哈夫曼树并进行哈夫曼编码*/
    for(i = 1; i <= n; i++)
        printf("%d-->%s\n", ht[i].weight, hc[i]);   /*输出每个权值对应的哈夫曼编码*/

    return 0;
}
