#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n ;
    cin >> n;
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
            cout << max(abs(i - (n - 1)), abs(j - (n - 1))) + 1 << " ";
      }
      cout << endl;
    }
    return 0;
}
