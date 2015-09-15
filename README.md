# Arduino RC navigation lights
Simple LED lights switcher that uses RX power for your RC model

# About
General idea is take power from Rx line and provide it to several LEDs that will be navigation lights of your model.
Additional feature is that connecting to rx we can controll lights on and off.
Lights controllers that available on the market have separate power line which makes it very complex wiring. But when you have only few leds you can use this simple approach.

# Important notice
Most info on the web about popular arduino controllers say that output is limited to 20mA, with notice that can be up to 40 mA for a short time. 
I will not recommend to go more than 20ma for constantly glowing lights, and a little bit higher for blinking lights (25ma or so).
Voltage is lowered to approximate 3.55V, provided limitations are probably for 5V.

# Connecting
Pins numbers are custom, but pay attention that you need PWM ones.
- 'input' pin - to rx
- 'always on' pin
- 'switchable on' pin - when your rx signal more than 45%
- 'switchable blinking' pin 
- #TODO 'switchable off-on-blink' pin - for 3-position switch
