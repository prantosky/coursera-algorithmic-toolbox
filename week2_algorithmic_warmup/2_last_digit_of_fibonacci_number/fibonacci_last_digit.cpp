#include <cassert>
#include <iostream>

int get_fibonacci_last_digit(int n) {
    if (n <= 1) return n;

    long long previous = 0;
    long long current = 1;
    long long tmp_previous = 0;

    for (int i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}

int main() {
    int n;
    std::cin >> n;

    int d = get_fibonacci_last_digit(n);

    std::cout << d << "\n";
}
