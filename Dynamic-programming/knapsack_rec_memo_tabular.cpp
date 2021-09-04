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

//DP begin till DP has no end

int dp[10000][10000];

int knapsack(int val[],int wt[],int W,int n){   // 0/1 knapsack problem
    if( n==0 || W==0 ){
        return 0;           //base case
    }

    if( dp[n][W] != -1 ){
        return dp[n][w];    // To return the memoized value
    }

    if( wt[n-1] <= W ){
        return dp[n][w] = max(
                val[n-1] + knapsack(val,wt,W-wt[n-1],n-1) , //including the value
                knapsack(val,wt,W,n-1)         //for not including the value & weight
            ) ;
    }
    else if( wt[n-1]> W ){
        return knapsack(val,wt,W,n-1);
    }
}

int knapsack_tab(int val[],int wt[],int W, int n){    //tabular way of solving knapsack problem
    for(int i= 0;i<10000;i++){
        dp[i][0] = dp[0][i] = 0;    //initialisation of 2d array refering base case
    }

    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<W+1;j++){
            if(wt[i-1] <= W){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] ,
                        dp[i-1][j] ;
                    );
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

void Solve(){
    int n,W;cin>>n>>W;
    int wt[n];IA(wt,n);
    int val[n];IA(val,n);

    memset( dp , -1 , sizeof(dp) );

    int res_rec = knapsack(val,wt,W,n);

    int res_tab = knapsack_tab(val,wt,W,n);

    cout<<res_rec<<" "<<res_tab;

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
