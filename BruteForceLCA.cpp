#include <iostream>
#include <cassert>
#include <vector>
#define MAX_N 100001

using namespace std;

int nodes, queries;

int depth[MAX_N], father[MAX_N];
int level;

void dfs(int node){

	level ++;
	depth[node] = level;

	for(int i = 2; i <= nodes; i ++)
		if(father[i] == node)
			dfs(i);
	level --;

}

int main(){

	cin >> nodes >> queries;

	assert(1 <= nodes && nodes < MAX_N);

	int x, y;

	for(int i = 2; i <= nodes; i ++){

		cin >> father[i];
		assert(1 <= father[i] && father[i] < MAX_N);

	}

	dfs(1);

	while(queries --){

		cin >> x >> y;

		assert(1 <= x && x < MAX_N);
		assert(1 <= y && y < MAX_N);

		while(x != y){
			if(depth[x] > depth[y])
				x = father[x];
			else
				y = father[y];
		}

		cout << x << "\n";

	}

	return 0;


}