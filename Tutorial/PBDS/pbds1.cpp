#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;

int main()
{
    PBDS st;
    st.insert(15);
    st.insert(1);
    st.insert(10);
    st.insert(4);
    st.insert(3);

    for (ll i = 0; i < st.size(); i++)
    {
        cout << i << " " << *st.find_by_order(i) << endl;
    }

    // Tells at which index key will come if not present
    cout << st.order_of_key(5) << endl;
    return 0;
}