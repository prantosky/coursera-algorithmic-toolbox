#include <bits/c++config.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

using namespace std;

long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	} else if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else {
		assert(0);
	}
}

long long get_maximum_value(const string &exp) {
	size_t n = (exp.size() + 1) / 2;
	vector<pair<long long, long long>> solution(n * n);

	auto sol_get = [&solution, &exp, n](long long i, long long j) {
		return solution.at(i * n + j);
	};
	auto sol_set = [&solution, &exp, n](long long i, long long j,
										pair<long long, long long> value) {
		return solution[i * n + j] = value;
	};

	auto digits = [&exp](long long i) { return exp.at(2 * i) - '0'; };
	auto op = [&exp](long long i) { return exp.at(2 * i + 1); };

	for (size_t i = 0; i < n; i++) {
		sol_set(i, i, make_pair(digits(i), digits(i)));
	}
	long long temp_min, temp_max;
	long long a, b, c, d;

	for (size_t i = 1; i < n; i++) {
		for (size_t j = i; j < n; j++) {
			temp_min = numeric_limits<long long>::max();
			temp_max = numeric_limits<long long>::min();
			// cout << "(" << j - i << "," << j << ")"
			// 	 << " ";
			for (size_t k = j - i; k < j; k++) {
				a = eval(sol_get(j - i, k).first, sol_get(k + 1, j).first,
						 op(k));
				b = eval(sol_get(j - i, k).second, sol_get(k + 1, j).second,
						 op(k));
				c = eval(sol_get(j - i, k).first, sol_get(k + 1, j).second,
						 op(k));
				d = eval(sol_get(j - i, k).second, sol_get(k + 1, j).first,
						 op(k));
				temp_min = min(temp_min, min(min(a, b), min(c, d)));
				temp_max = max(temp_max, max(max(a, b), max(c, d)));
				sol_set(j - i, j, make_pair(temp_min, temp_max));
			}
		}
		// cout << endl;
	}

	// for (size_t i = 0; i < n; i++) {
	// 	for (size_t j = 0; j < n; j++) {
	// 		cout << "(" << sol_get(i, j).first << "," << sol_get(i, j).second
	// 			 << ")"
	// 			 << " ";
	// 	}
	// 	cout << endl;
	// }
	return sol_get(0, exp.size() / 2).second;
}

int main() {
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}
