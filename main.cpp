#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int counting_distinct_subseq(string str, string key) {
  char dp_array[key.length() + 1][str.length() + 1];
  
  // Initializing the array with zero, to hadnle the grabage values
  for(int i=0; i<=key.length();i++) {
    for(int j=0; j<=str.length(); j++) {
      if(i == 0)
        dp_array[i][j] = 1;
      else
        dp_array[i][j] = 0;
    } 
  }

  for(int i=1; i<=key.length();i++) {
    for(int j=1; j<=str.length(); j++) {
      if(key[i-1]==str[j-1])
      {
        dp_array[i][j]=dp_array[i-1][j-1]+dp_array[i][j-1];
      }
      else
        dp_array[i][j]=dp_array[i][j-1];
    }
  }
  return dp_array[key.length()][str.length()]; 
}

int main() {
  string str = "babgbag";
  string key = "bag";
  
  int result = counting_distinct_subseq(str, key);
  cout<<"Distinct subsequence = "<<result<<endl;   
} 