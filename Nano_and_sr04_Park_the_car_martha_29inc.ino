/* Test with Github */

#define trigPin 10
#define echoPin 12
#define led 9



unsigned long x; // Count to determine if car is parked
int stopdistance = 29;  // minimum distance in inches from wall to car

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  long duration, distance;
 
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  distance = distance * .3937007; // cm to inches

// slow blink when with in range
  if (x != 20  && distance < (stopdistance * 2)){
    digitalWrite(led,HIGH);
    delay(10);
    digitalWrite(led,LOW);
    }

     Serial.println(x);
  if ((distance < stopdistance) && (x < 20) && (distance < 200) && (distance > 1)){  
    digitalWrite(led,HIGH);  
    x = x + 1;
    }
  else {
    digitalWrite(led,LOW);
       }
    if (distance >= 200 || distance <= 0){
    Serial.print("Out of range");
    Serial.print(distance);
     }
    else {
    Serial.print(distance);
    Serial.println(" Inch");
     }
 
  delay(500);
 
  
  if (x >= 20) {
    digitalWrite(led,LOW); // Car is parked for count to 20 then turn red light off
     }  
  if ((x >= 20) && (distance > stopdistance)) {   // car has moved away, prepare for when it returns
    x = 0;
  }
}
  
