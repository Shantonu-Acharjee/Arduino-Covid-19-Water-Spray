int trigPinA =A0;
int echoPinA =A1;
long durationA;
int distanceA;
int va;
int val;
int LED =A2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPinA,OUTPUT);
  pinMode(echoPinA,INPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(A0,HIGH);
   
}



void loop() {
   digitalWrite(trigPinA,LOW);
   delayMicroseconds(2);

   digitalWrite(trigPinA,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinA,LOW);

   durationA=pulseIn(echoPinA,HIGH);
  
   distanceA = durationA*0.034/2;
   Serial.print("distanceA:");
   Serial.println(distanceA);

va = analogRead(A4);
val = map(va,0,1023,0,30000);

Serial.println(val);
if (distanceA <= 100){
  digitalWrite(LED,LOW);
  delay(300);
  delay(val);
  digitalWrite(LED,HIGH);
}

else{
  digitalWrite(LED,HIGH);
}
}
