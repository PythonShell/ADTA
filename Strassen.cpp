// Algorithm Strassen,
// Used to calculate two Matrix Mutiple
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector< vector<int> > Muti(vector< vector<int> > v1, vector< vector<int> > v2); // Main function.
vector< vector<int> > Add(vector< vector<int> > v1, vector< vector<int> > v2);  // Add function.
vector< vector<int> > Dec(vector< vector<int> > v1, vector< vector<int> > v2);  // - function.

int main() {
	ifstream fin("Strassen.in");
	ofstream fout("Strassen.out");
	int n, temp;
	fin >> n;
	vector< vector<int> > v1, v2;
	vector<int> vTemp;
	for(int i=0; i<n; i++) {
		vTemp.clear();
		for(int j=0; j<n; j++) {
			fin >> temp;
			vTemp.push_back(temp);
		}
		v1.push_back(vTemp);
	}
	for(int i=0; i<n; i++) {
		vTemp.clear();
		for(int j=0; j<n; j++) {
			fin >> temp;
			vTemp.push_back(temp);
		}
		v2.push_back(vTemp);
	}
	vector< vector<int> > result;
	result = Muti(v1, v2);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			fout << result[i][j] << " ";
		fout << endl;
	}
	return 0;
}

vector< vector<int> > Muti(vector< vector<int> > v1, vector< vector<int> > v2) {
	int n = v1.size();
	int k = n/2;
	vector< vector<int> > result;
	if(n==2) {
		int d1 = (v1[0][0]+v1[1][1])*(v2[0][0]+v2[1][1]);
		int d2 = (v1[1][0]+v1[1][1])*v2[0][0];
		int d3 = v1[0][0]*(v2[0][1] - v2[1][1]);
		int d4 = v1[1][1]*(v2[1][0] - v2[0][0]);
		int d5 = (v1[0][0]+v1[0][1])*v2[1][1];
		int d6 = (v1[1][0]-v1[0][0])*(v2[0][0]+v2[0][1]);
		int d7 = (v1[0][1]-v1[1][1])*(v2[1][0]+v2[1][1]);
		vector<int> r;
		r.push_back(d1+d4-d5+d7);
		r.push_back(d3+d5);
		result.push_back(r);
		r.clear();
		r.push_back(d2+d4);
		r.push_back(d1+d3-d2+d6);
		result.push_back(r);
	}
	else {
		vector< vector<int> > a11, a12, a21, a22, b11, b12, b21, b22, c11, c12, c21, c22, d1, d2, d3, d4, d5, d6, d7, temp1, temp2;
		vector<int> vTemp1, vTemp2, vTemp3, vTemp4, vTemp5, vTemp6, vTemp7, vTemp8;
		int temp;
		for(int i=0; i<k; i++) {
			for(int j=0; j<k; j++) {
				temp = v1[i][j];
				vTemp1.push_back(temp);
				temp = v1[i][j+k];
				vTemp2.push_back(temp);
				temp = v1[i+k][j];
				vTemp3.push_back(temp);
				temp = v1[i+k][j+k];
				vTemp4.push_back(temp);
				temp = v2[i][j];
				vTemp5.push_back(temp);
				temp = v2[i][j+k];
				vTemp6.push_back(temp);
				temp = v2[i+k][j];
				vTemp7.push_back(temp);
				temp = v2[i+k][j+k];
				vTemp8.push_back(temp);
			}
			a11.push_back(vTemp1);
			a12.push_back(vTemp2);
			a21.push_back(vTemp3);
			a22.push_back(vTemp4);

			b11.push_back(vTemp5);
			b12.push_back(vTemp6);
			b21.push_back(vTemp7);
			b22.push_back(vTemp8);

			vTemp1.clear();
			vTemp2.clear();
			vTemp3.clear();
			vTemp4.clear();
			vTemp5.clear();
			vTemp6.clear();
			vTemp7.clear();
			vTemp8.clear();
		}

		temp1 = Add(a11, a22);
		temp2 = Add(b11, b22);
		d1 = Muti(temp1, temp2);

		temp1 = Add(a21, a22);
		d2 = Muti(temp1, b11);

		temp1 = Dec(b12, b22);
		d3 = Muti(a11, temp1);

		temp1 = Dec(b21, b11);
		d4 = Muti(a22, temp1);

		temp1 = Add(a11, a12);
		d5 = Muti(temp1, b22);

		temp1 = Dec(a21, a11);
		temp2 = Add(b11, b12);
		d6 = Muti(temp1, temp2);

		temp1 = Dec(a12, a22);
		temp2 = Add(b21, b22);
		d7 = Muti(temp1, temp2);

		c12 = Add(d3, d5);
		c21 = Add(d2, d4);

		temp1 = Add(d1, d4);
		temp1 = Dec(temp1, d5);
		c11 = Add(temp1, d7);

		temp1 = Add(d1, d3);
		temp1 = Dec(temp1, d2);
		c22 = Add(temp1, d6);

		for(int i=0; i<k; i++) {
			vTemp1.clear();
			for(int j=0; j<k; j++)
				vTemp1.push_back(c11[i][j]);
			for(int j=0; j<k; j++)
				vTemp1.push_back(c12[i][j]);
			result.push_back(vTemp1);
		}

		for(int i=0; i<k; i++) {
			vTemp1.clear();
			for(int j=0; j<k; j++)
				vTemp1.push_back(c21[i][j]);
			for(int j=0; j<k; j++)
				vTemp1.push_back(c22[i][j]);
			result.push_back(vTemp1);
		}
	}
	return result;
}

vector< vector<int> > Add(vector< vector<int> > v1, vector< vector<int> > v2) {
	int n = v1.size();
	int temp;
	vector<int> vTemp;
	vector< vector<int> > result;
	for(int i=0; i<n; i++) {
		vTemp.clear();
		for(int j=0; j<n; j++) {
			temp = v1[i][j] + v2[i][j];
			vTemp.push_back(temp);
		}
		result.push_back(vTemp);
	}
	return result;
}


vector< vector<int> > Dec(vector< vector<int> > v1, vector< vector<int> > v2) {
	int n = v1.size();
	int temp;
	vector<int> vTemp;
	vector< vector<int> > result;
	for(int i=0; i<n; i++) {
		vTemp.clear();
		for(int j=0; j<n; j++) {
			temp = v1[i][j] - v2[i][j];
			vTemp.push_back(temp);
		}
		result.push_back(vTemp);
	}
	return result;
}
