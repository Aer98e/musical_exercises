# 🎹 Módulo `Scale`

## 🎯 Propósito
El módulo `Scale` gestiona una colección circular de objetos `Note`, permitiendo construir, manipular y recorrer estructuras musicales completas (escalas). Implementa el patrón **Singleton** para mantener una instancia base global.

---

## 📐 Responsabilidades
- Construir la estructura circular de notas vinculadas.
- Gestionar la "nota seleccionada" actual para navegación.
- Aplicar patrones interválicos (Mayor, Menor, etc.) a las notas.
- Reasignar grados musicales dinámicamente.
- Proporcionar acceso aleatorio o secuencial a las notas de la escala.

---

## 🧩 API (Funciones y Métodos Públicos)

### Singleton
#### static Scale* getScale()
- **Descripción**: Retorna la instancia única de la escala. Si no existe, la crea con una base diatónica de Do Mayor.
- **Retorno**: Puntero a la instancia de `Scale`.

### Navegación
#### void selectNextNote(int steps = 1) / void selectPreviousNote(int steps = 1)
- **Descripción**: Mueve el puntero `selectedNote` el número de pasos especificado.

#### Note* getSelectedNote()
- **Descripción**: Retorna la nota que tiene el foco actual.

#### void goBeginning()
- **Descripción**: Reposiciona `selectedNote` en el primer grado (Tónica) de la escala.

### Manipulación
#### void applyScalePattern(std::vector<int> pattern, int initialModification = 0)
- **Descripción**: Modifica las alteraciones (`pitchVariation`) de todas las notas según un patrón de semitonos.
- **Parámetros**:
    - `pattern`: Vector de enteros (ej. `{2, 2, 1, 2, 2, 2, 1}`).
    - `initialModification`: Ajuste inicial para la tónica (-1 a 1).
- **Excepciones**: `std::invalid_argument` si el patrón no suma 12 o el tamaño es incorrecto.

#### void reassignGrades(short value)
- **Descripción**: Reasigna los grados I-VII empezando desde la nota seleccionada.

---

## 🔄 Flujo de uso
1. Obtener la escala: `Scale* s = Scale::getScale();`
2. Aplicar un patrón: `s->applyScalePattern({2, 1, 2, 2, 1, 2, 2});` // Menor Natural
3. Navegar: `s->selectNextNote(2);` // Salta a la tercera
4. Consultar: `std::cout << s->getSelectedNote()->getName();`

---

## ⚠️ Errores y validaciones
- Valida que la suma de semitonos en un patrón sea exactamente 12.
- Asegura que el tamaño del patrón coincida con el número de notas en la escala (usualmente 7).

---

## 🚀 Extensibilidad
- Permitir escalas de diferente número de notas (pentatónicas, cromáticas).
- Soporte para múltiples instancias de escala simultáneas.

---

## 📎 Relación con otros módulos
- **Note**: `Scale` es el contenedor y gestor principal de objetos `Note`.
- **ExercisesFunctions**: Utiliza `Scale` para generar el contexto de los ejercicios.
