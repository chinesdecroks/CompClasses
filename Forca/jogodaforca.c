#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// assinar funções antes de declara-las permite coloca-las em qualquer ordem
// assina funções em outros arquivos .h denominados header files que podem interagir com o código como o file forca.h
#include "forca.h"

/* variaveis globais podem ser vistas e alteradas por qualquer função
são declaradas fora de qualquer escopo por isso globais*/
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;
char nome[TAMANHO_PALAVRA];

//funções void não devolvem nada, funções int devolvem inteiros
void abertura(){
	printf("*****************************\n");
	printf("*       JOGO DA FORCA       *\n");
	printf("*****************************\n\n");
	printf("Digite seu nome:");
	scanf("%s", nome);


}

void chuta(){

	
	char chute;
	printf("Qual letra?");														
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	chutesdados++;
}

int jachutou(char letra){

	int achou = 0;

	for (int j = 0; j < chutesdados; j++){
		//printf("-->Chute %c\n", chutes[j]);
		
		if (chutes[j] == letra){
			//printf("--->Chute correto!\n");
			achou = 1;
			break;
					
		}

	}

	return achou;
}

void desenhaforca() {

	int erros = chuteserrados();

	printf("   _______       \n");
	printf("  |/      |      \n");
	printf("  |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
	(erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' ')); 
	printf("  |      %c%c%c    \n", (erros >= 3 ? '\\' : ' '),
	 (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
	printf("  |       %c      \n", (erros >= 2 ? '|' : ' '));
	printf("  |      %c %c    \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
	printf("  |              \n");
	printf("  |              \n");
	printf("__|___           \n");
	printf("\n\n");







	for (int i = 0; i < strlen(palavrasecreta); i++) {
				
		//printf("Eu estou vendo a letra secreta %d = %c\n", i, palavrasecreta[i]);

		//aqui estava o código que esta na funçao jachutou()
		int achou = jachutou(palavrasecreta[i]);

		if(achou){
			printf("%c ", palavrasecreta[i]);
		} else{
			printf("_ ");

		}
				

	}

		printf("\n");

}

void adicionapalavra() {

	char quer;
	printf("Você quer adicionar uma nova palavra no jogo? (S/N)\n");
	scanf(" %c", &quer);

	if (quer == 'S'){
		char novapalavra[TAMANHO_PALAVRA];
		printf("Qual é a nova palavra?\n");
		scanf("%s", novapalavra);

		FILE* f;

		f = fopen("palavras.txt", "r+");
		if(f == 0){
			printf("Desculpe, banco de dados não disponivel\n\n");
			exit(1);

		}

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d",qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);


		fclose(f);
	}
}

void escolhepalavra(){
	//SPRINTF(nome do arquivo, para que vai abrir o arquivo(r = read))	é capaz de passar uma sequncia de chars para uma array
	//sprintf(palavrasecreta, "MELANCIA");
	//fopen() = file open abre um arquivo
	FILE* f;

	f = fopen("palavras.txt", "r");
	if(f == 0){
		printf("Desculpe, banco de dados não disponivel\n\n");
		exit(1);

	}

	int qtddepalavras;

	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomico = rand() % qtddepalavras;

	for(int i = 0; i <= randomico; i++){

		fscanf(f, "%s", palavrasecreta);

	}


	fclose(f);

}

int acertou() {
	for(int i = 0; i < strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}

	return 1;
}

int chuteserrados(){
	int erros = 0;
	for(int i = 0; i < chutesdados; i++){

		int existe = 0;

		for (int j = 0; j < strlen(palavrasecreta); j++){
			if (chutes[i] == palavrasecreta[j]){

				existe = 1;
				break;
			}
		}

		if(!existe) erros++;

	}

	return erros;
}


int enforcou() {

	return chuteserrados() >= 5;
}



int main() {
	

	//do e while serve para executar o bloco de código primeiro e logo após a condição
	//! representa a palavra não que inverte um valor booleano, ex: acertou = 0(false) !acertou = 1(true)
	// utiliza /0 para indicar que voce não utilizou todos os caracteres da array

	escolhepalavra();
	
	abertura();

	do{
		
		desenhaforca();

		chuta();
		
		



	} while(!acertou() && !enforcou());

	if(acertou()){
		printf("\n Parabéns, você ganhou\n\n");

		printf("        ##########################          \n");
		printf("        ##########################          \n");
		printf("   #####################################    \n");
		printf(" #########################################  \n");
		printf("####      ######################       #### \n");
		printf("###       ######################        ### \n");
		printf("##        ######################        ### \n");
		printf("###     ##########################      ### \n");
		printf("###    ############################    #### \n");
		printf(" ###   ### #################### ###    ###  \n");
		printf(" ####   ### ################## ####  ####   \n");
		printf("   ####  ######################### #####    \n");
		printf("    ######## ################ #########     \n");
		printf("      ######  ##############   ######       \n");
		printf("               ############                 \n");
		printf("                 ########                   \n");
		printf("                   ####                     \n");
		printf("                   ####                     \n");
		printf("                   ####                     \n");
		printf("                   ####                     \n");
		printf("               ############                 \n");
		printf("            ##################              \n");
		printf("            ##################              \n");
		printf("            ###            ###              \n");
		printf("            ###    *%s*    ###              \n", nome);
		printf("            ###            ###              \n");
		printf("            ##################              \n");
		printf("            ##################              \n");
		printf("          ######################            \n");
		printf("         ########################           \n");

	} else {

		printf("\nPuxa, você foi enforcado!\n");
		printf("A palavra secreta era **%s**\n\n", palavrasecreta);

		printf("                    @@@@@@@@@@@@@@@@@@@                    \n");    
		printf("                 @@@@@@             @@@@@@@                \n");    
		printf("              @@@@                       @@@@              \n");     
		printf("             @@@                             @@            \n");     
		printf("            @@                                @@           \n");     
		printf("           @@                                 @@           \n");   
		printf("          @@                                   @@          \n");    
		printf("          @@ @@                             @@ @@          \n");     
		printf("          @@ @@                             @@  @          \n");     
		printf("          @@ @@                             @@  @          \n");     
		printf("          @@  @@                            @@ @@          \n");
		printf("          @@  @@                           @@  @@          \n");
		printf("           @@ @@   @@@@@@@@     @@@@@@@@   @@ @@           \n");
		printf("            @@@@ @@@@@@@@@@     @@@@@@@@@@ @@@@@           \n");
		printf("             @@@ @@@@@@@@@@     @@@@@@@@@@ @@@             \n");
		printf("    @@@       @@  @@@@@@@@       @@@@@@@@@  @@      @@@@   \n");
		printf("   @@@@@     @@   @@@@@@@   @@@   @@@@@@@   @@     @@@@@@  \n");
		printf("  @@   @@    @@     @@@    @@@@@    @@@     @@    @@   @@  \n");
		printf(" @@@    @@@@  @@          @@@@@@@          @@  @@@@    @@@ \n");
		printf("@@         @@@@@@@@       @@@@@@@       @@@@@@@@@        @@\n");
		printf("@@@@@@@@@     @@@@@@@@    @@@@@@@    @@@@@@@@      @@@@@@@@\n");
		printf("  @@@@ @@@@@      @@@@@              @@@ @@     @@@@@@ @@@ \n");
		printf("          @@@@@@  @@@  @@           @@  @@@  @@@@@@        \n");
		printf("              @@@@@@ @@ @@@@@@@@@@@ @@ @@@@@@              \n");
		printf("                  @@ @@ @ @ @ @ @ @ @ @ @@                 \n");
		printf("                @@@@  @ @ @ @ @ @ @ @   @@@@@              \n");
		printf("            @@@@@ @@   @@@@@@@@@@@@@   @@ @@@@@            \n");
		printf("    @@@@@@@@@@     @@                 @@      @@@@@@@@@    \n");
		printf("   @@           @@@@@@@             @@@@@@@@          @@   \n");
		printf("    @@@     @@@@@     @@@@@@@@@@@@@@@     @@@@@     @@@    \n");
		printf("      @@   @@@           @@@@@@@@@           @@@   @@      \n");
		printf("      @@  @@                                   @@  @@      \n");
		printf("       @@@@                                     @@@@       \n");


	}

}

