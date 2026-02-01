# 📐 Arquitectura del Generador de Ejercicios Musicales

## Objetivo
Definir cómo interactúan los módulos principales del proyecto:
- **Note** → Representa una nota musical individual.
- **Scale** → Conjunto de notas organizadas en una escala.
- **Exercises Functions** → Funciones que generan y evalúan ejercicios.
- **main.cpp** → Punto de entrada, gestiona el menú y la interacción con el usuario.

---

## Diagrama de interacción (simplificado)

```
+-------------------+
|      main.cpp     |
|  - Menú usuario   |
|  - Control flujo  |
+---------+---------+
          |
          v
+-------------------+       +-------------------+
| ExercisesFunctions|<----->|       Scale       |
| - Ejercicios      |       | - Conjunto Notes |
| - Lógica práctica |       | - Métodos acceso |
+-------------------+       +---------+---------+
                                    |
                                    v
                           +-------------------+
                           |       Note        |
                           | - Nombre          |
                           | - Pitch           |
                           | - Grado           |
                           | - Enlaces (prev/next) |
                           +-------------------+
```

---

## Flujo de ejecución
1. **Usuario** selecciona un ejercicio en `main.cpp`.
2. `main.cpp` llama a la función correspondiente en **ExercisesFunctions**.
3. Las funciones de ejercicios consultan o manipulan una **Scale**.
4. **Scale** se compone de múltiples objetos **Note**, enlazados entre sí.
5. Cada **Note** aporta información sobre nombre, grado y variaciones de altura.
6. El resultado se muestra en consola.

---

## Responsabilidades de cada módulo

- **Note**
  - Encapsula la información de una nota.
  - Permite recorrer notas mediante punteros `next` y `previous`.
  - Gestiona alteraciones (`#`, `b`) y grados musicales.

- **Scale**
  - Construye y organiza un conjunto de `Note`.
  - Proporciona acceso a notas según posición o grado.
  - Sirve como base para ejercicios de escalas e intervalos.

- **ExercisesFunctions**
  - Implementa la lógica de los distintos ejercicios.
  - Usa `Scale` y `Note` para generar preguntas y validar respuestas.
  - Mantiene independencia del menú principal.

- **main.cpp**
  - Presenta el menú al usuario.
  - Controla el flujo de ejecución.
  - Invoca funciones de ejercicios según la opción seleccionada.

