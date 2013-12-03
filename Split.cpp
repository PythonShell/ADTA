#include <iostream>
#include <fstream>

using namespace std;

int split(int *arr, int low, int high);

int main() {
	ifstream fin("Split.in");
	ofstream fout("Split.out");
	int n, *arr;
	fin >> n;
	arr = new int[n];
	for(int i=1; i<=n; i++)
		fin >> arr[i];
	fout << split(arr, 1, n) << endl;
	delete[] arr;
	return 0;
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
