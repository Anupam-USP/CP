#include <bits/stdc++.h>
using namespace std;
#define ll long long

void generate_bracks(char *out, int n, int idx, int open, int close){
    if(idx==2*n){
        out[idx] = '\0';
        cout << out << endl;
        return;
    }

    if(open<n){
        out[idx] = '(';
        generate_bracks(out, n, idx + 1, open + 1, close);
    }
    if(close<open){
        out[idx] = ')';
        generate_bracks(out, n, idx + 1, open, close + 1);
    }
    return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    char out[100];
    int idx = 0;
    generate_bracks(out, n, 0, 0, 0);
    return 0;
}