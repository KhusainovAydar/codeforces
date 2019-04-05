#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int used[60][60];
int sit[60];
bool second = false;
struct Point{
    int x, y;
};

bool check(Point p) {
    if (1 <= p.x && p.x <= n && 1 <= p.y && p.y <= n && used[p.x][p.y] == 0) {
        return true;
    }
    return false;
}

vector< pair<pair<int, int>, int>>  go_up(vector<Point> points) {
    vector<pair< pair<int, int>, int> > path;
    while (true) {
        bool flag = false;
        for (int i = 0; i < m; i++) {
            Point nw = points[i];
            nw.x += dx[2];
            nw.y += dy[2];
            if (check(nw)) {
                Point p = points[i];
                used[nw.x][nw.y] = used[p.x][p.y];
                used[p.x][p.y] = 0;
                points[i] = nw;
                flag = true;
                path.push_back({{p.x, p.y}, 2});
            }
        }
        if (!flag) break;
    }

    for (int i = 1; i <= n; i++) {
        int pos = -1;
        if (used[i][1]) continue;
        for (int j = 0; j < m; j++)
        {
            if (points[j].y != 1 and (pos == -1 or abs(points[pos].x - i) > abs(points[j].x - i) or
            (abs(points[pos].x - i) == abs(points[j].x - i) and points[pos].y < points[j].y)))
                pos = j;
        }
        if (pos == -1) break;
        Point p = points[pos];
        while (i < p.x) {
            path.push_back({{p.x, p.y}, 3});
            Point nw = p;
            nw.x += dx[3];
            nw.y += dy[3];
            used[nw.x][nw.y] = used[p.x][p.y];
            used[p.x][p.y] = 0;
            p = nw;
        }

        while (i > p.x) {
            path.push_back({{p.x, p.y}, 1});
            Point nw = p;
            nw.x += dx[1];
            nw.y += dy[1];
            used[nw.x][nw.y] = used[p.x][p.y];
            used[p.x][p.y] = 0;
            p = nw;
        }

        while (1 < p.y) {
            path.push_back({{p.x, p.y}, 2});
            Point nw = p;
            nw.x += dx[2];
            nw.y += dy[2];
            used[nw.x][nw.y] = used[p.x][p.y];
            used[p.x][p.y] = 0;
            p = nw;
        }
        points[pos] = p;
    }
    if (n > 2) {
        if (second) {
            for (int i = 1; i <= n; i++) {
                if (!used[i][1]) continue;
                int num = sit[used[i][1]];
                Point p;
                p.x = i, p.y = 1;
                path.push_back({{p.x, p.y}, 0});
                p.x += dx[0];
                p.y += dy[0];

                while (num < p.x) {
                    path.push_back({{p.x, p.y}, 3});
                    p.x -= 1;
                }

                while (num > p.x) {
                    path.push_back({{p.x, p.y}, 1});
                    p.x += 1;
                }

                path.push_back({{p.x, p.y}, 0});
                p.x += dx[0];
                p.y += dy[0];
            }
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (used[i][j] == 0) continue;
                    Point p = {i, j};
                    while (true) {
                        Point nw = p;
                        nw.x += dx[3];
                        nw.y += dy[3];
                        if (check(nw)) {
                            path.push_back({{p.x, p.y}, 3});
                            used[nw.x][nw.y] = used[p.x][p.y];
                            used[p.x][p.y] = 0;
                            p = nw;
                        } else {
                            break;
                        }
                    }
                }

            }
            for (int i = 1; i <= m; i++) {
                sit[used[i][1]] = i;
                Point p;
                p.x = i, p.y = 1;
                path.push_back({{p.x, p.y}, 0});
                p.x += dx[0];
                p.y += dy[0];
                path.push_back({{p.x, p.y}, 0});
                p.x += dx[0];
                p.y += dy[0];
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!used[i][1]) continue;
            int num = used[i][1];
            Point p;
            p.x = i, p.y = 1;
            if (i == 1) {
                path.push_back({{p.x, p.y}, 0});
                p.x += dx[0];
                p.y += dy[0];
            }
            while (num < p.x) {
                path.push_back({{p.x, p.y}, 3});
                p.x -= 1;
            }

            while (num > p.x) {
                path.push_back({{p.x, p.y}, 1});
                p.x += 1;
            }
            if (i == 2) {
                path.push_back({{p.x, p.y}, 0});
                p.x += dx[0];
                p.y += dy[0];
            }
        }
    }
    second = true;
    return path;
}


int main()
{

#ifdef ONPC
    assert(freopen("/home/contest/CLionProjects/untitled/a.in", "r", stdin));
    assert(freopen("/home/contest/CLionProjects/untitled/a.out", "w", stdout));
#endif
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector< Point > points(m);
    vector< Point > points1(m);
    vector< Point > points2(m);
    for (int i = 0; i < m; i++) {
        cin >> points1[i].x >> points1[i].y;
        used[points1[i].x][points1[i].y] = i + 1;
    }

    vector< pair< pair<int, int>, int> > ans1, ans2;
    points = points1;
    ans1 = go_up(points);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            used[i][j] = 0;

        }
    }
    for (int i = 0; i < m; i++) {
        cin >> points2[i].x >> points2[i].y;
        used[points2[i].x][points2[i].y] = i + 1;
    }
    points = points2;
    ans2 = go_up(points);
    reverse(ans2.begin(), ans2.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            used[i][j] = 0;

        }
    }
    for (int i = 0; i < m; i++) {
        used[points1[i].x][points1[i].y] = i + 1;
    }
    int k = static_cast<int>(ans1.size() + ans2.size());
    cout << k << endl;
    for (int i = 0; i < ans1.size(); i++) {
        int x = ans1[i].first.first;
        int y = ans1[i].first.second;
        int de = ans1[i].second;
        cout << x << ' ' << y <<  ' ' << x + dx[de] << ' ' << y + dy[de] << endl;
        used[x + dx[de]][y + dy[de]] = used[x][y];
        used[x][y] = 0;
    }
    for (int i = 0; i < ans2.size(); i++) {
        int x = ans2[i].first.first;
        int y = ans2[i].first.second;
        int de = ans2[i].second;
        cout << x + dx[de] << ' ' << y + dy[de] << ' ' << x << ' ' << y << endl;
        used[x][y] = used[x + dx[de]][y + dy[de]];
        used[x + dx[de]][y + dy[de]] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (used[points2[i].x][points2[i].y] != i + 1)
            cout << "dfghdkjsghdsfg";
    }
}
