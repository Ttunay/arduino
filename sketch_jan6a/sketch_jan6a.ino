#define led1 3
#define led2 6
#define led3 5
#define led4 4
#define btn 2
int flag = 1;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(btn, INPUT);
  // put your setup code here, to run once:
}

void loop() {
  if (digitalRead(btn) == HIGH) {
    if (flag == 1) {
      flag = 2;
      delay(200);
    } else {
      flag = 1;
      delay(200);
    }
  }
  if (flag == 1) {
    digitalWrite(led1, LOW);
    digitalWrite(led4, HIGH);
    delay(100);

    digitalWrite(led4, LOW);
    digitalWrite(led3, HIGH);
    delay(100);

    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    delay(100);

    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    delay(100);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led4, LOW);
    delay(100);

    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    delay(100);

    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    delay(100);

    digitalWrite(led4, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
  } 
}