#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;

    std::cout << "? 1" << std::endl;
    int x;
    std::cin >> x;
    std::cout << "? " << 1 + n / 2 << std::endl;
    int y;
    std::cin >> y;
    if ((x - y) % 2) {
        std::cout << "! -1" << std::endl;
        return 0;
    }
    int mn = (x > y ? 1 : -1);
    int l = 1, r = n / 2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int nx, ny;
        std::cout << "? " << m << std::endl;
        std::cin >> nx;
        std::cout << "? " << (m - 1 + n / 2) % n + 1 << std::endl;
        std::cin >> ny;
        if (nx == ny) {
            std::cout << "! " << m << std::endl;
            return 0;
        }
        if ((nx - ny) * mn > 0) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << "! " << l << std::endl;
}
