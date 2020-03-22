/*			



								Algorithm Design
			
								   Chapter 4:
							   The Greedy Approach

									Project 2:
						Implementation of a Greedy algorithm

									 Professor:
								 Dr.Bahman Arasteh

									Hiwa Amiri


*/
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#define infinity 999
#define x 100
using namespace std;
void Random(int cost[x][x],int n);
void manual(int cost[x][x],int n);
void dijkstra(int n,int v,int cost[x][x],int dist[]); 
//******************************************************************
void main()
{
	int n,v,i,j;
	int cost[x][x],dist[x];
	char ans;
	cout<<"\n\n       *************************************************************";
    cout<<"\n       *** Dijkstra's Algorithm for Single-Source Shortest Paths ***";
    cout<<"\n       *************************************************************";
	reset:
	cout<<"\n\n Enter the number of nodes (maximum 100) :";
	cin>>n;

	cout<<" Would you want to Initialize randomly? (y/n): ";
        ans=getche();
        if(ans=='y')
                Random(cost,n);
        else
                manual(cost,n);
        cout<<"____________________________________________________\n";
        cout<<" Matrix of graph:\n\n";
        for (i=1 ; i<=n ; i++)
        {
                cout<<"\t\t";
                for (j=1 ; j<=n ; j++)
                        if (cost[i][j] == infinity)
							cout<<">< ";
                        else
                                cout<<cost[i][j]<<"  ";
                        cout<<endl;
        }
	tryy:
	cout<<"\n Enter the source node:";
	cin>>v;
	if(v>n){
		cout<<"\n ERROR: Number of source must be less than or equal to the number of vertices\n";
		goto tryy;}
	dijkstra(n,v,cost,dist);
	cout<<"\n Cost of shortest path:\n\n";
	for(i=1;i<=n;i++) if(i!=v) cout<<" "<<v<<" to "<<i<<"; cost = "<<dist[i]<<endl;
	cout<<"\n Press R to reset program or Enter to exit ...";
	ans=getche();
	system("cls");
	if (ans=='r') goto reset;
}
//******************************************************************
void Random(int cost[x][x],int n)
{
        int i,j;
        cout<<endl;
        for (i=1 ; i<=n ; i++)
                for (j=1 ; j<=n ; j++)
                {
                        cost[i][j]=0;
                        if (i != j){ 
							cost[i][j]=rand()%9;
								if(cost[i][j]==0) cost[i][j]=infinity;}
                        else 
                                cost[i][j]=0;

                }
}
//******************************************************************
void manual(int cost[x][x],int n)
{
        int i,j;
        cout<<endl;
        for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				cout<<" Enter ["<<i<<"]["<<j<<"]: ";
				cin>>cost[i][j];
				if(cost[i][j]==0)
					cost[i][j]=infinity;
			}

}

//******************************************************************
void dijkstra(int n,int v,int cost[x][x],int dist[])
{
	int i;
	int u;
	int count; 
	int w;
	int flag[10];
	int min;

	for(i=1;i<=n;i++)
		flag[i]=0, dist[i]=cost[v][i];
	count=2;
	while(count<=n)
	{
		min=99;
		for(w=1;w<=n;w++)
			if(dist[w]<min && !flag[w])
				min=dist[w],u=w;
		flag[u]=1;
		count++;
		for(w=1;w<=n;w++)
			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
				dist[w]=dist[u]+cost[u][w];
	}
}
