#include <iostream>
#include <fstream>

using namespace std;

void quicksort(int *arr, int low, int high);
int split(int *arr, int low, int high);

int main() {
	ifstream fin("QuickSort.in");
	ofstream fout("QuickSort.out");
	int n, *arr;
	fin >> n;
	arr = new int[n];
	for(int i=1; i<=n; i++)
		fin >> arr[i];
	quicksort(arr, 1, n);
	for(int i=1; i<n; i++)
		fout << arr[i] << " ";
	fout << arr[n] << endl;
	delete[] arr;
	return 0;
}

void quicksort(int *arr, int low, int high) {
	if(low<high) {
		int w = split(arr, low, high);
		quicksort(arr, low, w-1);
		quicksort(arr, w+1, high);
	}
}

int split(int *arr, int low, int high) {
	int i=low;
	int x=arr[i];
	for(int j = low+1; j<=high; j++) {
		if (arr[j]<=x) {
			i++;
			if(i!=j) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int temp = arr[low];
	arr[low] = arr[i];
	arr[i] = temp;
	return i;
}
