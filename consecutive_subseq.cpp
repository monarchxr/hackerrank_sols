//submission link - https://www.hackerrank.com/challenges/consecutive-subsequences/submissions/code/429267233

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        
        vector<int> v(n,0);
        
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        
        long long count = 0;
        long long prefix_sum = 0;
        
        unordered_map<int, int> mod_count;
        
        mod_count[0] = 1;
        
        
        for(int i = 0; i<n; i++){
            
            prefix_sum += v[i];
            
            int mod = ((prefix_sum%k)+k)%k;
            
            count += mod_count[mod];
            
            mod_count[mod]++;
        }
        
        cout << count << endl;
    } 
    return 0;
}
