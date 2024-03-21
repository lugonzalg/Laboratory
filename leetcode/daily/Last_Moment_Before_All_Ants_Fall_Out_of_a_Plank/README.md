We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. Some of the ants move to the left, the other move to the right.

When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.

When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.

Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.

Example 1:

	!(image)[https://assets.leetcode.com/uploads/2020/06/17/ants.jpg]

	El input de la función es n, izq[] y der[], donde:

		n es la longitud de la tabla.
		izq es la lista de hormigas que se mueven a la izquierda.
		der es ... a la derecha.

	Como primera aproximación sería utilizando las listas seguir un bucle, donde:

		Todo lo que llegue a -1 o n + 1, desaparece.
		Cuando dos hormigas se cruzan cambian de dirección.
		Cuando dos hormigas se cruzan, cancelan su movimiento para aplicar la nueva dirección.

	La cantidad de hormigas, 1 o infinito es igual. Por lo que creo que se puede representar todo
	en un mapa, donde:

	Una hormiga cambiara de dirección en mitad del movimiento:
		Comprobar si en la siguiente posición hay una hormiga con movimiento inverso.
	Una hormiga cambiara de dirección al finalizar el movimiento:
		Comprobar si en la posición final hay una hormiga con movimiento inverso.

	BLOQUEO

	Tipo de dato a elegir.

		Array:

			Dos arrays de dirección me facilitan el movimiento, pero para la busqueda
			en inserción tengo que revisar el array n veces. La busqueda se puede optimizar con
			binary search.

		Mapa:

			Un único mapa que aglutina todo. El primer elemento es la posición. El segundo debe ser un par
			para las dos direcciones posibles.

		Linked List:

			Debo crear una red de movimientos que crece según el programa.

	SOLUCIÓN:

		FAIL

	CONCLUSION:

		https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/solutions/4246013/for-beginners-ii-o-n-ii-just-for-loop/?envType=daily-question&envId=2023-11-04

		El resultado era mucho mas simple de lo que pensaba. TT.




