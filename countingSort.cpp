#include <bits/stdc++.h>

using namespace std;

void countingSort(int *arr, int size){
	int min = arr[0], max = arr[0];
	for(int i = 0; i < size; i++){
		if(arr[i] < min)
			min = arr[i];
		else if(arr[i] > max)
			max = arr[i];
	}

	int samSize = max - min + 1, ini = min;

	int *sample = new int[samSize]();

	for(int i = 0; i < size; i++){
		sample[(arr[i] - ini)]++;
	}

	for(int i = 1; i < samSize; i++){
		sample[i] += sample[i - 1];
	}

	int *sorted = new int[size];

	for(int i = size - 1; i >= 0; i--){
		sorted[(--sample[arr[i] - ini])] = arr[i];
	}

	sorted[size - 1] = max;

	cout<<"Sorted array : ";
	for(int i = 0; i < size; i++){
		cout<<sorted[i]<<" ";
	}

	delete sample;
}

int main(int argc, char const *argv[])
{
	int size;
	cout<<"Enter the number of elements : ";
	cin>>size;

	int arr[size];

	cout<<"Enter the array : ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	
	countingSort(arr, size);
	return 0;
}