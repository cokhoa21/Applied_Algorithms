#include <iostream>

const int MOD = 1000000007;

long long power_mod(long long a, long long b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        long long half_pow = power_mod(a, b / 2);
        return (half_pow * half_pow) % MOD;
    } else {
        return (a * power_mod(a, b - 1)) % MOD;
    }
}

int main() {
    // Input
    long long a, b;
    std::cin >> a >> b;

    // Output
    long long result = power_mod(a, b);
    std::cout << result << std::endl;

    return 0;
}