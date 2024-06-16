const int buttonPin = 2;    // Пин, к которому подключена кнопка
int buttonState = 0;        // Текущее состояние кнопки
int pattern = 0;            // Текущий паттерн мигания

void setup() {
  pinMode(buttonPin, INPUT);
  // Настройка пинов для светодиодов
  // pinMode(ledPins, OUTPUT); 
  // Допишите настройку для всех пинов светодиодов
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    pattern++;
    if (pattern > 2) {  // Допустим, у нас 3 паттерна мигания
      pattern = 0;
    }
    delay(200);  // Дебаунсинг
  }

  switch (pattern) {
    case 0:
      // Паттерн мигания 1
      pattern1();
      break;
    case 1:
      // Паттерн мигания 2
      pattern2();
      break;
    case 2:
      // Паттерн мигания 3
      pattern3();
      break;
  }
}

void pattern1() {
  // Код для паттерна мигания 1
}

void pattern2() {
  // Код для паттерна мигания 2
}

void pattern3() {
  // Код для паттерна мигания 3
}
