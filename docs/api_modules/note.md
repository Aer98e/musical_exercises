# 🎼 Módulo `Note`

## Propósito
El módulo `Note` representa una **nota musical** con:
- Nombre (ej. `"Do"`, `"Reb"`, `"Fa#"`).
- Valor de altura natural (`valuePitch`), nunca cambia, y se usa de referencia.
- Variaciones de alteración (`pitchVariation` → representa sostenidos `#` o bemoles `b`).
- Grado musical dentro de la escala (`grades`).
- Enlaces a notas vecinas (`next`, `previous`) para recorrer diatonicamente las notas como en una escala.

---

## Estructura de la clase

```cpp
class Note {
public:
    Note(std::string name, int natural, Note* next = nullptr, Note* previous = nullptr);

    // Identidad
    std::string getName();

    // Grado musical
    std::string getGradeName();
    short getGradeValue();
    void changeGrade(int value);

    // Enlaces
    Note* getNextPtr();
    Note* getPreviousPtr();
    void modifyNextPtr(Note* newPtr);
    void modifyPreviousPtr(Note* newPtr);

    // Altura y variaciones
    short getValuePitch();
    void setPitchVariation(short variation);
    short getPitchVariation();
    void resetPitchVariation();
    int getGeneralPitch();

    // Debug
    void show();
private:
    std::string name;
    int valuePitch;
    Note* next;
    Note* previous;
    short pitchVariation;
    grades grade;
};
```

---

## Detalle de métodos

| Método | Descripción | Ejemplo |
|--------|-------------|---------|
| `getName()` | Devuelve el nombre de la nota con alteraciones (`Do#`, `Sib`). | `"Do"` + `pitchVariation=1` → `"C#"` |
| `getGradeName()` | Devuelve el grado en formato romano (`I`, `II`, …). | `grades::III` → `"III"` |
| `changeGrade(int value)` | Cambia el grado (1–7). Lanza excepción si el valor es inválido. | `changeGrade(5)` → grado V |
| `getNextPtr()` / `getPreviousPtr()` | Devuelven punteros a notas vecinas. | útil para recorrer escalas |
| `modifyNextPtr(Note*)` / `modifyPreviousPtr(Note*)` | Actualizan enlaces a notas vecinas. | conectar notas en lista circular |
| `getValuePitch()` | Devuelve el valor natural de la nota. | `"Do"` → 0, `"Re"` → 2 |
| `setPitchVariation(short)` | Cambia en valor de alteración. (ej. `+1` sostenido, `-1` bemol). | `setPitchVariation(-1)` → pitchVariation = -1 |
| `getGeneralPitch()` | Devuelve altura total (`valuePitch + pitchVariation`). | `"C"` (0) + `+1` → 1 |
| `show()` | Imprime información de depuración en consola. | `"Note (name):C ,(valuePitch):0 ,(next):0x...)"` |

---

## Notas de diseño
- **Encadenamiento**: `next` y `previous` permiten construir estructuras como escalas.
- **Robustez**: `changeGrade` valida valores entre 1 y 7, evitando grados inválidos.
- **Extensibilidad**: se puede ampliar para soportar octavas, armaduras de clave o microtonalidad.

---


# 🎼 Módulo `Note`

## 🎯 Propósito
- Abstraer notas musicales, sus relaciones y sus caracteristicas.
- Brinda herramientas a `Scale`, para abstraer escalas de la misma manera que con las notas.

---

## 📐 Responsabilidades
Cada isntancia de `Note`, brinda una nota que:
- Tiene nombre que puede contener alteraciones como **#** o **b** (ej. `"Fa#"`).
- Tiene un grado, que indica su lugar dentro de una escala (ej. `grades::V`).
- Tiene un numero invariable para su estado natural sin alteraciones (ej. `4`).
- Tiene un numero variable para indicar si tiene alteraciones (ej. `-1`).
- Tiene un número para indicar el valor de la nota inlcuyendo la alteracion (`3`).
- Puede conectarse por punteros a otros similares, a manera de presedente y consecuente.
- Metodos para modificar casi todo lo anterior.
- **No se puede alterar** ni el número de su estado natural, ni su nombre, una vez creados.

---

## 🧩 API (Funciones y Métodos Públicos)

### Sobre Identidad

#### getName()

```cpp
std::string getName();
```

- **Descripción**: Retorna el nombre de la nota, y en caso tenga alteraciones las agrega al nombre.
- **Retorno**: Nombre de la nota como `std::string`.
- **Ejemplo de uso**:

    ```cpp
    Note n("Do", 0);
    n.setPitchVariation(1);
    std::cout << n.getName(); // "Do#"
    ```

---

### Sobre Grados Musicales

#### getGradeName()

```cpp
std::string getGradeName();
```

- **Descripción**: Retorna el nombre del grado musical.
- **Retorno**: Grado de la nota del I - VII como `std::string`, en caso de no haberse iniciado retorna `"None"`.
- **Ejemplo de uso**:

    ```cpp
    Note n("Do", 0);
    n.changeGrade(5);
    std::cout << n.getGradeName(); // "V"
    ```

---

#### getGradeValue()
#### changeGrade()

---
### Sobre Enlaces
#### getNextPtr()
#### getPreviousPtr()
#### modifyNextPtr()
#### modifyPreviousPtr()
---
### Sobre Altura y Alteraciones
#### getValuePitch()
#### getPitchVariation()
#### settPitchVariation()
#### resetPitchVariation()
#### getGeneralPitch()
---
### Sobre Debug
#### show()

```cpp
// Ejemplo de firma

```

- **Descripción**: Explica qué hace.
- **Parámetros**: Lista con nombre, tipo y propósito.
- **Retorno**: Qué devuelve y en qué casos.
- **Excepciones**: Qué errores puede lanzar.
- **Ejemplo de uso**:
```cpp
// Ejemplo práctico de cómo se invoca
```

*(Repite esta sección para cada función o método relevante)*

---

## 🔄 Flujo de uso
Describe cómo se utiliza el módulo en un caso práctico:
1. Entrada del usuario o llamada desde otro módulo.
2. Procesamiento interno.
3. Salida esperada.

Incluye ejemplos de consola o fragmentos de código.

---

## ⚠️ Errores y validaciones
- Lista de validaciones implementadas.
- Errores comunes que pueden ocurrir.
- Validaciones pendientes por implementar.

---

## 🚀 Extensibilidad
- Cómo se puede ampliar el módulo.
- Limitaciones actuales.
- Ideas para futuras mejoras.

---

## 📎 Relación con otros módulos
- Qué módulos dependen de este.
- Qué módulos lo utilizan.
- Cómo se conecta en el diagrama de arquitectura.