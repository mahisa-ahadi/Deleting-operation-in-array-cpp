#include<iostream>
using namespace std;
int binarySearch(int a[],int size,int value)
{
	int index,mid;
	int low=0,high=size-1;
	index=-1;
	while(low<=high)
	{
	    mid=(high+low)/2;
		if(value==a[mid])
		{
			index=mid;
			break;
		}
		
		if(value<a[mid])
		{
			high=mid-1;
		}		
		if(value>a[mid])
		{
			low=mid+1;
		}
	}
    return index;
}
int main(void)
{
	int size,num;
	cout<<"enter the size of your array: ";
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
	{
		cout<<"a["<<i<<"]= ";
		cin>>a[i];
		cout<<endl;
	}
	cout<<"how many elements do you want to delete?: ";
	cin>>num;
	int b[num];
	for(int i=0;i<num;i++)
	{
		cout<<"enter element number "<<i<<": ";
		cin>>b[i];
	}
	
	//bubble sort for a[i]
	int temp;
	for(int j=1;j<size;j++)
	{
		for(int i=0;i<size-1;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}		
	}

	cout<<endl;
	//first binary search to check if the value in array b exists in array a
	int count=0;
	for(int i=0;i<num;i++)
	{
		int searchIndex=binarySearch(a, size, b[i]);
		if(searchIndex==-1)
		{
		  cout<<"The value "<<b[i]<<" is not found!"<<endl;		
		}

	}
	
	//deleting elements of array a
		for(int j=0;j<num;j++)
		{
			int searchIndex=binarySearch(a,size,b[j]);
			if(searchIndex!=-1)
			{
				size=size-1;
				for(int i=searchIndex;i<size;i++)
				{
					a[i]=a[i+1];
									
				}

			}
		}	
		
		//printing the final result
		for(int i=0;i<size;i++)
		{
			cout<<"a["<<i<<"]= "<<a[i]<<endl;
		}
	
	return 0;
}