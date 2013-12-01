#include <iostream>
#include <fstream>

using namespace std;

int candidate(int m, int n, int *arr);

int main() {
	ifstream fin("Majority.in");
	ofstream fout("Majority.out");
	int n, *arr;
	fin >> n;
	arr = new int[n+1];
	for(int i=1; i<=n; i++)
		fin >> arr[i];
	
	int c = candidate(1, n, arr);
	int count = 0;
	for(int j=1; j<=n; j++)
		if(arr[j]==c)
			count++;
	if(count>(n/2))
		fout << c << endl;
	else
		fout << "none" << endl;

	delete[] arr;
	return 0;
}

int candidate(int m, int n, int *arr) {
	int j = m;
	int c = arr[m];
	int count = 1;
	while(j<n && count>0) {
		j++;
		if(arr[j]==c)
			count++;
		else
			count--;
	}
	if(j==n)
		return c;
	else
		return candidate(j+1, n, arr);
}
