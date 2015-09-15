#define VOLTAGE 184
#define BLINK_ON 600
#define BLINK_OFF 450
#define PWM_READ 650

// RC NAV LIGHTS PINS
//
// PIN_RX - Rx Input
// PIN_ALWAYS_ON - Always On
// PIN_SWITCHABLE_ON - On when >45%
// PIN_SWITCHABLE_BLINK - Blink when >45%
// X - Off when 0-5%, On when 45-55%, Blink when 95%

// DIGISPARK PINS
//Pin 0 → I2C SDA, PWM (LED on Model B)
//Pin 1 → PWM (LED on Model A)
//Pin 2 → I2C SCK, Analog
//Pin 3 → Analog In (also used for USB+ when USB is in use)
//Pin 4 → PWM, Analog (also used for USB- when USB is in use)
//Pin 5 → Analog In

#define PIN_RX 0
#define PIN_ALWAYS_ON 2
#define PIN_SWITCHABLE_ON 1
#define PIN_SWITCHABLE_BLINK 4

unsigned long lastTimeBlink = 0;
unsigned long lastPwmRead = 0;
int signal = 0;

void setup() {   
  // initialize the digital pin as an output.
  pinMode(PIN_RX, INPUT); 
  pinMode(PIN_SWITCHABLE_ON, OUTPUT); //LED on Model A   
  pinMode(PIN_ALWAYS_ON, OUTPUT);
  pinMode(PIN_SWITCHABLE_BLINK, OUTPUT);
  //wait a moment
  delay(100);
}


void loop() {
  //read rx signal
  if(millis() > lastPwmRead+PWM_READ){
    signal = pulseIn(PIN_RX, HIGH) - 1000; 
    lastPwmRead = millis();
  }

  //always on
  analogWrite(PIN_ALWAYS_ON, VOLTAGE);

  //switchable on
  if(signal>460){
    analogWrite(PIN_SWITCHABLE_ON, VOLTAGE);
  } else {
    analogWrite(PIN_SWITCHABLE_ON, 0);
  }

  //switchable blink
  if(millis() > lastTimeBlink+BLINK_OFF && signal>460){
    analogWrite(PIN_SWITCHABLE_BLINK, VOLTAGE);
  }
  if(millis() > lastTimeBlink+BLINK_ON+BLINK_OFF && signal>460){
    analogWrite(PIN_SWITCHABLE_BLINK, 0);
    lastTimeBlink = millis();
  }
  if(signal<460){
    analogWrite(PIN_SWITCHABLE_BLINK, 0);
  }
}
