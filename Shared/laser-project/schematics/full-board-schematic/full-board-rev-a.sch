EESchema Schematic File Version 2  date 11/4/2013 7:34:03 PM
LIBS:power
LIBS:at90usb1286
LIBS:ceramic-resonator
LIBS:mcp1825
LIBS:op598c
LIBS:smcap
LIBS:smres
LIBS:ds1077
LIBS:opv332
LIBS:ad8302
LIBS:molex-usb-b
LIBS:push-switch
LIBS:bss138
LIBS:74xx
LIBS:adc-dac
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:brooktre
LIBS:cmos_ieee
LIBS:cmos4000
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:device
LIBS:digital-audio
LIBS:display
LIBS:dsp
LIBS:gennum
LIBS:graphic
LIBS:intel
LIBS:interface
LIBS:linear
LIBS:memory
LIBS:microchip
LIBS:microchip1
LIBS:microcontrollers
LIBS:motorola
LIBS:opto
LIBS:philips
LIBS:pspice
LIBS:regul
LIBS:sensors
LIBS:siliconi
LIBS:special
LIBS:texas
LIBS:transf
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:video
LIBS:xilinx
LIBS:TEENSYPP2
LIBS:IMU
EELAYER 24 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Laser Mapping Project"
Date "5 nov 2013"
Rev "A"
Comp "Laser Team"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AT90USB1286 U1
U 1 1 526E12D6
P 3600 800
F 0 "U1" H 3650 850 60  0000 C CNN
F 1 "AT90USB1286" H 4250 850 60  0000 C CNN
F 2 "~" H 5400 -300 60  0000 C CNN
F 3 "~" H 5400 -300 60  0000 C CNN
	1    3600 800 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 526E133E
P 3200 4100
F 0 "#PWR01" H 3200 4100 30  0001 C CNN
F 1 "GND" H 3200 4030 30  0001 C CNN
F 2 "" H 3200 4100 60  0000 C CNN
F 3 "" H 3200 4100 60  0000 C CNN
	1    3200 4100
	1    0    0    -1  
$EndComp
$Comp
L CERAMIC-RESONATOR X1
U 1 1 526DDAF8
P 1200 2800
F 0 "X1" H 1300 2650 60  0000 C CNN
F 1 "CERAMIC-RESONATOR" H 1300 2650 60  0001 C CNN
F 2 "~" H 1100 2800 60  0000 C CNN
F 3 "~" H 1100 2800 60  0000 C CNN
F 4 "16MHz" H 1300 2850 60  0000 C CNN "Frequency"
	1    1200 2800
	-1   0    0    1   
$EndComp
$Comp
L DS1077 U2
U 1 1 526F0599
P 9150 950
F 0 "U2" H 8900 1250 60  0000 C CNN
F 1 "DS1077" H 9250 1250 60  0000 C CNN
F 2 "" H 8900 1250 60  0000 C CNN
F 3 "" H 8900 1250 60  0000 C CNN
	1    9150 950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5271870F
P 7400 3400
F 0 "#PWR02" H 7400 3400 30  0001 C CNN
F 1 "GND" H 7400 3330 30  0001 C CNN
F 2 "" H 7400 3400 60  0000 C CNN
F 3 "" H 7400 3400 60  0000 C CNN
	1    7400 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 52718763
P 7250 1700
F 0 "#PWR03" H 7250 1700 30  0001 C CNN
F 1 "GND" H 7250 1630 30  0001 C CNN
F 2 "" H 7250 1700 60  0000 C CNN
F 3 "" H 7250 1700 60  0000 C CNN
	1    7250 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 52718769
P 7650 2200
F 0 "#PWR04" H 7650 2200 30  0001 C CNN
F 1 "GND" H 7650 2130 30  0001 C CNN
F 2 "" H 7650 2200 60  0000 C CNN
F 3 "" H 7650 2200 60  0000 C CNN
	1    7650 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5271876F
P 9350 3600
F 0 "#PWR05" H 9350 3600 30  0001 C CNN
F 1 "GND" H 9350 3530 30  0001 C CNN
F 2 "" H 9350 3600 60  0000 C CNN
F 3 "" H 9350 3600 60  0000 C CNN
	1    9350 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 52718775
P 9000 3600
F 0 "#PWR06" H 9000 3600 30  0001 C CNN
F 1 "GND" H 9000 3530 30  0001 C CNN
F 2 "" H 9000 3600 60  0000 C CNN
F 3 "" H 9000 3600 60  0000 C CNN
	1    9000 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 52718D27
P 8500 1650
F 0 "#PWR07" H 8500 1650 30  0001 C CNN
F 1 "GND" H 8500 1580 30  0001 C CNN
F 2 "" H 8500 1650 60  0000 C CNN
F 3 "" H 8500 1650 60  0000 C CNN
	1    8500 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3500 3200 3500
Wire Wire Line
	3200 3500 3200 4100
Wire Wire Line
	3300 3600 3200 3600
Connection ~ 3200 3600
Wire Wire Line
	3300 3700 3200 3700
Connection ~ 3200 3700
Wire Wire Line
	3300 3800 3200 3800
Connection ~ 3200 3800
Wire Wire Line
	3200 900  3200 1000
Wire Wire Line
	3200 1000 3300 1000
Connection ~ 3200 900 
Wire Wire Line
	7650 3200 7400 3200
Connection ~ 7400 3200
Wire Wire Line
	7400 2600 7400 3400
Wire Wire Line
	7400 2600 7650 2600
Wire Wire Line
	7250 1500 7250 1450
Wire Wire Line
	7250 1650 7250 1700
Wire Wire Line
	9350 3450 9350 3600
NoConn ~ 8500 850 
Wire Wire Line
	8900 2700 9150 2700
Wire Wire Line
	9150 2700 9150 2800
Wire Wire Line
	9150 2800 8900 2800
Connection ~ 9150 2750
Wire Wire Line
	8900 3000 9150 3000
Wire Wire Line
	9150 3000 9150 3100
Wire Wire Line
	9150 3100 8900 3100
Connection ~ 9150 3050
Wire Wire Line
	10000 2900 8900 2900
$Comp
L GND #PWR08
U 1 1 5271A8CC
P 10150 2600
F 0 "#PWR08" H 10150 2600 30  0001 C CNN
F 1 "GND" H 10150 2530 30  0001 C CNN
F 2 "" H 10150 2600 60  0000 C CNN
F 3 "" H 10150 2600 60  0000 C CNN
	1    10150 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 1400 10150 1650
$Comp
L SMRES R1
U 1 1 527404D4
P 10100 1900
F 0 "R1" V 10300 1700 60  0000 C CNN
F 1 "SMRES" H 10400 1950 60  0001 C CNN
F 2 "" H 9850 2200 60  0000 C CNN
F 3 "" H 9850 2200 60  0000 C CNN
F 4 "1.5k" V 10200 1700 60  0000 C CNN "Resistance"
	1    10100 1900
	0    -1   -1   0   
$EndComp
$Comp
L OPV332 LD1
U 1 1 52740787
P 10200 2050
F 0 "LD1" V 10250 2175 60  0000 C CNN
F 1 "OPV332" V 10350 2250 60  0000 C CNN
F 2 "~" H 10000 2250 60  0000 C CNN
F 3 "~" H 10000 2250 60  0000 C CNN
	1    10200 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	10150 1900 10150 2050
Wire Wire Line
	10150 2250 10150 2600
Wire Wire Line
	9900 1400 10150 1400
Text Label 9900 1400 0    60   ~ 0
mod_sig_1
Wire Wire Line
	8500 750  7550 750 
Text Label 7550 750  0    60   ~ 0
mod_sig_1
$Comp
L SMRES R2
U 1 1 52740B3E
P 9300 4350
F 0 "R2" V 9500 4450 60  0000 C CNN
F 1 "SMRES" H 9600 4400 60  0001 C CNN
F 2 "" H 9050 4650 60  0000 C CNN
F 3 "" H 9050 4650 60  0000 C CNN
F 4 "10k?" V 9400 4450 60  0000 C CNN "Resistance"
	1    9300 4350
	0    -1   -1   0   
$EndComp
$Comp
L AD8302 U3
U 1 1 52740C04
P 8350 2800
F 0 "U3" H 8150 3150 60  0000 C CNN
F 1 "AD8302" H 8450 3150 60  0000 C CNN
F 2 "" H 8150 3150 60  0000 C CNN
F 3 "" H 8150 3150 60  0000 C CNN
	1    8350 2800
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C1
U 1 1 52740C13
P 8950 3450
F 0 "C1" V 9050 3250 60  0000 C CNN
F 1 "SMCAP" H 9200 3500 60  0001 C CNN
F 2 "" H 8750 3650 60  0000 C CNN
F 3 "" H 8750 3650 60  0000 C CNN
F 4 "5p" V 8950 3250 60  0000 C CNN "Capacitance"
	1    8950 3450
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C2
U 1 1 52740CC0
P 9300 3450
F 0 "C2" V 9400 3250 60  0000 C CNN
F 1 "SMCAP" H 9550 3500 60  0001 C CNN
F 2 "" H 9100 3650 60  0000 C CNN
F 3 "" H 9100 3650 60  0000 C CNN
F 4 "5p" V 9300 3250 60  0000 C CNN "Capacitance"
	1    9300 3450
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C3
U 1 1 52740D9C
P 7600 2050
F 0 "C3" V 7700 2150 60  0000 C CNN
F 1 "SMCAP" H 7850 2100 60  0001 C CNN
F 2 "" H 7400 2250 60  0000 C CNN
F 3 "" H 7400 2250 60  0000 C CNN
F 4 "5p" V 7600 2150 60  0000 C CNN "Capacitance"
	1    7600 2050
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C4
U 1 1 52740DAB
P 7200 1650
F 0 "C4" V 7350 1750 60  0000 C CNN
F 1 "SMCAP" H 7450 1700 60  0001 C CNN
F 2 "" H 7000 1850 60  0000 C CNN
F 3 "" H 7000 1850 60  0000 C CNN
F 4 "5p" V 7250 1750 60  0000 C CNN "Capacitance"
	1    7200 1650
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R4
U 1 1 52740E3B
P 7600 1800
F 0 "R4" V 7800 1600 60  0000 C CNN
F 1 "SMRES" H 7900 1850 60  0001 C CNN
F 2 "" H 7350 2100 60  0000 C CNN
F 3 "" H 7350 2100 60  0000 C CNN
F 4 "10k?" V 7700 1550 60  0000 C CNN "Resistance"
	1    7600 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7650 1250 7650 1550
Wire Wire Line
	7650 1250 7250 1250
Wire Wire Line
	7250 1450 7650 1450
Connection ~ 7650 1450
Text Label 7250 1250 0    60   ~ 0
regulator_5V
Wire Wire Line
	7650 1800 7650 1900
Wire Wire Line
	7650 2050 7650 2200
Wire Wire Line
	7650 1850 8050 1850
Connection ~ 7650 1850
Text Label 7850 1850 0    60   ~ 0
ad8302_vpos
$Comp
L SMCAP C5
U 1 1 52741380
P 9550 3950
F 0 "C5" H 9550 4000 60  0000 C CNN
F 1 "SMCAP" H 9800 4000 60  0001 C CNN
F 2 "" H 9350 4150 60  0000 C CNN
F 3 "" H 9350 4150 60  0000 C CNN
F 4 "5p?" H 9750 4000 60  0000 C CNN "Capacitance"
	1    9550 3950
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C6
U 1 1 5274138F
P 9550 4400
F 0 "C6" H 9550 4450 60  0000 C CNN
F 1 "SMCAP" H 9800 4450 60  0001 C CNN
F 2 "" H 9350 4600 60  0000 C CNN
F 3 "" H 9350 4600 60  0000 C CNN
F 4 "5p?" H 9750 4450 60  0000 C CNN "Capacitance"
	1    9550 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 4100 9350 4000
Wire Wire Line
	8950 4000 9550 4000
Wire Wire Line
	9350 4350 9350 4750
Wire Wire Line
	9350 4450 9550 4450
Wire Wire Line
	9700 4000 10300 4000
Wire Wire Line
	9700 4450 10300 4450
Connection ~ 9350 4000
Text Label 8950 4000 0    60   ~ 0
mod_sig_1
Text Label 9900 4000 0    60   ~ 0
ad8302_inpa
Text Label 9900 4450 0    60   ~ 0
ad8302_ofsa
Wire Wire Line
	7650 2700 6700 2700
Wire Wire Line
	7650 2800 6700 2800
Wire Wire Line
	7650 2900 6700 2900
Text Label 6700 2700 0    60   ~ 0
ad8302_inpa
Text Label 6700 2800 0    60   ~ 0
ad8302_ofsa
Text Label 6700 2900 0    60   ~ 0
regulator_5v
$Comp
L GND #PWR09
U 1 1 527418CA
P 9350 4750
F 0 "#PWR09" H 9350 4750 30  0001 C CNN
F 1 "GND" H 9350 4680 30  0001 C CNN
F 2 "" H 9350 4750 60  0000 C CNN
F 3 "" H 9350 4750 60  0000 C CNN
	1    9350 4750
	1    0    0    -1  
$EndComp
Connection ~ 9350 4450
$Comp
L SMRES R3
U 1 1 5274196B
P 7450 4350
F 0 "R3" V 7650 4450 60  0000 C CNN
F 1 "SMRES" H 7750 4400 60  0001 C CNN
F 2 "" H 7200 4650 60  0000 C CNN
F 3 "" H 7200 4650 60  0000 C CNN
F 4 "10k?" V 7500 4450 60  0000 C CNN "Resistance"
	1    7450 4350
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C7
U 1 1 52741972
P 7700 3950
F 0 "C7" H 7700 4000 60  0000 C CNN
F 1 "SMCAP" H 7950 4000 60  0001 C CNN
F 2 "" H 7500 4150 60  0000 C CNN
F 3 "" H 7500 4150 60  0000 C CNN
F 4 "5p?" H 7900 4000 60  0000 C CNN "Capacitance"
	1    7700 3950
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C8
U 1 1 52741979
P 7700 4400
F 0 "C8" H 7700 4450 60  0000 C CNN
F 1 "SMCAP" H 7950 4450 60  0001 C CNN
F 2 "" H 7500 4600 60  0000 C CNN
F 3 "" H 7500 4600 60  0000 C CNN
F 4 "5p?" H 7900 4450 60  0000 C CNN "Capacitance"
	1    7700 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 4100 7500 4000
Wire Wire Line
	7100 4000 7700 4000
Wire Wire Line
	7500 4350 7500 4750
Wire Wire Line
	7500 4450 7700 4450
Wire Wire Line
	7850 4000 8450 4000
Wire Wire Line
	7850 4450 8450 4450
Connection ~ 7500 4000
Text Label 7100 4000 0    60   ~ 0
return_sig
Text Label 8050 4000 0    60   ~ 0
ad8302_inpb
Text Label 8050 4450 0    60   ~ 0
ad8302_ofsb
$Comp
L GND #PWR010
U 1 1 52741989
P 7500 4750
F 0 "#PWR010" H 7500 4750 30  0001 C CNN
F 1 "GND" H 7500 4680 30  0001 C CNN
F 2 "" H 7500 4750 60  0000 C CNN
F 3 "" H 7500 4750 60  0000 C CNN
	1    7500 4750
	1    0    0    -1  
$EndComp
Connection ~ 7500 4450
Wire Wire Line
	7650 3000 6700 3000
Wire Wire Line
	7650 3100 6700 3100
Text Label 6700 3000 0    60   ~ 0
ad8302_ofsb
Text Label 6700 3100 0    60   ~ 0
ad8302_inpb
$Comp
L OP598C T1
U 1 1 52741D7D
P 9150 1600
F 0 "T1" H 9380 1570 50  0000 C CNN
F 1 "OP598C" H 9480 1410 50  0000 C CNN
F 2 "" H 9115 1630 60  0000 C CNN
F 3 "" H 9115 1630 60  0000 C CNN
	1    9150 1600
	1    0    0    -1  
$EndComp
$Comp
L SMRES R5
U 1 1 52741D8C
P 9250 2250
F 0 "R5" V 9450 2350 60  0000 C CNN
F 1 "SMRES" H 9550 2300 60  0001 C CNN
F 2 "" H 9000 2550 60  0000 C CNN
F 3 "" H 9000 2550 60  0000 C CNN
F 4 "10k?" V 9350 2350 60  0000 C CNN "Resistance"
	1    9250 2250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR011
U 1 1 52741DBC
P 9300 2400
F 0 "#PWR011" H 9300 2400 30  0001 C CNN
F 1 "GND" H 9300 2330 30  0001 C CNN
F 2 "" H 9300 2400 60  0000 C CNN
F 3 "" H 9300 2400 60  0000 C CNN
	1    9300 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 1600 9300 1400
Wire Wire Line
	9300 1400 8750 1400
Wire Wire Line
	9300 1800 9300 2000
Wire Wire Line
	9300 2250 9300 2400
Text Label 8750 1400 0    60   ~ 0
regulator_5V
Wire Wire Line
	9300 1950 9900 1950
Connection ~ 9300 1950
Text Label 9500 1950 0    60   ~ 0
return_sig
Wire Wire Line
	9150 2750 10000 2750
Wire Wire Line
	9150 3050 10000 3050
Text Label 9500 2750 0    60   ~ 0
ad8302_mag
Text Label 9500 3050 0    60   ~ 0
ad8302_phs
Text Label 9500 2900 0    60   ~ 0
ad8302_vref
Wire Wire Line
	5800 5400 6500 5400
Wire Wire Line
	5800 5500 6500 5500
Text Label 6500 5400 2    60   ~ 0
ad8302_mag
Text Label 6500 5500 2    60   ~ 0
ad8302_phs
Wire Wire Line
	3300 1200 2500 1200
Text Label 2500 1200 0    60   ~ 0
ad8302_vref
Wire Wire Line
	5800 900  6250 900 
Wire Wire Line
	5800 1000 6250 1000
Text Label 6250 900  2    60   ~ 0
twi_scl_5V
Text Label 6250 1000 2    60   ~ 0
twi_sda_5V
Wire Wire Line
	9750 750  10250 750 
Wire Wire Line
	9750 850  10250 850 
Text Label 10250 750  2    60   ~ 0
twi_scl_5V
Text Label 10250 850  2    60   ~ 0
twi_sda_5V
Wire Wire Line
	7550 950  8500 950 
Text Label 7550 950  0    60   ~ 0
regulator_5V
$Comp
L SMCAP C9
U 1 1 527427A7
P 8200 1350
F 0 "C9" V 8300 1450 60  0000 C CNN
F 1 "SMCAP" H 8450 1400 60  0001 C CNN
F 2 "" H 8000 1550 60  0000 C CNN
F 3 "" H 8000 1550 60  0000 C CNN
F 4 "0.01u" V 8200 1500 60  0000 C CNN "Capacitance"
	1    8200 1350
	0    -1   -1   0   
$EndComp
Connection ~ 8250 950 
Wire Wire Line
	8250 950  8250 1200
Wire Wire Line
	8500 1050 8500 1650
Wire Wire Line
	8250 1350 8250 1500
Wire Wire Line
	8250 1500 8500 1500
Connection ~ 8500 1500
Wire Wire Line
	9750 950  10250 950 
Wire Wire Line
	9750 1050 10250 1050
Text Label 10250 950  2    60   ~ 0
osc_ctrl1
Text Label 10250 1050 2    60   ~ 0
osc_ctrl0
$Comp
L USB-B CON1
U 1 1 52742E6C
P 700 850
F 0 "CON1" H 650 950 60  0000 C CNN
F 1 "USB-B" H 700 350 60  0000 C CNN
F 2 "~" H 500 1050 60  0000 C CNN
F 3 "~" H 500 1050 60  0000 C CNN
	1    700  850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  900  1400 900 
Wire Wire Line
	900  1000 1400 1000
Wire Wire Line
	900  1100 1400 1100
Text Label 1100 900  0    60   ~ 0
usb_5V
Text Label 1100 1000 0    60   ~ 0
usb_d-
Text Label 1100 1100 0    60   ~ 0
usb_d+
$Comp
L GND #PWR012
U 1 1 527430CE
P 1000 1400
F 0 "#PWR012" H 1000 1400 30  0001 C CNN
F 1 "GND" H 1000 1330 30  0001 C CNN
F 2 "" H 1000 1400 60  0000 C CNN
F 3 "" H 1000 1400 60  0000 C CNN
	1    1000 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  1200 1000 1200
Wire Wire Line
	1000 1200 1000 1400
Wire Wire Line
	5800 3400 5950 3400
Wire Wire Line
	5800 3500 5950 3500
Text Label 5950 3400 0    60   ~ 0
osc_ctrl0
Text Label 5950 3500 0    60   ~ 0
osc_ctrl1
Wire Wire Line
	1150 3950 1150 4200
Wire Wire Line
	600  4050 1250 4050
Wire Wire Line
	1250 4050 1250 3950
Connection ~ 1150 4050
Text Label 600  4050 0    60   ~ 0
usb_5V
$Comp
L GND #PWR013
U 1 1 52742975
P 1350 4800
F 0 "#PWR013" H 1350 4800 30  0001 C CNN
F 1 "GND" H 1350 4730 30  0001 C CNN
F 2 "" H 1350 4800 60  0000 C CNN
F 3 "" H 1350 4800 60  0000 C CNN
	1    1350 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 3950 1350 4800
Connection ~ 1350 4200
$Comp
L MCP1825 U4
U 1 1 52742B72
P 1050 3450
F 0 "U4" H 1100 3500 60  0000 C CNN
F 1 "MCP1825" H 1550 3500 60  0000 C CNN
F 2 "~" H 1050 3250 60  0000 C CNN
F 3 "~" H 1050 3250 60  0000 C CNN
	1    1050 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3950 1450 4200
Wire Wire Line
	1450 4200 1350 4200
Wire Wire Line
	1650 3950 1650 4350
Wire Wire Line
	1550 3950 1550 4050
Wire Wire Line
	1550 4050 2600 4050
$Comp
L SMRES R6
U 1 1 52742E11
P 1850 4300
F 0 "R6" V 2000 4150 60  0000 C CNN
F 1 "SMRES" H 2150 4350 60  0001 C CNN
F 2 "~" H 1600 4600 60  0000 C CNN
F 3 "~" H 1600 4600 60  0000 C CNN
F 4 "750k" V 1900 4100 60  0000 C CNN "Resistance"
	1    1850 4300
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R7
U 1 1 52742E20
P 1850 4650
F 0 "R7" V 2000 4500 60  0000 C CNN
F 1 "SMRES" H 2150 4700 60  0001 C CNN
F 2 "~" H 1600 4950 60  0000 C CNN
F 3 "~" H 1600 4950 60  0000 C CNN
F 4 "68k" V 1900 4475 60  0000 C CNN "Resistance"
	1    1850 4650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR014
U 1 1 52742E46
P 1900 4800
F 0 "#PWR014" H 1900 4800 30  0001 C CNN
F 1 "GND" H 1900 4730 30  0001 C CNN
F 2 "" H 1900 4800 60  0000 C CNN
F 3 "" H 1900 4800 60  0000 C CNN
	1    1900 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 4650 1900 4800
Wire Wire Line
	1900 4300 1900 4400
Wire Wire Line
	1650 4350 1900 4350
Connection ~ 1900 4350
$Comp
L SMCAP C10
U 1 1 52743059
P 2200 4300
F 0 "C10" V 2300 4100 60  0000 C CNN
F 1 "SMCAP" H 2450 4350 60  0001 C CNN
F 2 "~" H 2000 4500 60  0000 C CNN
F 3 "~" H 2000 4500 60  0000 C CNN
F 4 "1u" V 2200 4100 60  0000 C CNN "Capacitance"
	1    2200 4300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 52743066
P 2250 4800
F 0 "#PWR015" H 2250 4800 30  0001 C CNN
F 1 "GND" H 2250 4730 30  0001 C CNN
F 2 "" H 2250 4800 60  0000 C CNN
F 3 "" H 2250 4800 60  0000 C CNN
	1    2250 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4050 2250 4150
Connection ~ 2250 4050
Wire Wire Line
	2250 4300 2250 4800
Text Label 2250 4050 0    60   ~ 0
regulator_5V
$Comp
L SMRES R8
U 1 1 52743371
P 2700 2450
F 0 "R8" H 2800 2500 60  0000 C CNN
F 1 "SMRES" H 3000 2500 60  0001 C CNN
F 2 "~" H 2450 2750 60  0000 C CNN
F 3 "~" H 2450 2750 60  0000 C CNN
F 4 "22" H 2950 2500 60  0000 C CNN "Resistance"
	1    2700 2450
	1    0    0    -1  
$EndComp
$Comp
L SMRES R9
U 1 1 52743380
P 2700 2550
F 0 "R9" H 2800 2400 60  0000 C CNN
F 1 "SMRES" H 3000 2600 60  0001 C CNN
F 2 "~" H 2450 2850 60  0000 C CNN
F 3 "~" H 2450 2850 60  0000 C CNN
F 4 "22" H 2950 2400 60  0000 C CNN "Resistance"
	1    2700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2500 2950 2500
Wire Wire Line
	2950 2600 3300 2600
Wire Wire Line
	2700 2500 2200 2500
Wire Wire Line
	2700 2600 2200 2600
Text Label 2200 2500 0    60   ~ 0
usb_d-
Text Label 2200 2600 0    60   ~ 0
usb_d+
$Comp
L SMCAP C12
U 1 1 52743812
P 1350 2900
F 0 "C12" V 1450 2700 60  0000 C CNN
F 1 "SMCAP" H 1600 2950 60  0001 C CNN
F 2 "~" H 1150 3100 60  0000 C CNN
F 3 "~" H 1150 3100 60  0000 C CNN
F 4 "10p" V 1350 2700 60  0000 C CNN "Capacitance"
	1    1350 2900
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C11
U 1 1 52743821
P 750 2900
F 0 "C11" V 850 3000 60  0000 C CNN
F 1 "SMCAP" H 1000 2950 60  0001 C CNN
F 2 "~" H 550 3100 60  0000 C CNN
F 3 "~" H 550 3100 60  0000 C CNN
F 4 "10p" V 750 3000 60  0000 C CNN "Capacitance"
	1    750  2900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR016
U 1 1 527438E8
P 1400 3150
F 0 "#PWR016" H 1400 3150 30  0001 C CNN
F 1 "GND" H 1400 3080 30  0001 C CNN
F 2 "" H 1400 3150 60  0000 C CNN
F 3 "" H 1400 3150 60  0000 C CNN
	1    1400 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 527438EE
P 800 3150
F 0 "#PWR017" H 800 3150 30  0001 C CNN
F 1 "GND" H 800 3080 30  0001 C CNN
F 2 "" H 800 3150 60  0000 C CNN
F 3 "" H 800 3150 60  0000 C CNN
	1    800  3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3150 1400 2900
Wire Wire Line
	800  3150 800  2900
Wire Wire Line
	1400 2750 1400 2600
Wire Wire Line
	1400 2600 1800 2600
Wire Wire Line
	800  2750 800  2500
Wire Wire Line
	800  2500 1800 2500
Wire Wire Line
	1200 2750 1400 2750
Wire Wire Line
	1000 2750 800  2750
Text Label 1450 2500 0    60   ~ 0
xtal1_sig
Text Label 1450 2600 0    60   ~ 0
xtal2_sig
Wire Wire Line
	3300 2000 2500 2000
Wire Wire Line
	3300 2100 2500 2100
Wire Wire Line
	3300 1900 2500 1900
Text Label 2500 1900 0    60   ~ 0
reset_sig
Text Label 2500 2000 0    60   ~ 0
xtal1_sig
Text Label 2500 2100 0    60   ~ 0
xtal2_sig
$Comp
L PUSHSWITCH SW1
U 1 1 52742FC6
P 1000 1950
F 0 "SW1" H 1100 2000 60  0000 C CNN
F 1 "PUSHSWITCH" H 1100 1800 60  0000 C CNN
F 2 "~" H 800 2150 60  0000 C CNN
F 3 "~" H 800 2150 60  0000 C CNN
	1    1000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  2000 1000 2000
Wire Wire Line
	600  2000 600  2250
$Comp
L GND #PWR018
U 1 1 5274305F
P 600 2250
F 0 "#PWR018" H 600 2250 30  0001 C CNN
F 1 "GND" H 600 2180 30  0001 C CNN
F 2 "" H 600 2250 60  0000 C CNN
F 3 "" H 600 2250 60  0000 C CNN
	1    600  2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2000 1950 2000
Text Label 1600 2000 0    60   ~ 0
reset_sig
$Comp
L SMCAP C13
U 1 1 5274318A
P 1000 1650
F 0 "C13" H 1000 1700 60  0000 C CNN
F 1 "SMCAP" H 1250 1700 60  0001 C CNN
F 2 "~" H 800 1850 60  0000 C CNN
F 3 "~" H 800 1850 60  0000 C CNN
F 4 "?" H 1200 1700 60  0000 C CNN "Capacitance"
	1    1000 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1700 750  1700
Wire Wire Line
	750  1700 750  2000
Connection ~ 750  2000
Wire Wire Line
	1150 1700 1450 1700
Wire Wire Line
	1450 1700 1450 2000
Connection ~ 1450 2000
Wire Wire Line
	9000 3600 9000 3450
Wire Wire Line
	8900 3200 9000 3200
Wire Wire Line
	9000 3200 9000 3300
Wire Wire Line
	9350 3300 9350 2600
Wire Wire Line
	9350 2600 8900 2600
$Comp
L SMCAP C14
U 1 1 52746D59
P 1100 4350
F 0 "C14" V 1250 4450 60  0000 C CNN
F 1 "SMCAP" H 1350 4400 60  0001 C CNN
F 2 "~" H 900 4550 60  0000 C CNN
F 3 "~" H 900 4550 60  0000 C CNN
F 4 "1u" V 1100 4450 60  0000 C CNN "Capacitance"
	1    1100 4350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1150 4350 1150 4500
Wire Wire Line
	1150 4500 1350 4500
Connection ~ 1350 4500
Wire Wire Line
	1150 5600 1150 5850
Wire Wire Line
	600  5700 1250 5700
Wire Wire Line
	1250 5700 1250 5600
Connection ~ 1150 5700
Text Label 600  5700 0    60   ~ 0
usb_5V
$Comp
L GND #PWR019
U 1 1 52746E9E
P 1350 6450
F 0 "#PWR019" H 1350 6450 30  0001 C CNN
F 1 "GND" H 1350 6380 30  0001 C CNN
F 2 "" H 1350 6450 60  0000 C CNN
F 3 "" H 1350 6450 60  0000 C CNN
	1    1350 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 5600 1350 6450
Connection ~ 1350 5850
$Comp
L MCP1825 U5
U 1 1 52746EA6
P 1050 5100
F 0 "U5" H 1100 5150 60  0000 C CNN
F 1 "MCP1825" H 1550 5150 60  0000 C CNN
F 2 "~" H 1050 4900 60  0000 C CNN
F 3 "~" H 1050 4900 60  0000 C CNN
	1    1050 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5600 1450 5850
Wire Wire Line
	1450 5850 1350 5850
Wire Wire Line
	1650 5600 1650 6000
Wire Wire Line
	1550 5600 1550 5700
Wire Wire Line
	1550 5700 2600 5700
$Comp
L SMRES R10
U 1 1 52746EB2
P 1850 5950
F 0 "R10" V 2000 5750 60  0000 C CNN
F 1 "SMRES" H 2150 6000 60  0001 C CNN
F 2 "~" H 1600 6250 60  0000 C CNN
F 3 "~" H 1600 6250 60  0000 C CNN
F 4 "91k" V 1900 5775 60  0000 C CNN "Resistance"
	1    1850 5950
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R11
U 1 1 52746EB9
P 1850 6300
F 0 "R11" V 2000 6100 60  0000 C CNN
F 1 "SMRES" H 2150 6350 60  0001 C CNN
F 2 "~" H 1600 6600 60  0000 C CNN
F 3 "~" H 1600 6600 60  0000 C CNN
F 4 "13k" V 1900 6125 60  0000 C CNN "Resistance"
	1    1850 6300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR020
U 1 1 52746EBF
P 1900 6450
F 0 "#PWR020" H 1900 6450 30  0001 C CNN
F 1 "GND" H 1900 6380 30  0001 C CNN
F 2 "" H 1900 6450 60  0000 C CNN
F 3 "" H 1900 6450 60  0000 C CNN
	1    1900 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6300 1900 6450
Wire Wire Line
	1900 5950 1900 6050
Wire Wire Line
	1650 6000 1900 6000
Connection ~ 1900 6000
$Comp
L SMCAP C16
U 1 1 52746ECA
P 2200 5950
F 0 "C16" V 2300 5750 60  0000 C CNN
F 1 "SMCAP" H 2450 6000 60  0001 C CNN
F 2 "~" H 2000 6150 60  0000 C CNN
F 3 "~" H 2000 6150 60  0000 C CNN
F 4 "1u" V 2200 5750 60  0000 C CNN "Capacitance"
	1    2200 5950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR021
U 1 1 52746ED0
P 2250 6450
F 0 "#PWR021" H 2250 6450 30  0001 C CNN
F 1 "GND" H 2250 6380 30  0001 C CNN
F 2 "" H 2250 6450 60  0000 C CNN
F 3 "" H 2250 6450 60  0000 C CNN
	1    2250 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 5700 2250 5800
Connection ~ 2250 5700
Wire Wire Line
	2250 5950 2250 6450
Text Label 2250 5700 0    60   ~ 0
regulator_3.3V
$Comp
L SMCAP C15
U 1 1 52746EDB
P 1100 6000
F 0 "C15" V 1250 6100 60  0000 C CNN
F 1 "SMCAP" H 1350 6050 60  0001 C CNN
F 2 "~" H 900 6200 60  0000 C CNN
F 3 "~" H 900 6200 60  0000 C CNN
F 4 "1u" V 1100 6100 60  0000 C CNN "Capacitance"
	1    1100 6000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1150 6000 1150 6150
Wire Wire Line
	1150 6150 1350 6150
Connection ~ 1350 6150
$Comp
L BSS138 T2
U 1 1 52747BC6
P 1600 7150
F 0 "T2" V 1600 6950 60  0000 C CNN
F 1 "BSS138" V 1900 7050 60  0000 C CNN
F 2 "~" H 1400 7350 60  0000 C CNN
F 3 "~" H 1400 7350 60  0000 C CNN
	1    1600 7150
	0    1    1    0   
$EndComp
$Comp
L SMRES R13
U 1 1 52747C02
P 1700 7250
F 0 "R13" V 1900 7050 60  0000 C CNN
F 1 "SMRES" H 2000 7300 60  0001 C CNN
F 2 "~" H 1450 7550 60  0000 C CNN
F 3 "~" H 1450 7550 60  0000 C CNN
F 4 "10k" V 1800 7050 60  0000 C CNN "Resistance"
	1    1700 7250
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R12
U 1 1 52747C11
P 1200 7250
F 0 "R12" V 1400 7350 60  0000 C CNN
F 1 "SMRES" H 1500 7300 60  0001 C CNN
F 2 "~" H 950 7550 60  0000 C CNN
F 3 "~" H 950 7550 60  0000 C CNN
F 4 "10k" V 1300 7350 60  0000 C CNN "Resistance"
	1    1200 7250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	700  7300 1400 7300
Wire Wire Line
	1250 7250 1250 7300
Connection ~ 1250 7300
Wire Wire Line
	1600 7300 2400 7300
Wire Wire Line
	1750 7250 1750 7300
Connection ~ 1750 7300
Wire Wire Line
	1750 7000 1750 6750
Wire Wire Line
	1750 6750 2100 6750
Wire Wire Line
	1250 6750 1250 7000
Wire Wire Line
	1250 6750 850  6750
Wire Wire Line
	1250 6900 1500 6900
Wire Wire Line
	1500 6900 1500 7150
Connection ~ 1250 6900
Text Label 850  6750 0    60   ~ 0
regulator_3.3V
Text Label 1850 6750 0    60   ~ 0
regulator_5V
Text Label 1950 7300 0    60   ~ 0
twi_scl_5V
Text Label 700  7300 0    60   ~ 0
twi_scl_3.3V
$Comp
L BSS138 T3
U 1 1 52748162
P 3500 7150
F 0 "T3" V 3500 6950 60  0000 C CNN
F 1 "BSS138" V 3800 7050 60  0000 C CNN
F 2 "~" H 3300 7350 60  0000 C CNN
F 3 "~" H 3300 7350 60  0000 C CNN
	1    3500 7150
	0    1    1    0   
$EndComp
$Comp
L SMRES R15
U 1 1 52748169
P 3600 7250
F 0 "R15" V 3800 7050 60  0000 C CNN
F 1 "SMRES" H 3900 7300 60  0001 C CNN
F 2 "~" H 3350 7550 60  0000 C CNN
F 3 "~" H 3350 7550 60  0000 C CNN
F 4 "10k" V 3700 7050 60  0000 C CNN "Resistance"
	1    3600 7250
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R14
U 1 1 52748170
P 3100 7250
F 0 "R14" V 3300 7350 60  0000 C CNN
F 1 "SMRES" H 3400 7300 60  0001 C CNN
F 2 "~" H 2850 7550 60  0000 C CNN
F 3 "~" H 2850 7550 60  0000 C CNN
F 4 "10k" V 3200 7350 60  0000 C CNN "Resistance"
	1    3100 7250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2550 7300 3300 7300
Wire Wire Line
	3150 7250 3150 7300
Connection ~ 3150 7300
Wire Wire Line
	3500 7300 4300 7300
Wire Wire Line
	3650 7250 3650 7300
Connection ~ 3650 7300
Wire Wire Line
	3650 7000 3650 6750
Wire Wire Line
	3650 6750 4000 6750
Wire Wire Line
	3150 6750 3150 7000
Wire Wire Line
	3150 6750 2750 6750
Wire Wire Line
	3150 6900 3400 6900
Wire Wire Line
	3400 6900 3400 7150
Connection ~ 3150 6900
Text Label 2750 6750 0    60   ~ 0
regulator_3.3V
Text Label 3750 6750 0    60   ~ 0
regulator_5V
Text Label 3850 7300 0    60   ~ 0
twi_sda_5V
Text Label 2550 7300 0    60   ~ 0
twi_sda_3.3V
Wire Wire Line
	3300 900  3200 900 
Text Label 3200 900  2    60   ~ 0
usb_5V
Text Label 5950 1600 0    60   ~ 0
A0
Text Label 5950 1700 0    60   ~ 0
A1
Text Label 5950 1800 0    60   ~ 0
A2
Text Label 5950 1900 0    60   ~ 0
A3
Text Label 5950 2000 0    60   ~ 0
A4
Text Label 5950 2100 0    60   ~ 0
A5
Text Label 5950 2200 0    60   ~ 0
A6
Text Label 5950 2300 0    60   ~ 0
A7
Wire Wire Line
	5800 1600 5950 1600
Wire Wire Line
	5800 1700 5950 1700
Wire Wire Line
	5800 1800 5950 1800
Wire Wire Line
	5800 1900 5950 1900
Wire Wire Line
	5800 2000 5950 2000
Wire Wire Line
	5800 2100 5950 2100
Wire Wire Line
	5800 2200 5950 2200
Wire Wire Line
	5800 2300 5950 2300
Text Label 5950 2500 0    60   ~ 0
B0
Text Label 5950 2600 0    60   ~ 0
B1
Text Label 5950 2700 0    60   ~ 0
B2
Text Label 5950 2800 0    60   ~ 0
B3
Text Label 5950 2900 0    60   ~ 0
B4
Text Label 5950 3000 0    60   ~ 0
B5
Text Label 5950 3100 0    60   ~ 0
B6
Text Label 5950 3200 0    60   ~ 0
B7
Text Label 5950 3600 0    60   ~ 0
C2
Text Label 5950 3700 0    60   ~ 0
C3
Text Label 5950 3800 0    60   ~ 0
C4
Text Label 5950 3900 0    60   ~ 0
C5
Text Label 5950 4000 0    60   ~ 0
C6
Text Label 5950 4100 0    60   ~ 0
C7
Text Label 5950 1200 0    60   ~ 0
D3
Text Label 5950 1300 0    60   ~ 0
D2
Text Label 5950 1400 0    60   ~ 0
D5
Wire Wire Line
	5950 1200 5800 1200
Wire Wire Line
	5950 1300 5800 1300
Wire Wire Line
	5950 1400 5800 1400
Wire Wire Line
	5950 2500 5800 2500
Wire Wire Line
	5800 2600 5950 2600
Wire Wire Line
	5950 2700 5800 2700
Wire Wire Line
	5800 2800 5950 2800
Wire Wire Line
	5950 2900 5800 2900
Wire Wire Line
	5950 3000 5800 3000
Wire Wire Line
	5950 3100 5800 3100
Wire Wire Line
	5950 3200 5800 3200
Wire Wire Line
	5950 3600 5800 3600
Wire Wire Line
	5950 3700 5800 3700
Wire Wire Line
	5950 3800 5800 3800
Wire Wire Line
	5950 3900 5800 3900
Wire Wire Line
	5950 4000 5800 4000
Wire Wire Line
	5950 4100 5800 4100
Text Label 5950 4300 0    60   ~ 0
D4
Text Label 5950 4400 0    60   ~ 0
D6
Text Label 5950 4500 0    60   ~ 0
D7
Wire Wire Line
	5950 4300 5800 4300
Wire Wire Line
	5950 4400 5800 4400
Wire Wire Line
	5950 4500 5800 4500
Text Label 5950 4700 0    60   ~ 0
E0
Text Label 5950 4800 0    60   ~ 0
E1
Text Label 5950 4900 0    60   ~ 0
E4
Text Label 5950 5000 0    60   ~ 0
E5
Text Label 5950 5100 0    60   ~ 0
E6
Text Label 5950 5200 0    60   ~ 0
E7
Wire Wire Line
	5950 4700 5800 4700
Wire Wire Line
	5950 4800 5800 4800
Wire Wire Line
	5950 4900 5800 4900
Wire Wire Line
	5950 5000 5800 5000
Wire Wire Line
	5950 5100 5800 5100
Wire Wire Line
	5950 5200 5800 5200
Text Label 5950 5600 0    60   ~ 0
F2
Text Label 5950 5700 0    60   ~ 0
F3
Text Label 5950 5800 0    60   ~ 0
F4
Text Label 5950 5900 0    60   ~ 0
F5
Text Label 5950 6000 0    60   ~ 0
F6
Text Label 5950 6100 0    60   ~ 0
F7
Wire Wire Line
	5950 5600 5800 5600
Wire Wire Line
	5950 5700 5800 5700
Wire Wire Line
	5950 5800 5800 5800
Wire Wire Line
	5950 5900 5800 5900
Wire Wire Line
	5950 6000 5800 6000
Wire Wire Line
	5950 6100 5800 6100
$Comp
L 6DOF U6
U 1 1 527841C1
P 7550 5500
F 0 "U6" H 7550 5450 60  0000 C CNN
F 1 "6DOF" H 7600 4700 60  0000 C CNN
F 2 "" H 7650 5450 60  0000 C CNN
F 3 "" H 7650 5450 60  0000 C CNN
	1    7550 5500
	1    0    0    -1  
$EndComp
Text Label 8050 5950 0    60   ~ 0
twi_sda_3.3V
Text Label 8050 5850 0    60   ~ 0
twi_scl_3.3V
$Comp
L GND #PWR022
U 1 1 527841F1
P 8950 6250
F 0 "#PWR022" H 8950 6250 30  0001 C CNN
F 1 "GND" H 8950 6180 30  0001 C CNN
F 2 "" H 8950 6250 60  0000 C CNN
F 3 "" H 8950 6250 60  0000 C CNN
	1    8950 6250
	1    0    0    -1  
$EndComp
Text Label 8050 6150 0    60   ~ 0
regulator_3.3V
Wire Wire Line
	8050 6050 8950 6050
Wire Wire Line
	8950 6050 8950 6250
NoConn ~ 8050 5650
NoConn ~ 8050 5750
$EndSCHEMATC
