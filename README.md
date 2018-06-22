PriorityQueue_Hospital

	A cada paciente que chega em um hospital é verificada qual a urgência, a idade e o tipo. 
	De acordo com a urgência, se chega outro paciente com a mesma urgência, é verificada a idade,
	sendo assim, o mais velho tem a prioridade. O tipo recebido, serve para que seja levado ao respectivo setor.

A urgência se dá por: u - urgente;
				l - leve;
				m - moderado.  

O tipo se dá por: c - cabeça;
			  t - tronco;
			  i - inferiores.

Utilizando dessa forma O MAX_HEAPIFY.
-> O heap é uma estrutura de dados que pode ser visto como uma árvore binária praticamente completa.

máximo: para todo vértice (i) diferente da raiz:
dado[pai(i)] >= dado[i]

exemplo:
	  100 (pai-> dado)  
	  / \
     45    36
     /\    /\
    32 30 25 22


Pré-requisitos:
	Este projeto roda em qualquer plataforma que receba um código em C. Foi implementado no sotware CodeBlocks.
	
Instalando:
	Faça o download deste projeto e abra o documento que está no formato (.cbp), se for no CodeBlocks.
	Caso seja outro software, apenas copie os documentos (.c, .h e .csv), inicie um projeto no software desejado e inclua esses arquivos.
	Agora é só rodar o arquivo.

Desenvolvimento:
	Há uma lista de pacientes que está em formato (.csv), pode ser modificada como desejar.

Construído com:
	CodeBlocks

Autores:
	Hellen Ávila Rosa
	Letícia de Oliveira Nunes

Agradecimentos:
	Ao Renan Starke - professor de Programação, pela paciência, ajuda no desenvolvimento do projeto e por trazer conhecimento por todo o semestre.
	Ao Hazael - monitor de programação, por ajudar a arrumar bugs e erros de projeto.
	À Hellen - minha parceira de projeto, que me atura nessa jornada.


