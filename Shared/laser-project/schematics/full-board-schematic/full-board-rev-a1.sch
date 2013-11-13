EESchema Schematic File Version 2
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
LIBS:TEENSYPP2
LIBS:IMU
LIBS:murataosc
LIBS:jtag-10mil-header
LIBS:encoder-10mil-header
EELAYER 27 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Laser Mapping Project"
Date "12 nov 2013"
Rev "A"
Comp "Laser Team"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DS1077 U3
U 1 1 526F0599
P 5950 2950
F 0 "U3" H 5700 3250 60  0000 C CNN
F 1 "DS1077" H 6050 3250 60  0000 C CNN
F 2 "SO8N" H 5950 2950 60  0001 C CNN
F 3 "" H 5950 2950 60  0001 C CNN
	1    5950 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5271870F
P 7150 4550
F 0 "#PWR01" H 7150 4550 30  0001 C CNN
F 1 "GND" H 7150 4480 30  0001 C CNN
F 2 "" H 7150 4550 60  0001 C CNN
F 3 "" H 7150 4550 60  0001 C CNN
	1    7150 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 52718763
P 7050 6550
F 0 "#PWR02" H 7050 6550 30  0001 C CNN
F 1 "GND" H 7050 6480 30  0001 C CNN
F 2 "" H 7050 6550 60  0001 C CNN
F 3 "" H 7050 6550 60  0001 C CNN
	1    7050 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 52718769
P 7450 6550
F 0 "#PWR03" H 7450 6550 30  0001 C CNN
F 1 "GND" H 7450 6480 30  0001 C CNN
F 2 "" H 7450 6550 60  0001 C CNN
F 3 "" H 7450 6550 60  0001 C CNN
	1    7450 6550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5271876F
P 9200 4750
F 0 "#PWR04" H 9200 4750 30  0001 C CNN
F 1 "GND" H 9200 4680 30  0001 C CNN
F 2 "" H 9200 4750 60  0001 C CNN
F 3 "" H 9200 4750 60  0001 C CNN
	1    9200 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 52718775
P 8850 4750
F 0 "#PWR05" H 8850 4750 30  0001 C CNN
F 1 "GND" H 8850 4680 30  0001 C CNN
F 2 "" H 8850 4750 60  0001 C CNN
F 3 "" H 8850 4750 60  0001 C CNN
	1    8850 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 52718D27
P 5500 3250
F 0 "#PWR06" H 5500 3250 30  0001 C CNN
F 1 "GND" H 5500 3180 30  0001 C CNN
F 2 "" H 5500 3250 60  0001 C CNN
F 3 "" H 5500 3250 60  0001 C CNN
	1    5500 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5271A8CC
P 4550 4800
F 0 "#PWR07" H 4550 4800 30  0001 C CNN
F 1 "GND" H 4550 4730 30  0001 C CNN
F 2 "" H 4550 4800 60  0001 C CNN
F 3 "" H 4550 4800 60  0001 C CNN
	1    4550 4800
	1    0    0    -1  
$EndComp
$Comp
L SMRES R7
U 1 1 527404D4
P 4500 4300
F 0 "R7" V 4700 4100 60  0000 C CNN
F 1 "SMRES" H 4800 4350 60  0001 C CNN
F 2 "SM1210" H 4500 4300 60  0001 C CNN
F 3 "" H 4500 4300 60  0001 C CNN
F 4 "1.5k" V 4600 4100 60  0000 C CNN "Resistance"
	1    4500 4300
	0    -1   -1   0   
$EndComp
$Comp
L OPV332 LD1
U 1 1 52740787
P 4600 4500
F 0 "LD1" V 4650 4625 60  0000 C CNN
F 1 "OPV332" V 4750 4700 60  0000 C CNN
F 2 "LED-5MM" H 4400 4700 60  0000 C CNN
F 3 "~" H 4400 4700 60  0000 C CNN
	1    4600 4500
	0    1    1    0   
$EndComp
Text Label 4550 3950 0    60   ~ 0
mod_sig_1
Text Label 5500 2750 2    60   ~ 0
mod_sig_1
$Comp
L SMRES R5
U 1 1 52740B3E
P 3800 5800
F 0 "R5" V 4000 5900 60  0000 C CNN
F 1 "SMRES" H 4100 5850 60  0001 C CNN
F 2 "SM1210" H 3800 5800 60  0001 C CNN
F 3 "" H 3800 5800 60  0001 C CNN
F 4 "56" V 3900 5900 60  0000 C CNN "Resistance"
	1    3800 5800
	0    -1   -1   0   
$EndComp
$Comp
L AD8302 U4
U 1 1 52740C04
P 8000 3700
F 0 "U4" H 8050 3750 60  0000 C CNN
F 1 "AD8302" H 8500 3750 60  0000 C CNN
F 2 "AD8302" H 8000 3700 60  0001 C CNN
F 3 "" H 8000 3700 60  0001 C CNN
	1    8000 3700
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C11
U 1 1 52740C13
P 8800 4600
F 0 "C11" V 8900 4400 60  0000 C CNN
F 1 "SMCAP" H 9050 4650 60  0001 C CNN
F 2 "SM1210" H 8800 4600 60  0001 C CNN
F 3 "" H 8800 4600 60  0001 C CNN
F 4 "5p" V 8800 4400 60  0000 C CNN "Capacitance"
	1    8800 4600
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C12
U 1 1 52740CC0
P 9150 4600
F 0 "C12" V 9250 4400 60  0000 C CNN
F 1 "SMCAP" H 9400 4650 60  0001 C CNN
F 2 "SM1210" H 9150 4600 60  0001 C CNN
F 3 "" H 9150 4600 60  0001 C CNN
F 4 "5p" V 9150 4400 60  0000 C CNN "Capacitance"
	1    9150 4600
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C9
U 1 1 52740D9C
P 7400 6400
F 0 "C9" V 7500 6500 60  0000 C CNN
F 1 "SMCAP" H 7650 6450 60  0001 C CNN
F 2 "SM1210" H 7400 6400 60  0001 C CNN
F 3 "" H 7400 6400 60  0001 C CNN
F 4 "100p" V 7400 6500 60  0000 C CNN "Capacitance"
	1    7400 6400
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C8
U 1 1 52740DAB
P 7000 6400
F 0 "C8" V 7150 6500 60  0000 C CNN
F 1 "SMCAP" H 7250 6450 60  0001 C CNN
F 2 "SM1210" H 7000 6400 60  0001 C CNN
F 3 "" H 7000 6400 60  0001 C CNN
F 4 "100n" V 7050 6500 60  0000 C CNN "Capacitance"
	1    7000 6400
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R11
U 1 1 52740E3B
P 7400 6050
F 0 "R11" V 7600 5850 60  0000 C CNN
F 1 "SMRES" H 7700 6100 60  0001 C CNN
F 2 "SM1210" H 7400 6050 60  0001 C CNN
F 3 "" H 7400 6050 60  0001 C CNN
F 4 "0" V 7500 5800 60  0000 C CNN "Resistance"
	1    7400 6050
	0    -1   -1   0   
$EndComp
Text Label 7450 5700 0    60   ~ 0
regulator_5V
Text Label 7450 6200 0    60   ~ 0
ad8302_vpos
$Comp
L SMCAP C3
U 1 1 52741380
P 4050 5400
F 0 "C3" H 4050 5450 60  0000 C CNN
F 1 "SMCAP" H 4300 5450 60  0001 C CNN
F 2 "SM1210" H 4050 5400 60  0001 C CNN
F 3 "" H 4050 5400 60  0001 C CNN
F 4 "1n" H 4250 5450 60  0000 C CNN "Capacitance"
	1    4050 5400
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C4
U 1 1 5274138F
P 4050 5850
F 0 "C4" H 4050 5900 60  0000 C CNN
F 1 "SMCAP" H 4300 5900 60  0001 C CNN
F 2 "SM1210" H 4050 5850 60  0001 C CNN
F 3 "" H 4050 5850 60  0001 C CNN
F 4 "200p" H 4250 5900 60  0000 C CNN "Capacitance"
	1    4050 5850
	1    0    0    -1  
$EndComp
Text Label 3450 5450 0    60   ~ 0
mod_sig_1
Text Label 4400 5450 0    60   ~ 0
ad8302_inpa
Text Label 4400 5900 0    60   ~ 0
ad8302_ofsa
Text Label 7900 3850 2    60   ~ 0
ad8302_inpa
Text Label 7900 3950 2    60   ~ 0
ad8302_ofsa
$Comp
L GND #PWR08
U 1 1 527418CA
P 3850 6200
F 0 "#PWR08" H 3850 6200 30  0001 C CNN
F 1 "GND" H 3850 6130 30  0001 C CNN
F 2 "" H 3850 6200 60  0001 C CNN
F 3 "" H 3850 6200 60  0001 C CNN
	1    3850 6200
	1    0    0    -1  
$EndComp
$Comp
L SMRES R2
U 1 1 5274196B
P 1300 5750
F 0 "R2" V 1500 5850 60  0000 C CNN
F 1 "SMRES" H 1600 5800 60  0001 C CNN
F 2 "SM1210" H 1300 5750 60  0001 C CNN
F 3 "" H 1300 5750 60  0001 C CNN
F 4 "56" V 1350 5850 60  0000 C CNN "Resistance"
	1    1300 5750
	0    -1   -1   0   
$EndComp
$Comp
L SMCAP C1
U 1 1 52741972
P 1550 5350
F 0 "C1" H 1550 5400 60  0000 C CNN
F 1 "SMCAP" H 1800 5400 60  0001 C CNN
F 2 "SM1210" H 1550 5350 60  0001 C CNN
F 3 "" H 1550 5350 60  0001 C CNN
F 4 "1n" H 1750 5400 60  0000 C CNN "Capacitance"
	1    1550 5350
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C2
U 1 1 52741979
P 1550 5800
F 0 "C2" H 1550 5850 60  0000 C CNN
F 1 "SMCAP" H 1800 5850 60  0001 C CNN
F 2 "SM1210" H 1550 5800 60  0001 C CNN
F 3 "" H 1550 5800 60  0001 C CNN
F 4 "200p" H 1750 5850 60  0000 C CNN "Capacitance"
	1    1550 5800
	1    0    0    -1  
$EndComp
Text Label 950  5400 0    60   ~ 0
return_sig
Text Label 1900 5400 0    60   ~ 0
ad8302_inpb
Text Label 1900 5850 0    60   ~ 0
ad8302_ofsb
$Comp
L GND #PWR09
U 1 1 52741989
P 1350 6150
F 0 "#PWR09" H 1350 6150 30  0001 C CNN
F 1 "GND" H 1350 6080 30  0001 C CNN
F 2 "" H 1350 6150 60  0001 C CNN
F 3 "" H 1350 6150 60  0001 C CNN
	1    1350 6150
	1    0    0    -1  
$EndComp
Text Label 7900 4150 2    60   ~ 0
ad8302_ofsb
Text Label 7900 4250 2    60   ~ 0
ad8302_inpb
$Comp
L OP598C T3
U 1 1 52741D7D
P 5750 4150
F 0 "T3" H 5980 4120 50  0000 C CNN
F 1 "OP598C" H 6080 3960 50  0000 C CNN
F 2 "LED-5MM" H 5750 4150 60  0001 C CNN
F 3 "" H 5750 4150 60  0001 C CNN
	1    5750 4150
	1    0    0    -1  
$EndComp
$Comp
L SMRES R8
U 1 1 52741D8C
P 5850 4850
F 0 "R8" V 6050 4950 60  0000 C CNN
F 1 "SMRES" H 6150 4900 60  0001 C CNN
F 2 "SM1210" H 5850 4850 60  0001 C CNN
F 3 "" H 5850 4850 60  0001 C CNN
F 4 "10k?" V 5950 4950 60  0000 C CNN "Resistance"
	1    5850 4850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 52741DBC
P 5900 4900
F 0 "#PWR010" H 5900 4900 30  0001 C CNN
F 1 "GND" H 5900 4830 30  0001 C CNN
F 2 "" H 5900 4900 60  0001 C CNN
F 3 "" H 5900 4900 60  0001 C CNN
	1    5900 4900
	1    0    0    -1  
$EndComp
Text Label 5900 4050 0    60   ~ 0
regulator_5V
Text Label 5900 4500 0    60   ~ 0
return_sig
Text Label 9350 3900 0    60   ~ 0
ad8302_mag
Text Label 9350 4200 0    60   ~ 0
ad8302_phs
Text Label 9350 4050 0    60   ~ 0
ad8302_vref
Text Label 6250 2750 0    60   ~ 0
twi_scl_5V
Text Label 6250 2850 0    60   ~ 0
twi_sda_5V
Text Label 5350 2950 2    60   ~ 0
regulator_5V
$Comp
L SMCAP C5
U 1 1 527427A7
P 5300 3150
F 0 "C5" V 5400 3250 60  0000 C CNN
F 1 "SMCAP" H 5550 3200 60  0001 C CNN
F 2 "SM1210" H 5300 3150 60  0001 C CNN
F 3 "" H 5300 3150 60  0001 C CNN
F 4 "0.01u" V 5300 3300 60  0000 C CNN "Capacitance"
	1    5300 3150
	0    -1   -1   0   
$EndComp
Text Label 6250 2950 0    60   ~ 0
osc_ctrl1
Text Label 6250 3050 0    60   ~ 0
osc_ctrl0
Text Label 7650 1300 0    60   ~ 0
usb_5V
$Comp
L GND #PWR011
U 1 1 52742975
P 8400 2050
F 0 "#PWR011" H 8400 2050 30  0001 C CNN
F 1 "GND" H 8400 1980 30  0001 C CNN
F 2 "" H 8400 2050 60  0001 C CNN
F 3 "" H 8400 2050 60  0001 C CNN
	1    8400 2050
	1    0    0    -1  
$EndComp
$Comp
L MCP1825 U5
U 1 1 52742B72
P 8100 700
F 0 "U5" H 8150 750 60  0000 C CNN
F 1 "MCP1825" H 8600 750 60  0000 C CNN
F 2 "SOT-223-5pin" H 8100 500 60  0000 C CNN
F 3 "~" H 8100 500 60  0000 C CNN
	1    8100 700 
	1    0    0    -1  
$EndComp
$Comp
L SMRES R12
U 1 1 52742E11
P 8900 1550
F 0 "R12" V 9050 1400 60  0000 C CNN
F 1 "SMRES" H 9200 1600 60  0001 C CNN
F 2 "SM1210" H 8650 1850 60  0000 C CNN
F 3 "~" H 8650 1850 60  0000 C CNN
F 4 "200k" V 8950 1350 60  0000 C CNN "Resistance"
	1    8900 1550
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R13
U 1 1 52742E20
P 8900 1900
F 0 "R13" V 9050 1750 60  0000 C CNN
F 1 "SMRES" H 9200 1950 60  0001 C CNN
F 2 "SM1210" H 8650 2200 60  0000 C CNN
F 3 "~" H 8650 2200 60  0000 C CNN
F 4 "16k" V 8950 1725 60  0000 C CNN "Resistance"
	1    8900 1900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR012
U 1 1 52742E46
P 8950 2050
F 0 "#PWR012" H 8950 2050 30  0001 C CNN
F 1 "GND" H 8950 1980 30  0001 C CNN
F 2 "" H 8950 2050 60  0001 C CNN
F 3 "" H 8950 2050 60  0001 C CNN
	1    8950 2050
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C13
U 1 1 52743059
P 9250 1550
F 0 "C13" V 9350 1350 60  0000 C CNN
F 1 "SMCAP" H 9500 1600 60  0001 C CNN
F 2 "SM1210" H 9050 1750 60  0000 C CNN
F 3 "~" H 9050 1750 60  0000 C CNN
F 4 "1u" V 9250 1350 60  0000 C CNN "Capacitance"
	1    9250 1550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 52743066
P 9300 2050
F 0 "#PWR013" H 9300 2050 30  0001 C CNN
F 1 "GND" H 9300 1980 30  0001 C CNN
F 2 "" H 9300 2050 60  0001 C CNN
F 3 "" H 9300 2050 60  0001 C CNN
	1    9300 2050
	1    0    0    -1  
$EndComp
Text Label 9300 1300 0    60   ~ 0
regulator_5V
$Comp
L SMCAP C10
U 1 1 52746D59
P 8150 1600
F 0 "C10" V 8300 1700 60  0000 C CNN
F 1 "SMCAP" H 8400 1650 60  0001 C CNN
F 2 "SM1210" H 7950 1800 60  0000 C CNN
F 3 "~" H 7950 1800 60  0000 C CNN
F 4 "1u" V 8150 1700 60  0000 C CNN "Capacitance"
	1    8150 1600
	0    -1   -1   0   
$EndComp
Text Label 4950 1300 0    60   ~ 0
usb_5V
$Comp
L GND #PWR014
U 1 1 52746E9E
P 5700 2050
F 0 "#PWR014" H 5700 2050 30  0001 C CNN
F 1 "GND" H 5700 1980 30  0001 C CNN
F 2 "" H 5700 2050 60  0001 C CNN
F 3 "" H 5700 2050 60  0001 C CNN
	1    5700 2050
	1    0    0    -1  
$EndComp
$Comp
L MCP1825 U2
U 1 1 52746EA6
P 5400 700
F 0 "U2" H 5450 750 60  0000 C CNN
F 1 "MCP1825" H 5900 750 60  0000 C CNN
F 2 "SOT-223-5pin" H 5400 500 60  0000 C CNN
F 3 "~" H 5400 500 60  0000 C CNN
	1    5400 700 
	1    0    0    -1  
$EndComp
$Comp
L SMRES R9
U 1 1 52746EB2
P 6200 1550
F 0 "R9" V 6350 1350 60  0000 C CNN
F 1 "SMRES" H 6500 1600 60  0001 C CNN
F 2 "SM1210" H 5950 1850 60  0000 C CNN
F 3 "~" H 5950 1850 60  0000 C CNN
F 4 "90.9k" V 6250 1300 60  0000 C CNN "Resistance"
	1    6200 1550
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R10
U 1 1 52746EB9
P 6200 1900
F 0 "R10" V 6350 1700 60  0000 C CNN
F 1 "SMRES" H 6500 1950 60  0001 C CNN
F 2 "SM1210" H 5950 2200 60  0000 C CNN
F 3 "~" H 5950 2200 60  0000 C CNN
F 4 "13k" V 6250 1725 60  0000 C CNN "Resistance"
	1    6200 1900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 52746EBF
P 6250 2050
F 0 "#PWR015" H 6250 2050 30  0001 C CNN
F 1 "GND" H 6250 1980 30  0001 C CNN
F 2 "" H 6250 2050 60  0001 C CNN
F 3 "" H 6250 2050 60  0001 C CNN
	1    6250 2050
	1    0    0    -1  
$EndComp
$Comp
L SMCAP C7
U 1 1 52746ECA
P 6750 1550
F 0 "C7" V 6850 1350 60  0000 C CNN
F 1 "SMCAP" H 7000 1600 60  0001 C CNN
F 2 "SM1210" H 6550 1750 60  0000 C CNN
F 3 "~" H 6550 1750 60  0000 C CNN
F 4 "1u" V 6750 1350 60  0000 C CNN "Capacitance"
	1    6750 1550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR016
U 1 1 52746ED0
P 6800 2050
F 0 "#PWR016" H 6800 2050 30  0001 C CNN
F 1 "GND" H 6800 1980 30  0001 C CNN
F 2 "" H 6800 2050 60  0001 C CNN
F 3 "" H 6800 2050 60  0001 C CNN
	1    6800 2050
	1    0    0    -1  
$EndComp
Text Label 6800 1300 0    60   ~ 0
regulator_3.3V
$Comp
L SMCAP C6
U 1 1 52746EDB
P 5450 1600
F 0 "C6" V 5600 1700 60  0000 C CNN
F 1 "SMCAP" H 5700 1650 60  0001 C CNN
F 2 "SM1210" H 5250 1800 60  0000 C CNN
F 3 "~" H 5250 1800 60  0000 C CNN
F 4 "1u" V 5450 1700 60  0000 C CNN "Capacitance"
	1    5450 1600
	0    -1   -1   0   
$EndComp
$Comp
L BSS138 T1
U 1 1 52747BC6
P 1650 7300
F 0 "T1" V 1650 7100 60  0000 C CNN
F 1 "BSS138" V 1900 7200 60  0000 C CNN
F 2 "SOT23" H 1450 7500 60  0000 C CNN
F 3 "~" H 1450 7500 60  0000 C CNN
	1    1650 7300
	0    1    1    0   
$EndComp
$Comp
L SMRES R3
U 1 1 52747C02
P 1750 7400
F 0 "R3" V 1950 7200 60  0000 C CNN
F 1 "SMRES" H 2050 7450 60  0001 C CNN
F 2 "SM1210" H 1500 7700 60  0000 C CNN
F 3 "~" H 1500 7700 60  0000 C CNN
F 4 "10k" V 1850 7200 60  0000 C CNN "Resistance"
	1    1750 7400
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R1
U 1 1 52747C11
P 1250 7400
F 0 "R1" V 1450 7500 60  0000 C CNN
F 1 "SMRES" H 1550 7450 60  0001 C CNN
F 2 "SM1210" H 1000 7700 60  0000 C CNN
F 3 "~" H 1000 7700 60  0000 C CNN
F 4 "10k" V 1350 7500 60  0000 C CNN "Resistance"
	1    1250 7400
	0    -1   -1   0   
$EndComp
Text Label 900  6900 0    60   ~ 0
regulator_3.3V
Text Label 1800 6900 0    60   ~ 0
regulator_5V
Text Label 2000 7450 0    60   ~ 0
twi_scl_5V
Text Label 750  7450 0    60   ~ 0
twi_scl_3.3V
$Comp
L BSS138 T2
U 1 1 52748162
P 4150 7350
F 0 "T2" V 4150 7150 60  0000 C CNN
F 1 "BSS138" V 4400 7250 60  0000 C CNN
F 2 "SOT23" H 3950 7550 60  0000 C CNN
F 3 "~" H 3950 7550 60  0000 C CNN
	1    4150 7350
	0    1    1    0   
$EndComp
$Comp
L SMRES R6
U 1 1 52748169
P 4250 7450
F 0 "R6" V 4450 7250 60  0000 C CNN
F 1 "SMRES" H 4550 7500 60  0001 C CNN
F 2 "SM1210" H 4000 7750 60  0000 C CNN
F 3 "~" H 4000 7750 60  0000 C CNN
F 4 "10k" V 4350 7250 60  0000 C CNN "Resistance"
	1    4250 7450
	0    -1   -1   0   
$EndComp
$Comp
L SMRES R4
U 1 1 52748170
P 3750 7450
F 0 "R4" V 3950 7550 60  0000 C CNN
F 1 "SMRES" H 4050 7500 60  0001 C CNN
F 2 "SM1210" H 3500 7750 60  0000 C CNN
F 3 "~" H 3500 7750 60  0000 C CNN
F 4 "10k" V 3850 7550 60  0000 C CNN "Resistance"
	1    3750 7450
	0    -1   -1   0   
$EndComp
Text Label 3400 6950 0    60   ~ 0
regulator_3.3V
Text Label 4300 6950 0    60   ~ 0
regulator_5V
Text Label 4500 7500 0    60   ~ 0
twi_sda_5V
Text Label 3200 7500 0    60   ~ 0
twi_sda_3.3V
$Comp
L 6DOF U6
U 1 1 527841C1
P 8750 5100
F 0 "U6" H 8750 5050 60  0000 C CNN
F 1 "6DOF" H 8800 4300 60  0000 C CNN
F 2 "PIN_ARRAY-6X1" H 8750 5100 60  0001 C CNN
F 3 "" H 8750 5100 60  0001 C CNN
	1    8750 5100
	1    0    0    -1  
$EndComp
Text Label 9250 5550 0    60   ~ 0
twi_sda_3.3V
Text Label 9250 5450 0    60   ~ 0
twi_scl_3.3V
$Comp
L GND #PWR017
U 1 1 527841F1
P 10150 5850
F 0 "#PWR017" H 10150 5850 30  0001 C CNN
F 1 "GND" H 10150 5780 30  0001 C CNN
F 2 "" H 10150 5850 60  0001 C CNN
F 3 "" H 10150 5850 60  0001 C CNN
	1    10150 5850
	1    0    0    -1  
$EndComp
Text Label 9250 5750 0    60   ~ 0
regulator_3.3V
NoConn ~ 9250 5250
NoConn ~ 9250 5350
Wire Wire Line
	9200 4600 9200 4750
Wire Wire Line
	8750 3850 9000 3850
Wire Wire Line
	9000 3850 9000 3950
Wire Wire Line
	9000 3950 8750 3950
Connection ~ 9000 3900
Wire Wire Line
	8750 4150 9000 4150
Wire Wire Line
	9000 4150 9000 4250
Wire Wire Line
	9000 4250 8750 4250
Connection ~ 9000 4200
Wire Wire Line
	9850 4050 8750 4050
Connection ~ 7450 5700
Wire Wire Line
	7450 6400 7450 6550
Wire Wire Line
	3850 5550 3850 5450
Wire Wire Line
	3450 5450 4050 5450
Wire Wire Line
	3850 5800 3850 6200
Wire Wire Line
	3850 5900 4050 5900
Wire Wire Line
	4200 5450 4800 5450
Wire Wire Line
	4200 5900 4800 5900
Connection ~ 3850 5450
Connection ~ 3850 5900
Wire Wire Line
	1350 5500 1350 5400
Wire Wire Line
	950  5400 1550 5400
Wire Wire Line
	1350 5750 1350 6150
Wire Wire Line
	1350 5850 1550 5850
Wire Wire Line
	1700 5400 2300 5400
Wire Wire Line
	1700 5850 2300 5850
Connection ~ 1350 5400
Connection ~ 1350 5850
Wire Wire Line
	9000 3900 9850 3900
Wire Wire Line
	9000 4200 9850 4200
Wire Wire Line
	8200 1200 8200 1450
Wire Wire Line
	7650 1300 8300 1300
Wire Wire Line
	8300 1300 8300 1200
Connection ~ 8200 1300
Wire Wire Line
	8400 1200 8400 2050
Connection ~ 8400 1450
Wire Wire Line
	8500 1200 8500 1450
Wire Wire Line
	8500 1450 8400 1450
Wire Wire Line
	8700 1200 8700 1600
Wire Wire Line
	8600 1200 8600 1300
Wire Wire Line
	8950 1900 8950 2050
Wire Wire Line
	8950 1550 8950 1650
Wire Wire Line
	8700 1600 8950 1600
Connection ~ 8950 1600
Wire Wire Line
	9300 1300 9300 1400
Connection ~ 9300 1300
Wire Wire Line
	9300 1550 9300 2050
Wire Wire Line
	8850 4750 8850 4600
Wire Wire Line
	8750 4350 8850 4350
Wire Wire Line
	8850 4350 8850 4450
Wire Wire Line
	9200 4450 9200 3750
Wire Wire Line
	9200 3750 8750 3750
Wire Wire Line
	8200 1600 8200 1750
Wire Wire Line
	8200 1750 8400 1750
Connection ~ 8400 1750
Wire Wire Line
	5500 1200 5500 1450
Wire Wire Line
	4950 1300 5600 1300
Wire Wire Line
	5600 1300 5600 1200
Connection ~ 5500 1300
Wire Wire Line
	5700 1200 5700 2050
Connection ~ 5700 1450
Wire Wire Line
	5800 1200 5800 1450
Wire Wire Line
	5800 1450 5700 1450
Wire Wire Line
	6000 1200 6000 1600
Wire Wire Line
	5900 1200 5900 1300
Wire Wire Line
	6250 1900 6250 2050
Wire Wire Line
	6250 1550 6250 1650
Wire Wire Line
	6000 1600 6250 1600
Connection ~ 6250 1600
Wire Wire Line
	6800 1300 6800 1400
Connection ~ 6800 1300
Wire Wire Line
	6800 1550 6800 2050
Wire Wire Line
	5500 1600 5500 1750
Wire Wire Line
	5500 1750 5700 1750
Connection ~ 5700 1750
Wire Wire Line
	750  7450 1450 7450
Wire Wire Line
	1300 7400 1300 7450
Connection ~ 1300 7450
Wire Wire Line
	1650 7450 2450 7450
Wire Wire Line
	1800 7400 1800 7450
Connection ~ 1800 7450
Wire Wire Line
	1800 7150 1800 6900
Wire Wire Line
	1300 7150 1300 6900
Wire Wire Line
	1300 6900 900  6900
Wire Wire Line
	1300 7050 1550 7050
Wire Wire Line
	1550 7050 1550 7300
Connection ~ 1300 7050
Wire Wire Line
	3200 7500 3950 7500
Wire Wire Line
	3800 7450 3800 7500
Connection ~ 3800 7500
Wire Wire Line
	4150 7500 4950 7500
Wire Wire Line
	4300 7450 4300 7500
Connection ~ 4300 7500
Wire Wire Line
	4300 7200 4300 6950
Wire Wire Line
	3800 7200 3800 6950
Wire Wire Line
	3800 6950 3400 6950
Wire Wire Line
	3800 7100 4050 7100
Wire Wire Line
	4050 7100 4050 7350
Connection ~ 3800 7100
Wire Wire Line
	9250 5650 10150 5650
Wire Wire Line
	10150 5650 10150 5850
Wire Wire Line
	5900 1300 6800 1300
Connection ~ 6250 1300
Text Notes 9500 4550 0    60   ~ 0
C1,C2\nMay be left open.
Wire Wire Line
	5500 3050 5500 3250
Wire Wire Line
	5350 3200 5500 3200
Connection ~ 5500 3200
Wire Wire Line
	5350 2950 5500 2950
NoConn ~ 5500 2850
Wire Wire Line
	5350 3200 5350 3150
Wire Wire Line
	5350 3000 5350 2950
Wire Wire Line
	8600 1300 9300 1300
Connection ~ 8950 1300
Wire Wire Line
	7450 5700 7450 5800
Wire Wire Line
	7450 6050 7450 6250
Wire Wire Line
	7050 6550 7050 6400
Wire Wire Line
	7050 6250 7050 5700
Wire Wire Line
	7050 5700 7450 5700
Text Label 7900 4050 2    60   ~ 0
ad8302_vpos
Wire Wire Line
	7900 3750 7150 3750
Wire Wire Line
	7150 3750 7150 4550
Wire Wire Line
	7900 4350 7150 4350
Connection ~ 7150 4350
Wire Wire Line
	4550 3950 4550 4050
Wire Wire Line
	4550 4300 4550 4500
Wire Wire Line
	4550 4700 4550 4800
Wire Wire Line
	5900 4900 5900 4850
Wire Wire Line
	5900 4350 5900 4600
Wire Wire Line
	5900 4150 5900 4050
$Comp
L JTAG-10MIL-HDR CON2
U 1 1 527EE66C
P 10100 2900
F 0 "CON2" H 10150 2400 60  0000 C CNN
F 1 "JTAG-10MIL-HDR" H 10100 3000 60  0000 C CNN
F 2 "JTAG-10mil-hdr" H 9900 3100 60  0000 C CNN
F 3 "~" H 9900 3100 60  0000 C CNN
	1    10100 2900
	-1   0    0    1   
$EndComp
Text Label 9850 2850 2    60   ~ 0
jtag_tck
Text Label 9850 2750 2    60   ~ 0
jtag_tms
Text Label 9850 2550 2    60   ~ 0
jtag_tdi
Text Label 9850 2650 2    60   ~ 0
jtag_tdo
$Comp
L ENCODER-10MIL-HEADER CON1
U 1 1 52806A9E
P 8800 3100
F 0 "CON1" H 8850 2300 60  0000 C CNN
F 1 "ENCODER-10MIL-HEADER" H 8850 3200 60  0000 C CNN
F 2 "encoder-10mil-header" H 8600 3300 60  0000 C CNN
F 3 "~" H 8600 3300 60  0000 C CNN
	1    8800 3100
	-1   0    0    1   
$EndComp
Text Label 8550 3050 2    60   ~ 0
regulator_5V
Text Label 8550 2950 2    60   ~ 0
regulator_3.3V
Text Label 8550 2850 2    60   ~ 0
encoder-interface-0
Text Label 8550 2750 2    60   ~ 0
encoder-interface-1
Text Label 8550 2650 2    60   ~ 0
encoder-interface-2
Text Label 8550 2550 2    60   ~ 0
encoder-interface-3
$Comp
L GND #PWR018
U 1 1 52806AE4
P 7400 3150
F 0 "#PWR018" H 7400 3150 30  0001 C CNN
F 1 "GND" H 7400 3080 30  0001 C CNN
F 2 "" H 7400 3150 60  0001 C CNN
F 3 "" H 7400 3150 60  0001 C CNN
	1    7400 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 2450 7400 2450
Wire Wire Line
	7400 2450 7400 3150
$Comp
L TEENSYPP2 U1
U 1 1 5280746C
P 2500 2350
F 0 "U1" H 2500 2250 50  0000 C CNN
F 1 "TEENSYPP2" H 2500 2450 50  0000 C CNN
F 2 "TEENSYPP2" H 2500 2350 50  0001 C CNN
F 3 "DOCUMENTATION" H 2500 2350 50  0001 C CNN
	1    2500 2350
	1    0    0    -1  
$EndComp
Text Label 3850 1400 0    40   ~ 0
regulator_5V
Text Label 3850 2500 0    40   ~ 0
ad8302_vref
Text Label 1950 3800 3    40   ~ 0
regulator_5V
Text Label 3050 900  0    40   ~ 0
encoder-interface-0
Text Label 2950 900  2    40   ~ 0
encoder-interface-1
Text Label 3850 2300 0    40   ~ 0
encoder-interface-2
Text Label 3850 2200 0    40   ~ 0
encoder-interface-3
Text Label 1150 2600 2    40   ~ 0
osc_ctrl0
Text Label 1150 2700 2    40   ~ 0
osc_ctrl1
Text Label 1150 1600 2    40   ~ 0
twi_scl_5V
Text Label 1150 1700 2    40   ~ 0
twi_sda_5V
Text Label 3850 3000 0    40   ~ 0
jtag_tck
Text Label 3850 3100 0    40   ~ 0
jtag_tms
Text Label 3850 3200 0    40   ~ 0
jtag_tdo
Text Label 3850 3300 0    40   ~ 0
jtag_tdi
$Comp
L GND #PWR019
U 1 1 5280798C
P 3650 4050
F 0 "#PWR019" H 3650 4050 30  0001 C CNN
F 1 "GND" H 3650 3980 30  0001 C CNN
F 2 "" H 3650 4050 60  0001 C CNN
F 3 "" H 3650 4050 60  0001 C CNN
	1    3650 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4050 3650 3800
Text Label 3650 3800 0    40   ~ 0
teensy-gnd
Text Label 3850 2400 0    40   ~ 0
teensy-gnd
Text Label 2050 3800 3    40   ~ 0
teensy-gnd
Text Label 1150 1400 2    40   ~ 0
teensy-gnd
Text Label 3850 2600 0    40   ~ 0
ad8302_mag
Text Label 3850 2700 0    40   ~ 0
ad8302_phs
$EndSCHEMATC
