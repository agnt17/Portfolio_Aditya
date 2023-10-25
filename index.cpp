#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>//policy based data structure
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define svec sort(v.begin(), v.end());
#define sarr sort(arr,arr+n);
#define reversearr reverse(arr,arr+n)
#define reversestr reverse(str.begin(),str.end())
#define minvec *min_element(v.begin(),v.end())
#define maxvec *max_element(v.begin(),v.end())
#define issorted is_sorted(v.begin(),v.end())
typedef pair<int,pair<int,int>> ppi;
//indexed set
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int countDigit(int n)
{
    return floor(log10(n) + 1);
}

bool newwaybinary(vector<int> &v, int &n, int &target){
int p=0;
for(int i=n;i>=1;i/=2){
while(i+p<n && v[i+p]<=target){
p+=i;
}
}
return v[p]==target;
}

const int MOD = 1e9+7;
const int mod = 998244353;
const int inf  = 2e18 ;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef agent17
    #endif
    // cout<<fixed<<setprecision(9);
    // s.find_by_order(index_position for indexed set)
    // s.order_of_key(element_position for indexed set)
    int n,k;cin>>n>>k;
    vector<int> steps;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;steps.pb(x);
    }
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minsteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if(i-j>=0){
                int jump = dp[i-j] + abs(steps[i] - steps[i-j]);
                minsteps = min(minsteps, jump);
            }
        }
        dp[i] = minsteps;
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}