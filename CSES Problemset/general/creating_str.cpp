#include<bits/stdc++.h>
using namespace std;
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

long long uniquePermutations(string s) {

    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }

    long long numerator = factorial(s.size());
    
    long long denominator = 1;
    for (int f : freq) {
        if (f > 1) denominator *= factorial(f);
    }
    return numerator / denominator;
}

int main(){
      string s;
      cin>>s;
      sort(s.begin(), s.end());
      cout<<uniquePermutations(s)<<"\n";

      do{
            cout<<s<<"\n";
      }while(next_permutation(s.begin(), s.end()));
      return 0;
}