#include<bits/stdc++.h>

using namespace std;

int find_open_lockers() {
	int len = 100;
	vector<int>lockers(len+1);
	fill(lockers.begin(), lockers.end(), 0);
    for(int i = 2; i <= len; i++) {
        for(int j = i; j <= len; j += i) {
            lockers[j]++;
    }
    }
    int open_count = 0;
    for(int i = 1; i <= len; i++) {
        if(lockers[i] % 2 == 0) {
            open_count++;
    }
    }
    return open_count;
}

int main() {
    cout<<find_open_lockers()<<endl;
	return 0;
}
