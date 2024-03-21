Busqueda del patron de caracteres t dentro del string s.

i.e s = barbacoa t = bor respuesta = rbacoa.

siguiendo el patrón de los anteriores ejercicios, utilizando un hash_map como
validador y record de datos.

Acotar el patron. Cualquier patron que se busque dentro de la cadena, empezará y
acabará con un caracter de t. La longitud del substring siempre será => que t.

Empezando desde el comienzo. Buscar la primera ocurrencia de t. Para hacer la busqueda
más rápida utilzar el hash_map como referencia, cuando sea != 0, ahí comienza la
búsqueda.

Con el comienzo, buscar el final, del substring hasta que en el hash_map sea != 0.

En caso de que cualquiera de los dos sea igual a la longitud de s o la resta entre
el comienzo y el final sea menos a t. Devolver una string vacia.
