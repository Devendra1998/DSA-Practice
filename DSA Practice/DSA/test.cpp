#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int arr[10000008];

// C++ program to print dimensions of a
// multidimensional array

template <typename T, size_t N> void printDimensions(const T (&a)[N]) {
  std::cout << N;
}

template <typename T, size_t N, size_t M>
void printDimensions(const T (&a)[N][M]) {
  std::cout << N << "x";
  printDimensions(a[0]);
}

int32_t main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // int a[2][3][4][1];
  // printDimensions(a);
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<string>> matrix(n, vector<string>(m));
  vector<vector<int>> ans(n, vector<int>(m));
  vector<pair<int, int>> os;
  vector<pair<int, int>> bomb;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == "O") {
        ans[i][j] = 1;
        os.push_back({i, j});
      } else if (matrix[i][j] == "W") {
        ans[i][j] = -1;
      } else if (matrix[i][j] == "B") {
        ans[i][j] = 0;
        bomb.push_back({i, j});
      }
    }
  }
  for (int i = 0; i < os.size(); i++) {
    int dist = INT_MAX;
    for (int j = 0; j < bomb.size(); j++) {
      int temp_dist =
          abs(os[i].first - bomb[j].first) + abs(os[i].second - bomb[j].second);
      dist = min(dist, temp_dist);
    }
    ans[os[i].first][os[i].second] = dist;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
