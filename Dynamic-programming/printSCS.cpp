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


//To print shortest common subsequence

string printSCS(string a,string b,int n,int m){
    int dp[n+1][m+1];
    
    rep(i,0,n+1){
        dp[i][0] = 0;
    }
    rep(j,0,m+1){
        dp[0][j] = 0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    string s = "";
    int i = n , j = m ;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            s += a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                s += a[i-1];
                i--;
            }
            else{
                s += b[j-1];
                j--;
            }
        }
    }
    while(i>0){
        s += a[i-1];
    }
    while(j>0){
        s += b[j-1];
    }
    reverse(s.begin(),s.end());
    
    return s;
}


void Solve(){
    int n,m;//cin>>n>>m;
    string a,b;
    cin>>a>>b;
    n = a.size();m = b.size();
    string res = printSCS(a,b,n,m);
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