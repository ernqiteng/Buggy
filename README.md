# RoboSoc Buggy Project 🤖🚗

This project was developed as part of the **Buggy Project** organised by the University of Manchester Robotics Society (RoboSoc). Across the second semester, our team built, programmed, and refined a fully functional robotics buggy using embedded systems, sensor integration, and real-time motor control.

Our buggy successfully competed in the end-of-semester RoboSoc competition, where we won the **Straight-Line Challenge** 🏆 — a category focused on achieving stable, accurate, and consistent autonomous forward movement.

---

# Project Overview

The buggy is an Arduino-powered robotic vehicle capable of controlled movement, sensor-based distance measurement, and servo-assisted environmental scanning.

The project combines:

* Embedded C++ programming
* Motor driver control
* Ultrasonic sensing
* Servo actuation
* Circuit assembly and soldering
* Real-world robotics debugging

The aim was not only to build a working robot, but to understand how software logic interacts with physical hardware and mechanical systems.

---

# Key Features

## ⚡ Dual DC Motor Drive System

Independent control of left and right motors allows:

* Forward movement
* Reverse movement
* Precision turning
* Differential steering

PWM motor control enables adjustable speed tuning for smoother movement and improved stability.

---

## 📡 Ultrasonic Distance Sensing

An HC-SR04 ultrasonic sensor provides real-time distance measurements by calculating pulse reflection timing.

```cpp
long distance = (duration / 2) * 0.0343;
```

This forms the foundation for future autonomous obstacle avoidance functionality.

---

## 🎯 Servo-Based Sensor Scanning

The ultrasonic sensor is mounted on a servo motor capable of rotating between:

* 0°
* 90°
* 180°

This enables wider environmental awareness and directional sensing.

---

## 🧠 Modular Embedded Control System

The software architecture was designed using modular functions for clarity and scalability:

```cpp
moveForwards();
moveBackwards();
turnleft();
turnright();
halt();
```

Each function independently manages motor direction and speed using the motor driver circuitry.

---

# Hardware Components

| Component                 | Purpose               |
| ------------------------- | --------------------- |
| Arduino UNO               | Main microcontroller  |
| L298N Motor Driver        | DC motor control      |
| HC-SR04 Ultrasonic Sensor | Distance measurement  |
| Servo Motor               | Sensor positioning    |
| DC Motors (x2)            | Locomotion            |
| Chassis + Wheels          | Structural platform   |
| External Battery Pack     | Portable power supply |

---

# Pin Configuration

| Arduino Pin | Function                 |
| ----------- | ------------------------ |
| 3           | Right Motor Enable (ENB) |
| 4           | Right Motor Direction    |
| 5           | Right Motor Direction    |
| 7           | Left Motor Direction     |
| 8           | Left Motor Direction     |
| 9           | Left Motor Enable (ENA)  |
| 10          | Servo Control            |
| 6           | Ultrasonic Trigger       |
| 11          | Ultrasonic Echo          |

---

# Software Structure

## Movement Functions

```cpp
moveForwards();
moveBackwards();
turnleft();
turnright();
halt();
```

These functions control motor direction using the L298N motor driver and PWM speed signals.

---

## Distance Measurement

```cpp
measureDistance();
```

The ultrasonic sensor continuously measures nearby objects and outputs readings to the Serial Monitor.

---

## Servo Scanning

```cpp
move_servo();
```

The servo rotates the sensor to scan different angles and simulate basic environmental mapping.

---

## Diagnostic Testing

```cpp
testmovement();
```

This routine sequentially tests:

* Forward motion
* Reverse motion
* Left turn
* Right turn
* Full stop

allowing rapid debugging of motor behaviour and wiring.

---

# Technical Skills Developed

This project significantly strengthened practical engineering and robotics skills, including:

* Embedded C++ programming
* Arduino development
* Electronics assembly
* Soldering and wiring
* PWM motor control
* Sensor integration
* Hardware debugging
* System-level troubleshooting
* Robotics calibration and testing
