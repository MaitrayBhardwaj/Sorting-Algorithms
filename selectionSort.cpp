#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *arr, int size){
	int min;
	for(int i=0;i<size-1;i++){
		min = i;
		for(int j=i+1;j<size;j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;

		cout<<"\nSorted sub-array after Pass "<<i+1<<" : ";
		for(int k=0;k<=i;k++){
			cout<<arr[k]<<" ";
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[50], size;
	cout<<"Enter the size of the array : ";
	cin>>size;

	cout<<"Enter the elements of the array : ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}

	selectionSort(arr, size);
	return 0;
}