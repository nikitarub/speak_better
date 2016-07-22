#define LED_PIN             13  // Встроенный светодиод Arduino
#define LOUDNESS_SENSOR_PIN A5  // Датчик громкости подключён к А5
#define TRESHOLD            500 // Устанавливаем порог србатывания


void setup() {
  // put your setup code here, to run once:

pinMode(LED_PIN, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

 // Считаем текущее значение громкости
  int loudness = analogRead(LOUDNESS_SENSOR_PIN);

  Serial.println(loudness);
 delay (100);
  // Если громкость выше пороговой..
  if (loudness > TRESHOLD)
    // зажгём светодиод,
    digitalWrite(LED_PIN, HIGH);
  else
    // а если нет - погасим
    digitalWrite(LED_PIN, LOW); 

}
