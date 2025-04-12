
Para desencriptar estas imágenes con C++, seguiremos una serie de pasos distribuidos en distintas funciones.

La primera función se encargará de realizar las transformaciones sobre los datos. Estas transformaciones pueden ser: desplazamiento a la derecha, desplazamiento a la izquierda, rotación a la derecha o rotación a la izquierda, todas aplicadas a bloques de ocho bits.

Una vez probada alguna de estas transformaciones, se aplicará la segunda función: el enmascaramiento. Esta función sumará el resultado de la transformación con una máscara específica.

Luego, entra en juego la función de verificación. Esta se encargará de comprobar si, después de aplicar la transformación y el enmascaramiento, el resultado coincide con los datos contenidos en un archivo .txt que usamos como referencia. Si la verificación es exitosa, se guarda la imagen correspondiente y se repite el proceso con los siguientes bloques de datos.

En caso de que la verificación falle, se prueba con una transformación distinta entre las disponibles, y se repite el proceso de transformación, enmascaramiento y verificación.

Este procedimiento continúa hasta que todas las verificaciones coincidan con los datos de los archivos .txt, logrando así reconstruir por completo la imagen original.