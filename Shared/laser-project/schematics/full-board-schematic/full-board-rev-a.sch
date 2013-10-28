EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:at90usb1286
LIBS:full-board-rev-a-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "28 oct 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AT90USB1286 U1
U 1 1 526E12D6
P 4400 900
F 0 "U1" H 4450 950 60  0000 C CNN
F 1 "AT90USB1286" H 5050 950 60  0000 C CNN
F 2 "~" H 6200 -200 60  0000 C CNN
F 3 "~" H 6200 -200 60  0000 C CNN
	1    4400 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3600 4000 3600
Wire Wire Line
	4000 3600 4000 4200
Wire Wire Line
	4100 3700 4000 3700
Connection ~ 4000 3700
Wire Wire Line
	4100 3800 4000 3800
Connection ~ 4000 3800
Wire Wire Line
	4100 3900 4000 3900
Connection ~ 4000 3900
$Comp
L GND #PWR?
U 1 1 526E133E
P 4000 4200
F 0 "#PWR?" H 4000 4200 30  0001 C CNN
F 1 "GND" H 4000 4130 30  0001 C CNN
F 2 "" H 4000 4200 60  0000 C CNN
F 3 "" H 4000 4200 60  0000 C CNN
	1    4000 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 526E134D
P 3550 3400
F 0 "#PWR?" H 3550 3400 30  0001 C CNN
F 1 "GND" H 3550 3330 30  0001 C CNN
F 2 "" H 3550 3400 60  0000 C CNN
F 3 "" H 3550 3400 60  0000 C CNN
	1    3550 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 526E135C
P 3100 2700
F 0 "#PWR?" H 3100 2700 30  0001 C CNN
F 1 "GND" H 3100 2630 30  0001 C CNN
F 2 "" H 3100 2700 60  0000 C CNN
F 3 "" H 3100 2700 60  0000 C CNN
	1    3100 2700
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 526E14AE
P 2600 1900
F 0 "C?" H 2650 2000 50  0000 L CNN
F 1 "CP1" H 2650 1800 50  0000 L CNN
F 2 "~" H 2600 1900 60  0000 C CNN
F 3 "~" H 2600 1900 60  0000 C CNN
	1    2600 1900
	0    1    1    0   
$EndComp
$Comp
L CP1 C?
U 1 1 526E14BB
P 2600 2300
F 0 "C?" H 2650 2400 50  0000 L CNN
F 1 "CP1" H 2650 2200 50  0000 L CNN
F 2 "~" H 2600 2300 60  0000 C CNN
F 3 "~" H 2600 2300 60  0000 C CNN
	1    2600 2300
	0    1    1    0   
$EndComp
$EndSCHEMATC
