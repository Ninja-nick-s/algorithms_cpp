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

void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] <<" "  ;}
void IA(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
string yup="YES";
string nope="NO";

bool issafe(int x,int y , int** arr , int n){
    rep(i,0,x){
        if(arr[i][y]==1){
            return false;
        }
    }

    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nqueen(int x,int n,int** arr){
    if(x>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(issafe(x,i,arr,n)){
            arr[x][i] = 1;
            if(nqueen(x+1 , n ,arr)){
                return true;
            }
            arr[x][i] = 0;
        }
    }
    return false;
}

/* CHECK t */
void Solve(){
    int n;cin>>n;

    int** arr = new int*[n];
    rep(i,0,n){
        arr[i] = new int[n];
        rep(j,0,n){
            arr[i][j] = 0;
        }
    }
    if(nqueen(0,n,arr)){
        rep(i,0,n){
            rep(j,0,n){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"0";
    }
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