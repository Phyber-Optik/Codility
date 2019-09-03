#include<bits/stdc++.h>

using namespace std;

int multiply_helper(int smaller , int larger) {
    if(smaller == 0) return 0;
    if(smaller == 1) return larger;
    int half = multiply_helper(smaller >> 1, larger);
    if(smaller % 2 == 0) {
        return half + half;
    }
    return half + half + larger;
}

int multiply(int x, int y) {
    return multiply_helper(min(x, y), max(x, y));
}

int main() {
    cout<<multiply(6, 4)<<endl;
    return 0;
}