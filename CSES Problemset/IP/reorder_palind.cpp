#include<bits/stdc++.h>
using namespace std;
int main(){
      string word;
      cin >> word;
      vector<int>freq(26, 0);
      for(auto ch:word){
            freq[ch-'A']++;
      }
      int odd_count = 0;
      int mark = -1;
      for(int i=0;i<26;i++){
            if(freq[i] & 1){
                  odd_count++;
                  mark = i;
            }
      }

      if(odd_count > 1){
            cout << "NO SOLUTION\n";
      }else{
            string mid = "";
            if(mark != -1){
                  mid = string(1, 'A' + mark);
                  freq[mark]--;
            }
            string left = "", right = "";
            for(int j = 0; j < 26; j++){
                  left += string(freq[j]/2, 'A'+j);
            }
            right = left;
            reverse(right.begin(), right.end());
            cout << (left + mid + right) << endl;
      }
      return 0;
}
