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

bool isPallindrome(string s,int i,int j){
    if(i>=j){
        return true;
    }
    while(i < j){
        if(s[i] != s[j]){
            //cout<<s[i];
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int dp[1000][1000];

int partition(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(isPallindrome(s,i,j)){
        return 0 ;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int mini = INT_MAX;
    for(int k = i;k<j;k++){
        int left,right;
        if(dp[i][k]!=-1){
            left = dp[i][k];
        }
        else{
            left = partition(s,i,k);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1){
            right = dp[k+1][j];
        }
        else{
            right = partition(s,k+1,j);
            dp[k+1][j]=right;
        }

        int temp = left+right+1;

        mini=min(mini,temp);

    }
    return dp[i][j] = mini;

}

void Solve(){
    int n;cin>>n;
    string s;cin>>s;
    memset(dp,-1,sizeof(dp));
    int res = partition(s,0,n-1);
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