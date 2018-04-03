/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor,Sri City
*/
#include <bits/stdc++.h>
using namespace std;

int find_median(int *Arr,int n)
{
	sort(Arr,Arr+n);
	return Arr[n/2];
}

int partition (int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
int kth_element(int Arr[],int low,int high,int k)
{
	//cout<<k;
	int n,mm,part;
	n=high-low+1;
	int med[(n+4)/5],i=0;
	for (i = 0; i < n/5; i++)
	{
		med[i]=find_median(Arr+low+i*5,5);
	}
	if(i*5<n)
	{
		med[i]=find_median(Arr+low+i*5,n%5);
		i++;
	}
	mm=(i==1)?med[i-1]:kth_element(med,0,i-1,i/2);
	for (i=low; i<high; i++)
        if (Arr[i] == mm)
           break;
    swap(Arr[i], Arr[high]);
	part=partition(Arr,low,high);
	if(part-low==k-1)
		return Arr[part];
	if(part-low>k-1)
		return kth_element(Arr,low,part-1,k);
	return kth_element(Arr,part+1,high,k-part+low-1);
}


int main()
{
    int t;
   	cin>>t;
    while(t--)
    {
    	int n,k,value;
    	cin>>n>>k;
    	int Arr[n];
    	for (int i = 0; i < n; i++)
    	{
    		cin>>Arr[i];
    	}
    	value=kth_element(Arr,0,n-1,k);
    	cout<<value<<endl;
    }
    return 0;
}
