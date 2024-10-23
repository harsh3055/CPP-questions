#include<bits/stdc++.h>
using namespace std;

const int N = 4;
int t;
int init[N][N], final[N][N];
int dx[] = { -1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// bool check() {
//     int inv = 0, pos = 0;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             if (init[i][j] == 0) {
//                 pos = i;
//                 continue;
//             }
//             for (int k = 0; k < i * N + j; k++) {
//                 int x = k / N, y = k % N;
//                 if (init[x][y] != 0 && init[x][y] > init[i][j])
//                     inv++;
//             }
//         }
//     }
//     if ((inv + pos) % 2 == 0) return true;
//     return false;
// }

bool dfs(int step) {
    if (step > 15) return false;
    if (memcmp(init, final, sizeof(init)) == 0) return true;
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (init[i][j] == 0) {
                x = i, y = j;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny)) {
            swap(init[x][y], init[nx][ny]);
            if (dfs(step + 1)) return true;
            swap(init[x][y], init[nx][ny]);
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    cin >> t;
    while (t--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> init[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                final[i][j] = i * N + j + 1;
            }
        }
        final[N - 1][N - 1] = 0;

        if (dfs(0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
