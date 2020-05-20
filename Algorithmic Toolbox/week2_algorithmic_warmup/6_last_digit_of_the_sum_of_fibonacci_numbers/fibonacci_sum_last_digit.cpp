#include <iostream>

int fibonacci_sum_naive(long long n) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		sum += current;
	}

	return sum % 10;
}

long long fibonacci_sum(long long n) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;
	long long res_sum = 1, seq_sum = 1;
	long long tmp_previous = 0;

	for (long long i = 0; i < 59; ++i) {
		tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		seq_sum = (seq_sum + current) % 10;
		if (i < (n - 1) % 60) {
			res_sum = (res_sum + current) % 10;
		}
	}
	return (seq_sum * (n / 60) % 10 + res_sum) % 10;
}

int main() {
	long long n = 0;
	std::cin >> n;
	// std::cout << fibonacci_sum_naive(n);
	std::cout << fibonacci_sum(n);
}
