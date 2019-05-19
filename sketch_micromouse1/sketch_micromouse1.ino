//Motor 1, Reverse, Forward, Enable Pins
const int M1_R = 6;
const int M1_F = 7;
const int M1_EN = 1;

//Motor 1, Reverse, Forward, Enable Pins
const int M2_R = 5;
const int M2_F = 4;
const int M2_EN = 0;

//Sensors 1, 2, 3 Pins
int SENSOR_1A = A7;
int SENSOR_2A = A6;
int SENSOR_3A = A5;

//Motor 1 & Motor 2 Speed
const int M1_SPEED = HIGH;
const int M2_SPEED = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Set up Motor 1
  pinMode(M1_EN, OUTPUT);
  pinMode(M1_F, OUTPUT);
  pinMode(M1_R, OUTPUT);

  //Set up Motor 2
  pinMode(M2_EN, OUTPUT);
  pinMode(M2_F, OUTPUT);
  pinMode(M2_R, OUTPUT);


  //Set up Sensor Pins
  pinMode(SENSOR_1A, INPUT);
  pinMode(SENSOR_2A, INPUT);
  pinMode(SENSOR_3A, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensor(SENSOR_1A, 1);
  readSensor(SENSOR_2A, 2);
  readSensor(SENSOR_3A, 3);
  //forward();
}

void forward(){
  //Moves forward
  digitalWrite(M1_EN, HIGH);
  digitalWrite(M2_EN, HIGH);
  digitalWrite(M1_R, LOW);
  //digitalWrite(M1_F, M1_SPEED);
  analogWrite(M1_F, 200);
  digitalWrite(M2_R, LOW);
  //digitalWrite(M2_F, M2_SPEED);
  analogWrite(M2_F, 100);
  Serial.print("Forward\n");
}

void reverse(){
  //Moves backward
  digitalWrite(M1_EN, HIGH);
  digitalWrite(M2_EN, HIGH);
  digitalWrite(M1_R, M1_SPEED);
  digitalWrite(M1_F, LOW);
  digitalWrite(M2_R, M2_SPEED);
  digitalWrite(M2_F, LOW);
}

void readSensor(int sensor_pin, int pinNum){
  //Analog Reads from Sensor Pin
  int sensorReading = analogRead(sensor_pin);
  //sensorReading = map(sensorReading, 0, 400, 0, 800);
  
  //Prints Sensor Values
  Serial.print("Reading of sensor ");
  Serial.print(pinNum);
  Serial.print(" is ");
  Serial.print(sensorReading);
  Serial.print("\n");
  delay(500);
}

void proportionalControl(int rightSensor, int leftSensor){
  //TODO: incorrect fix proportional control
  int rightSpeed = 150;
  //int leftSpeed = 150;
  int error = rightSensor - leftSensor;
  rightSpeed = rightSpeed + error;
}



