#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    ll computeLineIntersection(ll A, ll B, ll X, ll Y) {
        return max(0LL, min(B, Y) - max(A, X));
    }
    ll computeRectArea(ll A, ll B, ll C, ll D) {
        return (C - A) * (D - B);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rectA = computeRectArea((ll)A, (ll)B, (ll)C, (ll)D);
        int rectE = computeRectArea((ll)E, (ll)F, (ll)G, (ll)H);
        int intersectionArea = computeLineIntersection((ll)A, (ll)C, (ll)E, (ll)G) * computeLineIntersection((ll)B, (ll)D, (ll)F, (ll)H);
        return rectA + rectE - intersectionArea;
    }
};