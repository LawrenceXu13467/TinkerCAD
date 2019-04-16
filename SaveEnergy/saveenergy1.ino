int LED = 13;

int pinBtn = 2;
int startTime = 0;
bool pressed = false;
bool pressed_deb = false;
bool ledOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(pinBtn, INPUT);
  startTime = millis();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(ledOn){
    // Serial.print(0.001*(millis() - startTime));

    digitalWrite(LED, HIGH);
    if(millis() - startTime >= 5000){
		Serial.print("The LED was on for ");
      	Serial.print("5.00");
      	Serial.println(" seconds.");
    	digitalWrite(LED, LOW);
      	ledOn = false;
      	startTime = millis();
    }
  }
  
  pressed = digitalRead(pinBtn);
  pressed = !pressed;
  delay(100);
  pressed_deb = digitalRead(pinBtn);
  pressed_deb = !pressed_deb;
  
  if(pressed != pressed_deb){
	  pressed = !pressed;
  }
  
  // Serial.println(pressed);
  if (pressed) {
    if(ledOn){
    	Serial.print("The LED was on for ");
      	Serial.print(0.001*(millis() - startTime));
      	Serial.println(" seconds.");
      	digitalWrite(LED, LOW);

    }else{
    	startTime = millis();
      	digitalWrite(LED, HIGH);
    }
    ledOn = !ledOn;
    pressed = false;
    
  }
}