//#include <iostream>
#include <stdio.h>
#include <conio.h>
#define edge 2000
#define node 1000
int G[edge][2];
int k; //k-core
int deg[node+2];
/*void degree_check(int G[edge][2],int deg[node+2]);
int empty(int G[edge][2],int Gout[edge][2]);

int empty(int G[edge][2],int Gout[edge][2])
{
	bool nonemp;
	int k;
	//degree_check(G);
	for(int i=0;i<node;i++)
	{
		if(deg[i]<k)
		{
			for(int i=0;i<edge;i++)
			{
				G[i][0]=1001; 
				G[i][1]=1001;
			}
		}
	}
	
	degree_check(G,deg);
	for(int i=0;i<node;i++) 
	    if (deg[i]!=0) nonemp=true;
}

void degree_check(int G[edge][2],int deg[node+2])
{
	for(int i=0;i<node+2;i++) deg[i]=0;
	for(int i=0;i<node;i++)
	{
		deg[G[i][0]]++;
		deg[G[i][1]]++;
	}
}*/
int main()
{
	int count;
	for(int I=0; I<edge;I++) { G[I][0]=1001; G[I][1]=1001;}
    scanf("%d",&count);
	
	for(int I=0; I<count; I++)
	{	
	    scanf("%d %d",&G[I][0],&G[I][1]);	    
	}
	
	printf("\n");
	k=2; bool nonemp=true;
	     bool kcore=true;
	     bool ithcore=false;
//degree_check(G);
	for(int i=0;i<node+2;i++) deg[i]=0; //Initialize
	for(int i=0;i<node;i++)
	{
		deg[G[i][0]]++;
		deg[G[i][1]]++;
	}
	
while(nonemp==true)
{
ithcore=false;
	//for(int i=0;i<9;i++) printf("%d, ",deg[i]); printf("k=%d\n",k);
while(ithcore==false && nonemp==true)
{   
    for(int i=0;i<node;i++)
	{
		if(deg[i]<k) //不符合k-core 
		{
			for(int j=0;j<edge;j++) //清除過該點所有連線 
			{
				if(G[j][0]==i || G[j][1]==i)
				{
				    G[j][0]=1001; //1001為假想不存在之空節點 
				    G[j][1]=1001;
				}
			}
		}
	}
	//degree_check(G);
	for(int i=0;i<node+2;i++) deg[i]=0; //Initialize
	for(int i=0;i<node;i++)
	{
		deg[G[i][0]]++;
		deg[G[i][1]]++;
	}
	for(int i=0;i<9;i++) printf("%d, ",deg[i]); printf("k=%d\n",k);
	
	int Totdeg=0; ithcore=true; //檢查變數初始化 
	for(int i=0;i<node;i++) //檢查是否符合條件 
	{
		Totdeg+=deg[i];  // 1.空圖情形(所有點degree皆為 0) 
	    if (deg[i]!=0 && deg[i]<k) ithcore=false; // 2.存在非空節點且degree<k (Ex. line graph) 
    }
	printf("totdeg %d, nonemp %d, kcore %d\n",Totdeg,nonemp,kcore);
	if(Totdeg==0) nonemp=false;
}
    
	
	for(int i=0;i<edge;i++)
	    if(G[i][0]!=1001 && G[i][1]!=1001)
	    printf("%d %d\n",G[i][0],G[i][1]);	
	printf("--------------\n")	;
	
	if(nonemp==true)
	k++;	    
	} 
	printf("%d-core",k-1);
}
