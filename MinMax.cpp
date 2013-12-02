#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> minmax(int *arr, int low, int high);

int main() {
	ifstream fin("MinMax.in");
	ofstream fout("MinMax.out");
	vector<int> result(2, 0);
	int n, *arr;
	fin >> n;
	arr = new int[n];
	for(int i=0; i<n; i++)
		fin >> arr[i];
	result = minmax(arr, 0, n-1);
	fout << "The min is: " << result[0] << endl;
	fout << "The max is: " << result[1] << endl;
	delete[] arr;
	return 0;
}

vector<int> minmax(int *arr, int low, int high) {
	vector<int> res(2, 0);
	if((high-low)==1) {
		if(arr[low]<arr[high]) {
			res[0] = arr[low];
			res[1] = arr[high];
			return res;
		}
		else {
			res[0] = arr[high];
			res[1] = arr[low];
			return res;
		}
	}
	else {
		int mid = (low+high)/2;
		vector<int> res1 = minmax(arr, low, mid);
		vector<int> res2 = minmax(arr, mid+1, high);
		res[0] = res1[0] < res2[0] ? res1[0] : res2[0];
		res[1] = res1[1] > res2[1] ? res1[1] : res2[1];
		return res;
	}
}
