# Questão 3

Estudamos diversas classificaçoes para arquiteturas computacionais considerando o acesso aos
dados  e  instruçoes,  organização  dos  processadores,  rede  de  comunicação,  entre  outros  aspectos.  Assim, utilize as classificaçoes estudadas para identificar (completamente) a seguinte arquitetura.

Arquitetura: Um aglomerado composto por 6 servidores Dell PowerEdge R720, cada um equipado com
Intel Xeon E5-2620 v3 (Haswell, 2.40GHz, 2 CPUs/node, 6 cores/CPU), 128 GB RAM, armazenamento 278 GB HDD SCSI PERC H330. Os servidores são interconectados por duas redes: (a) eth0/eno1, Ethernet, 10 Gbps; e (b) InfiniBand, 56 Gbps, modelo Mellanox Technologies MT27500 Family [ConnectX-3]. Por fim, cada servidor possui duas NVIDIA Titan Black (CUDA cores: 2880, memória: 6144 MB com vazão de 288.4 GB/s, warp size: 32, número maximo de threads por bloco: 1024).

Se você identificar múltiplas classificaçoes, explique sua resposta

---

Um aglomerado é um cluster computacional, são 6 servidores, em um sistema distribuído e homogêneo, o qual cada computador (dispositivo) no cluster possui as mesmas características de um mesmo hardware. É um sistema distribuído pois está conectado pela rede, e não possui memória compartilhada, entre dispositivos.

---