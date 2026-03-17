// Line Follower with Recovery Logic
// Developed by Enzo Luigi Romani

// Pin definitions (Example - adjust to your actual pins)
const int leftSensorPin = 2;
const int centerSensorPin = 3;
const int rightSensorPin = 4;

char lastPosition = 'S'; // 'L' for Left, 'R' for Right, 'S' for Straight

void setup() {
  pinMode(leftSensorPin, INPUT);
  pinMode(centerSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  
  // Initialize motor pins here
  // Serial.begin(9600);
}

void loop() {
  // Read sensor states (Assuming LOW = Line Detected)
  int leftSensor = digitalRead(leftSensorPin);
  int centerSensor = digitalRead(centerSensorPin);
  int rightSensor = digitalRead(rightSensorPin);

  // Update memory: record the last side that detected the track
  if (rightSensor == LOW) {
    lastPosition = 'R';
  } else if (leftSensor == LOW) {
    lastPosition = 'L';
  }

  // --- Normal Line Following Logic ---
  if (centerSensor == LOW) {
    moveForward();
  } 
  else if (leftSensor == LOW) {
    turnLeft();
  } 
  else if (rightSensor == LOW) {
    turnRight();
  } 
  
  // --- Recovery Logic: Robot is off-track ---
  else {
    if (lastPosition == 'R') {
      spinRecoverRight(); // Spin to relocate line on the right
    } 
    else if (lastPosition == 'L') {
      spinRecoverLeft();  // Spin to relocate line on the left
    } 
    else {
      stopRobot();        // Default safety stop
    }
  }

  delay(10);
}

// --- Motor Control Functions ---
void moveForward() { /* Add motor logic */ }
void turnLeft() { /* Add motor logic */ }
void turnRight() { /* Add motor logic */ }
void spinRecoverLeft() { /* Add reverse/spin logic */ }
void spinRecoverRight() { /* Add reverse/spin logic */ }
void stopRobot() { /* Add motor stop logic */ }
