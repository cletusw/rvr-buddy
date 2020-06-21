# RVR Buddy
Arduino Micro/ATmega32u4 sketch for linking a Raspberry Pi and the Sphero RVR.

* Acts as a UART passthrough between the USB connected to the RVR and the Arduino's UART pins connected to the Raspberry Pi.
  * Don't forget a voltage divider since the Ardunio's UART operates at 5V but the Pi's only expecting 3.3V!
* Can provide power to the Pi from the USB's 5V.
  * You'll need to pull power from before the Arduino's 500mA resettable fuse. I soldered a wire directly to the fuse itself on the side connected to the USB 5V pin.
* TODO: Communicate with the Pi over I2C as well so the Arduino can act as a servo driver, ADC, etc., just like the Picon Zero (see [firmware](https://github.com/4tronix/PiconZero/blob/7d0fa41e6157f674e8cc8b4dd84236c8042ceb8d/Arduino/PiconZero10.ino)).
