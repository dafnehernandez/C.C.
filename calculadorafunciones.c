#include <stdio.h>

int sumar(int a, int b){
    return a+b;
}

int restar(int a, int b){
    return a-b;
}

int multiplicar(int a, int b){
    return a*b;
}

int dividir(int a, int b){
    if (b==0){
        printf("No se puede dividir entre cero");
        return -1;
    }
    return a/b;
}


int main(){

   int(*ptrarray[4]) (int, int); //declaracion del arreglo
   int(*opptr)(int, int); //apunta al array
   char res;
   int num1, num2, opcion;

do {
   printf("Indica los dos números a operar:\n");
   scanf("%d%d", &num1, &num2);

   printf("Elige una opción de la calculadora:\n 1.-sumar\n 2.-restar\n 3.-multiplicar\n 4.-dividir\n");
   scanf("%d", &opcion);

    ptrarray[0] = sumar;
    ptrarray[1] = restar;
    ptrarray[2] = multiplicar;
    ptrarray[3] = dividir;

        switch (opcion){
            case 1:
                opptr = ptrarray[0];//método - sumar
                printf("el resultado de la suma es: ");
                break;
            case 2:
                opptr = ptrarray[1]; //método - restar
                printf("el resultado de la resta es: ");
                break;
            case 3:
                opptr = ptrarray[2];//método - multiplicar
                printf("el resultado de la multiplicacion es: ");
                break;
            case 4:
                opptr = ptrarray[3]; //método - dividir
                printf("el resultado de la division es: ");
                break;
       }
       int resultado = opptr(num1,num2); //se asigna el resultado
       printf("%d\n", resultado); 
       printf("¿Deseas realizar otro calculo? presiona s para si o n para no\n");
       scanf("%s", &res);

}while(res!='n');

    return 0;
}
