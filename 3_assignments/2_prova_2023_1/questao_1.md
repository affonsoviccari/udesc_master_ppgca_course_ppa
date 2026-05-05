# Questão 1

Um  dos  maiores  desafios  na  programação  de  alto  desempenho  e  reportar  com eficiência  os resultados obtidos.

a) Quando apresentar resultados de aceleração, informe se a comparação e realizada frente a uma
execução paralela simples ou frente a um código sequencial otimizado. Discuta sobre como um código pode ser  otimizado,  mesmo  mantendo  sua  estrutura  sequencial.  Indique  exemplos  de  ações  que  podem  ser realizadas. 

---

Um código sequencial pode ser otimizado aplicando boas práticas de programação, para reduzir a quantidade de instruções, essas boas práticas são singulares para cada tipo de linguagem. Além disso, também pode-se utilizar atalhos para evitar carregar bibliotecas pesadas de matemática, como por exemplo armazenar valores de sen/cos ou trocar pow(2,x), por x*x.

Também, pode-se passar algumas tarefas sequenciais para o compilador, além de configurar o compilador com parâmetros de otimização, como -O1, -O2, -O3, -Ofast.

---

b) Para  medição  de  tempos  paralelos,  o  ideal  e  obter  individualmente  os  tempos  necessarios  para sincronização, comunicação e processamento. Discuta sobre a complexidade no balanceamento de carga de sistemas paralelos. Como uma arquitetura heterogênea pode prejudicar o paralelismo?

---

Uma arquitetura heterogênea é composta por dispositivos que podem ser semelhantes mas que definitivamente não são iguais, com uma arquitetura deste tipo a complexidade do balanceamento de carga é muito elevada pois cada hardware diferente deve ser considerado, e isso não é uma tarefa simples.

---