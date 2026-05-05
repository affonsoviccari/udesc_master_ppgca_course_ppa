# Questão 4

As  nuvens  computacionais estão  presentes  em  diversas  areas  da  computação,  auxiliando  em múltiplos aspectos, inclusive na busca por computação de alto desempenho. É fato que o uso de nuvens para processamento  de  alto  desempenho  apresenta  vantagens  e  desafios. Especificamente  sobre  os  desafios, utilize  as  figuras  abaixo  (que  representam  alguns  conceitos  sobre  escalonamento  e  gerenciamento)  para explicar o impacto do compartilhamento de recursos sobre as aplicações com uso intensivo de CPU.

---

A figura da esquerda representa um problema de mutex, que nada mais é do que o compartilhamento de recursos e memória durante a execução de um problema ou lógica. É necessário fazer o bloqueio de certos recuros para que não haja concorrência de recursos durante a execução, o que traz um problema de incerteza, pois não se sabe qual processador utilizou e disponibilizará o recurso primeiro.

A figura da direita, mostra uma topologia de uma virtualização de um dispositivo físico, um cluster local em uma máquina, onde são criadas Máquinas Virtuais que compartilham a mesma memória física, essa que por sua vez foi virtualizada. Também a uma camada adicional de monitoramento dessas máquinas virtuais.

Podemos explicar o impacto do compartilhamento de recursos, pelo fato de precisarmos de lógicas de bloqueio, que são seguras e aplicáveis quando feitas através de soluções em hardware, e a dificuldade de aplicar essas metologias em sistemas em nuvens, com a clusterização de uma máquina em diversas máquinas virtuais, criando assim um aglomerado de elementos que compartilham a mesma memória física, ainda que virtualizada.

---