#include<bits/stdc++.h>

using namespace std;

int main() {
   int TC;
   cin >> TC;
   for (int i = 0; i < TC; i++) {
      int N;
      cin >> N;
      vector<int> A(N);
      map<int, int> freq;
      for (auto &a : A) {
         cin >> a;
         freq[a]++;
      }
      int winner = -1;
      for (int j = 0; j < N; j++) {
         if (freq[A[j]] == 1 && (winner == -1 || A[j] < A[winner])) {
            winner = j;
         }
      }
      if (winner != -1) winner++;
      cout << winner << "\n";
   }
}
