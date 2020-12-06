#include<bits/stdc++.h>

using namespace std;

vector<long long> primeFactorisation(long long n) {
   vector<long long> factors;
   while (n % 2 == 0) {
      factors.push_back(2);
      n /= 2;
   }
   for (long long i = 3; i*i <= n; i += 2) {
      while (n % i == 0) {
         factors.push_back(i);
         n /= i;
      }
   }
   if (n > 2) {
      factors.push_back(n);
   }
   return factors; 
}

void run_case() {
   long long n;
   cin >> n;
   vector<long long> primeFactors = primeFactorisation(n);
   vector<long long> products;
   long long total = 1;
   while (total != n) {
      long long product = 1;
      for (int i = primeFactors.size() - 1; i >= 0; i--) {
         if (product % primeFactors[i] != 0) {
            product *= primeFactors[i];
            primeFactors[i] = 1;
         } 
      }
      total *= product;
      products.push_back(product);
   }
   cout << products.size() << "\n";
   for (int i = products.size()-1; i >= 0; i--) {
      cout << products[i] << " ";
   }
   cout << "\n";
}

void run_cases() {
   int TC;
   cin >> TC;
   for (int i = 0; i < TC; i++) {
      run_case();
   }
}

int main() {
   //freopen("d.txt", "r", stdin);
   run_cases();
}

