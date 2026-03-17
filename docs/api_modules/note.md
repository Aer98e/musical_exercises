# 🎼 Módulo `Note`

## 🎯 Propósito
El módulo `Note` representa una **nota musical** individual, encapsulando su nombre, altura musical, alteraciones (sostenidos/bemoles) y su grado dentro de una estructura diatónica (escala).

---

## 📐 Responsabilidades
- Mantener la identidad de la nota (nombre y altura base).
- Gestionar alteraciones dinámicas (`pitchVariation`).
- Rastrear el grado musical (I-VII) asignado a la nota.
- Facilitar el recorrido diatónico mediante punteros a notas adyacentes (`next`, `previous`).
- **No** gestiona la lógica de conjuntos de notas o patrones de escala (responsabilidad de `Scale`).

---

## 🧩 API (Funciones y Métodos Públicos)

### Constructor
```cpp
Note(std::string name, int natural, Note* next = nullptr, Note* previous = nullptr);
```
- **Descripción**: Inicializa una nota con su nombre fonético y su valor de semitono base.
- **Parámetros**: 
    - `name`: Nombre base (ej. "Do").
    - `natural`: Valor de pitch base (0-11).
    - `next`/`previous`: Punteros opcionales para encadenamiento.

### Identidad
#### getName()
- **Descripción**: Retorna el nombre completo de la nota calculando alteraciones.
- **Retorno**: `std::string` (ej. "Do#", "Rebb").

### Grados Musicales
#### getGradeName()
- **Descripción**: Retorna el grado en notación romana ("I", "II", etc.).
- **Retorno**: `std::string`.

#### changeGrade(int value)
- **Descripción**: Asigna un nuevo grado a la nota.
- **Parámetros**: `value` (1-7).
- **Excepciones**: `std::invalid_argument` si el valor está fuera de rango.

### Enlaces
#### getNextPtr() / getPreviousPtr()
- **Descripción**: Obtiene los punteros a las notas ligadas.

#### modifyNextPtr(Note*) / modifyPreviousPtr(Note*)
- **Descripción**: Actualiza los enlaces para formar estructuras circulares o lineales.

### Altura y Alteraciones
#### setPitchVariation(short variation)
- **Descripción**: Establece el número de semitonos de alteración.
- **Parámetros**: `variation` (positivo para sostenidos, negativo para bemoles).

#### getGeneralPitch()
- **Descripción**: Retorna la suma del pitch base y la variación actual.
- **Retorno**: `int`.

---

## 🔄 Flujo de uso
1. Se crea una nota: `Note c("Do", 0);`
2. Se integra en una escala (se enlazan punteros).
3. Se asigna un grado: `c.changeGrade(1);`
4. Se aplica una alteración según el contexto musical: `c.setPitchVariation(1);` // Do#

---

## ⚠️ Errores y validaciones
- `changeGrade` valida que el grado sea un entero entre 1 y 7.
- Los punteros `next` y `previous` pueden ser `nullptr` si no se han inicializado, lo que requiere precaución al recorrer.

---

## 🚀 Extensibilidad
- Puede ampliarse para incluir información de octava.
- Posibilidad de añadir soporte para microtonalidad mediante variaciones de coma o cent.

---

## 📎 Relación con otros módulos
- **Scale**: Utiliza múltiples instancias de `Note` para construir estructuras musicales.
- **ExercisesFunctions**: Consulta propiedades de `Note` para validar respuestas del usuario.
dependen de este.
- Qué módulos lo utilizan.
- Cómo se conecta en el diagrama de arquitectura.