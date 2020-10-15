If you are using smootheware firmware, please disable the LEDs event in the configuration file,  as shown below
> leds_disable                        true

> play_led_disable                    true

![image](https://user-images.githubusercontent.com/38851044/96061203-337b5900-0ec5-11eb-9d09-7e546d5545cc.png)

Because there is no led on SKR v1.1, and the LED on smoothieboard uses the same IO as the X-Axis enable pin in SKR V1.1. If the LED is not disabled, the X-Axis motor cannot be locked in the idle state
