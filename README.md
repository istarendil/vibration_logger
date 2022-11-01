# vibration_logger
The main idea of this project is to build a device capable of measuring vibrations in structures such as buildings and transmitting the information obtained to a database that can be accessed remotely through the internet. The objective of having a remote monitoring system is to collect useful data on the state of the buildings for its later analysis.

![logger](https://user-images.githubusercontent.com/107052856/199179846-55ddc8d5-e831-40ba-be4f-0a824f0ae602.jpg)
![pcb1](https://user-images.githubusercontent.com/107052856/199181725-22bdbf7b-645b-4cb6-8b40-06d4a3f1458f.jpg)

This project was commissioned by the Department of Structural Analysis of the Faculty of Engineering of the Autonomous University of the State of Mexico to the System Dynamics and Control Laboratory. 

![pcb2](https://user-images.githubusercontent.com/107052856/199182059-b04b9d82-56e6-4549-b3e9-a0529d74c18f.jpg)
![pcb3](https://user-images.githubusercontent.com/107052856/199182070-ecd37920-b398-48b6-86a1-4dfdd94b6055.jpg)


# Tools and materials
- esp8266
- dsPic30f3014
- RTC DS1302

# Software
|name| version|
|----|--------|
|MPLAB X| 10 |
|C16 compiler|1.25|
|Matlab| 2016|


# Directories and files
- The firmware/logger directory contains the source code written for the C16 compiler in MPLAB X.
- The firmware/esp8266 folder contains the different versions of the esp8266 firmware.
- The firmware/configuration_files folder contains the necessary files for the operation of the logger and for the connection to the Wi-fi network, as well as a file that shows how the data is stored.
- The pcb folder contains the PCB design files.
- The Excel document at te test folder contains a test performed on the prototype, where data was acquired and the results were graphed.
