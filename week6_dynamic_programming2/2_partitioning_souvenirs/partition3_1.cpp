#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<long long>& w) {
	vector<vector<long long>> values(w.size() + 1, vector<long long>(W + 1));
	for (size_t i = 0; i <= W; i++) { values[0][i] = 0; }
	for (size_t i = 0; i <= w.size(); i++) { values[i][0] = 0; }

	for (size_t i = 1; i <= w.size(); i++) {
		for (size_t j = 1; j <= W; j++) {
			if (j >= w[i - 1]) {
				values[i][j] = max(w[i - 1] + values[i - 1][j - w[i - 1]],
								   values[i - 1][j]);
			} else {
				values[i][j] = values[i - 1][j];
			}
		}
	}
	return values[w.size()][W];
}

bool partition3(vector<long long>& A) {
	long long n = accumulate(A.begin(), A.end(), 0);
	// cout << n << " " << *max_element(A.begin(), A.end()) << endl;
	if (n % 3 != 0 or A.size() < 3 or
		*max_element(A.begin(), A.end()) > n / 3) {
		// cout << "Invalid";
		return false;
	}

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	vector<long long> partitions(3, 0);
	return optimal_weight(n / 3, A) == n / 3 and
		   optimal_weight(2 * n / 3, A) == 2 * n / 3;
}

int main() {
	int n;
	std::cin >> n;
	vector<long long> A(n);
	for (size_t i = 0; i < A.size(); ++i) { std::cin >> A[i]; }
	std::cout << partition3(A) << '\n';
}
