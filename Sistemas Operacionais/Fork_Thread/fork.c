#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

int main() {

	pid_t filho;
	int saldo = 0;
	int arq1[2], arq2[2], arq3[2]; //Identifica o arquivo aberto do processo

	if (pipe(arq1) == -1) { //Passa o valor para a impressão
		printf("Pipe 1 falhou\n");
		exit(EXIT_FAILURE); 
	}

	if (pipe(arq2) == -1) { //Passa o valor do incremento para o decremento
		printf("Pipe 2 falhou\n");
		exit(EXIT_FAILURE);
	}

	if (pipe(arq3) == -1) { //Passa o valor do decremento para o incremento
		printf("Pipe 3 falhou\n");
		exit(EXIT_FAILURE);
	}

	write(arq2[1], &saldo, sizeof(int));
	
	filho = fork(); //É criado o primeiro fork

	if (filho < 0) {
		printf("Fork 1 falhou\n");
		exit(EXIT_FAILURE);
	}

	if (filho == 0) { //Processo de impressão do valor do saldo - O filho executa esse processo
		printf("PID do processo de impressão do saldo: %d\n", getpid());
		close(arq1[1]);
		close(arq2[0]); close(arq2[1]);
		close(arq3[0]); close(arq3[1]);

		for (int i = 0; i < 1000; i++) {
			read(arq1[0], &saldo, sizeof(int));
			printf("(impresao)Saldo: %d\n", saldo);
		}
		close(arq1[0]);

	} 
	else { //O pai executa esse processo
		filho = fork(); //É criado outro fork

		if (filho < 0) {
			printf("Fork 2 falhou\n");
			exit(EXIT_FAILURE);
		}

		if (filho == 0) { //Processo para incrementar o saldo - Processo filho
			printf("PID do processo de incrementar: %d\n", getpid());
			close(arq1[0]);
			close(arq2[0]);
			close(arq3[1]);

			for (int i = 0; i < 1000; i++) {
				read(arq3[0], &saldo, sizeof(int));
				saldo += 100;
				write(arq2[1], &saldo, sizeof(int)); //Escrevendo para o decremento
				write(arq1[1], &saldo, sizeof(int)); //Escrevendo para a impressão
				//printf("(incremento)Saldo: %d\n", saldo);
			}

			close(arq1[1]);
			close(arq2[1]);
			close(arq3[0]); 

		} 
		else { //Processo para decrementar o saldo - Processo pai
			printf("PID do processo de decrementar: %d\n", getpid());
			close(arq1[0]);
			close(arq2[1]);
			close(arq3[0]);

			for (int i = 0; i < 1000; i++) {
				read(arq2[0], &saldo, sizeof(int));
				saldo -= 100;
				write(arq3[1], &saldo, sizeof(int));
				write(arq1[1], &saldo, sizeof(int));
				//printf("(decremento)Saldo: %d\n", saldo);
			}

			close(arq1[1]);
			close(arq2[0]);
			close(arq3[1]);
		}
	}

	return 0;
}
