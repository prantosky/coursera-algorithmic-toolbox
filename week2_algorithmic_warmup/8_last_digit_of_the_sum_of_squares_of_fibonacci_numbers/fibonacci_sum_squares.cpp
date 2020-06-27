#include <cmath>
#include <iostream>
#include <vector>
using std::vector;

int fibonacci_sum_squares_naive(long long n) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		sum += current * current;
	}
	return sum % 10;
}

long long fibonacci_sum_squares(long long to) {
	if (to <= 1) return to;

	bool flag = false;
	long long previous = 0;
	long long current = 1;
	long long tmp_previous = 0;

	long long seq_sum = 1;

	for (long long i = 2; i < 60; ++i) {
		tmp_previous = current;
		current = (previous + current) % 10;
		previous = tmp_previous;
		seq_sum = (seq_sum + current * current) % 10;
	}

	seq_sum = (seq_sum * ((to / 60) % 10)) % 10;

	previous = 0;
	current = 1;
	tmp_previous = 0;
	for (size_t i = 0; i < 60; i++) {
		if (i <= 1 and i <= to % 60)
			seq_sum = (seq_sum + i) % 10;
		else if (i <= to % 60) {
			tmp_previous = current;
			current = (current + previous) % 10;
			previous = tmp_previous;
			seq_sum = (seq_sum + current * current) % 10;
		}
	}
	return seq_sum;
}

int main() {
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum_squares(n) << std::endl;
}
