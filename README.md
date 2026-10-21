RFID Based Hospital Cabinet Access Control System using LPC2129

An embedded systems project built on the LPC2129 (ARM7TDMI-S) microcontroller. The cabinet opens only when an authorized RFID card is scanned. An unauthorized card triggers a buzzer alarm. The system status is shown on a 16x2 LCD.

Features
RFID card authentication using the EM-18 reader
Live status messages on a 16x2 LCD
DC motor opens and closes the cabinet through an L293D driver
LED indication
Buzzer alarm for unauthorized cards
Push switch to close the cabinet
Modular code: each peripheral has its own header file

Hardware Components
Component	Purpose
	LPC2129 development board	- Microcontroller
	EM-18 RFID reader with 125 kHz - tags	Reads card ID over UART0
	16x2 LCD	- Status display
	L293D motor driver - rives the DC motor
	DC motor -	Opens and closes the cabinet
	LED with resistor	- Status indication
  Buzzer -	Unauthorized access alarm
  Push button	- Door Close command

  Block Diagram
  ![image alt](https://github.com/sumithasenthil31-sudo/RFID-Based-Medicine-Cabinet-Locked-System/blob/c07685801420a82f7e6a7b27de4af9d0448d0d63/RFID%20Medicine%20Cabinet%20Lock%20Diagram.png)

Software and Tools
Embedded C
Keil uVision (compiler and IDE)
Flash Magic (flashing the hex file)

Folder Structure
rfid_cabinet/
├── main.c        # main program flow
├── pins.h        # pin definitions
├── delay.h       # timer based millisecond delay
├── uart.h        # UART0 init and receive
├── rfid.h        # tag read and check
├── lcd.h         # 16x2 LCD driver
├── motor.h       # motor open, close, stop
├── led.h         # LED on and off
├── buzzer.h      # buzzer on and off
├── images/       # photos and diagrams
└── README.md



