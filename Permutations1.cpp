#include <iostream>
#include <fstream>

using namespace std;

void perm1(int m, int n, int *arr);

int main() {
	ifstream fin("Permutations1.in");
	int n, *arr;
	fin >> n;
	arr = new int[n+1];
	for(int i=1; i<n+1; i++)
		arr[i] = i;
	perm1(1, n, arr);
	delete[] arr;
	return 0;
}

void perm1(int m, int n, int *arr) {
	if(m==n) {
		ofstream fout("Permutations1.out", fstream::app);
		for(int i=1; i<n; i++)
			fout << arr[i] << " ";
		fout << arr[n] << endl;
		fout.close();
	}
	else {
		for(int j=m; j<=n; j++) {
			int temp;

			temp = arr[j];
			arr[j] = arr[m];
			arr[m] = temp;

			perm1(m+1, n, arr);

			temp = arr[j];
			arr[j] = arr[m];
			arr[m] = temp;
		}
	}
}

