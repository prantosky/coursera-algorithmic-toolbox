#include <algorithm>
#include <iostream>
#include <vector>

using std::max;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
	int seq[a.size() + 1][b.size() + 1];
	int index = 0;
	while (index <= a.size()) {
		seq[index][0] = 0;
		index++;
	}
	index = 1;
	while (index <= b.size()) {
		seq[0][index] = 0;
		index++;
	}
	for (size_t i = 1; i <= a.size(); i++) {
		for (size_t j = 1; j <= b.size(); j++) {
			if (a.at(i - 1) == b.at(j - 1)) {
				seq[i][j] = 1 + seq[i - 1][j - 1];
			} else {
				seq[i][j] = std::max(seq[i - 1][j], seq[i][j - 1]);
			}
		}
	}
	return seq[a.size()][b.size()];
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) { std::cin >> a[i]; }

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) { std::cin >> b[i]; }

	std::cout << lcs2(a, b) << std::endl;
}
