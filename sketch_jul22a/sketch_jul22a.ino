#define LED_PIN             13  // Встроенный светодиод Arduino
#define LOUDNESS_SENSOR_PIN A5  // Датчик громкости подключён к А5
#define TRESHOLD            500 // Устанавливаем порог србатывания


const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:

//pinMode(LED_PIN, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


Serial.println("Hello Pi");
  if (Serial.available())
  {
     flash(Serial.read() - '0');
  }
  delay(1000);






 // Считаем текущее значение громкости
  int loudness = analogRead(LOUDNESS_SENSOR_PIN);

  //Serial.println(loudness);
 //delay (100);
  // Если громкость выше пороговой..
  if (loudness > TRESHOLD)
    // зажгём светодиод,
    digitalWrite(ledPin, HIGH);
  else
    // а если нет - погасим
    digitalWrite(ledPin, LOW); 

}





void flash(int n)
{
  for (int i = 0; i < n; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}


