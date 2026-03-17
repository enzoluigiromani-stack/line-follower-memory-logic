# Autonomous Line Follower with Recovery Logic 

An Arduino-powered robot designed to navigate tracks using infrared sensors. This project stands out by implementing a **memory-state algorithm** to handle track-loss situations.

##  The "Last Position" Logic
Most basic line followers stop or fail when they lose the line. This code implements a smart recovery:
* It constantly monitors which sensor last saw the track.
* If all sensors read "white" (line lost), the robot uses its **memory** to spin back in the direction where the line was last detected.

##  Tech Stack
* **Language:** C++ (Arduino IDE)
* **Hardware:** IR Sensors, DC Motors, L298N Driver.
* **Concepts:** Conditional Logic, State Memory, Sensor Polling.

##  Structure
* `/src`: Contains the `.ino` firmware.
* `/media`: (Add your robot's photos here!)

---
*Part of my Computer Science (UFFS) and Mechatronics (IFRS) portfolio.*
