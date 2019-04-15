#include <fstream>
#include <climits>
#include <cassert>
#include <vector>
#define DIM 200001
#define MAX_N 100001
#define MAX_Q 2000001

using namespace std;

int nodes, queries;
vector <int> edges[MAX_N];
vector< pair <int, int> > pairs[MAX_N];
int root[MAX_N];
int count[MAX_N];
int color[MAX_N];
int anc[MAX_N]; 
int ans[MAX_Q];

ifstream fin("lca.in");
ofstream fout("lca.out");

int find(int x){

    int var = x;

    while(var != root[var])
        var = root[var];

    while(x != root[x]){
        int aux = root[x];
        root[x] = var;
        x = aux;
    }

    return var;

}

void unite(int x, int y){

    int a = find(x), b = find(y);

    if(a == b)
        return;

    if(count[a] >= count[b]){
        root[b] = a;
        count[a] += count[b];
    }else{
        root[a] = b;
        count[b] += count[a];
    }

}

void DFS(int node){

    root[node] = node;
    anc[find(node)] = node;

    for(vector<int>::iterator it = edges[node].begin(); it != edges[node].end(); it ++){
        DFS(*it);
        unite(find(node), find(*it));
        anc[find(node)] = node;
    }

    color[node] = 1;

    for(vector< pair <int, int> >::iterator it = pairs[node].begin(); it != pairs[node].end(); it ++)
        if(color[it->first])
            ans[it->second] = anc[find(it->first)];


}

void parseTree(){

    fin >> nodes >> queries;

    assert(1 <= nodes && nodes <= MAX_N);
    assert(1 <= queries && queries <= MAX_Q);

    int x;

    for(int i = 2; i <= nodes; i ++){
        fin >> x;
        assert(1 <= x && x <= MAX_N);
        edges[x].push_back(i);
    }

    for(int i = 1; i <= queries; i ++){
        int x, y;
        fin >> x >> y;

        assert(1 <= x && x <= MAX_N);
        assert(1 <= y && y <= MAX_N);

        pairs[x].push_back(make_pair(y, i));
        pairs[y].push_back(make_pair(x, i));
    }

}

int main(){

    parseTree();

    DFS(1);

    for(int i = 1; i <= queries; i ++)
        fout << ans[i] << "\n";

    fin.close();
    fout.close();

    return 0;
}


