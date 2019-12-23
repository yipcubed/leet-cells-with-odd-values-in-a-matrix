#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>> &indices) {
    int odd = 0;
    vector<vector<int>> f;
    vector<int> singlerow(m);
    for (int i = 0; i < n; ++i) {
      f.push_back(singlerow);
    }
    for (auto &mx : indices) {
      int extrarow = mx[0];
      int extracol = mx[1];
      for (int col = 0; col < m; ++col) {
        ++f[extrarow][col];
      }
      for (int row = 0; row < n; ++row) {
        ++f[row][extracol];
      }
    }
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        if (f[row][col] % 2 != 0)
          ++odd;
      }
    }
    return odd;
  }
};

void test1() {
  int n = 2;
  int m = 3;
  vector<vector<int>> indices{vector<int>{0, 1}, vector<int>{1, 1}};

  cout << "6 ? " << Solution().oddCells(n, m, indices) << endl;
}

void test2() {

}

void test3() {

}