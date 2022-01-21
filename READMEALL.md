//MEDIA-MEDIANA-MODA
Primero comencé pensando en la forma para validar si el usuario ingresa el caracter 'x' y que ello no tuviera conflicto con el ingreso de los números mi solución fue leer como cadena, implementar un do while con una condición donde se repita el proceso de solicitar la cantidad de números, una vez terminada la primera petición, hasta que el usuario ingrese una x. Posteriormente si el usuario no ingresa la x, hago la conversión de ese valor ingresado según el código ASCII y evalúo nuevamente según lo solicitado si la cantidad de números ingresados es menor a 2 o mayor a 5 sino se cumple, manda un mensaje de error y te pide escribir nuevamente. Si la condición se cumple, empieza el llenado del arreglo, una vez que se guarda cualquier valor, se evalua si ese valor cumple la condición de no ser un valor negativo ni mayor a cien. Si no cumple la condición se manda un mensaje de error, se decrementa el iterador para sobreescribir únicamente ese dato érroneo y se regresa al usuario a evaluar nuevamente.
Cuando el arreglo está lleno se mandan a llamar a las funciones de Maximo, Minimo, Media, Mediana y Moda pasándoles como parámetros el arreglo y la cantidad de datos ingresados ya que representa el tamano del arreglo.
El primer método evalúa al máximo tomando como primer valor la primera posición del arreglo por lo tanto la evaluación comienza en la posición 1 para no ser redudantes, se compara a la variable "temporal" con los demás valores y así se conoce cuál es el valor máximo. Se toma como caos único encontrar el valor 99 ya que no habrá un valor más grande que este.
El segundo método evalúa al mínimo tomando como primer valor el número 100 ya quel valor más grande nunca superará a este número, se toma como caso único el encontrar al valor 0 ya que ningún valor será menor que este, de manera similar a máximo hace la evaluación y retorna ese valor.
El tercer método es el de la Media el cual de forma simple suma todos los valores del arreglo en una variable y finalmente los divide entre la cantidad de elementos.
El cuarto método, el de la Mediana, requiere tener los datos ordenados ascendentemente por lo tanto se creó un método burbuja, declarado con anterioridad para ordenar el arreglo de este modo. Se manda a llamar y con los datos ordenados se determinan dos casos: cantidad de datos pares o impares. Siendo el caso de los pares más complejo se evalúa que se tendrán dos posibles valores para la mediana, por lo que se parte en 2 el arreglo: numero de elementos a la mitad, y el resultado arroja el índice de unos de los elementos a evaluar, al tratarse de un array se entiende que el índice hace referencia al segundo elemento por lo tanto en una variable se declara realizar la suma del arreglo en la posición de ese segundo elemento + el arreglo en la posición anterior menos 1 de ese modo accedemos al primer valor, finalmente este resultado se divide entre dos y obtenemos la mediana correcta. En el caso de elementos impares únicamente se necesita dividir el número de elemtnos entre dos y nos dará el el índice del arreglo correcto.
El último método, el de la moda, utiliza un arreglo auxiliar el cual se llenará de ceros y el proceso consiste en: 1.- Recorrer el vector y anotar las repeticiones 2.- Estas repeticiones se almacenan en el vector auxiliar así como su posición 3.- Teniendo lo anterior ahora se determina la posición donde se encuentran más repeticiones, se hace uso de una variable llamada posmayor la cual de cumplirse la condición donde el array auxiliar es mayor que quien tiene el valor mayor, almacena la posición de ese valor más repetido.
Finalmente se imprime el arreglo colocando como índice a la variable posmayor ya que esta tiene como último valor la posición del valor que más veces se repitió
Se imprimen los mensajes con los resultados y se le solicita al usuario si quiere volver a evaluar.

//Calculadora

Solicitar al usuario dos números.
Solicitar al usuario la operación a realizar.
La implementación de las operaciones, sera a través de funciones.
Los cálculos de las operaciones, se harán a través de las funciones implementadas.

Operaciones:
1.- suma
2.- resta
3.- multiplicación
4.- división

Las llamadas a las funciones se hará a través de punteros de funciones, que estén declarados en un arreglo
La aplicación deberá mostrar el resultado del cálculo.


//CURP
Generar la CURP de una persona mediante el llenado de la solicitud de sus datos: nombre, lugar de nacimiento, fecha, sexo, etc.
