Tengo que buscar el mayor numero de prefijos identicos dentro de un set de palabras

Lo mas simple es iterar con cada palabra el resto y guardar en un mapa la cantidad de iteraciones hasta encontrar una desigualdad.

i.e

flor fauna florecer

Para flor:
  - fauna tiene 1 letra en comun en el prefijo
  - florecer tiene 3 letras en comun en el prefijo

En un set infinito, con un mapa puedo guardar la cantidad maxima del prefijo.
En una variable puedo guardar el maximo de coincidencias para un prefijo