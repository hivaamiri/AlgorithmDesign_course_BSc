
/*			



														  Algorithm Design
			
															 Chapter 3:
														Dynamic Programming

															 Project 3:
												Implementation of a Dynamic algorithm

															Professor:
														Dr.Bahman Arasteh

															 Hiwa Amiri


*/

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<string.h>
#define infinity 999
#define x 100
using namespace std;
void show  (int i,int j,int p[x][x]);
void floyd (int D[x][x],int n, int p[x][x] );
void Random(int W[x][x],int n);
void manual(int W[x][x],int n);


void main()
{
        int i,j,n;
        char ans;
        int W[x][x], p[x][x];
		cout<<"\n\n       **********************************************************";
        cout<<"\n             *** Floyd's Algorithm for Shortest Paths ***";
        cout<<"\n       **********************************************************";
		reset:
        cout<<"\n\n Enter number of vertices (maximum 100): ";
        cin>>n;
        cout<<" Would you want to Initialize randomly? (y/n): ";
        ans=getche();
        if(ans=='y')
                Random(W,n);
        else
                manual(W,n);
        cout<<"____________________________________________________\n";
        cout<<" Matrix of graph:\n\n";
        for (i=1 ; i<=n ; i++)
        {
                cout<<"\t\t";
                for (j=1 ; j<=n ; j++)
                        if (W[i][j] == infinity)
							cout<<">< ";
                        else
                                cout<<W[i][j]<<"  ";
                        cout<<endl;
        }
        for (i=1 ; i<=n ; i++)
                for (j=1 ; j<=n ; j++)
                        p[i][j]=0;
        floyd (W,n,p);
        cout<<endl;
        //system("pause");
		cout<<"\n Press R to reset program or Enter to exit ...";
		ans=getche();
		system("cls");
		if (ans=='r') goto reset;
		



}
//*************************************************************
void Random(int W[x][x],int n)
{
        int i,j;
        cout<<endl;
        for (i=1 ; i<=n ; i++)
                for (j=1 ; j<=n ; j++)
                {
                        W[i][j]=0;
                        if (i != j){
                                W[i][j]=rand()%9;
								if(W[i][j]==0) W[i][j]=infinity;}
                        else
                                W[i][j]=0;

                }
}
//******************************************************************
void manual(int W[x][x],int n)
{
        int i,j;
        cout<<endl;
        for (i=1 ; i<=n ; i++)
                for (j=1 ; j<=n ; j++)
                {
                        W[i][j]=0;
                        if (i != j)
                        {
                                cout<<" Enter ["<<i<<"] ["<<j<<"] :";
                                cin>>W[i][j];
								if(W[i][j]==0)
									W[i][j]=infinity;
                        }
                        else
                                W[i][j]=0;
                }

}
//***************************************************************
void show (int i,int j,int p[x][x])
{
        if(p[i][j]!=0)
        {
                show (i,p[i][j],p);
                cout<<" Shortest path from "<<i<<" to "<<j<<" by "<<p[i][j];
                cout<<endl;
                show (p[i][j],j,p);
        }

}
//****************************************************************
void floyd (int D[x][x],int n,int p[x][x] )
{
        int i,j,k;
        for (k=1;k<=n;k++)
                for(i=1;i<=n;i++)
                        for(j=1;j<=n;j++)
                                if((D[i][k]+D[k][j])<D[i][j])
                                {
                                        D[i][j]=D[i][k]+D[k][j];
                                        p[i][j]=k;
                                }
        cout<<"\n Matrix of shortest path cost:\n\n";
        for (i=1;i<=n;i++)
        {
                cout<<"\t\t";
				for (j=1 ; j<=n ; j++)
						if (D[i][j] == infinity)
							cout<<"<> ";
                        else
                        {
                                cout<<D[i][j]<<" ";
                                if (D[i][j]<=9)
                                        cout<< " ";
                        }

                cout<<endl;
        }

        cout<<endl;
        cout<<" Matrix of shortest path:\n\n ";
        for (i=1 ; i<=n ; i++)
        {
                cout<<"\t\t";
                for (j=1 ; j<=n ; j++)
                        cout<<p[i][j]<<"  ";
                cout<<endl;
        }
        cout<<endl;
        cout<<"____________________________________________________";
        cout<<endl;
        for (int ii=1;ii<=n;ii++)
                for (int jj=1;jj<=n;jj++)
                        show(ii,jj,p);

}

