# Tesla-Arduino
An autonomous vehicle created in conjunction with a partner during Fall 2022 of my senior year at UIC. Device equipped with the capability to manually control it via an application on your smartphone. This project utilizes two advanced subsystems to allow for the functionality desired, letting the user have full control of the vehicle.
 
Names, NetIds, and Email addresses of all team members
Rayaan Siddiqi
NETID: rsiddi29
Email: rsiddi29@uic.edu

Sean Kudrna 
NETID: skudr2
Email: skudr2@uic.edu

The title of your project
The Tesla Arduino

Abstract of your project (hard limit of 100 words or less)
We are creating an autonomous vehicle with the capability to manually control it via an application on your smartphone. This project utilizes two advanced subsystems to allow for the functionality desired, letting the user full control of the vehicle. This project consists of two main systems, each having unique roles with the autonomous system controlling the car’s movement to ensure no obstacles are hit and the manual system allowing for the car’s movements to be dictated by the person controlling the application.

Motivation
Our motivation for creating “The Tesla Arduino” was a combination of our group's interests in real life paired with what we believed was possible with the Arduino. At the beginning of the semester we both knew that we wanted to go out for something out of the box and create something which was applicable to real life. That led us to conclude our idea of creating an autonomous car but we decided to add a twist for some greater structure related to computer science. That led us to integrate the application we created to support a different functionality for the project and made the whole process worthwhile. 
Overall description of the system..
The main aspect of this system/project is to create an autonomous driving car using two arduino unos for computation, control, and obstacle avoidance. The car will be equipped with ultrasonic sensors which will aid in the avoidance functionality. By default, the car will move in a straight direction, and halt when it approaches an obstacle. 

The arduinos will be listening to the values provided by the ultrasonic sensor to know when the vehicle is in close proximity to a wall/obstacle. The car will then observe its surroundings, and pick the most efficient route to go depending on the furthest obstacle from it. For example, if the car is in a maze, when it reaches a wall it will look left, right, and then evaluate which direction allows it to move the most freely (which direction has a wall furthest away). Once it establishes the best direction to move in, the car will proceed in that trajectory.

As for the second aspect of the system, another arduino will be used to command the car, if specified by the user, manually using a mobile application that is connected via bluetooth. 
Ideally, the car would also be equipped with a small camera that will stream video to the application for the user to view directly in front of the car, and a simple directional pad will be provided for movement control. From here, the autonomous driving code will be halted, and the user can take command of the vehicle and steer in any way they see fit.
Description of each subsystem.
Subsystem 1: Automated Control Unit (ACU)
The ACU is responsible for all computations when it comes to vehicle movement and obstacle avoidance. 

Set to forward movement by default, the drive motors spin the wheels in the forward direction until the ultrasonic sensor picks up an obstacle within a designated close proximity. Upon halting, the vehicle analyzes its surroundings, recording distance measurements in respective directions, and then sending a signal to the drive motors to turn the vehicle in the best analyzed direction while illuminating led’s to signify a turn and then continuing movement in that direction. 

Subsystem 2: Manual Override Control (MOC)
The MOC acts as the contrary to the ACU subsystem. 

With this subsystem, the functionality of the hardware remains unchanged. The obstacle avoidance code is replaced by the networking involvements required for mobile app connection, and manual user input control for drive movement. In addition, the MOC has the additional output device of a camera, which streams video to the mobile application for user viewing and vehicle control.

List of Input and Output devices per subsystem. 

SUBSYSTEM #1: AUTOMATED CONTROL UNIT


Subsystem 1. Input devices.

Device
Behaviour
Input
Ultrasonic Sensor
Used to measure distance for calculations in obstacle avoidance
Light/sound waves



Subsystem 1. Output devices.

Device
Behaviour
Output
Drive Motors
LED
Responsible for turning wheels
Responsible for illuminating when turning
Turning movements 

SUBSYSTEM #2: MANUAL OVERRIDE CONTROL


Subsystem 1. Input devices.

Device
Behaviour
Input
Application
Buttons and user inputs communicated via bluetooth for decision making when it comes to decision of vehicle
App



Subsystem 1. Output devices.

Device
Behaviour
Output
Drive Motors
LED
Responsible for turning wheels
Responsible for illuminating when turning
Turning movements 



Communication mechanism. 
The main communication method between our application and the arduino will be via Bluetooth. The hardware will be communicated through with the information we send over from our app designating the moves and directions the vehicle will move towards. As for in-between the Arduinos, they will communicate through a serial communication and this communication will mainly entail details on the mode the vehicle is currently being driven on. This can be the autonomous mode or the manually controlled mode.
Similar projects (State of the art)
Mcnelly, Hannah. “Arduino Uno Autonomous Car.” Arduino Project Hub, 2017, 
https://create.arduino.cc/projecthub/hannahmcneelyy/arduino-uno-autonomous-car-c45fd1. 
This project is a base foundation for what we are going for. It is a watered down version of the autonomous vehicle which makes turns in response to the state of LED lights in front of it.

Sohail, Mohammad. “Android Mobile Controlled Bluetooth RC Car.” 
Arduino Project Hub, 2021, https://create.arduino.cc/projecthub/mohammadsohail0008/android-mobile-controlled-bluetooth-rc-car-e77f77. 
This project provides the base line for the manually controlled vehicle aspect of our project. It shows an application made to control the directions and movements of the vehicle.
Statement of originality
Our project is original with the combination of the two subsystems we are implementing. While current iterations only utilize one subsystem, we are combining the idea of an autonomous vehicle with the aspect of it being manually controlled too in order to get the best of both worlds. This option to switch between automated and manual mode along with the ability to control the application with a mobile app and video output add layers of creativity and craftsmanship to our project.
List of Materials
- Ultrasonic Sensors
- Arduino
- Breadboard
- Ground wires
- LED’s
- Battery Charge Shield
- Bluetooth Module
- Wheel Motors
Block Diagram of the system (Big picture diagram).

Hardware diagrams 




Steps to build your project 
1. Order all the parts required 
- Ensure that all parts needed are here

2. Work on Automated Control Unit
- Hardware
   - Have arduino board and breadboard laid out
   - Connect arduino to the car unit 
   - Connect Ultrasonic sensor to front of the car unit
- Software
   - Write code to connect all required components and pins
   - Use conditional statements to detect obstacles 
   - Upon detection of obstacle, rotate wheels directions and speed
   - Shift car unit placement to allow for successful avoidance of obstacles in path

3. Work on Manual Override Control
- Hardware
   - Connect arduino to car unit
- Software
   -Create application using MIT App inventor
   -Connect device to car unit via Bluetooth
User guide
The user has two options when presented with our system which can be categorized below:
1. Click the button on the app titled “Auto Pilot”
- This will initiate the ACU subsystem which will start the autonomous driving mode for the car. 
2. Click the button titled “Control Car”
- This will initiate the MOC subsystem in which the user can drive the car themselves with controls to move it forward, backward, right, and left.
Video of the current prototype working 
https://youtu.be/SnBGzoqBMXE


Lessons Learned
Throughout the creation of our final project, we learned many valuable lessons. If we had the opportunity to do it all again, we would stick to mostly the same of everything. We worked hard as a group together and got everything done in a timely manner. If we were to improve one thing it would be to improve the obstacle detection algorithm, however, it is currently still really good with detecting obstacles. We would like to make it even better to optimize the decisions it makes when detecting obstacles. We encountered problems as well such as those related to battery issues as the standard 5V battery included in our Arduino kit was not large enough to power the four motors of the vehicle. This led us to think of an intuitive solution: a battery bank. This ensured that our motors were properly powered. If we had more time and resources, we would like to improve the speed of our vehicle and this could be done through a better energy solution and weight reduction.
Timeline
Week of Friday, November 4th
Work on subsystem #1:
Experiment with small version of app (start process)
on subsystem #2:
Connect all parts of subsystem (ACU)

Week of Friday, November 11th
Work on subsystem #1:
Translate app to larger version for project
Work on subsystem #2:
Communicate with autonomous aspect/code
Milestone 5 (11/14)

Week of Friday, November 18th
Work on subsystem #1:
Coding for app and connection to vehicle
Work on subsystem #2:
Communicate with autonomous aspect/code continued

Week of Friday, November 25th
Start testing and more testing
Serial communication code and testing
Ensure quality control of vehicle
Milestone 6 (11/29)
Milestone 7 (12/1)

Week of Friday, December 2nd
Ensure everything works together
Practice presentation and wrap up!

Milestone 8 (12/2)
Milestone 9 (12/5)

References
Build your own app that connects to Arduino/Genuino 101. Arduino Project Hub. (n.d.). Retrieved September 29, 2022, from https://create.arduino.cc/projecthub/inmyorbit/build-your-own-app-that-connects-to-arduino-genuino-101-e55dfe 

“IOS and Arduino Serial Communication Using Blexar App and Bluetooth.” Maker Portal, makersportal.com/blexar-serial-communication. 

Arduino Uno Autonomous Car. Arduino Project Hub. (n.d.). Retrieved September 29, 2022, from https://create.arduino.cc/projecthub/hannahmcneelyy/arduino-uno-autonomous-car-c45fd1 

“Building the Elegoo Smart Robot Car Part 1 - Arduino Based Robotics Project.” YouTube, YouTube, 28 Nov. 2018, https://www.youtube.com/watch?v=xTILIkExKZo. 
