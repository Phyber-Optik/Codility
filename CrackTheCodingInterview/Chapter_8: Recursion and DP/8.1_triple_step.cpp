#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int dp[MAX];
int valid_steps[3] = {1, 2, 3};

int solve(int cur_step, int stairs_count) {
	if(cur_step >= stairs_count) return (cur_step == stairs_count);
	if(dp[cur_step] != -1) return dp[cur_step];
	int total_ways = 0;
	for(int i = 0; i < 3; i++) {
		total_ways += solve(cur_step + valid_steps[i], stairs_count);
}
return dp[cur_step] = total_ways;
}

int main(){
	memset(dp, -1, sizeof dp);
	cout<<solve(0, 10)<<endl;
	return 0;
}
