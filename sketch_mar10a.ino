
#define trig PA5
#define echo  PA6
#define pot PA4
int val =0; 
#include<Servo.h>
#define led PA7
Servo servo; 
#define servopin PB3
long duration; 
int distance; 
int angle =0; 
void setup() {
 
  Serial.begin(9600); 
  pinMode(trig,OUTPUT); 
  pinMode(echo,INPUT); 
  Serial.println("Ultrasonic sensor");
  pinMode(led,OUTPUT); 
  servo.attach(servopin); 
  
  // put your setup code here, to run once:

}

void loop() {
val =analogRead(pot);
val = map(val, 0, 1023, 0, 180);
  int servoangle = servo.read(); 
  Serial.print(servoangle); 
  for(angle =0; angle<180; angle+=45)
{
  servo.write(angle); 
  delay(15);  
  distance = calculateDistance(); 
  int light = digitalRead(PB0); 
  if(light ==1){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print("."); 
  if(distance<40){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
    
  }
  }
  delay(1000); 
for(angle =180;angle>=1; angle-=45){
  servo.write(angle);
  delay(15);
  distance = calculateDistance(); 
    if(distance<40){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
    
  }
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print("."); 
}
  delay(1000);
}
int calculateDistance(){
  // Clears the trigPin condition
digitalWrite(trig,LOW);
delayMicroseconds(2); 
digitalWrite(trig,HIGH);
// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
delayMicroseconds(10); 

digitalWrite(trig,LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds

duration = pulseIn(echo, HIGH);
 distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
 

  return distance; 

}
