/*************************************Ninja-nick-s*****************************************/

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

/* CHECK t */
void Solve(){
    int n; cin>>n;
    int k=n;
    vector<int> a(n+1);
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            a[i]++;
            n = n/i;
        }
        if(n==1){
            break;
        }
        
    }
    a[n]=1;
    for(auto x:a){
        cout<<x;
    }
    if(n==k){
        cout<<"\nno. is prime";
    }
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

