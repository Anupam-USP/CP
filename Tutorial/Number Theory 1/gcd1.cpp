#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a,int b){
    // euclidean
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a,int b){
    return a * b / gcd(a, b);
}

int x, y, GCD;

void gcdext(int a,int b){
    // extended euclidean
    if (b==0){
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    gcdext(b, a % b);
    int cX = y;
    int cY = x - (a / b) * y;

    x = cX;
    y = cY;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << gcd(4, 12) << endl;
    gcdext(18, 30);
    cout << x << " : " << y << endl;
    return 0;
}