#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 5


int main() {
	//emprime o cabeçalho do jogo
printf(" __| |____________________________________________| |__   \n");
printf("(__   ____________________________________________   __)   \n");
printf("   | |                                            | |      \n");
printf("   | |                                            | |       \n");
printf("   | |                                            | |       \n");
printf("   | |  **Bem vindo ao jogo de adivinhação**      | |        \n");
printf("   | |                                            | |         \n");
printf("   | |                                            | |          \n");
printf(" __| |____________________________________________| |__        \n");
printf("(__   ____________________________________________   __)        \n");
printf("   | |                                            | |           \n");
	
	
	int chute;
	int segundos = time(0);
	srand(segundos);
	int numerogrande = rand();
	int numeroSecreto = numerogrande % 100;
	int acertou = 0;
	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1)Fácil (2)Médio (3)Difícil\n\n");
	printf("Escolha:");	
	scanf("%d", &nivel);
	
	int tentativas = 0;
	int numerodetentativas;
	
	//função switch possui a mesma função do if com os cases e o default (else)
	switch(nivel){
	
		case 1:
			numerodetentativas = 20;
			break;			
		case 2:
			numerodetentativas = 15;
			break;
		case 3:
			numerodetentativas = 6;
			break;
		default:
			printf("Escolha uma das dificuldades acima.");
	}
		
	double pontos = 1000;
	
	//printf("%d %d\n", numerogrande, numeroSecreto);
	
	//printf ("O Número %d é o secreto. Não conte para ninguém!\n", numeroSecreto);
	//printf ("%d %d", numeroSecreto, chute);
	for (int i = 1; i <= numerodetentativas; i++ ){
		
	//while (1) {
	
		tentativas++;
	
		printf("Tentativa %d \n", tentativas);
		
		printf("Qual é o seu chute? ");
		scanf("%d", &chute);
		
		if (chute < 0) {
			printf("Você não pode chutar números negativos!\n");
			//i--;
			continue;
		}
		
		//printf("Seu chute foi %d \n", chute);
		
		
		acertou = (chute == numeroSecreto);
		int maior = (chute > numeroSecreto);
		
		
		// printf("Acertou: %d \n", acertou);
		
		if (acertou) {
			
			//printf("Parabéns! Você acertou!\n");
			//printf("Jogue novamente, você é um ótimo jogador!\n");
			break;
			
		
		} 
		
		else if (maior){
			
			printf("O seu chute é maior que número secreto\n");
			
			
			} 
			
		else {
			
			printf("O seu chute é menor que o número secreto\n");		
			
			
			}
		//abs() serve para tornar os numeros positivos (absolutos) como um módulo	
		double pontosperdidos = abs(chute - numeroSecreto) / 2.0;
		pontos -= pontosperdidos; 	
			
		
		}
	
	printf("Fim de jogo\n");
		
	if(acertou){
	
	printf("Parabéns! Você acertou!\n");
	printf("Jogue novamente, você é um ótimo jogador!\n");
	printf("Você acertou em %d tentativas\n", tentativas);
        printf("Total de Pontos: %.1f\n", pontos );
	
	} else {
	
	printf("Você perdeu! Tente de novo!\n");
	
	}
		
		
    
    
    
    //printf("Fim de jogo\n");
    //printf("Você acertou em %d tentativas\n", tentativas);
    //printf("Total de Pontos: %.1f\n", pontos );
}
