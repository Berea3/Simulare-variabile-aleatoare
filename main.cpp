#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <utility>

using namespace std;



int Bernoulli(float p) {
	float u = (float)rand() / RAND_MAX;
	if (u < p) return 1;
	else return 0;
}
int uniform(int a, int b) {
	int lungime_interval = b - a + 1;
	return rand() % lungime_interval + a;
}
int discreta(float probabilitati[], int valori) {
	float u = (float)rand() / RAND_MAX;
	float suma_probabilitiati = 0.0;

	for (int i = 0; i < valori; i++) {
		suma_probabilitiati += probabilitati[i];
		if (u < suma_probabilitiati) {
			return i;
		}
	}

	return valori - 1;
}
int Binomiala(int n, float p) {
	int succes = 0;

	for (int i = 0; i < n; i++) {
		float r = (float)rand() / RAND_MAX;
		if (r < p) {
			succes++;
		}
	}

	return succes;
}
int geometrica(float p) {
	float u;
	int x;


		u = (float)rand() / RAND_MAX;
		x = (int)ceil(log(1 - u) / log(1 - p))+1;


	return x;
}

double exponetiala(float theta)
{
    float u=(float)rand() / RAND_MAX;
    float x=-log(1-u)*theta;
    return x;
}

float uniforma(float a, float b)
{
    float u=(float)rand() / RAND_MAX;
    float x=a+(b-a)*u;
    return x;
}

pair<float,float> dreptunghi(float a, float b, float c, float d)
{
    pair<float,float>p;
    float u=(float)rand() / RAND_MAX;
    p.first=a+(b-a)*u;
    u=(float)rand() / RAND_MAX;
    p.second=c+(d-c)*u;
    return p;
}

pair<float,float> elipsa(float a, float b)
{
    float u;
    pair<float,float>p;
    do{
        u=(float)rand() / RAND_MAX;
        p.first=-a+(2*a)*u;
        u=(float)rand() / RAND_MAX;
        p.second=-b+(2*b)*u;
    }while((pow(p.first,2)/a+pow(p.second,2)/b)>1);
    return p;
}

int main() {
    int opt,a,b, n;
	float V[100];
	printf(" Buna ziua\n");
	srand(time(NULL));
	float bernoulli_p;
	float Binomiala_p;
	float Geometrica_p;
	while (1)
    {
		printf("\n1.Simularea variabilelor aleatoare discrete:\n");
		printf("2.Simularea variabilelor continue:\n");
		printf("3.Simularea vectorilor aleatori continui\n");
		printf("4.Iesire\n");
		printf("Dati optiunea :");
		scanf("%d", &opt);
		switch (opt)
		{
        case 1:
        {
            printf("\n1. Simularea unei variabile aleatoare Bernoulli:\n");
            printf("2. Simularea distributiei  Uniforme discrete:\n");
            printf("3. Simularea distributiei  Neuniforme discrete:\n");
            printf("4. Simularea distributiei Binomiale\n");
            printf("5. Simularea distributiei Geometrice\n");
            printf("6. Simularea distributiei Poisson\n");
            printf("Dati optiunea :");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                printf("Un experiment Bernoulli este un experiment aleator ce consta dintr-un numar precizat sau nu de incercari independente.O incercare are doar doua rezultate mutual exclusive,unul numit succes, si celalalt numit esec.Variabila aleatoare X ce inregistreaza rezultatul unei incercari se numeste variabila aleatoare Bernoulli.Exemplul clasic de experiment Bernoulli este aruncarea monedei");
                printf("\nDati probabilitatea pentru o variabila Bernoulli:");
                scanf("%f", &bernoulli_p);
                printf("\nBernoulli: ");
                for (int i = 0; i < 10; i++) {
                    int value = Bernoulli(bernoulli_p);
                    printf("%d ", value);
                }
                printf("\n");
                break;
            case 2: {
                printf("Dati capetele intervalului:");
                scanf("%d", &a);
                scanf("%d", &b);
                uniform(a,b);
                printf("\nUniform pe intervalul[%d,%d]:", a, b);
                    for (int i = 0; i < 10; i++) {
                        int val = uniform(a, b);
                        printf("%d ", val);
                    }
                    break;
                 }
            case 3: {
                printf("\nDati numarul de valorii:");
                scanf("%d",&n);
                printf("Dati probabilitatiile:");
                for (int i = 0; i < n; i++) {
                    scanf("%f",&V[i]);
                }
                for (int i = 0; i < 10; i++) {
                    int value = discreta(V, n);
                    printf("%d ", value);
                }
                break;
            }
            case 4: {
                printf("O variabila aleatoare binomiala este asociata unui experiment Bernoulli ce consta din n ıncercari independente.O incercare este o etapa a experimentului ce are doua rezultate mutual exclusive: succes sau esec.");
                printf("\nDati probabilitatea succesului:");
                scanf("%f", &Binomiala_p);
                printf("Dati numarul de incercari:");
                scanf("%d", &n);
                int succes =Binomiala(n, Binomiala_p);
                printf("Numarul de succese din %d incercari este %d.",n,succes);
                break;
            }
            case 5:
            {
                printf("O variabila aleatoare ce are distributia geometrica da numarul de incercari intr-un proces Bernoulli pana se obtine primul succes, inclusiv");
                printf("\nDati probabilitatea:");
                scanf("%f", &Geometrica_p);
                int incercari = geometrica(Geometrica_p);
                printf("Numarul de incercari pana am dat de succes este %d", incercari);
                break;
            }
            }
            break;
        }
        case 2:{
            printf("1. Simularea distributiei exponentiale.\n");
            printf("2. Simularea distributiei uniforme.\n");
            printf("3. Simularea distributiei normale.\n");
            scanf("%d",&opt);
            switch(opt)
            {
            case 1:
                float theta;
                printf("Introduceti theta:");
                scanf("%f",&theta);
                for (int i=1;i<=10;i++)
                    printf("%f ",exponetiala(theta));
                break;
            case 2:
                float a,b;
                printf("Introduceti intervalul:");
                scanf("%f%f",&a,&b);
                for (int i=1;i<=10;i++)
                    printf("%f ",uniforma(a,b));
                break;
            }
        }
        case 3:{
            printf("1. Dreptunghi\n");
            printf("2. Elipsa\n");
            scanf("%d",&opt);
            switch(opt)
            {
            case 1:{
                float a,b,c,d;
                pair<float,float>x;
                printf("Introduceti valorile punctelor:");
                scanf("%f%f%f%f",&a,&b,&c,&d);
                x=dreptunghi(a,b,c,d);
                printf("%f %f",x.first,x.second);
                break;
            }
            case 2:
                printf("Introduceti a si b:");
                float a,b;
                scanf("%f%f",&a,&b);
                pair<float,float>x;
                x=(elipsa(a,b));
                printf("%f %f",x.first,x.second);
                break;
            }
            break;
        }
        case 4:
            exit(0);
        }
    }
	return 0;
}
