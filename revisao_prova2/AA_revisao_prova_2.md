# Conteudo

- Divisão e conquista
- Ordenação
- Grafos
- Algoritmo de Dijkstra (Complexodade de problemas. Análise amortizada).

<hr/>

## Lista de exercícios

1. Defina árvore geradora mínima e caminho mínimo em grafos:

   **Árvore geradora**
   É um subconjunto de grafos um grafo não dirigido que contem todos os vertices.

   **Árvore geradora mínima**
   Tendo um grafo não dirigido conectado, com suas arestas contendo pesos , uma árvore geradora mínima é o conjunto que contem as arestas com menor peso.

   **Caminho mínimo em grafos**
   É uma minimização do custo de travessia de um grafo entre dois nós;
   Esse custo é dado pela soma dos pesos de cada aresta percorrida;

    <div style="text-align:center;">
    <img style="height:15rem;" src="./assets/Minimum_spanning_tree.png" alt="Árvore geradora mínima"/>
    <img style="height:15rem;" src="./assets/caminho_minimo.jpg" alt="Caminho mínimo em grafos">
    </div>

2. Defina a matriz de adjacência do grafo G abaixo:
   
   <div style="text-align:center;">
   <img style="height:15rem;"src="./assets/grafo_q2.png" alt="Grafo G"/>
   </div>

~~~
     1 2 3 4 5 6
    ---       ---
1   |0,1,0,0,0,0|
2   |1,0,1,0,1,0|   
3   |0,1,0,1,1,0|   
4   |0,0,1,0,0,1|   
5   |0,1,1,0,0,1|   
6   |0,0,0,1,1,0|
    ---       ---
~~~

3. Em uma busca em largura, o valor **d[u]** atribuído a um vértice **u** é independente da ordem na qual são dados os vértices em cada lista de adjacência. Verdadeiro ou Falso ? Justifique sua resposta.

   **Verdadeiro**

4. Execute uma busca em profundidade a partir do vértice 0 no grafo orientado dado pelas listas de adjacência a seguir. Exiba o rastreamento da busca.
    
    | `00` | 01 | 04 |<br/>
    | `01` | 02 | 05 |<br/>
    | `02` | 03 |<br/>
    | `03` | 07 |<br/>
    | `04` | 08 |<br/>
    | `05` | 04 |<br/>
    | `06` | 05 | 10 | 02 |<br/>
    | `07` | 11 | 06 |<br/>
    | `08` | 09 |<br/>
    | `09` | 05 | 08 |<br/>
    | `10` | 09 |<br/>
    | `11` | 10 |<br/>