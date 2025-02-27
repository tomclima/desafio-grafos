# Topological Sort

*Em um projeto de sistemas, há várias tarefas a serem realizadas. Essas tarefas possuem dependência entre si, porque muitas vezes, é preciso terminar mais de uma tarefa para realizar alguma outra. Você foi contratado pelo Google para gerar a lista de tarefas que vão ser executadas em um projeto de melhoria do Youtube. Nós sabemos que, para cada tarefa, pode existir dependência de que outras tarefas tenham sido finalizadas anteriormente. Este é um problema conhecido como ordenação topológica. Utilizando necessariamente o encaminhamento em profundidade, implemente a lista de tarefas dado um grafo das tarefas e suas dependências do projeto.*

# Casos
## 0
### Input 
```
8
5
0 1
0 3
1 2
1 5
5 6
```
### Output 
```
7,4,0,3,1,5,6,2
```

## 1
### Input 
```
8
8
0 2
0 1
0 4
1 5 
2 5
3 5
3 7
6 7
```
### Output 
```
6,3,7,0,4,2,1,5
```

## 2
### Input 
```
8
9
0 1
0 3
0 4
1 2
1 6
1 5
2 5
3 7
4 7
```
### Output 
```
0,4,3,7,1,6,2,5
```

# Shortest Path

***Como encontrar o melhor caminho entre dois pontos? Como ir de um ponto a outro na cidade gastando o menor tempo?***

*Para modelar esse problema, o Waze considera diversas variáveis: tamanho das ruas, engarrafamentos nas ruas, velocidade máxima nas ruas, etc.
Se cada rua fosse "igual" (ou seja, possuísse o mesmo tamanho, o mesmo nível de engarrafamento, a mesma velocidade da via, etc), poderíamos resolver o problema do Waze com o algoritmo por encaminhamento por largura.
Vamos implementar o Waze considerando essas condições. Cada aresta representa uma rua possível de se trafegar na cidade. Entre dois pontos, qual o melhor caminho (menor sequência de arestas) que eu posso tomar?
Receba como entrada um grafo, G, e dois vértices desse grafo, A, B, e verifique qual o menor caminho (se existir) entre A e B neste grafo.
Um applet que mostra a execução da busca em largura para alguns grafos pode ser encontrado  [aqui](https://www.cs.usfca.edu/~galles/visualization/BFS.html)*

# Entrada
N ->  quantidade de vertices (vertices sempre são rotulados com 0,..., N-1)
Q -> quantidade de arestas
Vi Vj -> dois numeros inteiros para sinalizar a conexão da aresta direcionada Vi->Vj
Vi Vj -> dois numeros inteiros para sinalizar a conexão da aresta direcionada Vi->Vj
Vi Vj -> dois numeros inteiros para sinalizar a conexão da aresta direcionada Vi->Vj
...
(quantidade Q de pares Vi Vj)
Vi Vd
Vi Vd
...

# Saída
Para cada par Vi, Vd, printar 
```
A=Vi, B=Vd:
Vi, Vn, Vm, .... Vd
```
Sendo a segunda linha do output o menor caminho entre os dois vértices. 

Caso não haja caminho possível entre eles, printar
 
```
A=Vi, B=Vd:
---
```


# Casos
## 0
### input
```
8
12
0 2
1 0
1 2
1 3
2 5
2 6
3 7
4 7
5 7
6 2
6 4
6 7
0 7
1 4
4 3
```
### output
```
A=0, B=7:
0,2,5,7
A=1, B=4:
1,2,6,4
A=4, B=3:
---
```

## 1
### input
```
8
14
0 2
0 3
0 4
2 5
2 6
3 1
3 7
4 6
4 7
5 3
5 7
6 2
6 4
6 5
0 7
4 1
```
### output
```
A=0, B=7:
0,3,7
A=4, B=1:
4,6,5,3,1
```







