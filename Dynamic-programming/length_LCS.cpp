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

//finding length of longest common subsequence

int LCS(int n,int m,string s,string k){ /// LCS recursive memoised solution

    if(n==0 || m==0){   //base case checking for smallest valid input
        return 0;
    }

    if(dp[n][m] !=- 1){
        return dp[n][m];    //return if already present;
    }

    if(s[n-1] == k[m-1]){
        return dp[n][m] = 1+LCS(n-1,m-1,s,k);   //choice of having char equal
    }
    else{
        return dp[n][m] = max(LCS(n-1, m , s,k) , LCS(n , m-1 , s, k));   // if char is not equal
    }

}

int LCS_tabular(int n,int m,string s,string k){

    int dp2[n+1][m+1];
    //initialisation
    for(int i = 0;i<=n;i++){
        dp2[i][0] = 0;
    }
    for(int j = 0;j<=m;j++){
        dp2[0][j] = 0;
    }

    //choice diagram

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == k[j-1]){
                dp2[i][j] = 1 + dp2[i-1][j-1];
            }
            else{
                dp2[i][j] = max(dp2[i-1][j] , dp2[i][j-1]);
            }
        }
    }

    return dp2[n][m];
}

void Solve(){
    int n,m;cin>>n>>m;
    string s,k;
    cin>>s>>k;
    memset(dp,-1,sizeof(dp) );
    int res = LCS(n,m,s,k);
    cout<<res<<"\n";
    res = LCS_tabular(n,m,s,k);
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