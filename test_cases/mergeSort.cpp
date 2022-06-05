#include <bits/stdc++.h>

using namespace std;

int comp = 0;

void merge(int *arr, int low, int mid, int high){
	int size1 = mid - low + 1;
	int size2 = high - mid;

	int temp1[size1], temp2[size2];

	for(int i=0;i<size1;i++)
		temp1[i] = arr[low + i];

	for(int j=0;j<size2;j++)
		temp2[j] = arr[mid + j + 1];

	int i = 0, j = 0, k = low;

	while(i < size1 && j < size2){
		comp++;
		if(temp1[i] <= temp2[j]){
			arr[k] = temp1[i];
			i++;
		}
		else{
			arr[k] = temp2[j];
			j++;
		}
		k++;
	}

	while(i < size1){
		arr[k] = temp1[i];
		i++;
		k++;
	}
}

void mergeSort(int *arr, int low, int high){
	if(low >= high)
		return;

	int mid = (low + high) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}

// int main(int argc, char const *argv[])
// {
// 	int arr[1000], size;

// 	int limit;

// 	cout<<"Enter the limit : ";
// 	cin>>limit;

// 	string line;

// 	fstream testCases;
// 	testCases.open("testCases.txt", ios::in);

// 	fstream data;
// 	data.open("mergeSortData.txt", ios::out);

// 	while(getline(testCases, line) && limit--){
// 		stringstream list(line);
// 		string num;
// 		size = 0;
// 		while(getline(list, num, ' ')){
// 			arr[size++] = stoi(num);
// 		}

// 		mergeSort(arr, 0, size-1);
// 		data<<comp<<endl;
// 		comp = 0;
// 	}

// 	testCases.close();
// 	data.close();
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	int size;
	cout<<"Enter the size of the array : ";
	cin>>size;

	int *arr = new int[size];
	cout<<"Enter the array : ";
	for(int i = 0; i < size; i++)
		cin>>arr[i];

	mergeSort(arr, 0, size - 1);
	cout<<"Sorted array : ";
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}