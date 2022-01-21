#include <stdio.h>

int BubbleSort(int valores[], int tam)
{
int i, j, aux; 
    for (i=1;i<=tam-1;i++) {
        for (j=0;j<=tam-2;j++){
                if (valores[j]>valores[j+1]) { //comparacion 
                    aux=valores[j]; 
                    valores[j] = valores[j+1]; 
                    valores[j+1] = aux;
                }
        }
    }
}

int Maximo(int valores[], int tam)
{
 int i, temp=valores[0];
 
    for (i=1; i<tam; i++) {
            if (temp  == 99){
                break;
            }
            if (temp < valores[i]){
                temp = valores[i];
            }
    }
    return temp;
 printf("\n");
}

int Minimo(int valores[], int tam)
{
 int i, temp=100;
 
    for (i=0; i<tam; i++) {
            if (valores[i] == 0){
                temp = valores[i];
                break;
            }
            if (temp > valores[i]){
                temp = valores[i];
            }
    }
    return temp;
 printf("\n");
}

int Media(int valores[], int tam)
{
 int i, sum = 0, res;
 
    for (i=0; i<tam; i++) {
        sum += valores[i];
    }
    res = sum / tam;
    return res;
 printf("\n");
}

int Mediana(int valores[], int tam)
{
 int i, aux, temp = 0, med;
 
    BubbleSort(valores,tam); //llamo al método que ordena los datos 
    
     if (tam % 2 == 0){ //es par
            aux = (tam / 2); //primer indice, es el segundo valor a sumar
            temp =  valores[aux] + valores[--aux]; //temporal suma el primer indice más el segundo índice 
            med = temp / 2; //en esta situación se saca la media y ya obtenemos la mediana correcta
    }
    else { //es impar
            i = (tam / 2);
            med = valores[i];
    }
    return med;
 printf("\n");
}

int Moda(int valores[], int tam)
{
 int i, j, aux[tam], num = 0, mayor = 0, pos = 0, posmayor, res;
    
     // Usamos un vector auxiliar y lo llenamos de ceros
    for(i=0;i<tam;i++) {
        aux[i]=0;
    }
    // Se recorre el vector y se observan las repeticiones existentes
    // y si existe se almacenan las mismas en el vector auxiliar segun la posición
    // del numero
    for(i=0;i<tam; i++) {
        num = valores[i]; 
        pos = i; 
        for(j=i;j<tam;j++) {
            if(valores[j]==num) aux[pos]++;
        }
    }
    // Si ya se conocen las repeticiones de cada numero ahora se establece cuál es la posición
    // del vector que tiene un más repeticiones, así este representa el nímero que se repite más veces en el vector
    // Primero se establece el mayor como primer elemento del vector
    mayor=aux[0];
    posmayor = 0;
    for(i=0;i<tam;i++) {
        if(aux[i]>mayor) {
            posmayor=i; 
            mayor=aux[i];
        }
    }
    
    res=valores[posmayor];
    
    return res;
 printf("\n");
}

int main()
{
    char num_c;
    int cantidad;
    int numeros[cantidad]; 
    do {
    printf("\nSi deseas salir presiona x de lo contrario ingresa la cantidad de numeros a evaluar (min 2 y max 5):");
    scanf("%s", &num_c);
    
        if (num_c=='x'){ break; } //sale directamente
        cantidad=num_c -'0'; //transformo el char a entero usando ASCII 
        //printf("El carácter '%c' es %d en entero", num_c, cantidad);
            if (cantidad>=2 && cantidad<6){
                    printf("Ingresa los numeros a evaluar del rango 0-99:");
                    //LLeno el arreglo
                        for(int i=0; i<cantidad; i++){
                            scanf("%d", &numeros[i]);
                            printf("\n");
                            if(numeros[i]<0 || numeros[i]>99){
                                printf("Error: el numero a evaluar no está en el rango del 0-99:");
                                i--;
                                //continue;
                            }
                        }
                    printf("El máximo es: %d\n", Maximo(numeros,cantidad)); //resultado maximo
                    printf("El mínimo es: %d\n", Minimo(numeros,cantidad)); //resultado minimo
                    printf("La media es: %d\n", Media(numeros,cantidad)); //resultado media
                    printf("La mediana es: %d\n", Mediana(numeros,cantidad)); //resultado mediana
                    printf("La moda es: %d\n", Moda(numeros,cantidad)); //resultado moda
            }
             else {
                printf("Error: ingresaste un caracter no permiido o un numero que no respeta las reglas: la cantidad de numeros a evaluar es min 2 y max 5\n");
            }
    } while(num_c!='x');
    return 0;
}
