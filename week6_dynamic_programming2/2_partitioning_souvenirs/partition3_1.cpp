#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int optimal_weight(int W, vector<long long>& w) {
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
	vector<bool> marks(w.size(), false);
	int ret_val = 0;
	if (values[w.size()][W] != W) {
		return values[w.size()][W];
	} else {
		ret_val = values[w.size()][W];
	}
	int i = w.size();
	int j = W;
	int weight_remaining = W;
	while (i > 0 and j > 0) {
		if (w[i - 1] + values[i - 1][j - w[i - 1]] == weight_remaining) {
			// cout << w[i - 1] << " ";
			marks.at(i - 1).flip();
			weight_remaining -= w[i - 1];
			j = j - w[i - 1];
			i = i - 1;
		} else if (values[i - 1][j] == weight_remaining) {
			i = i - 1;
		}
	}
	for (int i = w.size() - 1; i >= 0; i--) {
		if (marks.at(i)) { w.erase(w.begin() + i); }
	}
	// cout << endl;
	// cout << ret_val << endl;
	return ret_val;
}

bool partition3(vector<long long>& A) {
	long long n = accumulate(A.begin(), A.end(), 0);
	if (n % 3 != 0 or A.size() < 3 or
		*max_element(A.begin(), A.end()) > n / 3) {
		return false;
	}

	sort(A.begin(), A.end());
	// reverse(A.begin(), A.end());
	vector<long long> partitions(3, 0);
	bool part1 = optimal_weight(n / 3, A) == n / 3;
	bool part2 = optimal_weight(n / 3, A) == n / 3;
	// cout << part1 << " " << part2 << endl;
	return part1 and part2;
}

int main() {
	int n;
	std::cin >> n;
	vector<long long> A(n);
	for (size_t i = 0; i < A.size(); ++i) { std::cin >> A[i]; }
	std::cout << partition3(A) << '\n';
}
