#include <cmath>
#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	long long sum = 0;

	long long current = 0;
	long long next = 1;

	for (long long i = 0; i <= to; ++i) {
		if (i >= from) {
			sum += current;
		}

		long long new_current = next;
		next = (next + current) % 10;
		current = new_current;
	}
	std::cout << std::endl;
	return sum % 10;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
	if (to < from) return 0;
	vector<long> vec(60);
	long long previous = 0;
	long long current = 1;
	long long tmp_previous = 0;

	long long seq_sum = 1;

	vec[0] = 0;
	vec[1] = 1;

	for (long long i = 2; i < 60; ++i) {
		tmp_previous = current;
		current = (previous + current) % 10;
		previous = tmp_previous;
		seq_sum = (seq_sum + current) % 10;
		vec[i] = current;
	}
	seq_sum = (seq_sum * (((to - from + 1) / 60) % 10)) % 10;

	if (from / 60 == to / 60) {
		for (size_t i = from % 60; i <= to % 60; i++) {
			seq_sum = (seq_sum + vec.at(i)) % 10;
		}
	} else if (from / 60 < to / 60) {
		for (size_t i = 0; i < 60; i++) {
			if (i >= from % 60) {
				seq_sum = (seq_sum + vec.at(i)) % 10;
			}
			if (i <= to % 60) {
				seq_sum = (seq_sum + vec.at(i)) % 10;
			}
		}
	}
	return seq_sum;
}

int main() {
	long long from, to;
	std::cin >> from >> to;
	// std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
