#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *arr, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

		cout<<"\nSorted sub-array after Pass "<<i+1<<" : ";
		for(int k=size-i-1; k < size; k++){
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

	bubbleSort(arr, size);
	return 0;
}