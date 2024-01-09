#define BLED = 9;
#define GLED = 10;
#define RLED = 11;
#define BUTTON = 2;


boolean lastButton = LOW;
boolean currentButton = LOW;


int ledMode = 0;
void setup() {
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);
  if (last != current) {
    delay(5);
    current = digitalRead(BUTTON);
    return current;
  }
}

void setMode(int mode) {
  // Красный
  if (mode == 1) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  // Зеленый
  else if (mode == 2) {

    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  // Синий
  else if (mode == 3) {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  // Пурпурный (Красный+ Синий)
  else if (mode == 4) {
    analogWrite(RLED, 127);
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
  }
  // Бирюзовый (Синий+ Зеленый)

  else if (mode == 5) {
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }

  // Оранжевый (Зеленый+ Красный)

  else if (mode == 6) {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 0);
  }
  // Белый (Зеленый+ Красный+ Синий)
  else if (mode == 7) {
    analogWrite(RLED, 85);
    analogWrite(GLED, 85);
    analogWrite(BLED, 85);
  }
  // Выключен (mode = 0)
  else {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}
void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    ledMode++;
  }

  lastButton = currentButton;

  if (ledMode == 8)
    ledMode = 0;
  setMode(ledMode);
}
