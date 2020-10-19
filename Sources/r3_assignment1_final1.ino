//L293D
//Motor Top
const int top_motor_controller1  = 6;  // Pin 10 of L293
const int top_motor_controller2  = 5;  // Pin 14 of L293

//Motor Bottom
const int bottom_motor_controller1  = 9;  // Pin  2 of L293
const int bottom_motor_controller2  = 10; // Pin  7 of L293
//Potentiometer wiper
const int wiper_in = A0;
//wiper variable
double pot;
//DIP switches
const int s1 = 7;
const int s2 = 8;
const int s3 = 12;
const int s4 = 4;//commented for debugging


//This will run only one time.
void setup(){
    //Set pins as outputs
  	//Motor pin setups
    pinMode(top_motor_controller1, OUTPUT);
    pinMode(top_motor_controller2, OUTPUT);
    pinMode(bottom_motor_controller1, OUTPUT);
    pinMode(bottom_motor_controller2, OUTPUT);
  	//pot. pin setups
  	pinMode(wiper_in, INPUT);
  	//DIP swith setup
  	pinMode(s1, INPUT_PULLUP);
  	pinMode(s2, INPUT_PULLUP);
  	pinMode(s3, INPUT_PULLUP);
  	pinMode(s4, INPUT_PULLUP);
  	//debugger
  	//Serial.begin(9600);

}


void loop(){
  	//init. the pot. variable
  	pot = analogRead(wiper_in)/4.0;//to make sure we are not going neg.
  	
  	//swithcing conditions: 
  
  	//When all dip switches are off, two mkotors will be turned off by using control pins
  	if ((digitalRead(s1) == 1) && (digitalRead(s2) == 1) && (digitalRead(s3) == 1) && (digitalRead(s4) == 1)) {
     	analogWrite(top_motor_controller1, 0);
    	analogWrite(top_motor_controller2, 0);
    	analogWrite(bottom_motor_controller1, 0);
   		analogWrite(bottom_motor_controller2, 0);
    }
  
  	// When switch 1 (most left) is on, both motor move forward
  	else if((digitalRead(s1) == 0) && (digitalRead(s2) == 1) && (digitalRead(s3) == 1) && (digitalRead(s4) == 1)){
    	analogWrite(top_motor_controller1, 0);
    	analogWrite(top_motor_controller2, pot);
    	analogWrite(bottom_motor_controller1, 0);
   		analogWrite(bottom_motor_controller2, pot);
  	}
  
  	// When switch 2 (from left side) is on, we move both motors backwards
  	else if((digitalRead(s1) == 1) && (digitalRead(s2) == 0) && (digitalRead(s3) == 1) && (digitalRead(s4) == 1)){
    	analogWrite(top_motor_controller1, pot);
    	analogWrite(top_motor_controller2, 0);
    	analogWrite(bottom_motor_controller1, pot);
   		analogWrite(bottom_motor_controller2, 0);
  	}
  
  	//When switch 3 is on, we turn left (top motor backwards, bottom motor forwards
  	else if((digitalRead(s1) == 1) && (digitalRead(s2) == 1) && (digitalRead(s3) == 0) && (digitalRead(s4) == 1)){
      	analogWrite(top_motor_controller1, pot);
    	analogWrite(top_motor_controller2, 0);
    	analogWrite(bottom_motor_controller1, 0);
   		analogWrite(bottom_motor_controller2, pot);
    }
  
  	//When switch 4 is on, we turn right (top motor forward, bottom backwards) 	
  	else if((digitalRead(s1) == 1) && (digitalRead(s2) == 1) && (digitalRead(s3) == 1) && (digitalRead(s4) == 0)){
      	analogWrite(top_motor_controller1, 0);
    	analogWrite(top_motor_controller2, pot);
   		analogWrite(bottom_motor_controller2, 0);
      	analogWrite(bottom_motor_controller1, pot);
    }
  	
  	//since we dont want to turn on any motor when more than 
  	//one dip switch is on, we add the last else statement as follows
  	else{
    	analogWrite(top_motor_controller1, 0);
    	analogWrite(top_motor_controller2, 0);
    	analogWrite(bottom_motor_controller1, 0);
   		analogWrite(bottom_motor_controller2, 0);
  	}
   
  	

}
