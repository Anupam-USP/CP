#include <bits/stdc++.h>
using namespace std;
#define ll long long

void generate_subs(char *in, char *out, int i,int j){
    // base case
    if(in[i]=='\0'){
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // rec case
    // to include the char
    out[j] = in[i];
    generate_subs(in, out, i + 1, j + 1);
    // to exculde the char
    generate_subs(in, out, i + 1, j);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char input[] = "abc";
    char output[100];
    generate_subs(input, output, 0, 0);
    return 0;
}