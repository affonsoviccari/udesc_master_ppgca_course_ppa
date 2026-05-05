# Questão 2

Para resolver a questão, e necessario analisar a tabela (resumo dos resultados de uma aplicação
com uso intensivo de CPU).

| # rodada | sequencial | 2 threads | 4 threads | 8 threads | 16 threads | 32 threads |
|----------|------------|-----------|-----------|-----------|------------|------------|
| 1        | 9,98       | 4,98      | 2,90      | 1,50      | 1,69       | 1,97       |
| 2        | 9,89       | 4,89      | 2,85      | 1,53      | 1,72       | 2,01       |
| 3        | 10,01      | 5,01      | 3,01      | 1,49      | 1,93       | 1,97       |
| 4        | 9,85       | 5,03      | 2,77      | 1,41      | 1,88       | 1,95       |
| 5        | 9,93       | 4,95      | 2,85      | 1,47      | 1,92       | 1,99       |

Responda aos questionamentos abaixo:
a) Qual a aceleração maxima obtida (considerando a media)?

---

Aceleração máxima é dada por Ac = Ts/Tp, ou seja, o tempo sequencial pelo tempo em paralelo. O menor tempo paralelo é o tempo de 8 threads.

Ac = 9.932/1.48 = 6.7108

---

b) Qual o número real de processadores (paralelismo de fato) estava disponível para execução?

---

Pelos dados da tabela, pode-se afirmar que o aumento das threads até o número de threads igual a 8, de fato, influenciou na performance do código em questão. Portanto, com o aumento das threads o valor da aceleração não aumentou, mas sim, diminuiu/estabilizou, fato que se deve ao aumento da troca de contexto para a mesma thread, por tanto, com os dados disponíveis, hipoteticamente pode-se afirmar que o número real de processadores, disponíveis para execução, é próximo a 8.

---

c) Os resultados caracterizam a Lei de Amdhal ou Gustafson? Justifique.

---

Os dados mostram que a aceleração cresce até 8 threads e depois piora, esse resultado caracteriza a lei de Amdhal que prevê uma fração sequencial que não pode ser paralelizada, ou seja, que impõe um teto em um problema de tamanho fixo.

---


