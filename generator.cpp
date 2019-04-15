#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <string.h>
#define DIM 200001
#define MAX_N 100001

using namespace std;

int N, Q;
int P[MAX_N];
set< std::pair<int,int> > QSet;
vector< pair<int, int> > Queries;

int generateTree(){

    vector<int> V[N + 1];
    queue<int> Q;
    int visited[N + 1];
    memset(visited, 0, sizeof(visited));
    int hasRoot = 0;

    for(int i = 2; i <= N; i ++){
        int x = rand() % N + 1;
        while(x == i)
            x = rand() % N + 1;
        P[i] = x;
        V[x].push_back(i);
        V[i].push_back(x);
        if(x == 1)
            hasRoot = 1;
    }

    if(!hasRoot)
        return 0;

    Q.push(1);
    visited[1] = 1;

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        for(std::vector<int>::iterator it = V[node].begin(); it != V[node].end(); it ++){
            if(!visited[*it]){
                Q.push(*it);
                visited[*it] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i ++)
        if(!visited[i])
            return 0;


    return 1;

}

void generateQueries(int Q){

    Queries.clear();
    QSet.clear();

    int x, y;

    while(Q){

        x = rand() % N + 1;
        y = rand() % N + 1;

        if(x > y)
            swap(x, y);

        if(x == y || QSet.count(make_pair(x, y)))
            continue;

        QSet.insert(make_pair(x, y));
        Queries.push_back(make_pair(x, y));

        Q --;
    }



}

int main(){

    time_t t;

    srand((unsigned)time(&t));

    cin >> N >> Q;

    while(!generateTree());

    cout << N << " " << Q << "\n";

    for(int i = 2; i <= N; i ++)
        cout << P[i] << " ";

    cout << "\n";
/*
    for(int i = 2; i <= N; i ++)
        fout << i << " ";

    cout << endl;
*/

    generateQueries(Q);

    for(int i = 0; i < Q; i ++)
        cout << Queries[i].first << " " << Queries[i].second << "\n";

}
