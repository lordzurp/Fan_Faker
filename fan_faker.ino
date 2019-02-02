/*
Fan faker

lordzurp
12/2018
*/

int sensorPin = A0;  // mesure tension entrée
int outputPin = 5;   // sortie signal carré
int heartbeat = 9;   // sortie LED

unsigned int sensorValueRaw = 0;  // valeur tension entrée brute
float sensorValue = 0;            // valeur tension étalonnée
float fake_rpm = 0;               // fréquence sortie

void setup() {
    pinMode(outputPin, OUTPUT);
    pinMode(heartbeat, OUTPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);

}

void loop() {
    
    sensorValueRaw = analogRead(sensorPin);  // on lit la tension d'entrée, qui est divisée par ~3 (0-12V -> 0-5V)
    fake_rpm = map(sensorValueRaw, 0, 1023, 0, 8000);  // on ajuste la mesure sur la vitesse voulue du ventilo (0-10.000 rpm)
    tone(outputPin, fake_rpm / 60 * 2);  // on envoie une pulse correspondant à la frequence du tachy : 10.000 rpm / 60s * 2 pulses par tour

    /* debug
    sensorValue = map(sensorValueRaw, 0, 1023, 0, 12000)/1000.0;  // on remet la valeur mesurée sur une echelle 0-15V
    Serial.println(sensorValue);  // on envoie la mesure sur le prot série, pour debug
    */

    digitalWrite(heartbeat, !digitalRead(heartbeat));  // heartbeat, pour verifier que le micro boucle toujours
    delay(500);
}
