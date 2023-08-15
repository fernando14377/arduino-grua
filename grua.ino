#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <IRremote.hpp>

#define boton_0 0xE916FF00
#define boton_1 0xF30CFF00 
#define boton_2 0xE718FF00
#define boton_3 0xA15EFF00 
#define boton_4 0xF708FF00
#define boton_5 0xE31CFF00

Servo servo_rotatorio;
Servo servo_giratorio;
Servo servo_medio;
Servo servo_bajo;
Servo servo_trasero;
Servo servo_trasero_bajo

// servo garra.
int pinServoGarra = 4;
int PULSOMINGARRA = 400;
int PULSOMAXGARRA = 800;

// servo bajo.
int pinServoBajo = 5;
int PULSOMINBAJO = 2000;
int PULSOMAXBAJO = 3000;

// servo medio.
int pinServoMedio = 6;
int PULSOMINMEDIO = 1000;
int PULSOMAXMEDIO = 2000;

// servo giratorio.
int pinServoGiratorio = 3;
int PULSOMINGIRATORIO = 1200;
int PULSOMAXGIRATORIO = 3200;

// pin del receptor infrarrojo.
int receptor = 11;

// servo trasero.
int pinServoTrasero = 7;
int PULSOMINTRASERO = 500;
int PULSOMAXTRASERO = 2000;

boolean mantener = false;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(receptor, DISABLE_LED_FEEDBACK);  
  servo_rotatorio.attach(pinServoGarra,PULSOMINGARRA,PULSOMAXGARRA);
  servo_bajo.attach(pinServoBajo,PULSOMINBAJO,PULSOMAXBAJO);
  servo_medio.attach(pinServoMedio, PULSOMINMEDIO,PULSOMAXMEDIO);
  servo_giratorio.attach(pinServoGiratorio,PULSOMINGIRATORIO, PULSOMAXGIRATORIO);
  servo_trasero.attach(pinServoTrasero, PULSOMINTRASERO, PULSOMAXTRASERO);
  servo_trasero_bajo.attach(8,1200,2200);
}

void loop() {
  if(IrReceiver.decode()) {
    if(mantener) {
      servo_trasero.write(85);
      servo_trasero.write(88);
      servo_trasero.write(90);
      
      servo_trasero_bajo.write(85);
      servo_trasero_bajo.write(88);
      servo_trasero.write(90);
    } else {
      servo_trasero.write(0);
      servo_trasero.write(3);
      servo_trasero.write(5);

      servo_trasero.write(0);
      servo_trasero.write(3);
      servo_trasero.write(5);
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    if(IrReceiver.decodedIRData.decodedRawData == 0xE916FF00) {
      servo_rotatorio.write(90);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xF30CFF00) {
      servo_rotatorio.write(0);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) {
      servo_bajo.write(0);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xA15EFF00) {
      servo_bajo.write(180);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xF708FF00) {
      servo_medio.write(0);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xE31CFF00) {
      servo_medio.write(180);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xA55AFF00) {
      servo_giratorio.write(0);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xBD42FF00) {
      servo_giratorio.write(180);
    }

    if(IrReceiver.decodedIRData.decodedRawData == 0xE619FF00) {
      servo_trasero.write(0);
      servo_trasero.write(3);
      servo_trasero.write(5);
    }

    if(IrReceiver.decodedIRData.decodedRawData = 0xF20DFF00) {
      servo_trasero.write(85);
      servo_trasero.write(88);
      servo_trasero.write(90);
    }

    IrReceiver.resume();
    delay(10);
  }
}
