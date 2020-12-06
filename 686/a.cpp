#include<bits/stdc++.h>

using namespace std;

int main() {
   int a, b;
   cin >> a;
   for (int i = 0; i < a; i++) {
      cin >> b;
      for (int j = 2; j <= b; j++)
         cout << j << " ";
      cout << "1" << "\n";
   }
   return 0;
}
