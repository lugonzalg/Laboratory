303. Range Sum Query - Immutable
Easy
Topics
Companies

Given an integer array nums, handle multiple queries of the following type:

    Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:

    NumArray(int[] nums) Initializes the object with the integer array nums.
    int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

 

Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

Analisis:

    BRUTE FORCE

        Una clase que recibe como parametro una lista de integers.
        Tiene que devolver la suma de los elementos en el array desde n a m.

    SUMA DE PREFIJOS

        Para evitar tener que calcular cada elemento en cada busqueda de forma lineal se puede hacer una pre-procesamiento de los datos.

            metodo 1:
                calcular todas los posibles resultados para cualquier indice. La complejidad de tiempo es O(n^2). Habria que giardarlo en un array 2D.

            metodo 2:
                calcular el prefijo. Crear una lista melliza que en cada posicion contiene el calculo hecho hasta ese indice.

                ejemplo:

                    para una lista 1,2,3,4 se crearia una lista melliza 1,3,6,10 cada indice nuevo lleva la suma de todos los valores anteriores.

                Para calcular el valor de cualquier rango que no empiece en 0 es: valor indice derecha - valor indice izquierda - 1

                ejemplo:

                    lista 1,2,3,4
                    melliza 1,3,6,10

                    valores desde 1 a 3

                        10 - 1 = 9
                        2[1]+3[2]+4[3] = 9

Algortimo:

    BRUTE FORCE:

        constructor:

            iniciar list de integers

        sumRange(left, right):

            sumar desde left a right y devolver el resultado

    SUMA DE PREFIJOS:

        constructor:

            crear lista melliza con el precalculo

        sumRange(l, r):

            si l es 0 (no hay que quitar nada)
                devolver acumulado[r]
            devolver acumulado[r] - acumulado[l - 1]