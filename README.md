### IoT-Based Home Automation

#### 1. Controling an Appliance using ESP32

Description:
The ESP32 hosts a server that allows you to control an appliance (e.g., a bulb) through a web interface. Access the control interface by visiting a specific URL in your browser.

Components Required:  
1. ESP32
2. Relay 
3. Bulb 

![image](./images/singleDevice.jpg)




### 2. Comibining multiple appliances 
Components Required:
1. ESP32 (for each device)
2. Relay
3. Bulb
4. Raspberry Pi
 
Description:
In this setup, multiple ESP32 devices are controlled through a Raspberry Pi server. The Raspberry Pi manages communication with each ESP32, allowing you to control several appliances from a single interface.

![image](./images/pi.jpg)
