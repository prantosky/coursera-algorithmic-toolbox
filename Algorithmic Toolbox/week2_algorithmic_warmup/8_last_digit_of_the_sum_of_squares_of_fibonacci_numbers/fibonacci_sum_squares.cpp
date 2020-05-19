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

long fibonacci_sum_squares(int to) {
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

    int start = 0;
    for (size_t i = 0; i <= to; i++) {
        sum = (sum + v[start] * v[start]) % 10;
        start++;
        start = start % 60;
    }
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
