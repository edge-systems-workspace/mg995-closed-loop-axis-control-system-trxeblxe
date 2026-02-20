
/**
 * @file main.cpp
 * @brief MG995 Closed-Loop Axis Control System
 * @author Sahil Srivastava
 * @date 2026-02-20
 *
 * @details
 * Implements PWM-based closed-loop control for MG995 servo motor.
 * Accepts angle input via Serial Monitor and validates range (0–180).
 * */
#include <Arduino.h>

#include <Servo.h>

Servo MYSERVO;

int trigPin = 9;
int echoPin = 10;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    MYSERVO.attach(5);
    Serial.begin(9600);
}

void loop() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.0343) / 2;

    if (distance <= 5) {
        MYSERVO.write(180);   // rotate servo
    } else {
        MYSERVO.write(0);     // reset servo
    }

    Serial.print("Distance:: ");
    Serial.print(distance);
    Serial.println("cm");

    delay(500);
}