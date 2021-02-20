/*************************************Ninja-nick-s*****************************************/
//Fast exponentiation
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);
ll ans = 1;
while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}
return ans;}

void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] <<" "  ;}
void IA(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}

int power(int n, int p){
    if(p==0){
        return 1;
    }
    else if(p==1){
        return n;
    }                                           //Fast exponentiation  
    else{                                       //can be used in modulus also
        int k = power(n,p/2);                   //and other arithmatic operations as well
        if(p%2==0){
            return k*k;
        }
        else{
            return k*k*n;
        }
    }
}

/* CHECK t */
void Solve(){
    int n,p; cin>>n>>p;
    cout<<power(n,p);
}
 
int main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
        Solve();cout<<"\n";
    }
    return 0;
}

