#include <stdio.h>
#include <stdlib.h>
#define N ('Z' - 'A'+1)
void nacitanie(char pole[], int *dlzka);
void vypisanie(char pole[], int dlzka);
void uprava(char pole[], char poleUpravene[], int dlzka, int *dlzkaUpravena);
void vypisanieUpravenej(char poleUpravene[], int dlzkaUpravena);
void vypisSlova(char pole[], int dlzka);
void histogram(char poleUpravene[], int dlzkaUpravena);
void sifra(char poleUpravene[], int dlzkaUpravena);
int main()
{
	char poleZnakov[1000] = {};
	char poleZnakovUpravene [1000] = {};
	int dlzkaPola = 0;
	int dlzkaUpravena = 0;
	char vyber;
	while (1) {
		scanf("%c", &vyber);
		if (vyber == 'k') {
			break;
		}
		else {
			switch (vyber) {
			case 'n':nacitanie(poleZnakov, &dlzkaPola);
				break;
			case 'v':vypisanie(poleZnakov, dlzkaPola);
				break;
            case 'u':uprava(poleZnakov, poleZnakovUpravene, dlzkaPola, &dlzkaUpravena);
                break;
            case 's':vypisanieUpravenej(poleZnakovUpravene, dlzkaUpravena);
                break;
            case 'd':vypisSlova(poleZnakov, dlzkaPola);
                break;
            case 'h':histogram(poleZnakovUpravene, dlzkaUpravena);
                break;
            case 'c':sifra(poleZnakovUpravene, dlzkaUpravena);
                break;
			}
		}
	}
}

void nacitanie(char pole[], int *dlzka) {
	FILE* fr;
	int pocet = 0, c;
	if ((fr = fopen("sifra.txt", "r")) != NULL) {
		while ((c = getc(fr)) != EOF) {
			pocet++;
			pole[pocet-1] = c;
		}
		*dlzka = pocet;
		fclose(fr);
	}
	else {
		printf("Spravu sa nepodarilo nacitat!\n");
	}
}

void vypisanie(char pole[], int dlzka) {
	if (dlzka == 0) {
		printf("Sprava nie je nacitana!\n");
	}
	else {
		int n;
		for (n = 0;n < dlzka;n++) {
			printf("%c", pole[n]);
		}
		printf("\n");
	}
}

void uprava(char pole[], char poleUpravene[], int dlzka, int *dlzkaUpravena) {
    if(dlzka==0){
        printf("Sprava nie je nacitana!\n");
    }
    else{
        int n,k=0;
		for (n = 0;n < dlzka;n++) {
            if(pole[n]>='A' && pole[n]<='Z'){
                poleUpravene[k]=pole[n];
                k++;
            }
            if(pole[n]>='a' && pole[n]<='z'){
                pole[n]&= ~0x20;
                poleUpravene[k]=pole[n];
                k++;
                pole[n]+=32;
            }

        }

         *dlzkaUpravena=k;
    }
}

void vypisanieUpravenej(char poleUpravene[], int dlzkaUpravena){
    if(dlzkaUpravena==0){
        printf("Nie je k dispozicii upravena sprava!\n");
    }
    else{
        int n;
        for(n=0;n<dlzkaUpravena;n++){
            printf("%c",poleUpravene[n]);
        }
        printf("\n");
    }
}
void vypisSlova(char pole[], int dlzka){
    if(dlzka==0){
        printf("Sprava nie je nacitana!\n");
    }
    else{
        int k,i,j;
        int pocet=0;
        int c;
        scanf("%d",&k);
        if (k>=1 && k<=100){
            for(i=0;i<dlzka;i++){
                c=pole[i];
                if(c!=' '){
                    pocet++;
                }
                else if(c==' ' || c == '\n'){
                    if(pocet==k){
                        for(j=i-k;j<i;j++){
                            printf("%c",pole[j]);
                        }
                        printf("\n");
                        pocet=0;
                    }
                    else{
                        pocet=0;
                    }
                }
            }
            if(pocet==k){
                        for(j=i-k;j<i;j++){
                            printf("%c",pole[j]);
                        }
                        printf("\n");
                        pocet=0;
                    }
        }
    }
}
void histogram(char poleUpravene[], int dlzkaUpravena){
    if(dlzkaUpravena==0){
        printf("Nie je k dispozicii upravena sprava!\n");
    }

    else{
        int i;
        int c;
        int pole[N];
        int k,j;

        for(i=0;i<N;i++){
            pole[i]=0;
        }

        for(i = 0; i < dlzkaUpravena; i++){
            pole[poleUpravene[i]-'A']++;
        }

        for(k=0;k<10;k++){
            for(j=0;j<26;j++){
                if(pole[j]/ (double) dlzkaUpravena *10>9-k){
                    printf("%c",'*');
                }
            }
            putchar('\n');
        }
        for(i=0;i<N;i++){
            printf("%c",'A'+i);
        }
        printf("\n");
    }
}

void sifra(char poleUpravene[], int dlzkaUpravena){
    if(dlzkaUpravena==0){
        printf("Nie je k dispozicii upravena sprava!\n");
    }
    else{
        int n,i;
        char c;
        scanf("%d",&n);
        if(n>=1 && n<=25){
            for(i=0;i<dlzkaUpravena;i++){
                c=poleUpravene[i];
                if(c>='A' && c<='Z'){
                   c=c-n ;
                   if(c<'A'){
                    c=c+'Z' - 'A' +1;
                   }
                   poleUpravene[i]=c;
                }
            }
        printf("%s\n",poleUpravene);
        }
    }
}




