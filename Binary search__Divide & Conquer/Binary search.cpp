/*			



							Algorithm Design
			
							   Chapter 2:
						   Divide-and-Conquer


							  Project 2:
			Implementation of a divide and conquer algorithm

							  Professor:
						   Dr.Bahman Arasteh

							  Hiwa Amiri


*/



#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <stddef.h>
using std::cout;
using std::endl;
using std::cin;
void put    (int *, int);
void quick  (int*,int,int);
void switch1(int *,int);

void main()
{
	int n;
	int *p;
    system ("cls");
    cout<<"\n\n       **********************************************************";
    cout<<"\n                       *** Binary Search ***";
    cout<<"\n       **********************************************************";

	cout<<"\n\n Enter the list number (1-350,000,000): ";
	cin>>n;
	p=(int *)malloc(n * sizeof(long int));
	if(!p)
	{
		cout<<"\n Allocation failure!";
		getch();
		exit(1);
	}//end if
	put(p,n);
	clock_t start = clock();
    quick(p,0,n);
	cout<<"\n\n List sorted in "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";
    while(1)
		switch1(p,n);

}//end main

//------------------------ put ----------------------------------
void put(int *p,int n)
{
        clock_t start = clock();
        int i;
	for(i=0 ; i<n ; i++)
		*(p+i)=rand()*rand();
		system ("cls");
        cout<<"\n\n List initialized in "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";


}// end put

//------------------------ quick sort----------------------------------
void quick(int *item, int left, int right)
{


        int i,j,x,y;
        i=left;
        j=right;
        x=*(item+((left+right)/2));
        do
        {       while(*(item+i)<x && i<right) i++;
                while(x<*(item+j)&& j> left) j--;
                if(i<=j)
                {
                        y= *(item+i);
                        *(item+i)=*(item+j);
                        *(item+j)=y;
                        i++;
                        j--;
                }
        }while(i<=j);
        if(left<j) quick(item, left, j);
        if(i<right) quick(item,i,right);


}
//-------------------------------------BSearch---------------------------


void BSearch(int low, int high, int x, int *p)
{
        int mid;
        if(low>high)
                cout<<"\n ** Object not found **";
        else
        {
                mid = (low+high)/2;
                if (x==*(p+mid))
                        cout<<"\n ** Object was found in "<<mid+1<<"th row **";
                else if (x<*(p+mid))
                                return BSearch (low, mid-1,x,p);
                     else
                                return BSearch (mid+1,high,x,p);
        }
}

//-------------------------------------switch---------------------------

void switch1(int *p,int n)
{
        int x,i,y,row;
        cout<<"\n\n Press any key to continue ...  ";
        getche();
		system ("cls");
        cout<<"\n\n __________________________________________________ \n ";
		cout<<"\n Main Menu :\n ";
		cout<<"\n        1) Show List    ";
        cout<<"\n        2) Show a specific object    ";
        cout<<"\n        3) Search an item ";
		cout<<"\n        choose a case : ";
		cin>>x;
		switch(x)
		{


                        case 1:
                        cout<<endl;
                        for(i=0 ; i<=n ; i++)
		                cout<<"\n row "<<i+1<<" --> "<<*(p+i);

                        break;

                        case 2:
						retry:
                        cout<<"\n Enter row: ";
                        cin>>row;
						if (row>n){
							cout<<"\n ERROR, retry";
							goto retry;}
                        cout<<"\n amount of row "<<row<<" is "<<*(p+row-1);
                        break;

                        case 3:
                        cout<<"\n Write your number to search: ";
                        cin>>y;
                        clock_t start = clock();
                        BSearch(0,n,y,p);
                        cout<<"\n\n Elapsed time for search: "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";
                        break;

						


        }



}

