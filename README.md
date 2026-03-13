# UNO-Q-Exemple-Brige.call-bouton-poussoir

Simple push-button test for UNO Q.

Pin 8 configured as INPUT_PULLUP.
Button connected between pin 8 and GND.

One press -> one Bridge.call() request to the MPU.
Debounce handled in software (20 ms).

![RouterBridge call example](doc/screenshot.jpg)


---

pin ---- bouton ---- GND
