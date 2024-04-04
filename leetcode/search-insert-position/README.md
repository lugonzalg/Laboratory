Debo buscar el elemento en una lista y devolver su posicion, si no existe, devolver su posicion teorica en un array ordenado.

Pide que la complejidad temporal sea de log n, binary search.

Primer intento, un bucle simple con complejidad n.

Segundo intento, busqueda binaria, para refrescar el algoritmo.

    |______^______|
   low    mid    high

    n se define como la longitud del array;
    mid se define como n / 2.
    high se define como n - 1.
    low se define como 0.

    Bucle:

        Si el objetivo es menor que mid:
            
            high = mid - 1;

        Si el objetivo es mayor que mid:

            low = mid + 1;


    Para este primer intento no esta contemplado que el numero no exista.
