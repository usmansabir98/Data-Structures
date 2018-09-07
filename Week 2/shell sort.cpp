#include<iostream>
#include<iomanip>
using namespace std;
void swap(int *p1, int *p2)
{
	int temp = *p2;
	*p2=*p1;
	*p1 = temp;
}
void shellSort(int arr[], int n)
{
	int temp,i,j, gap, beg, end;
	
	for(gap=n/2; gap>0;gap/=2)
	{
		for(end=gap; end<n; end++)
		{
			temp = arr[end];
			for(j=end; j>=gap && arr[j-gap]>temp; j-=gap)
				arr[j] = arr[j-gap];
			arr[j] = temp;
		}
	}
}

void printArray(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << setw(4) << arr[i];
	cout << endl;
}

int main()
{
	int data[9] = {22,44,10,7,37,21,33,52,4};
	cout << "Original Array: "; printArray(data,9);
	shellSort(data,9);
	cout << "\n\nSorted Array: "; printArray(data,9);
}
