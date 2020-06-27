#include <iostream>
#include <vector>

using std::vector;

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

long long get_fibonacci_huge(long long n, long long m) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;
	long long tmp_previous = 0;

	vector<long> pisano;
	pisano.push_back(0);
	pisano.push_back(1);

	while (true) {
		tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % m;
		if (current == 1 and previous == 0) {
			break;
		} else {
			pisano.push_back(current);
		}
	}
	pisano.pop_back();
	long index = n % pisano.size();
	return pisano.at(index);
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	// std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge(n, m) << '\n';
}
