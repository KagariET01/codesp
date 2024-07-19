#include "Minesweeper.h"

//----do not modify above----

void defuse_mines(int N){

}

//----do not modify below----

#ifndef ONLINE_JUDGE
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace {
	int N,x,y;
	std::vector<std::pair<int,int>> mines;
	int arr[510][510];
	bool vis[510][510];
	int count1,count2,correct;
	void wa(const char* msg) {
		printf("Wrong Answer: %s\n", msg);
		exit(0);
	}
}

int detect(int x,int y){
	++count1;
	if(x<1||y<1||x>N||y>N)
		wa("invalid detect query");
	return arr[x][y];
}

void defuse(int x,int y){
	++count2;
	if(count2 > N)
		wa("too many defuse operations");
	if(x<2||y<2||x>N-1||y>N-1)
		wa("invalid defuse operation");
	if(!vis[x][y]){
		vis[x][y] = 1;
		for(auto i:mines){
			if(i==std::make_pair(x,y)){
				correct++;
			}
		}
	}
}

int main() {
	assert(1 == scanf("%d", &N));
	for(int i=1;i<=N;i++){
		assert(2 == scanf("%d %d", &x, &y));
		mines.push_back(std::make_pair(x,y));
	}
	for(int i=0;i<N;i++){
		x = mines[i].first;
		y = mines[i].second;
		for(int j=-1;j<=1;j++){
			for(int k=-1;k<=1;k++){
				arr[x+j][y+k]++;
			}
		}
	}
	defuse_mines(N);
	printf("Accepted: %d %d %d %d\n", N, count1, count2, correct);
}
#endif // ONLINE_JUDGE

