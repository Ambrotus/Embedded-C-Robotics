#ifndef functions_h
#define functions_h

void moveForwardWithEncoders();
void leftTurnWithEncoders();
void rightTurnWithEncoders();
bool lineFollower(int upperPower, int lowerPower);
void moveForwardWithEncodersWithWait(int time);
void moveForwardWithEncodersWithSpeed(int speed);
void grabObject();
void reverse();
void dropObjectAtStart();

void moveForwardWithEncoders(){
	//this will be an upgrade from the autocorrecting move forward i made in lab 1 using the gyro to trouble shoot my robot.
	//turns out this is actually called Automated Straightening... and more precise than something i could come up with using my limited knowlegde at the time!
	if(SensorValue[leftEncoder] == SensorValue[rightEncoder]){
		motor[leftMotor] = 100;
		motor[rightMotor] = 100;
	}else if(SensorValue[leftEncoder] > SensorValue[rightEncoder]){
		motor[leftMotor] = 99;
		motor[rightMotor] = 100;
	}else{
		//if(SensorValue[leftEncoder] < SensorValue[rightEncoder]){
		motor[leftMotor] = 100;
		motor[rightMotor] = 99;
	}

}

void moveForwardWithEncodersWithSpeed(int speed){
	if(SensorValue[leftEncoder] == SensorValue[rightEncoder]){
		motor[leftMotor] = speed;
		motor[rightMotor] = speed;
	}else
		if(SensorValue[leftEncoder] > SensorValue[rightEncoder]){
		motor[leftMotor] = speed-1;
		motor[rightMotor] = speed;
		}else{
		//if(SensorValue[leftEncoder] < SensorValue[rightEncoder]){
		motor[leftMotor] = speed;
		motor[rightMotor] = speed-1;
	}

}

void moveForwardWithEncodersWithWaitAndSpeed(int time, int speed){
	//this will be an upgrade from the autocorrecting move forward i made in lab 1 using the gyro to trouble shoot my robot.
	//turns out this is actually called Automated Straightening... and more precise than something i could come up with using my limited knowlegde at the time!
	if(SensorValue[leftEncoder] == SensorValue[rightEncoder]){
		motor[leftMotor] = speed;
		motor[rightMotor] = speed;
	}else
		if(SensorValue[leftEncoder] > SensorValue[rightEncoder]){
		motor[leftMotor] = speed-1;
		motor[rightMotor] = speed;
		}else{
		//if(SensorValue[leftEncoder] < SensorValue[rightEncoder]){
		motor[leftMotor] = speed;
		motor[rightMotor] = speed-1;
	}
	wait10Msec(time);
}

void leftTurnWithEncoders(){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	waitUntilMotorStop(leftMotor);
	//wait10Msec(1);
	while (SensorValue[rightEncoder] < 269){
		motor[rightMotor] = 60;
		motor[leftMotor] = -60;
	}
}

void rightTurnWithEncoders(){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	waitUntilMotorStop(leftMotor);
	wait10Msec(1);
	while (SensorValue[leftEncoder] < 269){
		motor[rightMotor] = -60;
		motor[leftMotor] = 60;
	}
}

bool lineFollower(int upperPower, int lowerPower){
	//what if i actually use a variable and store sonar value at the end of the function for checking? instead of in the while loop
	bool sonarFlag = true;
	//while(SensorValue[sonarSensor] > 30 || SensorValue[sonarSensor] <= 0){
	while(sonarFlag){
		if(SensorValue[rightLineFollower] > 1100 ){
			if(SensorValue[rightLineFollower]>2000){ //2200
				motor[rightMotor] = -65;// big right turn
				motor[leftMotor] = 65;
				wait10Msec(10);//20
				}else{
				motor[rightMotor] = lowerPower;//30;// right turn
				motor[leftMotor] = upperPower;//70;
			}

		}else if(SensorValue[leftLineFollower] > 1100 ){ //change this to ~600? and then change upper and lower to be clsoer together?
			if(SensorValue[leftLineFollower]>2000){//2200
				motor[rightMotor] = 65;// big left turn
				motor[leftMotor] = -65;
				wait10Msec(10);//20
				} else{
				motor[rightMotor] = upperPower;//70 left turn
				motor[leftMotor] = lowerPower;//30
			}
		}

		if(SensorValue[rightLineFollower] <200 && SensorValue[leftLineFollower] <200){
			motor[rightMotor] = 80;//40
			motor[leftMotor] = 80;//40
		}

		if(SensorValue[rightLineFollower] <200 && SensorValue[centerLineFollower] <200 && SensorValue[leftLineFollower] <200 && SensorValue[sonarSensor]>50){
			motor[rightMotor] = -80;//40
			motor[leftMotor] = -80;//40
			//this wait until line may need adjusting as i just want it to back up a bit farther, may just change it to a time. rarly happens so hopefully this is a fix
			//waitUntil(SensorValue[rightLineFollower]  > 200 || SensorValue[centerLineFollower] > 200 || SensorValue[leftLineFollower] > 200);
			wait10Msec(2);
			}

		if(!(SensorValue[sonarSensor] > 30 || SensorValue[sonarSensor] <= 0)) {
			wait10Msec(1);
			if(!(SensorValue[sonarSensor] > 30 || SensorValue[sonarSensor] <= 0)){
				sonarFlag = false;
			}
		}
	}//while

	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	writeDebugStream("testing sonar: %i \n", SensorValue[sonarSensor]);
	return true;
}//function

void grabObject(){
	motor[clawMotor] = -25;
	motor[armMotor] = -105;//armMotor
	wait10Msec(100);
	motor[clawMotor] = 25;
	wait10Msec(50);
	motor[armMotor] = 105;//armMotor
}

void reverse(){
	motor[rightMotor] = -20;// big left turn
	motor[leftMotor] = -20; //-125
	wait10Msec(300);
}

void dropObjectAtStart(){

	while (SensorValue[sonarSensor] > 50 || SensorValue[sonarSensor] < 0 ){
		motor[rightMotor] = 70;// left turn
		motor[leftMotor] = 70;
	}
	motor[rightMotor] = 0;// left turn
	motor[leftMotor] = 0;
	motor[armMotor] = -105;//armMotor
	wait10Msec(200);
	motor[clawMotor] = -25;
	wait10Msec(10);
}


#endif /* functions_h */
