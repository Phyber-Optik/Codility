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
int A[1001][1001];

int main() {
    // read("in.txt");
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scan(A[i][j]);
        }
    }
    long long x = (long long)A[0][1];
    long long y = (long long)A[0][2];
    long long z = (long long)A[1][2];
    int a = (int)sqrt((x * y) / z);
    printf("%d ", a);
    for(int i = 1; i < n; i++) {
        printf("%d ", A[0][i] / a);
    }
    return 0;
}