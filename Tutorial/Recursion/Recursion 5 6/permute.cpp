#include <bits/stdc++.h>
using namespace std;
#define ll long long

void permute(char *in, int i){
    if(in[i]=='\0'){
        cout << in << endl;
        return;
    }

    // Rec case
    for (int j = i; in[j] != '\0';j++){
        swap(in[i], in[j]);
        permute(in, i + 1);
        // Backtracking
        swap(in[i], in[j]);
    }
}

void unique_permute(char *in, int i, set<string> &s){
    if(in[i]=='\0'){
        string t(in);
        s.insert(t);
        return;
    }

    // Rec case
    for (int j = i; in[j] != '\0';j++){
        swap(in[i], in[j]);
        unique_permute(in, i + 1, s);
        // Backtracking
        swap(in[i], in[j]);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char in[100];
    set<string> s;
    cin >> in;
    permute(in, 0);
    cout << "Sets: " << endl;
    unique_permute(in, 0, s);
    for(auto i:s)
        cout << i << endl;
    return 0;
}