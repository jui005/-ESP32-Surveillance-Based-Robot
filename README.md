Project Overview: Mobile-Controlled Car with MQTT and Live Streaming
This project involves creating a remote-controlled car that can be operated via a mobile phone app from anywhere in the world using the MQTT protocol. The car is equipped with live video streaming capability, thanks to an ESP32 camera module. The project integrates hardware and software components to provide seamless control and monitoring.

Components Used:
ESP32: Used for both Wi-Fi connectivity and live video streaming.
L298N Motor Driver: Controls the four motors for movement, including forward, backward, left, and right turns.
4 Motors: Drive the car, providing motion in various directions.
MIT App Inventor: Used to develop the mobile application for controlling the car.
MQTT Server: Facilitates global control by sending commands from the app to the car via the internet.


How it Works:
Control via MQTT: The mobile app sends movement commands to the car using the MQTT protocol, which ensures that the car can be controlled from anywhere with internet access. The commands are processed by the ESP32, which in turn instructs the L298N motor driver to move the motors accordingly.

Motor Control: The L298N motor driver controls the 4 motors that drive the car. By adjusting the power supplied to the motors, the car can move forward, backward, or turn.

Live Streaming: The ESP32 also serves as a video streaming module, providing real-time feedback of the car’s surroundings. This is critical for remote control, as it allows the user to monitor the car's environment from their mobile device.

Mobile App: The app built using MIT App Inventor provides a user-friendly interface with buttons to control the car’s movement. The app connects to the MQTT server, sends commands, and displays the live video stream.
