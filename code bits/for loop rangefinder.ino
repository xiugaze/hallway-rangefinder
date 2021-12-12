#include <Wire.h>
#include <LIDARLite.h>

LIDARLite lidarLite;
int cal_cnt = 0;

void setup() {
    Serial.begin(9600);
    lidarLite.begin(0, true);
    lidarLite.configure(0);

    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
} 

void loop() {
    int dist;
    if (cal_cnt == 0) {
        dist = lidarLite.distance();
    } else {
        dist = lidarLite.distance(false);
    }

    cal_cnt++;
    cal_cnt = cal_cnt % 100;

    int distCurrent = 0;
    for(int pin = 13; pin >= 5; pin--) {
      if(dist >= distCurrent) {
        digitalWrite(pin, HIGH);
      } else {
        digitalWrite(pin, LOW) ;
      }
      distCurrent += 10;
    }

    Serial.print(dist);
    Serial.println(" cm");
    delay(10);

    // if (dist >= 0) {
    //   digitalWrite(13, HIGH);
    // } else {
    //   digitalWrite(13, LOW);
    // }

    // if (dist >= 10) {
    //   digitalWrite(12, HIGH);
    // } else {
    //   digitalWrite(12, LOW);
    // }
     
    // if (dist >= 20) {
    //   digitalWrite(11, HIGH);
    // } else {
    //   digitalWrite(11, LOW);
    // }

    // if (dist >= 30) {
    //   digitalWrite(10, HIGH);
    // } else {
    //   digitalWrite(10, LOW);
    // }

    // if (dist >= 40) {
    //   digitalWrite(9, HIGH);
    // } else {
    //   digitalWrite(9, LOW);
    // }

    // if (dist >= 50) {
    //   digitalWrite(8, HIGH);
    // } else {
    //   digitalWrite(8, LOW);
    // }

    // if (dist >= 60) {
    //   digitalWrite(8, HIGH);
    // } else {
    //   digitalWrite(8, LOW);
    // }

    // if (dist >= 70) {
    //   digitalWrite(7, HIGH);
    // } else {
    //   digitalWrite(7, LOW);
    // }

    // if (dist >= 80) {
    //   digitalWrite(6, HIGH);
    // } else {
    //   digitalWrite(6, LOW);
    // }

    // if (dist >= 90) {
    //   digitalWrite(5, HIGH);
    // } else {
    //   digitalWrite(5, LOW);
    // }

    
    


    
}
