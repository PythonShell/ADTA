#include <iostream>
#include <fstream>

using namespace std;

void perm2(int m, int n, int *arr);

int main() {
	ifstream fin("Permutations2.in");
	ofstream fout("Permutations2.out");
	int n, *arr;
	fin >> n;
	arr = new int[n+1];
	for(int i=1; i<=n; i++)
		arr[i] = 0;
	perm2(n, n, arr);
	delete[] arr;
	return 0;
}

void perm2(int m, int n, int *arr) {
	if(m==0) {
		for(int i=1; i<n; i++)
			cout << arr[i] << " ";
		cout << arr[n] << endl;
	}
	else {
		for(int j=1; j<=n; j++) {
			if(arr[j]==0) {
				arr[j] = m;

				perm2(m-1, n, arr);

				arr[j] = 0;
			}
		}
	}
}
