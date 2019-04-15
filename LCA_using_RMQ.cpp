#include <fstream>
#include <climits>
#include <cassert>
#include <vector>
#define DIM 200001
#define MAX_N 100001
#define MAX_Q 2000001
#define MAX_LOG_N 20

using namespace std;

int nodes, queries;
int LCA[MAX_LOG_N][DIM];
int log[DIM];
vector <int> edges[MAX_N];
int depth[DIM];
int first[MAX_N];
int eulerPath[DIM];
int kappa, level;

ifstream fin("lca.in");
ofstream fout("lca.out");

inline void precompute(){

    log[0] = INT_MIN;
    log[1] = 0;

    for(int i = 2; i <= kappa; i ++)
        log[i] = log[i / 2] + 1;

    for(int i = 1; i <= kappa; i ++){
        LCA[0][i] = i;
    }

    for(int i = 1; i <= log[kappa]; i ++)
        for(int j = 1; i <= log[kappa - j]; j ++){

            int pow = (1 << (i - 1));
            LCA[i][j] = LCA[i - 1][j];

            if(depth[LCA[i][j]] > depth[ LCA[i - 1][j + pow] ])
                LCA[i][j] = LCA[i - 1][j + pow];

        }

}

inline void parseTree(){

    fin >> nodes >> queries;

    assert(1 <= nodes && nodes <= MAX_N);
    assert(1 <= queries && queries <= MAX_Q);

    int x;

    for(int i = 2; i <= nodes; i ++){
        fin >> x;
        assert(1 <= x && x <= MAX_N);
        edges[x].push_back(i);
    }

}

void eulerWalk(int node){

    level ++;
    eulerPath[++ kappa] = node;
    first[node] = kappa;
    depth[kappa] = level;

    for(std::vector<int>::iterator it = edges[node].begin(); it != edges[node].end(); it ++){

        eulerWalk(*it);
        eulerPath[++ kappa] = node;
        depth[kappa] = level;

    }

    level --;

}

int queryHandler(int a, int b){

    int sol;

    a = first[a];
    b = first[b];

    if(a > b)
        swap(a, b);

    int L = log[b - a + 1];

    sol = LCA[L][a];

    if(depth[sol] > depth[ LCA[L][b - (1 << L) + 1] ])
        sol = LCA[L][b - (1 << L) + 1];

    return eulerPath[sol];

}

int main(){

    parseTree();
    level = 0;
    eulerWalk(1);
    precompute();

    while(queries --){
        int x, y;
        fin >> x >> y;

        assert(1 <= x && x <= MAX_N);
        assert(1 <= y && y <= MAX_N);

        fout << queryHandler(x, y) << "\n";
    }

    fin.close();
    fout.close();

    return 0;


}


