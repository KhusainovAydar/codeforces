#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, size_t> > voter(n); // cost and index
    std::vector<int> cnt_party(m + 1, 0);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> voter[i].second >> voter[i].first;
        cnt_party[voter[i].second]++;
    }

    std::sort(voter.begin(), voter.end());
    int64_t ans = -1;
    for (size_t i = 1; i != n + 1; ++i) {
        int64_t current_ans = 0;
        std::vector<bool> used(n, false);

        for (size_t j = 0; j != n; ++j) {
            size_t p = voter[j].second;
            int cost = voter[j].first;
            if (cnt_party[p] >= i && p != 1) {
                --cnt_party[p];
                ++cnt_party[1];
                current_ans += cost;
                used[j] = true;
            }
        }

        for (size_t j = 0; j != n; ++j) {
            size_t p = voter[j].second;
            int cost = voter[j].first;
            if (p != 1 && cnt_party[1] < i && !used[j]) {
                ++cnt_party[1];
                current_ans += cost;
                used[j] = true;
            }
        }

        if (ans == -1 || current_ans < ans) {
            ans = current_ans;
        }
        std::fill(cnt_party.begin(), cnt_party.end(), 0);
        for (size_t j = 0; j != n; ++j) {
            cnt_party[voter[j].second]++;
        }
    }

    std::cout << ans << '\n';
    return 0;
}
