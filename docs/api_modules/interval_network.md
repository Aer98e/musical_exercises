# 🕸️ Módulo `Interval Network`

## 🎯 Propósito
El módulo `IntervalNetwork` gestiona la nomenclatura específica de los intervalos (Mayor, Menor, Justo, Aumentado, Disminuido) mediante una red de nodos interconectados que representan la "calidad" del intervalo.

---

## 📐 Responsabilidades
- Definir las relaciones entre calidades de intervalos (ej. Mayor -> Aumentado al subir un semitono).
- Calcular el nombre específico de un intervalo basándose en una "desviación" de semitonos.
- Diferenciar entre intervalos Mayores/Menores y Justos.

---

## 🧩 API (Funciones y Métodos Públicos)

### Clase `IntervalNetwork` (Singleton)
#### static IntervalNetwork& getInstance()
- **Descripción**: Acceso al singleton de la red de intervalos.

#### void selectMode(Mode mode)
- **Descripción**: Configura la red para un intervalo natural Mayor o Justo.
- **Parámetros**: `Mode::Mayor` o `Mode::Justo`.

#### std::string calculateInterval(int desviation)
- **Descripción**: Navega por la red según el número de semitonos de diferencia y retorna el nombre final.
- **Parámetros**: `desviation` (entero, puede ser negativo).
- **Retorno**: `std::string` (ej. "Menor", "Doble aumentado").

---

## 🔄 Flujo de uso
1. Seleccionar modo: `net.selectMode(Mode::Mayor);` // Para una 3ra, por ejemplo.
2. Calcular: `net.calculateInterval(-1);` // Retorna "Menor".
3. Resultado: El nombre se combina con el número (ej. "Tercera" + "Menor").

---

## ⚠️ Errores y validaciones
- Lanza `std::runtime_error` si se intenta navegar más allá de los límites definidos (ej. más abajo de "Doble disminuido").

---

## 🚀 Extensibilidad
- Se pueden añadir calidades más extremas (Triple aumentado) si fuera necesario.

---

## 📎 Relación con otros módulos
- **ExercisesFunctions**: Utiliza este módulo en `compareIntervals` para determinar la respuesta correcta de los ejercicios.
