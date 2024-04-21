Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

 

Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105


Analisis:

    paso 1:
        llorar

    paso 2:

        Según el video de neetcode. Utilzando la tecnica de los dos punteros.

            1 - Hay que guardar el maximo de altura para izquierda y derecha.

            2 - El calculo de agua se hace con el minimo de las alturas para izquierda y derecha.

            3 - El calculo es:
                
                res = min(max_left, max_right) - curr_pos

            4 - Sumar todos los valores que sean mayor que 0


Algoritmo:

    left, right = 0, len - 1
    max_left = max_right = 0

    while left < right

        if max_left <= max_right:
            res = min(max_left, max_right) - left
            max_left = max(max_left, left)
        else
            res = min(max_left, max_right) - right
            max_right = max(max_left, right)
        
        if res > 0:
            ans += res

    return ans