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

long get_fibonacci_partial_sum(int from, int to) {
    vector<long long> v;
    long previous = 0;
    long current = 1;

    long temp_previous = 0;
    long long sum = 0;

    v.push_back(0);
    v.push_back(1);

    for (size_t i = 0; i < 58; i++) {
        temp_previous = current;
        current = (current + previous) % 10;
        previous = temp_previous;
        v.push_back(current);
    }

    int start = from % 60;
    for (size_t i = from; i <= to; i++) {
        sum = (sum + v[start++]) % 10;
        start = start % 60;
    }
    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
