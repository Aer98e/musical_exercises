# 📊 Módulo `Data Music` (dtMusic)

## 🎯 Propósito
El namespace `dtMusic` centraliza todas las constantes, datos maestros y estructuras de datos estáticas necesarias para la teoría musical en el proyecto. Actúa como la "base de datos" del programa.

---

## 📐 Responsabilidades
- Almacenar nombres de notas, grados e intervalos.
- Definir los patrones interválicos de las escalas comunes.
- Mapear nombres de intervalos a sus distancias en semitonos.
- Proveer la clase auxiliar `Nota_c` para lógicas simplificadas de pitch.

---

## 🧩 API (Estructuras y Datos)

### Clase `Nota_c` (Helper)
```cpp
class Nota_c { ... };
```
- **Descripción**: Una versión ligera de nota para procesos que no requieren la complejidad de la clase `Note`.
- **Métodos**: `addAlteration(int)`, `getPitchValue()`.

### Constantes Globales (extern)
#### Patterns
- **Tipo**: `std::unordered_map<std::string, std::vector<int>>`
- **Contenido**: Mapea nombres de escalas (ej. "Mayor") a sus distancias de semitonos.

#### gradeAwName
- **Tipo**: `std::vector<std::string>`
- **Contenido**: Nombres abreviados de los grados (`"I"`, `"II"`, etc.).

#### valueIntervales
- **Tipo**: `std::map<int, int>`
- **Contenido**: Mapea el número de grado (distancia nominal) a la distancia natural en semitonos.

---

## 🔄 Flujo de uso
Este módulo se utiliza principalmente para consulta en otros módulos:
```cpp
auto pattern = dtMusic::Patterns["Menor Armonica"];
std::string grado = dtMusic::gradeAwName[0]; // "I"
```

---

## ⚠️ Errores y validaciones
- Al ser datos estáticos, el riesgo principal es el acceso a índices fuera de rango en los vectores globales si no se coordinan con las constantes.

---

## 🚀 Extensibilidad
- Fácilmente ampliable añadiendo nuevos tipos de escalas a `Patterns`.
- Se pueden añadir nombres de acordes, tensiones o armaduras de clave.

---

## 📎 Relación con otros módulos
- **Scale / ExercisesFunctions**: Dependen totalmente de estos datos para funcionar correctamente y mostrar texto al usuario.
