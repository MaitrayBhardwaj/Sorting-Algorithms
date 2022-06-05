#include <bits/stdc++.h>

using namespace std;

long long int swaps = 0, comp = 0;

int binarySearch(int a[], int item, int low, int high){
	while(low <= high){
		int mid = (low + high) / 2;
	    if (item > a[mid]){
	        low = mid + 1;
	        comp++;
	    }
	    
	    else if(item == a[mid])
	        return mid + 1;
	 
	    else if(item < a[mid]){
	        high = mid - 1;
	        comp++;
	    }
   }
   return low;
}

void insertionSort(int *arr, int size){
	int curr, pos;
	for(int i=1;i<size;i++){
		curr = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps++;
            comp++;
        }
        swaps++;
        arr[j + 1] = curr;
	}
}

void binInsertionSort(int *arr, int size){
	int curr, pos;
	for(int i=1;i<size;i++){
		curr = arr[i];
		int j = i - 1;

		pos = binarySearch(arr, curr, 0, j);
		
		while(j >= pos){
			arr[j + 1] = arr[j];
			j--;
			comp++;
			swaps++;
		}
		comp++;
		arr[j + 1] = curr;
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
	testCases.open("testCases.txt", ios::in);

	fstream data;
	data.open("insertionSortData.txt", ios::out);

	while(getline(testCases, line) && limit--){
		stringstream list(line);
		string num;
		size = 0;
		while(getline(list, num, ' ')){
			arr[size++] = stoi(num);
		}

		insertionSort(arr, size);
		data<<swaps<<" "<<comp<<endl;
		swaps = 0;
		comp = 0;
	}

	testCases.close();
	data.close();
	return 0;
}