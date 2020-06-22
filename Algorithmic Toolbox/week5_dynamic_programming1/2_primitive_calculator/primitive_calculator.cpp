#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> optimal_sequence(int n) {
	vector<int> array(n + 1);
	vector<int> sequences;
	int a1, m2, m3;
	for (int i = 2; i <= n; i++) {
		a1 = m2 = m3 = std::numeric_limits<int>::max();
		if (i - 1 >= 0) { a1 = 1 + array.at(i - 1); }
		if (i % 2 == 0 and i / 2 >= 0) { m2 = 1 + array.at(i / 2); }
		if (i % 3 == 0 and i / 3 >= 0) { m3 = 1 + array.at(i / 3); }
		array[i] = min(a1, min(m2, m3));
	}
	auto nums = array.at(n);
	while (n > 1) {
		if (n % 3 == 0 and array.at(n / 3) + 1 == array.at(n)) {
			sequences.push_back(n);
			n /= 3;
		} else if (n % 2 == 0 and array.at(n / 2) + 1 == array.at(n)) {
			sequences.push_back(n);
			n /= 2;
		} else if (array.at(n - 1) + 1 == array.at(n)) {
			sequences.push_back(n);
			n -= 1;
		}
	}
	sequences.push_back(1);
	reverse(sequences.begin(), sequences.end());
	return sequences;
}

int main() {
	int n;
	std::cin >> n;
	// cout << optimal_sequence(n) << endl;

	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}
