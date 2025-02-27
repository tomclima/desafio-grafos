#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int q;
    
    vector<vector<int>> grafo;
    
    cin >> n;
    cin >> q;
    
    grafo.resize(n);

    for (int i =0; i < q; i++){
        
        int vi;
        int vj;
        
        cin >> vi >> vj;
        
        grafo.at(vi).push_back(vj);
        
    }
    
    int vx, vd;
    
    cin >> vx >> vd;
    
    
    return 0;
}
