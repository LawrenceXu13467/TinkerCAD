int redLED = 13;
int greenLED = 12;
int yellowLED = 8;
int pinBtn = 2;
// int startTime = millis();
bool pressed = false;
bool pressed_deb = false;
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
  if (redOn){
    Serial.println("Red on");
  	digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
  }
  
  pressed = digitalRead(pinBtn);
  pressed = !pressed;
  if(!yellowOn){
    delay(100);
  }
  pressed_deb = digitalRead(pinBtn);
  pressed_deb = !pressed_deb;
  
  if(pressed != pressed_deb){
	  pressed = !pressed;
  }
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
    pressed = false;

  }
  

}