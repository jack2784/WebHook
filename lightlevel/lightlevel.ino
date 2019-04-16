int led = D7;  // The on-board LED

int photosensor = A4;

int analogvalue;

char lightLevel[30];

void setup() {
    Serial.begin();
    pinMode(led, OUTPUT);
    
    Particle.variable("analogvalue", &analogvalue, INT);
}


void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  
  analogvalue = analogRead(photosensor);
  
  Serial.printlnf("%d", analogvalue);
  
  sprintf(lightLevel,"%d", analogvalue);

  Particle.publish("light", lightLevel, PRIVATE);
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}