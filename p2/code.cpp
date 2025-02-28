/**
EQUIPE:

ARTHUR FERREIRA POMPILIO
GUSTAVO FELIPE ALVES DA SILVA
PAULA NÓBREGA DE CAMPOS GUIMARAES
TOMÉ DA COSTA LIMA



**/


#include <bits/stdc++.h>
using namespace std;

struct node{
    
    int val;
    node* prox;
    
};



struct fila {
    
    node* frente;
    node* tras;
    int tam;
    
};


fila* cria_fila(){
    
    fila* f = new fila();
    node* header = new node();
    header -> val = -1;
    f -> frente = header;
    f -> tras = header;
    f -> tam = 0;
    
    return f;
}

void libera_fila(fila* p) {
    while (p->frente) {
        node* temp = p ->frente;
        p->frente = p ->frente->prox;
        delete temp;
    }
    delete p;
}

void enqueue(fila* fil, int num){
    
    node* el = new node();
    el -> val = num;
    el -> prox = nullptr;
    fil -> tras -> prox = el;
    fil -> tras = fil -> tras -> prox;
    fil -> tam++;
}


int dequeue(fila* fil){
    
    if (fil -> tam != 0){
        
        node* el;
        el = fil -> frente -> prox;
        fil -> frente -> prox = fil -> frente -> prox -> prox;
        if (fil -> frente -> prox == nullptr){
            fil -> tras = fil -> frente;
            
        }
        fil -> tam--;
        return el -> val;
    }
    else{
        
        return -1;
    }
}







void menor_caminho (int ant[], int inicio, int final){
    
    vector<int> caminho_invertido;
    int x = final;
    
    while(true){
        
        if (x == -1){
            
            cout << "---" << endl;
            break;
        }
            
        if (x == inicio){
            
            caminho_invertido.push_back(x);
            
            for (int k = caminho_invertido.size() - 1; k >= 0; k--){
                
                if (k == 0){
                    cout << caminho_invertido[k] << endl;
                }
                else{
                    cout << caminho_invertido[k] << ",";
                }
            }
            
            break;
        } 
        
        caminho_invertido.push_back(x);
        x = ant[x];
        
    }
    
    return;
}



void bfs(vector<vector<int>> grafo, int inicio, int final, int n){

    
    bool visitado[n];
    int ant [n];
    
   
    
    for (int j = 0; j < n; j++){
        
        visitado[j] = false;
        ant[j] = -1;
        
    }



    fila* f = cria_fila();
    enqueue(f, inicio);
    visitado[inicio] = true;

    while(f->tam > 0){

        int v = dequeue(f);

        for (int g = 0; g < grafo.at(v).size(); g++){
            
            int h = grafo.at(v).at(g);

            if (visitado[h] == false){

                visitado[h] = true;
                ant[h] = v;
                enqueue(f, h);

            }


        }
    }

   
    menor_caminho (ant, inicio, final);

    
    return;

}





int main()
{
    int n;
    int q;

    cin >> n;
    cin >> q;
    
    vector<vector<int>> grafo;
    grafo.resize(n);


    for (int i =0; i < q; i++){
        
        int vi;
        int vj;
        
        cin >> vi >> vj;
        
        grafo.at(vi).push_back(vj);
        
    }
    
    int vx;
    
    while(cin >> vx){
        
        int vd;
        cin >> vd;
        cout << "A=" << vx << ", B=" << vd << ":" << endl; // fiquei em dúvida se botava esse ":", porque só aparece no output do primeiro test case
        bfs(grafo, vx, vd, n);
        cout << " "<< endl;
        
    }
    
    
    
    
    return 0;
}
