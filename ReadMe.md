### Tool to perform a USB Reset on Realtek hub 

##### Platforms 
* Tested on NVIDIA Jetson Nano DevKit and Jetson Xavier NX

* Note : 
It might work on other platform that have a internal USB Realtek Hub.
You can type lsusb to check that a hub appears : 

Ex : 

> on Nano devkit, it should output `0x0bda::0x5411`

> on Xavier NX devkit, it should output `0x0bda::0x5489`

Change the `unsigned  pid = XXXXX` in the realtek_hub_power_cycle.c accordingly.

##### Requirements
* libusb 

`$ sudo apt install libusb-1.0-0-dev`

* gcc

`$ sudo apt install build-essential`


##### How to build : 
Use the build script to build the executable :

`$ sh build.sh`

##### How to use
Once build, execute :

`sudo ./power_cycle`


