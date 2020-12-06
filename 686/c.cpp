#include<bits/stdc++.h>

using namespace std;

int main() {
   int TC;
   cin >> TC;
   for (int i = 0; i < TC; i++) {
      int N;
      cin >> N;
      vector<int> A(N);
      for (auto &a: A) {
         cin >> a;
      }
      A.erase(unique(A.begin(), A.end()), A.end());
      N = int(A.size());

      map<int, int> occur;

      for (auto& a : A) {
         occur[a]++;
      }

      int best = 9999;

      for (auto& a : A) {
         best = min(best, occur[a] + 1 - 1 * (A.front() == a) - 1 * (A.back() == a));
      }

      cout << best << "\n";

   }
}
