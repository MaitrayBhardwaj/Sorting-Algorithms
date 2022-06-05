#include <bits/stdc++.h>

using namespace std;

int swaps = 0, comp = 0;

int HoarePrtn(int *arr, int low, int high){
	int piv = arr[low];
	int i = low - 1, j = high + 1;

	while(true){
		do{
			i++;
			comp++;
		}while(arr[i] < piv);

		do{
			j--;
			comp++;
		}while(arr[j] > piv);

		if(i >= j){
			break;
		}

		if(i < j){
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			swaps++;
		}
	}
	int temp = arr[j];
	arr[j] = arr[low];
	arr[low] = temp;
	swaps++;

	return j;
}

int lomutoPrtn(int *arr, int low, int high){
	int piv = arr[high];
	int i = low - 1;

	for(int j = low; j < high; j++){
		if(arr[j] <= piv){
			i++;
			comp++;

			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			swaps++;
		}
	}

	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	swaps++;

	return i+1;
}

void quickSort(int *arr, int low, int high){
	if(low < high){
		int j = lomutoPrtn(arr, low, high);
		quickSort(arr, low, j-1);
		quickSort(arr, j+1, high);
	}
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
// 	data.open("quickSortData.txt", ios::out);

// 	while(getline(testCases, line) && limit--){
// 		stringstream list(line);
// 		string num;
// 		size = 0;
// 		while(getline(list, num, ' ')){
// 			arr[size++] = stoi(num);
// 		}
// 		quickSort(arr, 0, size-1);
// 		data<<swaps<<" "<<comp<<endl;
// 		swaps = 0;
// 		comp = 0;
// 	}

// 	testCases.close();
// 	data.close();
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	int arr[50], size;
	cout<<"Enter the size : ";
	cin>>size;

	cout<<"Enter the array : ";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}

	quickSort(arr, 0, size-1);
	cout<<"Sorted array : ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}