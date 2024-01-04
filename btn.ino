int LED=4;
int BTN=2;
boolean lastBtn = LOW;
boolean currentBtn = LOW;
boolean led0n = false;

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (BTN, INPUT);
  // put your setup code here, to run once:

}
void on(){
  if(digitalRead(BTN)== LOW){
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(BTN);
    if(last != current)
    {
        delay(100);
        current = digitalRead(BTN);
        return current;  
    }  
}
void loop() {
  currentBtn = debounce(lastBtn);
  if (lastBtn == LOW && currentBtn == HIGH)
  {
      led0n = !led0n;
  }
  
  lastBtn = currentBtn;
  digitalWrite(LED,led0n);
  // put your main code here, to run repeatedly:

}
