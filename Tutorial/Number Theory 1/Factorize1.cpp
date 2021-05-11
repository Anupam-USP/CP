// Naive and optimized approach
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void primeFactors(int n){
    vector<pair<int, int>> prime;
    int cnt;

    for (int i = 2; i * i <= n;i++){
        if(n%i==0){
            cnt = 0;
            while(n%i==0){
                cnt++;
                n /= i;
            }
            prime.push_back(pair<int, int>(i, cnt));
        }
    }

    if(n!=1){
        prime.push_back(pair<int, int>(n, 1));
    }

    for(auto i:prime){
        cout << i.first << "^" << i.second << endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    primeFactors(n);

    return 0;
}