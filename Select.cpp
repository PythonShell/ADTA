#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int select(vector<int> arr, int low, int high, int k);

int main() {
	ifstream fin("Select.in");
	ofstream fout("Select.out");
	int k, n, temp;
	vector<int> arr;
	fin >> k >> n;
	for(int i=1; i<=n; i++) {
		fin >> temp;
		arr.push_back(temp);
	}
	int res = select(arr, 0, n-1, k);
	fout << res << endl;
	return 0;
}

int select(vector<int> arr, int low, int high, int k) {
	int p = high - low + 1;
	if(p<44) {
		sort(arr.begin()+low, arr.begin()+high);
		return arr[low+k-1];
	}
	int q = p/5;
	vector<int> M;
	for(int i=0; i<q; i++) {
		sort(arr.begin()+5*i, arr.begin()+5+5*i);
		M.push_back(arr[3+5*i]);
	}
	int mm = select(M, 0, q-1, q/2);
	vector<int> A1, A2, A3;
	for(int i=low; i<=high; i++) {
	if(arr[i]<mm)
		A1.push_back(arr[i]);
	else if(arr[i]==mm)
		A2.push_back(arr[i]);
	else
		A3.push_back(arr[i]);
	}
	if(A1.size()>=k)
		return select(A1, 0, A1.size()-1, k);
	else if( (A1.size() + A2.size()) >=k)
		return mm;
	else
		return select(A3, 0, A3.size()-1, k-A1.size()-A2.size() );
}
