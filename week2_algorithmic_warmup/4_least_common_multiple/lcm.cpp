#include <iostream>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0) return l;

    return (long long)a * b;
}

long long gcd(long long x, long long y) {
    long long a = std::max(x, y);
    long long b = std::min(x, y);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    long long g = gcd(a, b);

    return (a * b) / g;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    // std::cout << lcm_naive(a, b) << std::endl;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
