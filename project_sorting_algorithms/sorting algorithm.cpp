/*			



					Algorithm Design
			
					  Chapter 1:
	    Algorithms—Efficiency, Analysis, and Order
		      	   
					  Project 1:
	Calculate the execution time of sorting algorithms
			
					 Professor:
				 Dr.Bahman Arasteh

					 Hiwa Amiri


*/

#include "stdafx.h"

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <stddef.h>
using namespace std;
void put(int *, int);
void bubble(int *,int);
void selection(int *, int);
void insertion(int *, int);
void quick(int*,int,int);
void switch1(int *,int);

void main()
{
	int n;
	int *p;
	system("cls");
    cout<<"\n\n       **********************************************************";
    cout<<"\n       *** Calculate the execution time of sorting algorithms ***";
    cout<<"\n       **********************************************************";
	cout<<"\n\n Enter the list number (1-100,000,000): ";
	cin>>n;
	p=(int *)malloc(n * sizeof(int));
	if(!p)
	{
		cout<<"\n Allocation failure!";
		getch();
		exit(1);
	}//end if
	put(p,n);
    while(1)
		switch1(p,n);

}//end main

//------------------------ put ----------------------------------
void put(int *p,int n)
{
        clock_t start = clock();
        int i;
		for(i=0 ; i<n ; i++)
			*(p+i)=rand();
        system("cls");
        cout<<"\n Elapsed time for initialization "<<n<<" case(s): "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";


}// end put


//------------------------ bubble sort ----------------------------------
void bubble(int *temp,int len)
{
        clock_t start = clock();
	int i, j, item;
	for(i=len-1 ; i>0 ; i--)
		for(j=0 ; j<i ; j++)
			if(*(temp+j)>*(temp+j+1))
			{
				item=*(temp+j);
				*(temp+j)=*(temp+j+1);
				*(temp+j+1)=item;
			}
        cout<<"\n Elapsed time for Bubble sorting: "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";
}
//------------------------ selection sort ----------------------------------
void selection(int *p,int n)
{


    clock_t start = clock();
	int i,j,index,large;
	for(i=n-1 ; i>0 ; i--)
	{
		large=*p;
		index=0;
		for(j=1 ; j<=i ; j++)
			if(*(p+j)>large)
			{
				large=*(p+j);
				index=j;
			}
		*(p+index)=*(p+i);
		*(p+i)=large;

	}
        cout<<"\n Elapsed time for selection sorting: "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";
}

//------------------------ insertion sort ----------------------------------
void insertion(int *p, int n)
{

        clock_t start = clock();
	int i,j,*t;
	for(i=1 ; i<n ; i++)
	{
		(*t)=*(p+i);
		for(j=i; j>0 && *(p+j-1)>(*t); j--)
			*(p+j)=*(p+j-1);
		*(p+j)=(*t);
	}

         cout<<"\n Elapsed time for insertion sorting: "<<((double)clock() - start) / CLOCKS_PER_SEC<<" second(s).";
}
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
//-------------------------------------switch---------------------------
void switch1(int *p,int n)
{
        int x,i;
        int *temp;

	cout<<"\n\n By which algorithm do you want to sort :\n ";
	cout<<"\n        1) bubble sort    ";
        cout<<"\n        2) selection sort ";
        cout<<"\n        3) insertion sort ";
        cout<<"\n        4) quick sort     ";
        cout<<"\n        choose a case : ";
	cin>>x;
	switch(x)
	{
		case 1:
                temp=(int *)malloc(n * sizeof(int));
                for(i=0 ; i<n ; i++)
		        *(temp+i)=*(p+i);
                bubble(temp,n);
                break;

		case 2:
                temp=(int *)malloc(n * sizeof(int));
                for(i=0 ; i<n ; i++)
		        *(temp+i)=*(p+i);
				selection(temp,n);
                break;

		case 3:
                temp=(int *)malloc(n * sizeof(int));
                for(i=0 ; i<n ; i++)
		        *(temp+i)=*(p+i);
                selection(temp,n);
                break;

                case 4:
                temp=(int *)malloc(n * sizeof(int));
                for(i=0 ; i<n ; i++)
		        *(temp+i)=*(p+i);
                clock_t start4 = clock();
                quick(temp,0,n);
                cout<<"\n Elapsed time for quick sorting: "<<((double)clock() - start4) / CLOCKS_PER_SEC<<" seconds";
                break;
        }


        cout<<"\n\n        5) print sorted data  ";
        cout<<"\n        6) print unsorted data ";
        cout<<"\n        7) return to algorithm sort menu ";
        cout<<"\n        8) exit ";
        cout<<"\n        choose a case : ";
        cin>>x;
        switch(x)
        {
                        case 5:
                        for(i=0 ; i<=n ; i++)
		                cout<<"\t"<<*(temp+i);
                        free(temp);
                        break;

                        case 6:
                        for(i=0 ; i<=n ; i++)
		                cout<<"\t"<<*(p+i);
                        break;

                        case 7:
                        system("cls");
                        switch1(p,n);
                        break;

                        case 8:
                        exit(1);
        }



}

