#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    int weight;
    char ch;
    int parent;
    int leftchild;
    int rightchild;	
}Huffman;

typedef struct Hcode
{
    int code[100]; 
    int start;           
};

Huffman huffman[100];
Hcode code[100];

void HuffmanTree(int n)
{
	int a,b,c,d;
    for (int i=0;i<n*2-1;++i)
	{
        huffman[i].weight=0;
        huffman[i].parent=-1;
        huffman[i].leftchild=-1;
        huffman[i].rightchild=-1;
    }
    for (int i=0;i<n;i++)
	{
        cin >> huffman[i].ch;
        scanf("%d",&huffman[i].weight);
    }
    for (int i=0;i<n-1;i++)
	{
        a=b=-1;
        c=d=10000;
        for (int j=0;j<n+i;j++)
		{
            if (huffman[j].parent==-1 && huffman[j].weight<c)
			{
                d=c;
                b=a;
                a=j;
                c=huffman[j].weight;
            }
            else if (huffman[j].parent==-1 && huffman[j].weight<d)
			{
                b=j;
                d=huffman[j].weight;
            }
        }
        huffman[n+i].leftchild=a;
        huffman[n+i].rightchild=b;
        huffman[n+i].weight=c+d;
        huffman[a].parent=n+i;
        huffman[b].parent=n+i;
    }
}
void printHuffmanTree(int n)
{
    Hcode tcode;
    int curParent;
    int c;
    for (int i = 0; i < n; ++i){
        tcode.start = n - 1;
        c = i;
        curParent = huffman[i].parent;
        while (curParent != -1)
		{
            if (huffman[curParent].leftchild == c)
			{
                tcode.code[tcode.start] = 0;
            }
            else
			{
                tcode.code[tcode.start] = 1;
            }
            tcode.start--;
            c=curParent;
            curParent=huffman[c].parent;
        }
        for(int j=tcode.start+1;j<n;j++)
		{
            code[i].code[j] = tcode.code[j];
        }
        code[i].start = tcode.start;
    }
}
int main()
{
	int n=0;
    scanf("%d",&n);
    HuffmanTree(n);
    printHuffmanTree(n);
    for (int i=0;i<n;++i)
	{
        printf("%c :",huffman[i].ch);
        for (int j=code[i].start+1;j<n;++j)
		{
            printf("%d",code[i].code[j]);
        }
        printf("\n");
    }
    return 0;
}