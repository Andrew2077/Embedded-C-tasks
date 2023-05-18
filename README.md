# Embedded-C-Tasks
Some projects/tasks taken in Embbedded C and Advanced Embedded C course - on compus

## Covered topics:
- C / Embedded C
- proteus
- GPIO - General Purpose Input Output
- SPI - Serial Peripheral Interface
- I2C - Inter-Integrated Circuit
- STM32 - ARM Cortex M4
- AVR - ATmega32
- RTOS - FreeRTOS
- Design Patterns
  - proxy 
  - observer 
  - polling
- SOLID principles

### Task 0: GPIO
- 7 segment - STM32
  
<video width="640" height="480" controls>
  <source src="misc\GPIO_7segments.mp4" type="video/mp4">
</video>

- Keypad - STM32
  
<video width="6480" height="480" controls>
  <source src="misc\GPIO_KeyPad.mp4" type="video/mp4">
</video>

### Task 1: Analog to Digital Converter (ADC) for Temperature Sensor
- ADC in STM32
![](misc/ADC.png)

### Task 2: Pulse Width Modulation (PWM)
- Pulse Width Modulation (PWM) in STM32
![](misc/PWD_circuit.png)
- PWM in Oscilloscope
![](misc/PWD_oscilator.png)

### Task 3: Applying Polling Pattern to Temperature Sensor reading
- SPI in AVR
- Polling Pattern
  - periodic
  - opportunistic

![](misc/Temp-read-Pooling-pattern.png)

### Task 4 : Observer Pattern
- Blinking LEDs using Observer Pattern
<video width="640" height="480" controls>
  <source src="misc\Observer.mp4" type="video/mp4">
</video>

### Task 5: Real Time Operating System (RTOS)
- FreeRTOS 
- Timers using LEDs as Ticks

![](misc/RTOS-TImer-LEDs.png)