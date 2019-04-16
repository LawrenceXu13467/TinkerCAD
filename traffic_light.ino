int redLED = 13;
int greenLED = 12;
int yellowLED = 8;
int pinBtn = 2;
// int startTime = millis();
bool pressed = false;
bool redOn = true;
bool greenOn = false;
bool yellowOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(pinBtn, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  pressed = digitalRead(pinBtn);
  pressed = !pressed;
  Serial.println(pressed);
  if (pressed && redOn) {
    Serial.println("Set Green");
    redOn = false;
    greenOn = true;
    pressed = false;
    
  }
  if (pressed && greenOn) {
    
    Serial.println("Set Yellow");

    greenOn = false;
    yellowOn = true;
    pressed = false;
  }


  if (redOn) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
  }

  if (greenOn) {
    Serial.println("Green on");

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
  }

  if (yellowOn) {
    Serial.println("Yellow on");

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(5000);
    redOn = true;
    yellowOn = false;
  }
  

}
