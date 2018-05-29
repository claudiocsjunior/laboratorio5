#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <algorithm>
using std::transform;

int square(int val) {
	return val * val;
}

int main(int argc, char* argv[]) {
	vector<int> col;
	vector<int> col2;

	for (int i = 1; i <= 9; ++i) {
		col.push_back(i);
	}


	transform(col.begin(), col.end(), back_inserter(col2), square);

	for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;
	return 0;
}
