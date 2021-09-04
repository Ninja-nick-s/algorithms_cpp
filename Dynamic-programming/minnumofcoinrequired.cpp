/*************************************Ninja-nick-s*****************************************/

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define YES {cout<<"YES\n";return;} 
#define NO {cout<<"NO\n";return;} 
#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(auto i=(start)-((start)>(end));i!=(end)-((start)>(end));((start)<(end)?i++:i--))
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);
ll ans = 1;
while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}
return ans;}
#define int long long
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] <<" "  ;}
void IA(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
string yup="YES";
string nope="NO";

int dp[1000][1000];

int mincoinrequired(int a[],int n,int sum){
    for(int i= 0;i<=sum;i++){
        dp[0][i] = INT_MAX-1;
    }
    for(int j = 1;j<=n;j++){
        dp[j][0] = 0;
    }
    for(int j = 1;j<=sum;j++){
        if(j%a[0] == 0){
            dp[1][j] = j/a[0];
        }
        else{
            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(a[i-1]<=sum){
                dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-a[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}


void Solve(){
    int n,sum;cin>>n>>sum;
    int a[n];IA(a,n);
    
    int res = mincoinrequired(a,n,sum);

    cout<<res;
}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    fast;
    int t = 1;
    //cin >> t;
    //cout<<fixed<<setprecision(9);
    while(t--){
        Solve();cout<<"\n";
    }
    return 0;
}