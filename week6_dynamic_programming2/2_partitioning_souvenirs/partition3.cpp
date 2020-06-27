#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int partition3(vector<int> &A) {
	int n = accumulate(A.begin(), A.end(), 0);

	if (n % 3 != 0 or A.size() < 3 or *max(A.begin(), A.end()) > n / 3) {
		return 0;
	}
	vector<vector<bool>> values((n / 3 + 1), vector<bool>(A.size() + 1, 0));

	for (size_t i = 0; i <= A.size(); i++) { values[0][i] = true; }
	int count = 0;
	for (int i = 1; i <= n / 3; i++) {
		for (int j = 1; j <= A.size(); j++) {
			values[i][j] = values[i][j - 1];
			if (i >= A.at(j - 1)) {
				values[i][j] =
					values[i - A.at(j - 1)][j - 1] or values[i][j - 1];
			}
		}
	}

	for (size_t i = 0; i <= n / 3; i++) {
		cout << i << " | ";
		for (size_t j = 0; j <= A.size(); j++) { cout << values[i][j] << " "; }
		cout << endl;
	}

	return values[n / 3][A.size()];
}

int main() {
	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) { std::cin >> A[i]; }
	std::cout << partition3(A) << '\n';
}
