EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:VCC #PWR?
U 1 1 5F306A75
P 3900 2250
F 0 "#PWR?" H 3900 2100 50  0001 C CNN
F 1 "VCC" H 3915 2423 50  0000 C CNN
F 2 "" H 3900 2250 50  0001 C CNN
F 3 "" H 3900 2250 50  0001 C CNN
	1    3900 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:L L1
U 1 1 5F308443
P 3900 2400
F 0 "L1" H 3952 2446 50  0000 L CNN
F 1 "Meter Coil" H 3952 2355 50  0000 L CNN
F 2 "" H 3900 2400 50  0001 C CNN
F 3 "~" H 3900 2400 50  0001 C CNN
	1    3900 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F304D9C
P 3900 2950
F 0 "#PWR?" H 3900 2700 50  0001 C CNN
F 1 "GND" H 3905 2777 50  0000 C CNN
F 2 "" H 3900 2950 50  0001 C CNN
F 3 "" H 3900 2950 50  0001 C CNN
	1    3900 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F304319
P 3450 2750
F 0 "R1" V 3243 2750 50  0000 C CNN
F 1 "220" V 3334 2750 50  0000 C CNN
F 2 "" V 3380 2750 50  0001 C CNN
F 3 "~" H 3450 2750 50  0001 C CNN
	1    3450 2750
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D1
U 1 1 5F3031C7
P 4500 2400
F 0 "D1" V 4454 2480 50  0000 L CNN
F 1 "SKIF08 26" V 4545 2480 50  0000 L CNN
F 2 "" H 4500 2400 50  0001 C CNN
F 3 "~" H 4500 2400 50  0001 C CNN
	1    4500 2400
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:IRF540N Q1
U 1 1 5F3015D2
P 3800 2750
F 0 "Q1" H 4004 2796 50  0000 L CNN
F 1 "IRLR024N" H 4004 2705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 4050 2675 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 3800 2750 50  0001 L CNN
	1    3800 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 D11
U 1 1 5F30D52F
P 2950 2750
F 0 "D11" H 2868 2525 50  0000 C CNN
F 1 "Arduino" H 2868 2616 50  0000 C CNN
F 2 "" H 2950 2750 50  0001 C CNN
F 3 "~" H 2950 2750 50  0001 C CNN
	1    2950 2750
	-1   0    0    1   
$EndComp
Wire Wire Line
	3150 2750 3300 2750
Wire Wire Line
	4500 2550 3900 2550
Connection ~ 3900 2550
Wire Wire Line
	4500 2250 3900 2250
Connection ~ 3900 2250
$EndSCHEMATC
