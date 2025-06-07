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
```

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
```

### Cronómetro interno
```cpp
// Reiniciar cronómetro
robot.crono();
// Obtener tiempo en milisegundos desde la última llamada a crono()
unsigned long tiempo = robot.tiempo();
```

---

## Documentación de métodos

| Método              | Descripción                                                                                          |
| ------------------- | ---------------------------------------------------------------------------------------------------- |
| `init()`            | Configura los pines como entrada o salida necesarios.                                                |
| `setMotors(v1, v2)` | Controla la velocidad y dirección de los motores. Valores entre -100 y 100.                          |
| `read_distance()`   | Lee la distancia desde el sensor ultrasónico HC-SR04 en centímetros. Retorna 450 si no detecta nada. |
| `tiempo()`          | Retorna el tiempo en milisegundos desde la última llamada a `crono()`.                           |
| `crono()`           | Reinicia el cronómetro interno |

---

## Configuración y prueba de pines y dirección de motores

Dado que la ubicación y conexión de los motores puede variar entre diferentes robots Probot MiniSumo, es importante verificar y ajustar la configuración de los pines para que cada motor funcione correctamente en ambas direcciones.

### Ejemplo para configurar y probar los motores

En el ejemplo siguiente podrás:

* Definir los pines para cada motor (motor A y motor B).
* Probar el movimiento hacia adelante y hacia atrás de cada motor por separado.
* Observar el comportamiento y, si es necesario, invertir la conexión de los pines para corregir la dirección.
* Leer la distancia del sensor ultrasónico.
* Imprimir el tiempo de ejecución y la distancia medida en el monitor serial.

```cpp
#include <MySumo.h>

// Ajusta estos pines según tu conexión
int motorA1 = 4;
int motorA2 = 5;
int motorB1 = 0;
int motorB2 = 2;
int trigPin = 14;
int echoPin = 12;

MySumo robot(motorA1, motorA2, motorB1, motorB2, trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  robot.init();
  Serial.println("Prueba de motores MiniSumo");

  // Motor A hacia adelante
  Serial.println("Motor A adelante");
  robot.setMotors(50, 0);
  delay(2000);

  // Motor A hacia atrás
  Serial.println("Motor A atrás");
  robot.setMotors(-50, 0);
  delay(2000);

  // Motor B hacia adelante
  Serial.println("Motor B adelante");
  robot.setMotors(0, 50);
  delay(2000);

  // Motor B hacia atrás
  Serial.println("Motor B atrás");
  robot.setMotors(0, -50);
  delay(2000);

  // Detener motores
  Serial.println("Motores detenidos");
  robot.setMotors(0, 0);
  robot.crono();
}

void loop() {
  float distancia = robot.read_distance();
  unsigned long tiempo = robot.tiempo();
  Serial.print("Tiempo: ");
  Serial.print(tiempo);
  Serial.print(" ms, ");
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);
}
```

### ¿Qué hacer si un motor gira al revés?

* Intercambia los pines `motorA1` y `motorA2` para corregir la dirección del motor A.
* Intercambia los pines `motorB1` y `motorB2` para corregir la dirección del motor B.
* Vuelve a cargar el programa y repite la prueba.

Esto te permitirá adaptar la librería fácilmente a la configuración física de tu robot.

---

## Autor

Patricio Welch  
Email: [patriciowelch@gmail.com](mailto:patriciowelch@gmail.com)

---

## Licencia

ProbotSchool derechos de reproduccion y comercialización.

---

¡Gracias por usar **MySumo**!  
Si tienes dudas o quieres contribuir, abre un issue o un pull request.
````
