#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int valiCad(const char *);
void primo(int);
int egolatra(char *);
char * fibo(int);
int fibonacci(char *, char*);
void imcc();
void magic();
int order_numbers_up(int list[], int n);
int order_numbers_do(int list[], int n);
void suma(int,int,int);
int intervalouno,intervalodos,numomitir;





int main() {
    char opcion;
    char cad[80];
    int n;

    int peso;
    float estatura;

    do{
        printf( "\n************************MENU*************************");
        printf( "\n   1. visualizar en forma descendente los numeros primos");
        printf( "\n   2. Leer si es numero Egolatra");
        printf( "\n   3. indicar si el numero es un Numero Magico");
        printf( "\n   4. Indice de Masa Corporal (IMC)");
        printf( "\n   5. La suma de cada uno de los digitos que no correspondan a un determinado digito");
        printf( "\n   6. cuantas veces esta p en F(n) fibonacci");
        printf( "\n   7. resultado de una prueba como una cadena {OOXXOXXOOO}");
        printf( "\n   8. Salir." );
        printf("\n   Introduzca opcion (1-8): ");
        do{
            scanf("%c", &opcion);
            fflush(stdin);

        }while(opcion <'1' || opcion >'8');

        switch(opcion){
            case '1':
                printf("\n   ****numeros primos****");
                printf( "\n   Ingrese un numero entero Positivo::");

                if(scanf("%i", &n) != 1){
                    printf("\nEntero no válido\n");
                }else{
                    printf("\nel valor es: %i\n", n);
                    printf("\nNumeros primos descendentes...");
                    primo(n);
                    printf("\n\n");
                }
                break;

            case '2':
                printf("\n   ****numeros egolatras****");
                printf("\ningrese numero...");
                scanf("%s", &cad);
                if(valiCad(cad)){
                    if(egolatra(cad)){
                        printf("\nEl numero [%s] es egolatra!!", cad);
                    }else{
                        printf("\nEl numero [%s] No egolatra!!", cad);
                    }
                }else{
                    printf("\nEntrada no valida!!!\n");
                }
                break;


            case '3':
                magic();

                break;


            case '4':
                imcc();
                break;

            case '5':
                printf("digite el valor del intervalo uno \n");
                scanf("%d",&intervalouno);
                printf("digite el valor del intervalo dos \n");
                scanf("%d",&intervalodos);
                printf("digite el valor a omitir \n");
                scanf("%d",&numomitir);
                Suma(intervalouno,intervalodos,numomitir);


                break;

            case '6':
                printf("\n   ******p en F(n) fibonacci****");
                printf( "\nIngrese n...");
                if(scanf("%i", &n) != 1){
                    printf("\nEntero no válido");
                }else{
                    printf("\nel valor es: %i", n);
                    char * str1= NULL;
                    str1= fibo(n);

                    printf( "\nIngrese patron p {000...111...}...");
                    scanf("%s", cad);
                    int cant= fibonacci(str1, cad);
                    printf("\nEl patron [%s] esta %d veces",cad, cant);
                }

                break;

            case '7':
                printf("Digite la cadena de texto conformada por OX \n");
                char cadena[1000];
                scanf("%s",&cadena);
                int cont=0,suma=0;

                for(int i=0;i<=strlen(cadena);i++){
                    if(cadena[i]=='O'||cadena[i]=='o'||cadena[i]=='0'){
                        cont++;
                        suma=suma+cont;
                    }

                    else {
                        cont=0;
                    }

                }
                printf("La suma total es: ");
                printf("%d",suma);
                break;

        }
    }while (opcion!= '8');
    return 0;
}


int valiCad(const char* cadena){
    for( ; *cadena; ++cadena ){
        if( '0' > *cadena || '9' < *cadena )
            return 0;
    }
    return 1;
}




void primo(int num){
    int cont=0;
    for (int i=num; i>1; i--){
        cont=0;
        for (int j=num; j>1; j--){
            if(i%j==0)
                cont++;
        }
        if(cont==1)
            printf("%d ",i);
    }
}

int egolatra(char * cad){
    int longitud= strlen(cad);
    int suma= 0;
    char cadSuma[longitud];
    char aux;
    int ent=0;

    for(int i= 0; i<longitud; i++ ){
        aux= cad[i];
        ent = aux - '0';
        ent = ent * ent * ent;
        suma = suma + ent;
    }
    sprintf(cadSuma, "%llu", suma);
    if(strcmp(cad, cadSuma)==0){return 1;}
    return 0;
}

char * fibo(int n){
    char * cadena="";
    char * s1="";
    char * s2="";
    if(n==0){cadena="0";}
    if(n==1){cadena="1";}

    else if(n>=2){
        s1= fibo(n-1);
        s2= fibo(n-2);

        const size_t len1= strlen(s1);
        const size_t len2= strlen(s2);
        char * result= malloc(len1 + len2 +1);

        memcpy(result, s1, len1);
        memcpy(result + len1, s2, len2 +1);
        cadena= result;
    }
    return cadena;
}
int fibonacci(char * str1, char * str2){
    char * busqueda=NULL;
    busqueda= strstr(str1, str2);
    int i=0;
    while(busqueda!=0){
        i++;
        busqueda= strstr(busqueda+1, str2);
    }
    return i;
}

void imcc(){
    int peso,genero;
    float estatura,imc;

    do {
        printf("INDICE DE MASA NUSCULAR\n"
               "ingrese el peso (Kg)\n");
        char cad[10];
        scanf("%s",&cad);

        peso = atoi(cad);
        if (!peso){
            printf("valor invalido\n");
        }
    }while (!peso);
    do{
        printf("ingrese la estatura (m)\n");
        char cad[10];
        scanf("%s",&cad);
        estatura = atof(cad);

        if (!estatura){
            printf("valor invalido\n");
        }
    }while (!estatura);

    estatura=estatura*estatura;

    imc=peso/estatura;

    printf("su imc es = %f\n",imc);
    do{
        printf("seleccione el genero\n"
               "1) hombre\n"
               "2) mujer\n");

        char cad[10];
        fgets(cad, 10, stdin);
        genero = atoi(cad);

        if (genero != 1 && genero != 2){
            printf("valor invalido\n");
        }
    }while (genero != 1 && genero != 2);

    printf("Diagnostico:\n");

    switch (genero) {

        case 1:
            if (imc<17){printf("Desnutricion\n");}

            if (17<=imc && imc<20.1){printf("Bajo Peso\n");}
            if (20<=imc && imc<25.1){printf("normal\n");}
            if (25<=imc && imc<30.1){printf("Sobre Peso\n");}
            if (30<=imc && imc<35.1){printf("Obesidad\n");}
            if (35<=imc && imc<40.1){printf("Obesidad Marcada\n");}
            if (40<=imc){printf("Obesidad Morbida\n");}
            break;
        case 2:
            if (imc<16){printf("Desnutricion\n");}
            if (16<=imc && imc<20.1){printf("Bajo Peso\n");}
            if (20<=imc && imc<24.1){printf("normal\n");}
            if (24<=imc && imc<29.1){printf("Sobre Peso\n");}
            if (29<=imc && imc<34.1){printf("Obesidad\n");}
            if (34<=imc && imc<39.1){printf("Obesidad Marcada\n");}
            if (39<=imc){printf("Obesidad Morbida\n");}
            break;
    }
}

void magic(){
    char cad[10];
    int i, n1, n2, number;



    printf("\n   ****numeros magicos****");
    printf("\nIntroducir el numero a evaluar...");
    scanf("%s", &cad);
    if(valiCad(cad)){
        number = atoi(cad);
        int longitud= strlen(cad);
        int num[longitud];


        for (i = 0; i < longitud; i++) {
            char a = cad[i];
            int b;
            b = a - '0';
            num[i] = b;
        }

        if (cad[0]== 'a'|| cad[0]== 'b'|| cad[0]== 'b'|| cad[0]== 'c'|| cad[0]== 'd'|| cad[0]== 'e'|| cad[0]== 'f'|| cad[0]== 'g'|| cad[0]== 'h'|| cad[0]== 'i'|| cad[0]== 'j'|| cad[0]== 'k'|| cad[0]== 'l'|| cad[0]== 'm'|| cad[0]== 'n'|| cad[0]== 'o'|| cad[0]== 'p'
            || cad[0]== 'q'|| cad[0]== 'r'|| cad[0]== 's'|| cad[0]== 't'|| cad[0]== 'u'|| cad[0]== 'v'|| cad[0]== 'w'|| cad[0]== 'x'|| cad[0]== 'y'|| cad[0]== 'z'){
            printf("numero invalido");

        } else{
            n1 = order_numbers_up(num, longitud);
            n2 = order_numbers_do(num, longitud);

            printf(" el numero ordenado ascendentemente es %d\n y el numero ordenado descendentemente es %d\n", n1, n2);
            if (n2 - n1 == number) {
                printf("el numero es magico ya que %d - %d = %d", n2, n1, number);
            } else {
                printf("el numero no es magico ya que %d - %d es diferente de %d", n2, n1, number);
            }
        }
    }else{
        printf("\nEntrada no valida!!!\n");
    }
}



int order_numbers_up(int list[], int n){
    long c, d, t;
    int num;
    char cad[n];

    for (c = 0 ; c < ( n - 1 ); c++){
        for (d = 0 ; d < n - c - 1; d++){
            if (list[d] > list[d+1]){
                t = list[d];
                list[d] = list[d+1];
                list[d+1] = t;
            }
        }
    }
    for (c=0;c<n;c++){
        sprintf(&cad[c],"%d",list[c]);
    }
    num=atoi(cad);

    return num;
}

int order_numbers_do(int list[], int n){
    long c, d, t;
    int num;
    char cad[n];

    for (c = 0 ; c < ( n - 1 ); c++){
        for (d = 0 ; d < n - c - 1; d++){
            if (list[d] < list[d+1]){
                t = list[d];
                list[d] = list[d+1];
                list[d+1] = t;
            }
        }
    }
    for (c=0;c<n;c++){
        sprintf(&cad[c],"%d",list[c]);
    }
    num=atoi(cad);

    return num;
}

void Suma(int intervaloUno, int intervaloDos,int numSaltar){
    int suma= 0;
    int contador=0;

    void separar(int numero, int digito){
        char cadena[100000];
        sprintf(cadena, "%d", numero);
        int cantidad=strlen (cadena);

        for (int i=0; i<cantidad;i++){
            int n=(int) cadena[i]-48;
            if (n==digito){
                contador++;
            }else{
                suma=suma+n;
            }
        }
    }
    int  i, j,digito;
    int cantidad, sumacifras=0;



    cantidad=intervaloDos-intervaloUno+1;

    int guardarnumero[cantidad-1];

    printf("Cantidad de números en el rango: %d \n",cantidad);
    printf("Números en el intervalo: ");

    int posicion=0;
    for(int i=intervaloUno;i<=intervaloDos;i++){
        guardarnumero[posicion]=i;

        printf("%d ",i);
        posicion++;

    }


    for(int j=0;j<=cantidad-1;j++){
        separar(guardarnumero[j],numSaltar);
    }
    printf ("\nTotal suma: %d \n", suma);
    printf ("Repeticiones del numero a omitir : %d \n", contador);
}


