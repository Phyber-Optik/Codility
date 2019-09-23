/*
    Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/
 
#include<bits/stdc++.h>
 
typedef long long ll;
 
#define SSTR(x)         dynamic_cast< ostringstream & >( \
                        (ostringstream() << dec << x )).str()
#define pb              push_back
#define mem(a, x)       memset(a, x, sizeof a)
#define PI              acos(-1)
#define all(a)          a.begin(), a.end()
#define ff              first
#define ss              second
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             1<<30
#define eps             1e-9
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define DBG(x)          cerr<<#x<<" : "<<x<<endl
#define DBGII(x, y)     cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define DBGVEC(v, n)    FORAB(i, 0, n) { cout<<v[i]<<" "; } cout<<"\n"
#define chkwhere        cerr<<"LOL\n"
#define pii             pair<int, int>
#define MOD             1000000007
#define MAX             1000007
 
int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
 
using namespace std;

int main() {
    // read("in.txt");
    int n;
    string s;
    cin>>n>>s;
    int z_count = 0;
    for(int i = 0; i < n; i++) {
        z_count += (s[i] == 'z');
    }
    int o_count = (n - z_count * 4) / 3;
    for(int i = 0; i < o_count; i++) printf("1 ");
    for(int i = 0; i < z_count; i++) printf("0 ");
    return 0;
}