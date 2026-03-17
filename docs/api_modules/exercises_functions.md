# 📝 Módulo `Exercises Functions`

## 🎯 Propósito
Este módulo contiene la lógica principal para la generación de los diferentes tipos de ejercicios de teoría musical. Actúa como el puente entre el motor musical (`Scale`, `Note`) y la interfaz de usuario.

---

## 📐 Responsabilidades
- Generar enunciados de ejercicios basados en parámetros aleatorios.
- Orquestar la manipulación de la escala para cada ejercicio.
- Validar (opcionalmente) las respuestas del usuario mediante comparaciones interválicas.

---

## 🧩 API (Funciones Disponibles)

### Ejercicios de Escalas
#### void byWriteScales_Nova(int amount, Scale* nova)
- **Descripción**: Genera ejercicios donde se pide escribir una escala específica a partir de una nota y un grado dado.

#### void byRecognizeScale(int amount, int numElements)
- **Descripción**: Pide al usuario identificar una escala que contenga un conjunto de notas dadas.

### Ejercicios de Intervalos
#### void byRecognizeIntervalsGrades_Nova(int amount, Scale* nova)
- **Descripción**: Genera preguntas sobre el intervalo entre dos grados de una escala (ej. entre el III y el VI).

#### void byRecognizeIntervalsNotes_Nova(int amount, Scale* nova)
- **Descripción**: Preguntas sobre el intervalo entre dos notas específicas incluyendo su octava.

### Acordes Especiales
#### void byFormAugmentedSixthChords(int amount, Scale* nova)
- **Descripción**: Ejercicios para formar acordes de sexta aumentada (Italiana, Francesa, Alemana, Suiza).

---

## 🔄 Flujo de uso
1. El `main.cpp` llama a una función: `byWriteScales_Nova(5, miEscala);`
2. La función selecciona una tónica y un patrón al azar.
3. Imprime el reto en la consola.
4. Espera a que el usuario presione una tecla o ingrese datos.

---

## ⚠️ Errores y validaciones
- Algunas funciones tienen validaciones de respuesta comentadas (pendientes de implementación final).
- Depende de que la instancia de `Scale` esté correctamente inicializada.

---

## 🚀 Extensibilidad
- Añadir ejercicios de lectura de clave.
- Ejercicios de dictado rítmico o melódico.
- Integrar un sistema de puntuación.

---

## 📎 Relación con otros módulos
- **main.cpp**: Es el consumidor principal de estas funciones.
- **Scale / Note**: Herramientas fundamentales para generar los datos de los ejercicios.
- **IntervalNetwork**: Usado para calcular las soluciones de los intervalos.
