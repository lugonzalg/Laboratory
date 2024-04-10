190. Reverse Bits
Easy
Topics
Companies

Reverse bits of a given 32 bits unsigned integer.

Note:

    Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

 

Constraints:

    The input must be a binary string of length 32

 

Follow up: If this function is called many times, how would you optimize it?

Analisis:

    Invertir los bits de 4 bytes. Empezar desde atras.

Algortimo:

    Asignar los bits en orden inverso empezando por 32 desde 0 hasta 0 desde 32

    1110 -> 0111

    empezando desde atras en este caso 0, que para llegar ahi tengo que hacer

    iterador = longitud - 1

    para el orden inverso es longitud - iterador e ira acercandose a 0 segun disminuya el iterador.

    Para el final es longitud - iterador
    Y para el comienzo es simplemente iterador.

    FAIL

Algoritmo 2:

 está en la respuesta XD. 