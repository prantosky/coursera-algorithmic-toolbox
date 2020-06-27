#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	int seq[a.size() + 1][b.size() + 1][c.size() + 1];
	for (size_t i = 0; i <= a.size(); i++) {
		for (size_t j = 0; j <= b.size(); j++) {
			for (size_t k = 0; k <= c.size(); k++) { seq[i][j][k] = 0; }
		}
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			for (int k = 1; k <= c.size(); k++) {
				if (a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]) {
					seq[i][j][k] = 1 + seq[i - 1][j - 1][k - 1];
				} else {
					seq[i][j][k] =
						max(seq[i][j][k - 1],
							max(seq[i][j - 1][k],
								max(seq[i - 1][j][k],
									max(seq[i][j - 1][k - 1],
										max(seq[i - 1][j][k - 1],
											max(seq[i - 1][j - 1][k],
												seq[i - 1][j - 1][k - 1]))))));
				}
			}
		}
	}
	return seq[a.size()][b.size()][c.size()];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) { std::cin >> a[i]; }
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) { std::cin >> b[i]; }
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) { std::cin >> c[i]; }
	std::cout << lcs3(a, b, c) << std::endl;
}
