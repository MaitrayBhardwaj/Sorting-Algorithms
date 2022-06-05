#include <bits/stdc++.h>

using namespace std;

long long int swaps = 0, comp = 0;

void MaxHeapify(int *arr, int size, int pos){
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;

	int largest = pos;

	if(left < size && arr[left] > arr[pos]){
		largest = left;
		comp++;
	}
	if(right < size && arr[right] > arr[largest]){
		largest = right;
		comp++;
	}
	if(largest != pos){
		int temp = arr[pos];
		arr[pos] = arr[largest];
		arr[largest] = temp;
		swaps++;

		MaxHeapify(arr, size, largest);
	}
}

void heapSort(int *arr, int size){
	for(int i = size/2 - 1; i >= 0; i--){
		MaxHeapify(arr, size, i);
	}

	for(int i = size - 1; i > 0; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		swaps++;

		MaxHeapify(arr, i, 0);
	}
}

int main(int argc, char const *argv[])
{
	int arr[1000], size;

	int limit;

	cout<<"Enter the limit : ";
	cin>>limit;

	string line;

	fstream testCases;
	testCases.open("testCasesIdentical.txt", ios::in);
	
	fstream data;
	data.open("heapSortData.txt", ios::out);
	
	while(getline(testCases, line) && limit--){
		stringstream list(line);
		string num;
		size = 0;
		while(getline(list, num, ' ')){
			arr[size++] = stoi(num);
		}

		heapSort(arr, size);
		data<<swaps<<" "<<comp<<endl;
		swaps = 0;
		comp = 0;
	}

	testCases.close();
	data.close();
	return 0;
}

// int main(int argc, char const *argv[])
// {
// 	int size;
// 	cout<<"Enter the number of elements : ";
// 	cin>>size;

// 	int arr[size];

// 	cout<<"Enter the array : ";
// 	for(int i=0;i<size;i++){
// 		cin>>arr[i];
// 	}
	
// 	heapSort(arr, size);

// 	cout<<"Sorted array : ";
// 	for(int i=0;i<size;i++){
// 		cout<<arr[i]<<" ";
// 	}
// 	return 0;
// }