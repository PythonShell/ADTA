#include <iostream>
#include <fstream>

using namespace std;

int binarysearch(int *arr, int low, int high, int x);

int main() {
	ifstream fin("BinarySearchRec.in");
	ofstream fout("BinarySearchRec.out");
	int x, n, *arr;
	fin >> x >> n;
	arr = new int[n+1];
	for(int i=1; i<=n; i++)
		fin >> arr[i];
	int result = binarysearch(arr, 1, n, x);
	fout << result << endl;
	return 0;
}

int binarysearch(int *arr, int low, int high, int x) {
	if(low>high)
		return 0;
	else {
		int mid = (low+high)/2;
		if(x==arr[mid])
			return mid;
		else if(x<arr[mid])
			return binarysearch(arr, low, mid-1, x);
		else
			return binarysearch(arr, mid+1, high, x);
	}
}
