int currentLED = 0; // the LED that is currently HIGH
int myLEDS[] = {6, 5, 4, 3}; // array with the pins that have LEDS
int numberOfPins = 4; // number of LEDS in board

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int inputPin = 2;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long startMillis;
unsigned long currentMillis;
unsigned long previousMillis;
const unsigned long period = 1000; // interval between each LED
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time;

int stop = 0; // if stop is 1 it means that the button was pressed and the current LED must remain HIGH

void setup() {
  pinMode(myLEDS[0], OUTPUT);
  pinMode(myLEDS[1], OUTPUT);
  pinMode(myLEDS[2], OUTPUT);
  pinMode(myLEDS[3], OUTPUT);
  pinMode(inputPin, INPUT);

  startMillis = millis();
  previousMillis = startMillis;

}

void loop() {
  currentMillis = millis();
  
   /*
   * Normal Mode
   * 1 – Red LED ON
   * 2 – Green LED ON
   * 3 – Blue LED ON
   * 4 – Yellow LED ON
   * 5 – All LEDs OFF
   */
  double delta = currentMillis - previousMillis;
  if(delta >= period && stop == 0) {

    previousMillis = currentMillis;

    for(int i = 0; i < numberOfPins; i++){
      if(i == currentLED){
        digitalWrite(myLEDS[i], HIGH);
      }
      else{
        digitalWrite(myLEDS[i], LOW);
      }
    }

    if(currentLED < numberOfPins){
      currentLED += 1;
    }
    else {
      currentLED = 0;
    }
  }

  /*
   * Button Debounce
   */
  int reading = digitalRead(inputPin);
  
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
          // The last LED must remain HIGH, which is currentLED-1
          digitalWrite(myLEDS[currentLED-1], HIGH);
          if(stop == 0) {
            stop = 1;
          }
          else {
            stop = 0;
          }
      }
    }
  }

  lastButtonState = reading;
}
