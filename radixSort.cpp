#include <bits/stdc++.h>

using namespace std;

int digit(int num, int d){
	return (((int)(num / pow(10, d - 1)) % 10));
}

void radixSort(int *arr, int size){
	int max = arr[0];
	for(int i = 0; i < size; i++){
		if(arr[i] > max)
			max = arr[i];
	}

	int *sorted = new int[size];

	int samSize = 10, d = log10(max) + 1;

	int *sample = new int[samSize]();

	for(int i = 1; i <= d; i++){
		for(int j = 0; j < samSize; j++){
			sample[j] = 0;
		}

		for(int j = 0; j < size; j++){
			sample[digit(arr[j], i)]++;
		}

		for(int j = 1; j < samSize; j++){
			sample[j] += sample[j - 1];
		}

		for(int j = size - 1; j >= 0; j--){
			sorted[(--sample[digit(arr[j], i)])] = arr[j];
		}

		for(int j = 0; j < size; j++){
			arr[j] = sorted[j];
		}
	}
	
	cout<<"Sorted array : ";
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
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
	
	radixSort(arr, size);
	return 0;
}