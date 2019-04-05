#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n, m;
    std::cin >> n >> m;
    std::vector<bool> used(n, false), killed(n, false), ans(n, false);
    std::vector<std::vector<size_t>> g(n), gr(n);

    for (size_t i = 0; i != m; ++i) {
        size_t a, b;
        std::cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    for (size_t i = 0; i != n; i++) {
        if (killed[i])
            continue;
        used[i] = true;
        for (auto &j: g[i]) {
            killed[j] = true;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (used[i]) {
            bool bad = false;
            for (auto &j : gr[i]) {
                if (ans[j]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                ans[i] = true;
            }
        }
    }

    int k = 0;
    for (size_t i = 0; i != n; ++i) {
        if (ans[i]) {
            ++k;
        }
    }
    std::cout << k << '\n';
    for (size_t i = 0; i != n; ++i) {
        if (ans[i]) {
            std::cout << i + 1 << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
