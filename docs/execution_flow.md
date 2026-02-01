# 🔄 Flujo de Ejecución

## Objetivo
Explicar paso a paso cómo el usuario interactúa con el programa, desde la selección de un ejercicio hasta la finalización.

---

## Ejemplo de sesión

### 1. Inicio del programa
Al ejecutar `./TeoricExercises`, se limpia la pantalla y aparece el menú principal:

```
    ====EJERCICIOS DE TEORIA MUSICAL====

1) Ejercicios para escalas.
2) Ejercicios de intervalos(GRADOS).
3) Ejercicios de intervalos(NOTAS).
4) Ejercicios para reconocer escalas.
5) Ejercicios para reconocer intervalos.
6) Ejercicios para sexta aumentada.
```

---

### 2. Selección de opción
El programa solicita al usuario elegir un ejercicio:

```
Que ejercicio desea?: 2
```

El usuario ingresa `2` (ejercicios de intervalos por grados).

---

### 3. Cantidad de ejercicios
El programa solicita la cantidad de ejercicios:

```
Cuantos ejercicios solicita?: 3
```

El usuario ingresa `3`.

---

### 4. Ejecución del ejercicio
El programa llama a la función correspondiente:

```cpp
byRecognizeIntervalsGrades_Nova(3, nova);
```

En consola se muestran los ejercicios generados (ejemplo):

```
Ejercicio 1: ¿Cuál es el intervalo entre Do y Mi?
Ejercicio 2: ¿Cuál es el intervalo entre D y A?
Ejercicio 3: ¿Cuál es el intervalo entre F y B?
```

---

### 5. Repetición
Al finalizar, el programa pregunta:

```
Desea otro ejercicio?(1 = si || 0 = no): 1
```

Si el usuario ingresa `1`, se repite el flujo desde el menú.  
Si ingresa `0`, el programa termina.

---

## Casos de error
- Si el usuario ingresa una opción inválida (`9`), se muestra:

```
Error de solicitud.
Vuelve a intentarlo.
```

- Si el usuario ingresa un valor no numérico, se debe implementar validación con `std::cin.fail` (pendiente).

---

## Resumen del flujo
1. Mostrar menú.  
2. Solicitar opción y cantidad de ejercicios.  
3. Ejecutar función correspondiente.  
4. Mostrar resultados.  
5. Preguntar si desea repetir.  
6. Terminar o reiniciar según respuesta.
