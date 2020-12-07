#include<bits/stdc++.h>

using namespace std;

class UnionFind {
   int *rank, *parent, n;
public:
   UnionFind(int n) {
      rank = new int[n];
      parent = new int[n];
      this->n = n;
      makeSet();
   }
   void makeSet() {
      for (int i = 0; i < n; i++) {
         parent[i] = i;
      }
   }
   int find(int x) {
      if (parent[x] != x) {
         parent[x] = find(parent[x]);
      }
      return parent[x];
   }
   void unite(int x, int y) {
      int xset = find(x);
      int yset = find(y);
      if (xset == yset) {
         return;
      }
      if (rank[xset] < rank[yset]) {
         parent[xset] = yset;
      }
      else if (rank[xset] > rank[yset]) {
         parent[yset] = xset;
      }
      else {
         parent[yset] = xset;
         rank[xset] = rank[xset] + 1;
      }
   }
};

void run_case() {
   int N;
   cin >> N;
   vector<vector<int>> adj(N);
   vector<array<int, 2>> edges(N);
   UnionFind uf(N);
   for (int i = 0; i < N; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges[i] = {u, v};
      uf.unite(u, v);
   }
}

void run_cases() {
   int TC;
   cin >> TC;
   for (int i = 0; i < TC; i++) {
      run_case();
   }
}

int main() {
   freopen("e.txt", "r", stdin);
   run_cases();
}

