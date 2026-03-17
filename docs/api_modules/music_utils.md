# 🛠️ Módulo `Music Utils`

## 🎯 Propósito
Este módulo provee funciones de utilidad general para la generación de números aleatorios y la selección al azar de patrones musicales, desacoplando la lógica de aleatoriedad del resto de los módulos.

---

## 📐 Responsabilidades
- Generar números enteros aleatorios dentro de rangos inclusivos.
- Seleccionar patrones de escala aleatorios desde `dtMusic::Patterns`.
- Asegurar que la semilla de aleatoriedad se gestione correctamente (mediante `std::random_device`).

---

## 🧩 API (Funciones Públicas)

### Aleatoriedad
#### int generate_rand_number(int max, int min = 0)
- **Descripción**: Genera un número entero entre `min` y `max` (ambos inclusive).
- **Parámetros**: `max` (límite superior), `min` (límite inferior, por defecto 0).
- **Sobrecarga**: Existe una versión para `std::size_t`.

### Patrones
#### std::pair<std::string, std::vector<int>> getRandPattern()
- **Descripción**: Selecciona una escala al azar de las disponibles en el sistema.
- **Retorno**: Un par conteniendo el nombre de la escala y su vector de intervalos.

---

## 🔄 Flujo de uso
```cpp
int notaAlAzar = generate_rand_number(6); // 0 a 6
auto [nombre, pasos] = getRandPattern(); // ej. {"Mayor", {2,2,1,2,2,2,1}}
```

---

## ⚠️ Errores y validaciones
- No realiza validaciones internas de rangos (asume que `min <= max`).

---

## 🚀 Extensibilidad
- Se pueden añadir funciones para generar ritmos aleatorios o duraciones.
- Posibilidad de implementar diferentes tipos de distribuciones (no solo uniforme).

---

## 📎 Relación con otros módulos
- **ExercisesFunctions**: Depende críticamente de estas funciones para generar la variabilidad en los ejercicios.
