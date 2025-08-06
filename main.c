#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>



int convert_bin_to_dec(const char *input) {
	int answer = 0;
	int len = strlen(input);
	if(input[0] == 0 && len > 1) {
		return -1;
	}
	int i = len - 1;
	int po = 0;
	while( i  >= 0) {
		if(input[i] == '1') {
			answer += 1 * pow(2,po);
		} else {
			answer += 0 * pow(2,po);
		}
		po++;
		i--;
	}
	return answer;
}


int get_taille(int quotient) {
	int cpt = 0;
	while(quotient != 0) {
		if(quotient ==1) {
			quotient = 0;
		}
		quotient = quotient/2;
		cpt++;
	}
	return cpt;
}

void convert_dec_to_bin(int input) {
	int quotient = input;
	int taille = get_taille(quotient);
	int reste[taille - 1];
	int i = 0;
	while (quotient != 0) {
		if(quotient == 1) {
			reste[i] = 1;
			quotient = 0;
		} else if(quotient%2 != 0) {
			reste[i] = 1;
			quotient = quotient /2;
		} else {
			reste[i] = 0;
			quotient = quotient/2;
		}
		i++;
	}
	i = taille - 1;
	printf(" Le nombre binaire est: ");
	while(i >= 0 ) {
		printf("%d",reste[i]);
		i--;
	}
	printf(" pour le nombre dC)cimal: %d",input);
}


int isBinary(const char *input) {
	int i = 0;
	while(input[i] != '\0') {
		if(input[i] != '0' && input[i] != '1') {
			return 0;
		}
		i++;
	}
	return 1;
}

void clear_console() {
	system("clear");
}


void start() {
	clear_console();
	printf("Veuillez choisir un mode de conversion: \n ");
	printf("1- Binaire vers dC)cimal \n ");
	printf("2- DC)cimal vers binaire \n ");
}

void end() {
	clear_console();
	printf("Merci d'avoir utilisC) ce mini-programme ! \n");
	printf("!--Antoin9-e--!");
}

void first_mode() {
	clear_console();
	char num [100];
	printf("Veuillez entrer un nombre binaire : \n");
	while(1) {
		scanf("%s",num);
		if(isBinary(num)) {
			break;
		} else {
			printf("EntrC)e invalide ! RC)essayez: \n");
		}
	}
	int res = convert_bin_to_dec(num);
	clear_console();
	printf("Le nombre dC)cimal est : %d pour le binaire : %s \n",res,num);
	menu_return();
}

void second_mode() {
	clear_console();
	int num;
	char c;
	printf("Veuillez entrer un nombre entier : \n");
	while(scanf("%d",&num) != 1) {
		printf("EntrC)e invalide ! RC)essayez: \n");
		while ((c = getchar()) != '\n' && c != EOF);
	}
	clear_console();
	convert_dec_to_bin(num);
	printf("\n");
	menu_return();
}

void menu_return() {
	printf("---------------------------------------------------\n");
	printf("1-Fermer le programme\n");
	printf("2-Retourner au menu\n");

}


int main() {
	bool fin =false;
	while (fin != true) {
		start();
		int input;
		scanf("%d",&input);
		if(input == 1) {
			first_mode();
			int choose;
			scanf("%d",&choose);
			if(choose == 1) {
				end();
				fin = true;
			}
		}
		if(input == 2) {
			second_mode();
			int choose;
			scanf("%d",&choose);
			if(choose == 1) {
				end();
				fin = true;
			}
		}
	}

	return 0;
}