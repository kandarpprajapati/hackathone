int trigPin = 9;
int echoPin = 10;
int buzzer = 11;
int ledPin = 2;
int value = 0;
int ldrPin = A0;
long dur;
int dis;
int sd;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  dur = pulseIn(echoPin, HIGH);

  dis = dur * 0.034 / 2;

  sd = dis;
  if (sd <= 35 && sd>0) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  Serial.print("DISTANCE = ");
  Serial.println(dis);

  value = analogRead(ldrPin);

  Serial.println("LDR value:");
  Serial.println(value);

  if (value < 10) {
    digitalWrite(ledPin, HIGH);
    Serial.print("Its Dark, Turn on the LED:");
    Serial.println(value);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.print("Its Bright, Turn off the LED:");
    Serial.println(value);
  }
}
