/*
Fan faker

lordzurp
12/2018
*/

int sensorPin = A0;  // mesure tension entrée
int outputPin = 5;   // sortie signal carré
int heartbeat = 9;   // sortie LED
int led = 13;        // internal LED

unsigned int sensorValueRaw = 0;  // valeur tension entrée brute
float sensorValue = 0;            // valeur tension étalonnée

float fake_rpm = 0;       // fréquence sortie

void setup()  {
  pinMode(outputPin, OUTPUT);
  pinMode(heartbeat, OUTPUT);
  pinMode(led, OUTPUT);      // set pin mode
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                // wait for a tenth of a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW

}

void loop()  {
    
    digitalWrite(heartbeat, HIGH);
    sensorValueRaw = analogRead(sensorPin);
    sensorValue = map(sensorValueRaw, 0, 1023, 0, 15000)/1000.0;
   
    fake_rpm = map(sensorValueRaw, 0, 1023, 0, 10000);
    tone(outputPin, fake_rpm/30);

    delay(100);               // wait for a second
    digitalWrite(heartbeat, LOW);    // turn the LED off by making the voltage LOW
    delay(900);        
}
