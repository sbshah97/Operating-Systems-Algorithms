#include <bits/stdc++.h>
using namespace std;

int max[10][10], allocation[10][10], available[10], allocation[10][10], process_order[10];

int main() {
	//Number of processes
	int n;

	//Number of states
	int m;

	//Enter the max matrix
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			scanf("%d",&max[i][j]);
		}
	}

	//Enter the allocation matrix
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			scanf("%d",&allocation[i][j]);
		}
	}

	//Enter the available matrix
	for(int i = 0; i < m; i ++) {
		scanf("%d",&available[i]);
	}

	//Enter the need matrix
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	int count = n;
	int process_no = 1;

	while(count) {
		for(int i = 0; i < n; i ++) {
			if(process_no > 5)
				process_no = 1;
			if(process_no == process_order[i]) {
				process_no = (process_no+1);
			}
		}


		int flag = 1;
		for(int i = 0; i < m; i ++) {
			if(need[process_no-1][i] > available[i])
				flag = 0;
		}

		if(flag)

	}



	return 0;
}
