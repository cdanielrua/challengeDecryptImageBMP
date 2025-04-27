🔓 Desencriptación de Imágenes BMP
Este proyecto describe el proceso de desencriptar imágenes BMP utilizando C++, aplicando una serie de transformaciones distribuidas en funciones específicas para recuperar los datos originales.

La primera función se encarga de realizar transformaciones sobre bloques de ocho bits. Entre las transformaciones disponibles se encuentran: desplazamiento a la derecha, desplazamiento a la izquierda, rotación a la derecha y rotación a la izquierda.

Una vez aplicada alguna transformación, interviene la función de enmascaramiento, que suma el resultado anterior con una máscara específica para modificar los datos de forma controlada.

Posteriormente, se utiliza la función de verificación, la cual compara el resultado de las operaciones con los datos de referencia almacenados en un archivo .txt. Si la verificación es exitosa, se guarda la imagen parcial correspondiente y el proceso continúa con los siguientes bloques de datos.

En caso de falla en la verificación, se prueba otra transformación diferente, repitiendo el ciclo de transformación, enmascaramiento y verificación hasta encontrar la combinación correcta.

Este procedimiento se repite hasta que todos los bloques de la imagen sean verificados exitosamente, logrando así reconstruir completamente la imagen BMP original.


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

## 📌 Ejemplo de equivalencia entre rotaciones

En una rotación circular de 8 bits, rotar a la izquierda `n` veces es **equivalente** a rotar a la derecha `8 - n` veces.

> 🔄 `rotate_left(value, n) == rotate_right(value, 8 - n)`

### 🔧 Ejemplo práctico

Tomamos el valor `0b10110101` y lo rotamos:

| Operación               | Resultado    |
|-------------------------|--------------|
| Valor original          | `10110101`   |
| Rotación izquierda (3)  | `10101101`   |
| Rotación derecha (5)    | `10101101`   |

Como se ve en la tabla, ambos resultados son **idénticos**.

### ✅ Conclusión

Esto demuestra que, en lugar de implementar funciones para rotar en ambas direcciones, podemos optimizar el código utilizando **solo una dirección** (por ejemplo, rotación a la izquierda), y ajustar la cantidad de bits para obtener el mismo resultado.
