
Para desencriptar estas imágenes con C++, seguiremos una serie de pasos distribuidos en distintas funciones.

La primera función se encargará de realizar las transformaciones sobre los datos. Estas transformaciones pueden ser: desplazamiento a la derecha, desplazamiento a la izquierda, rotación a la derecha o rotación a la izquierda, todas aplicadas a bloques de ocho bits.

Una vez probada alguna de estas transformaciones, se aplicará la segunda función: el enmascaramiento. Esta función sumará el resultado de la transformación con una máscara específica.

Luego, entra en juego la función de verificación. Esta se encargará de comprobar si, después de aplicar la transformación y el enmascaramiento, el resultado coincide con los datos contenidos en un archivo .txt que usamos como referencia. Si la verificación es exitosa, se guarda la imagen correspondiente y se repite el proceso con los siguientes bloques de datos.

En caso de que la verificación falle, se prueba con una transformación distinta entre las disponibles, y se repite el proceso de transformación, enmascaramiento y verificación.

Este procedimiento continúa hasta que todas las verificaciones coincidan con los datos de los archivos .txt, logrando así reconstruir por completo la imagen original.



---

## 🔐 Encriptación y Transformaciones sobre Bytes

Este repositorio implementa y analiza diferentes transformaciones sobre datos de 8 bits (1 byte), con el fin de evaluar su utilidad en procesos de cifrado y desencriptado, como en el caso del proyecto de imágenes BMP encriptadas.

### ✳️ Funciones implementadas

Se incluyen tres tipos de operaciones:

1. **XOR con máscara (8 bits)**  
   Permite aplicar una operación bit a bit con una máscara arbitraria, útil para ocultar patrones de forma reversible.

2. **Rotaciones (cíclicas) a la derecha e izquierda (1 a 7 bits)**  
   Estas operaciones **no pierden información**, ya que los bits desplazados salen por un lado y entran por el otro.  
   → Ideales para procesos de encriptación reversibles.

3. **Desplazamientos (shifts) a la derecha e izquierda (1 a 7 bits)**  
   Estas operaciones **sí pierden información**, porque al desplazar se introducen ceros en los extremos y se eliminan bits.  
   → **No son recomendables** para cifrado reversible, ya que no permiten recuperar el valor original.

### 🧠 Optimización de funciones

Inicialmente se implementan 15 funciones:

- 7 rotaciones a la derecha
- 7 rotaciones a la izquierda
- 1 función XOR

Pero debido a la **simetría en las rotaciones** (ej. rotar izquierda 1 es igual a rotar derecha 7), y a que los **shifts no se usan por pérdida de información**, se puede reducir a un conjunto **óptimo de solo 8 funciones**:

- `rotate_right(value, bits)` para `bits = 1 a 7`
- `xor_mask(value, mask)`

Estas funciones son suficientes para aplicar transformaciones seguras y reversibles sobre los datos binarios, con bajo costo computacional y buena capacidad de combinación.

---
