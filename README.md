# Generador de Ejercicios Musicales 🎶

## Descripción
Este proyecto en C++ implementa una serie de **ejercicios interactivos de teoría musical**, incluyendo escalas, intervalos y acordes especiales.  
El programa ofrece un menú en consola donde el usuario puede seleccionar el tipo de ejercicio y la cantidad de ejemplos a practicar.

## Estructura del proyecto

```
ProyectoMusical/
├── CMakeLists.txt
├── README.md
├── docs/
│   ├── architecture.md
│   ├── execution_flow.md
│   └── api_modules/
├── include/
│   ├── data_music.h
│   ├── exercises_functions.h
│   ├── interval_network.h
│   ├── music_utils.h
│   ├── note.h
│   └── scale.h
├── src/
│   ├── data_music.cpp
│   ├── exercises_functions.cpp
│   ├── interval_network.cpp
│   ├── main.cpp
│   ├── music_utils.cpp
│   ├── note.cpp
│   └── scale.cpp
└── tests/
    ├── test_intervalNetwork.cpp
    ├── test_notes.cpp
    └── test_scale.cpp

```

- `src/` → Código fuente en C++ (`.cpp`).
- `include/` → Cabeceras (`.h`).
- `docs/` → Documentación técnica.
- `tests/` → Pruebas unitarias.

## Requisitos
- **CMake ≥ 3.15**
- **Compilador C++20** (GCC, Clang o MSVC)
- Sistema operativo: Linux, macOS o Windows

## Compilación
Desde la raíz del proyecto:

```bash
mkdir build
cd build
cmake ..
make
```

Esto generará el ejecutable `TeoricExercises`.

## Ejecución
```bash
./TeoricExercises
```

El programa mostrará un menú con las siguientes opciones:
1. Ejercicios para escalas  
2. Ejercicios de intervalos (grados)  
3. Ejercicios de intervalos (notas)  
4. Ejercicios para reconocer escalas  
5. Ejercicios para reconocer intervalos  
6. Ejercicios para sexta aumentada  

## Próximos pasos
- Implementar validación de entrada (`std::cin.fail`).
- Documentar funciones en `docs/api.md`.
- Añadir pruebas unitarias en `tests/`.

---
