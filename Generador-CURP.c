#include <stdio.h>
#include <ctype.h>
int main()
{
    char nombre[36], primerApellido[25], segundoApellido[25], CURP[17];
    int aNac, mesNac, diaNac, estado;
    char sexo, res;
    char conver[2]; //auxiliar para convertir a caracteres
   //{"AS","BC","BS","CC","CS","CH","DF","CL","CM","DG","GT","GR","HG","JC","MC","MN","MS","NT","NL","OC","PL","QO","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS"};
    char codigoEstados[65] = {"0ASBCBSCCCSCHDFCLCMDGGTGRHGJCMCMNMSNTNLOCPLQOQRSPSLSRTCTSTLVZYNZS"};

    int banA = 0, banMes = 0, banDia = 0;//banderas para colocar bien el año, mes y dia
    int esbisiesto = 0; //se activa si es año bisiesto
    int longitud, consonante  = 0, vocal = 0;

    /*NOMBRE COMPLETO*/
     //NOMBRE
        printf("***CALCULA TU CURP***\n");
        printf("Escribe solo tu nombre(Ej: Fernanda, Sol, Roberto): ");
        scanf("%s", nombre);
        printf("\nSi tu primer nombre es Maria o Jose presiona s sino presiona cualquier otra tecla: ");
        scanf("%s", &res);
        if(res == 's'){
            printf("\nTienes un segundo nombre?: presiona x para confirmar o presiona cualquier otra tecla para negar: ");
            scanf("%s", &res);
            if(res == 'x'){
                printf("\nEscribe tu segundo nombre: ");
                scanf("%s", nombre);
            }
        }

        CURP[4] =  nombre[0];
        //printf("LETRA nombre: %c", CURP[3]);
        //método para encontrar primera consonante
        longitud = sizeof (nombre);
        for (int i=1; i<longitud; i++) {
            if (nombre[i] != 'a' && nombre[i] != 'e' && nombre[i] != 'i' && nombre[i] != 'o' && nombre[i] != 'u'){
                CURP[16] = nombre[i];
                break;
            }
        }
    //printf("consonante nombre: %c",CURP[15]);

     //APELLIDO PATERNO
        printf("\nEscribe tu apellido paterno(Ej: Hernandez, Solano, Pedraza): ");
        scanf("%s", primerApellido);
        //CURP[0] =  primerApellido[0];
        //printf("LETRA apellidoh ES: %c", CURP[0]);
        longitud = sizeof (primerApellido);
        for (int i=1; i<longitud; i++) {
            if ((consonante!=1) && primerApellido[i] != 'a' && primerApellido[i] != 'e' && primerApellido[i] != 'i' && primerApellido[i] != 'o' && primerApellido[i] != 'u'){
                CURP[14] = primerApellido[i];
                consonante++;
            }
            else if(vocal!=1){
                CURP[2] = primerApellido[i];
                vocal++;
            }
        }
        CURP[1] =  primerApellido[0];

     //APELLIDO MATERNO
        printf("\nEscribe tu apellido materno(Ej: Delfin, Soriano, Rocha): ");
        scanf("%s", segundoApellido);
        CURP[3] =  segundoApellido[0];
        //printf("LETRA apellidom: %c", CURP[2]);
        longitud = sizeof (segundoApellido);
        for (int i=1; i<longitud; i++) {
            if (segundoApellido[i] != 'a' && segundoApellido[i] != 'e' && segundoApellido[i] != 'i' && segundoApellido[i] != 'o' && segundoApellido[i] != 'u' ){
                CURP[15] = segundoApellido[i];
                break;
            }
        }

   /*FECHA DE NACIMIENTO*/
        //AÑO
        while (banA == 0){
            printf("\nIndica tu año de nacimiento colocando solo los dos ultimos digitos (EJ: 99,97,02, etc): ");
            scanf("%d", &aNac);
            if (aNac < 100 && aNac >= 0){
                banA = 1;
                if (aNac % 4 == 0){
                       //printf("Es un año bisiesto");  //testing
                        esbisiesto = 1;
                }
                if (aNac < 10){
                    //printf("Entre y vale %d", aNac);
                    CURP[5] = '0';
                    CURP[6] = aNac+'0';
                }
                else {
                    sprintf(conver, "%d", aNac);
                    CURP[5] = conver[0];
                    CURP[6] = conver[1];
                }
            }
            else {
                    printf("Error el año indicado no existe");
            }
        }
        //printf("\nEL ANO ES: %c%c", CURP[4], CURP[5]);

        //MES
        while (banMes == 0){
            printf("\nIndica el mes colocandolo en digito (EJ: 1,5,12, etc): ");
            scanf("%d", &mesNac);
            if(mesNac >= 0 && mesNac < 13){
                banMes = 1;
                if (mesNac < 10){
                    CURP[7] = '0';
                    CURP[8] = mesNac+'0';
                }
                else {
                    banMes = 1;
                    sprintf(conver, "%d", mesNac);
                    //printf("mes me dio %s", conver); //testing
                    CURP[7] = conver[0];
                    CURP[8] = conver[1];
                }
            }
            else {
                printf("Error el mes indicado no existe");
            }
        }

        //printf("\nEL MES ES: %c%c",CURP[6], CURP[7]); //Prueba

        //DIA
        while (banDia == 0){
            printf("\nIndica tu dia de nacimiento (EJ: 99,97,02, etc): ");
            scanf("%d", &diaNac);

            if (diaNac >= 32){
                printf("Error ningun mes tiene 32 dias o más");
            }
            else {
            //CASO FEBRERO
                if (mesNac == 2){
                    if(esbisiesto == 1){
                        if (diaNac < 30 ? banDia = 1 : printf("Error Febrero en año bisiesto no tiene mas de 29 dias\n")){
                        }
                    }
                    else {
                        if (diaNac < 29 ? banDia = 1 : printf("Error Febrero no tiene mas de 28 dias\n")){}
                    }
                }
                //30 dias
                else if(mesNac == 4 || mesNac == 6 || mesNac == 9 || mesNac == 11) {
                    if (diaNac < 31 ? banDia = 1 : printf("Error este mes no tiene mas de 30 dias\n")){}
                }
                //31 días
                else {
                    banDia = 1;
                }
                sprintf(conver, "%d", diaNac);
            }
        }
        CURP[9] = conver[0];
        CURP[10] = conver[1];
       // printf("\nEL DIA ES: %c%c", CURP[8], CURP[9]); //Prueba

    /*SEXO PERSONA*/
    printf("\nIntroduce tu sexo (M o H):");
    scanf("%s", &sexo);
     CURP[11] = sexo;

    /*ESTADO DE NACIMIENTO*/
    printf("\nSelecciona tu estado de nacimiento escribiendo el numero correspondiente: ");
    printf("\n\t\t1.-Aguascalientesz\n\t\t2.-Baja California\n\t\t3.-Baja California Sur\n\t\t4.-Campeche\n\t\t5.-Chiapas\n\t\t6.-Chihuahua\n\t\t7.-Ciudad de Mexico\n\t\t8.-Coahuila");
    printf("\n\t\t9.-Colima\n\t\t10.-Durango\n\t\t11.-Guanajuato\n\t\t12.-Guerrero\n\t\t13.-Hidalgo\n\t\t14.-Jalisco\n\t\t15.-Mexico\n\t\t16.-Michoacan");
    printf("\n\t\t17.-Morelos\n\t\t18.-Nayarit\n\t\t19.-Nuevo Leon\n\t\t20.-Oaxaca\n\t\t21.-Puebla\n\t\t22.-Queretaro\n\t\t23.-Quintana Roo\n\t\t24.-San Luis Potosi");
    printf("\n\t\t25.-Sinaloa\n\t\t26.-Sonora\n\t\t27.-Tabasco\n\t\t28.-Tamaulipas\n\t\t29.-Tlaxcala\n\t\t30.-Veracruz\n\t\t31.-Yucatan\n\t\t32.-Zacatecas\n");
    scanf("%d", &estado);

        int indice = estado*2;
        CURP[12] = codigoEstados[indice - 1];
        CURP[13] = codigoEstados[indice];

        //printf("\nEL ESTADO ES: %c%c",CURP[11], CURP[12]); //Prueba
        printf("\nTu CURP es: ");
        longitud = sizeof (CURP);
        for (int i = 1; i <= longitud; i++ ){
            printf("%c", toupper(CURP[i]));
        }
    return 0;
}
