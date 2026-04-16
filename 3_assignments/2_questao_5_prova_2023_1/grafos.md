# Teoria dos Grafos

## Introdução
[fonte](doc/GrafosA1.pdf)
Um grafo G consiste de um conjunto finito e não vazio de **n** nós, denotado por, `V(G)` e **m** arestas, detonado por, `A(G)`.

Cada aresta corresponde a um par não ordenado de nós, os nós constituintes de uma aresta podem ser diferentes ou não, se não forem diferentes então a aresta forma um laço.

Harary define um multigrafo como aquele que possui mais de uma aresta conectando dois vértices, mas que não possui loops. Se o grafo possui loop e múltiplas linhas conectando dois vértices então é chamado pseudografo.

<div style="text-align: center;">
  <img src="images/3.png" alt="Centered image">
  <figcaption>Multigrafo/pseudografo.</figcaption>
</div>


Dizemos que uma aresta é **incidente** aos nós aos quais está associada. **Arestas incidentes** em um mesmo nó são chamadas arestas adjacentes, como por exemplo, no nó 1, as arestas que ligam 1 e 2, e, 1 e 3 são arestas adjacentes. **Nós incidentes** em uma mesma aresta são chamados de nós adjacentes, como por exemplo 1 e 2. Um nó pode estar isolado dos demais, caso ele não esteja ligado através de uma aresta aos restantes.

<div style="text-align: center;">
  <img src="images/4.png" alt="Centered image">
  <figcaption>G1 e G2.</figcaption>
</div>

- G1 é descrito por V(G1) = {1,2,3,4,5} e A(G1) = {(1,2),(1,3),(1,4),(2,3),(2,4)}
- G2 é descrito por V(G2) = {1,2,3,4} e A(G2) = {a,b,c,d,e,f}

Um grafo dirigido, ou dígrafo, é um grafo cujas arestas são **pares ordenados**, comumente chamados de arcos ou arestas direcionadas. Os dígrafos diferem dos grafos orientados por possuirem pares simétricos de arestas direcionadas.

<div style="text-align: center;">
  <img src="images/5.png" alt="Centered image">
  <figcaption>Dígrafo e Grafo Orientado.</figcaption>
</div>

O grau de um nó corresponde ao número de arestas incidentes a ele.

> Cada laço conta como duas arestas.

O menor grau presente em um grafo G é denotado por `δ(G)`, já o maior grau presente em um grafo G é denotado por `Δ(G)`.

1. **A soma total dos graus de todos os vértices de um grafo é sempre par.**
    - B.I.: Suponha um grafo sem arcos. Todos os seus vértices têm grau zero e portanto a soma geral dos graus dos vértices é zero (par).
    - H.I.: Suponha que para todo grafo de n arestas a soma dos graus de todos os vértices é par.
    - P.I.: Suponha um grafo G de n+1 arestas. Seja G' um grafo igual a G exceto com menos uma aresta. Portanto G' tem n arestas e pela H.I. tem como soma total dos graus de seus vértices um número par.
    > A inclusão da aresta removida faz com a soma dos graus seja incrementada de 2 (é incrementado de 1 o grau dos vértices constituintes da aresta), portanto a soma dos graus dos vértices de G é um número par.
2. **Em um grafo qualquer, o número de vértices com grau ímpar tem que ser par.**
    - B.I. e H.I.

P.I. Seja G um grafo com n+1 arestas. Seja G', o grafo resultante da retirada de uma aresta (v,w). Pela H.I. G' tem um número par de vértices com grau impar.

Analisando o grafo G, baseado nas seguintes situações dos vértices v e w em G':
- **v tem grau impar e w tem grau impar**. A adição da aresta (v,w) faz com que v passe a ter grau par assim como w. Como a quantidade de vértices de grau impar é par e como transformamos 2 vértices de grau impar em vértices de grau par, G tem uma quantidade par de vértices de grau impar.
- **v tem grau impar e w tem grau par**. A adição da aresta (v,w) faz com que v passe a ter grau par e w passe a ter grau impar. Logo, G tem uma quantidade par de vértices com grau ímpar.
- **v tem grau par e w tem grau par**. A adição da aresta (v,w)  faz com que tanto v quanto w passem a ter grau impar. Como tínhamos em G' uma quantidade par de vértices de grau impar, e como aumentou em 2 esta quantidade, temos que a quantidade de vértices de grau ímpar em G é par.

Um **caminho** é um passeio que não contém nós repetidos. Entre os nós 1 e 4, do grafo G1 temos os seguintes caminhos: (1,4),(1,2,4),(1,3,2,4).

<div style="text-align: center;">
  <img src="images/6.png" alt="Centered image">
  <figcaption>G1</figcaption>
</div>

O comprimento de um caminho entre os vértices u e v é a quantidade de arestas presentes no caminho. Se existirem mais de um caminho de u a v, então o comprimento do caminho de u a v será igual ao menor comprimento dentre todos os caminho de u a v.

Um **circuito** é um passeio fechado, ou seja, o nó de partida é igual ao nó de chegada.
Um **ciclo** é um caminho fechado, isto é, um passeio que contém exatamente dois nós iguais: o primeiro e o último.
> Ciclos de comprimento 1 são laços (loops) e em ciclos, o número de arestas pertencentesa ele é igual ao número de vértices.

<div style="text-align: center;">
  <img src="images/7.png" alt="Centered image">
  <figcaption>G1</figcaption>
</div>

## Grafo Conexo/Desconexo
[fonte](doc/GrafosA2.pdf)
Um grafo é conexo se exite um caminho entre qualquer par de nós, caso contrário ele é chamado desconexo. Dois nós estão conectados se existe um caminho entre eles no grafo.

Os componentes conexos de um grafo são os subgrafos conexos maximais deste grafo, ou seja, são os subgrafos conexos que não estão estritamente contidos em outros subgrafos conexos.

O subgrafo formado pelos vértices u e v juntamente com a aresta (u,v) corresponde a componente conexo?

<div style="text-align: center;">
  <img src="images/8.png" alt="Centered image">
  <figcaption>Subgrafo</figcaption>
</div>

Não, pois ele está contido no subgrafo formado pelos nós u,v,w,x,y e arestas (u,v), (v,w), (w,x), (x,y), (y,u) e (u,x)

O grafo possui 2 componentes conexos. O primeiro é formado pelos nós u,v,w,x,y e arestas (u,v),(v,w),(w,x),(x,y),(y,u) e (u,x) e o segundo unicamente formado pelo nó p.

## Conjunto Independete
Um conjunto independete (maximal) em um grafo é um conjunto de vértices não adjacentes entre si que não está estritamente contido em outros conjuntos independetes.

O grafo abaixo mostra um conjunto independete de tamanho 2 formado pelos vértices (u,w).
<div style="text-align: center;">
  <img src="images/9.png" alt="Centered image">
  <figcaption>G1</figcaption>
</div>

## Grafo Totalmente conexo/desconexo
Um **grafo totalmente desconexo** tem todos os seus vértices com grau zero. Já um **grafo completo ou completamente conexo** de n vértices, denotado por Kn, possui a característica de que todo vértice do grafo é adjacente aos demais.

<div style="text-align: center;">
  <img src="images/10.png" alt="Centered image">
  <figcaption>Kn</figcaption>
</div>

> Um grafo completo Kn possui exatamente n(n-1)/2 arestas.

## Cliques
Um clique de um grafo é um conjunto de vértices adjacentes entre si que não está estritamente contido em outros cliques. Um clique de G é um subgrafo completo de G.

## Grafo Regular
Um grafo G é regular se todos os vértices de G possuírem o mesmo grau.

<div style="text-align: center;">
  <img src="images/11.png" alt="Centered image">
  <figcaption>Grafo Regular</figcaption>
</div>

Observe que todo grafo completo é regular de grau n-1, onde n corresponde ao número de vértices.

## Grafo Platônico
Um **grafo platônico** se forma com seus vértices e arestas a estrutura de um dos cinco sólidos platônicos (tetraedro, cubo, octaedro, dodecaedro, icosaedro). Um sóido platônico é convexo se suas faces correspondem a polígonos regulares e convexos.

<div style="text-align: center;">
  <img src="images/12.png" alt="Centered image">
  <figcaption>Grafo Platônico</figcaption>
</div>

## Grafo Bipartido
Um grafo G é bipartido se seus vértices podem ser separados em dois conjuntos disjuntos (independentes) de tal forma que toda aresta do grafo liga sempre dois vértices, um de cada conjunto.

<div style="text-align: center;">
  <img src="images/13.png" alt="Centered image">
  <figcaption>Grafo Bipartido</figcaption>
</div>

Neste caso, o conjunto de vértices pode ser dividido em dois conjuntos V1={y,u,v} e V2={x,z,w}.

## Grafo K-partido
Um grafo G é K-partido se ele possuir k conjuntos independentes. Logo, um grafo G bipartido é um grafo com 2 conjuntos independentes, portanto, ele é 2-partido.

<div style="text-align: center;">
  <img src="images/14.png" alt="Centered image">
  <figcaption>Grafo K-partido</figcaption>
</div>

## Grafo Estrela
Um grafo estrela é um grafo bipartido de n vértices que possui um conjunto independete com um único vértice e outro com n-1 vértices

<div style="text-align: center;">
  <img src="images/15.png" alt="Centered image">
  <figcaption>Grafo Estrela</figcaption>
</div>

## Grafo K-Cubos
Um k-cubo, Qk, são grafos bipartidos cujos vértices são k-tuplas de 0's e 1's, onde os vértices adjacentes diferem em exatamente uma coordenada.

<div style="text-align: center;">
  <img src="images/16.png" alt="Centered image">
  <figcaption>Grafo K-Cubo</figcaption>
</div>

## Representação
Um grafo pode ser descrito através de matrizes ou listas. A matriz de incidência de um grafo G associa os vértices de grafo às arestas do grafo. Cada entrada (a,b) desta matriz pode assumir os valores 0,1 ou 2.

1. O valor 0 indica que a aresta b não é incidente ao vértice a.
2. O valor 1 informa que o vértice a é incidente à aresta b e que a aresta b não é um laço.
3. O valor 3 indica que a aresta b é incidente ao vértice a e que ela é um laço.

<div style="text-align: center;">
  <img src="images/17.png" alt="Centered image">
  <figcaption>Grafo G e Matriz Incidência</figcaption>
</div>

A matriz de adjacência mostra o relacionamento entre os nós de um grafo. Se um nó a for adjacente a um nó b, então na matriz de adjacência M as entradas M[a,b] e M[b,a] serão diferentes de 0.

O valor armazenado nestas entradas indicará a quantidade de arestas existentes entre os vértices a e b.

<div style="text-align: center;">
  <img src="images/18.png" alt="Centered image">
  <figcaption>Grafo G e Matriz Adjacência</figcaption>
</div>

Uma lista de adjacência armazena o relacionamento entre os vértices de um grafo em uma estrutura de listas.

Note que para listar todos os nós adjacentes a um nó ni basta percorrermos a sua lista encadeada. Se quisermos saber se um nó ni é adjacente ao nó nk, basta realizar uma busca linear na lista associada a ni.

## Isomorfismo
Dois grafos G e G' são isomorfos, ou seja, G =~ G' se eles apresentam as mesmas propriedades estruturais.

Definição: Dois grafos G e G' são isomorfos se existe uma função bijetora `f: V(G) -> V(G')`, tal que`(u, v) E A(G) sse (f(u), f(v)) E A(G')`.

Logo,

```
 1   3   2
(1)-(2)-(3)
     G

(1)-(3)-(2)
     G'

G =~ G'
```

A relação de isomorfismo é uma relação de equivalência sobre o conjunto de grafos simples.

Propriedade reflexiva: uma permutação da identidade dos vértices de G é um isomorfismo de G para si próprio.

Propriedade simétrica: Se f: V(G) -> V(G') é uma função que define o isomorfismo entre G e G', então f-1 é a função que define o isomorfismo entre G' e G.

<div style="text-align: center;">
  <img src="images/19.png" alt="Centered image">
  <figcaption>Isomorfismo</figcaption>
</div>

Ou seja, as arestas u e v, pertencem as arestas de A(G) (arestas de G), se e somente se, f(u) e f(v) pertencerem a A(G') (arestas de G'). A mesma coisa acontece com a função inversa.

Se `f: V(G) -> V(H)` e `l: V(H) -> V(M)`, então pela propriedade de transitividade, `G=~H` e `H=~M`, que implica em `G=~M`.

Uma relação de equivalência divide um conjunto de grafos em classes de equivalência, onde dois grafos pertencem ao mesmo conjunto se e somente se eles são isomorfos.

Uma classe isomórfica de grafos é uma classe de equivalência de grafos regida por uma relação de isomorfismo, um exemplo de classe isomórfica é a classe chamada grafo de petersen.

### Grafo de Petersen
Um grafo de Petersen é um grafo simples não orientado gerado usando o seguinte conjunto S={1,2,3,4,5}. Seus vértices estão associados a subconjuntos de dois elementos de S.

Os vértices formados a partir destes subconjuntos serão conectados por uma aresta se seus subconjuntos correspondentes forem disjutos.

### Automorfismo
Um automorfismo de um grafo G é um isomorfismo de G para si próprio. 

Os automorfismos de G sã permutações de V(G) que podem ser aplicadas a ambas as linhas e colunas da matriz de adjacência sem mudar a adjacência entre os vértices de G.

<div style="text-align: center;">
  <img src="images/20.png" alt="Centered image">
  <figcaption>Matriz Adjacência do grafo G</figcaption>
</div>

G possui 2 automorfismos: ele próprio e a permutação que mapeia o vértice 1 para o vértice 4 e o vértice 2 para o vértice 3.

<div style="text-align: center;">
  <img src="images/21.png" alt="Centered image">
  <figcaption>Mapeamento e re-arranjo</figcaption>
</div>

Apenas trocar a identidade do vértice 1 pela identidade do 4 não é um automorfismo de G. Embora este grafo seja isomórfico ao grafo G, ele não é um automorfismo de G.

<div style="text-align: center;">
  <img src="images/21.png" alt="Centered image">
  <figcaption>Mapeamento e re-arranjo</figcaption>
</div>
