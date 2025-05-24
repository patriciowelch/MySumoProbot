````markdown
# MySumo

**MySumo** es una librería para controlar robots MiniSumo diseñados para Probot 2025.
Facilita la gestión de motores y la lectura de sensores ultrasónicos para la medición de distancia,
ideal para competiciones o proyectos educativos de MiniSumo.

---

## Características

- Control sencillo de dos motores DC con soporte para dirección y velocidad variables.
- Lectura de sensor ultrasónico HC-SR04 para medir distancia frontal.
- Configuración flexible de pines para motores y sensor.
- Métodos fáciles de usar: inicialización, control de motores y lectura de distancia.

---

## Instalación

1. Descarga o clona este repositorio.
2. Copia las carpetas `MySumo` en tu carpeta de librerías de Arduino (`Documents/Arduino/libraries/`).
3. Reinicia el IDE de Arduino.
4. Incluye la librería en tu sketch:

```cpp
#include <MySumo.h>
````

---

## Uso básico

### Crear una instancia

Puedes crear el objeto MySumo con diferentes constructores:

```cpp
// Con pines personalizados para motores y sensor ultrasónico
MySumo robot(4, 5, 0, 2, 14, 12);

// Con pines personalizados para motores, y pines por defecto para sensor
MySumo robot(4, 5, 0, 2);

// Con todos los pines por defecto
MySumo robot();
```

### Inicializar la librería

```cpp
robot.init();
```

### Controlar motores

```cpp
// Enviar velocidad a motores (valor entre -100 y 100)
// v1 para motor A, v2 para motor B
robot.setMotors(80, -50);
```

### Leer distancia con sensor ultrasónico

```cpp
float distancia = robot.read_distance();
Serial.println(distancia);
```

---

## Documentación de métodos

| Método              | Descripción                                                                                          |
| ------------------- | ---------------------------------------------------------------------------------------------------- |
| `init()`            | Configura los pines como entrada o salida necesarios.                                                |
| `setMotors(v1, v2)` | Controla la velocidad y dirección de los motores. Valores entre -100 y 100.                          |
| `read_distance()`   | Lee la distancia desde el sensor ultrasónico HC-SR04 en centímetros. Retorna 450 si no detecta nada. |

---

## Autor

Patricio Welch
Email: [patriciowelch@gmail.com](mailto:patriciowelch@gmail.com)

---

## Licencia

MIT License
(Agrega aquí la licencia que prefieras)

---

¡Gracias por usar **MySumo**!
Si tienes dudas o quieres contribuir, abre un issue o un pull request.

```

---

¿Quieres que te genere el archivo listo para subir? ¿O prefieres que incluya ejemplos de código más avanzados o alguna sección adicional?
```
