//GYRO METHODS
void resetGyro(){
	SensorValue[in8] = 0;
	wait1Msec(250);
}
void correct(){
	wait1Msec(250);
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	if(SensorValue[in8]>0){
		while(SensorValue[in8]>0){
			motor[leftDrive] = 60;
			motor[rightDrive] = -60;
		}
		motor[leftDrive] = 0;
		motor[rightDrive] = 0;
	}
	else if(SensorValue[in8]<0){
		while(SensorValue[in8]<0){
			motor[leftDrive] = -60;
			motor[rightDrive] = 60;
		}
		motor[leftDrive] = 0;
		motor[rightDrive] = 0;
	}

}
//DRIVETRAIN METHODS
void moveForward(int count){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//reset encoders
	SensorValue(DRIVETRAIN_RIGHT_ENCODER) = 0;
	SensorValue(DRIVETRAIN_LEFT_ENCODER) = 0;
	//keep moving until reach count
	while(SensorValue(DRIVETRAIN_RIGHT_ENCODER)<count || SensorValue(DRIVETRAIN_LEFT_ENCODER)<count){
		motor[rightDrive] = 100;
		motor[leftDrive] = 100;
	}

	//brief brake to eliminate drift
	motor[rightDrive] = -10;
	motor[leftDrive] = -10;
	wait1Msec(100);
	//zero out the motors
	motor[rightDrive] = 0;
	motor[leftDrive] = 0;
}
void special(){
		//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//reset encoders
	SensorValue(DRIVETRAIN_RIGHT_ENCODER) = 0;
	SensorValue(DRIVETRAIN_LEFT_ENCODER) = 0;
	//keep moving until reach count
	while(SensorValue(DRIVETRAIN_RIGHT_ENCODER)<800 || SensorValue(DRIVETRAIN_LEFT_ENCODER)<800){
		motor[rightDrive] = 100;
		motor[leftDrive] = 100;
	}
	while(SensorValue(DRIVETRAIN_RIGHT_ENCODER)<1350 || SensorValue(DRIVETRAIN_LEFT_ENCODER)<1350){
		motor[rightDrive] = 60;
		motor[leftDrive] = 60;
	}

	//brief brake to eliminate drift
	motor[rightDrive] = -10;
	motor[leftDrive] = -10;
	wait1Msec(100);
	//zero out the motors
	motor[rightDrive] = 0;
	motor[leftDrive] = 0;
}
void moveBackward(int count){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//reset encoders
	SensorValue(DRIVETRAIN_RIGHT_ENCODER) = 0;
	SensorValue(DRIVETRAIN_LEFT_ENCODER) = 0;
	//keep moving until reach count
	while(SensorValue(DRIVETRAIN_RIGHT_ENCODER)>-count || SensorValue(DRIVETRAIN_LEFT_ENCODER)>-count){
		motor[rightDrive] = -100;
		motor[leftDrive] = -100;
	}
	//brief brake to eliminate drift
	motor[rightDrive] = 30;
	motor[leftDrive] = 30;
	wait1Msec(200);
	//zero out the motors
	motor[rightDrive] = 0;
	motor[leftDrive] = 0;
}
void rotateRight(int degree){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//clear the Gyro
	SensorValue[in8] = 0;
	//move motors until reach degree
	while(abs(SensorValue[in8]) < degree){
		motor[rightDrive] = -75;
		motor[leftDrive] = 75;
	}
	//Brief brake to eliminate some drift
	motor[rightDrive] = 10;
	motor[leftDrive] = -10;
	wait1Msec(100);
}
void rotateLeft(int degree){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//clear the Gyro
	SensorValue[in8] = 0;
	//move motors until reach degree
	while(abs(SensorValue[in8]) < degree){
		motor[rightDrive] = 75;
		motor[leftDrive] = -75;
	}
	//Brief brake to eliminate some drift
	motor[rightDrive] = -10;
	motor[leftDrive] = 10;
	wait1Msec(100);
}
void slowMove(int count){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//reset encoders
	SensorValue(DRIVETRAIN_RIGHT_ENCODER) = 0;
	SensorValue(DRIVETRAIN_LEFT_ENCODER) = 0;
	//keep moving until reach count
	while(SensorValue(DRIVETRAIN_RIGHT_ENCODER)<count || SensorValue(DRIVETRAIN_LEFT_ENCODER)<count){
		motor[rightDrive] = 40;
		motor[leftDrive] = 40;
	}

	//brief brake to eliminate drift
	motor[rightDrive] = -10;
	motor[leftDrive] = -10;
	wait1Msec(100);
	//zero out the motors
	motor[rightDrive] = 0;
	motor[leftDrive] = 0;
}
void slowLeft(int degree){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//clear the Gyro
	SensorValue[in8] = 0;
	//move motors until reach degree
	while(abs(SensorValue[in8]) < degree){
		motor[rightDrive] = 40;
		motor[leftDrive] = -40;
	}
	//Brief brake to eliminate some drift
	motor[rightDrive] = -10;
	motor[leftDrive] = 10;
	wait1Msec(100);
}
void slowRight(int degree){
	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	//clear the Gyro
	SensorValue[in8] = 0;
	//move motors until reach degree
	while(abs(SensorValue[in8]) < degree){
		motor[rightDrive] = -40;
		motor[leftDrive] = 40;
	}
	//Brief brake to eliminate some drift
	motor[rightDrive] = 10;
	motor[leftDrive] = -10;
	wait1Msec(100);
}
//SET UP REQUESTED VALUES
int DRIVETRAIN_RIGHT_REQUESTED = 0;
int DRIVETRAIN_LEFT_REQUESTED = 0;
//SET UP DRIVE VALUES
int DRIVETRAIN_RIGHT_DRIVE;
int DRIVETRAIN_LEFT_DRIVE;
task DRIVETRAIN_RIGHT_PID(){

	slaveMotor(rightDrive2, rightDrive);

	float kP = 0.1;
	float currentRPM = 0;
	float lastTick;
	float currentTick;
	float error = 0;
	float timeInterval = 20;
	while(true){
		//CALCULATE VALUES
		currentTick = SensorValue(DRIVETRAIN_RIGHT_ENCODER);
		currentRPM = (currentTick-lastTick)*60/timeInterval;
		lastTick = currentTick;

		//CALCULATE ERROR
		error = DRIVETRAIN_RIGHT_REQUESTED - currentRPM;

		//CALCULATE DRIVE
		DRIVETRAIN_RIGHT_DRIVE = kP*error;

		//HANDLE BOUNDS
		if( DRIVETRAIN_RIGHT_DRIVE > 127 )
			DRIVETRAIN_RIGHT_DRIVE = 127;
		if( DRIVETRAIN_RIGHT_DRIVE < -127 )
			DRIVETRAIN_RIGHT_DRIVE = -127;

		//SEND TO MOTOR
		motor[rightDrive] = DRIVETRAIN_RIGHT_DRIVE;

		//WAIT TIME INTERVAL
		wait1Msec(timeInterval);
	}
}
task DRIVETRAIN_LEFT_PID(){
	slaveMotor(leftDrive2, leftDrive);

	float kP = 0.1;
	float currentRPM = 0;
	float lastTick;
	float currentTick;
	float error = 0;
	float timeInterval = 20;
	while(true){
		//CALCULATE VALUES
		currentTick = SensorValue(DRIVETRAIN_LEFT_ENCODER);
		currentRPM = (currentTick-lastTick)*60/timeInterval;
		lastTick = currentTick;

		//CALCULATE ERROR
		error = DRIVETRAIN_LEFT_REQUESTED - currentRPM;

		//CALCULATE DRIVE
		DRIVETRAIN_LEFT_DRIVE = kP*error;

		//HANDLE BOUNDS
		if( DRIVETRAIN_LEFT_DRIVE > 127 )
			DRIVETRAIN_LEFT_DRIVE = 127;
		if( DRIVETRAIN_LEFT_DRIVE < -127 )
			DRIVETRAIN_LEFT_DRIVE = -127;

		//SEND TO MOTOR
		motor[leftDrive] = DRIVETRAIN_LEFT_DRIVE;

		//HANDLE ENCODER LIMITS
		if(abs(SensorValue(DRIVETRAIN_LEFT_ENCODER)) > 20000){
			SensorValue(DRIVETRAIN_LEFT_ENCODER) = 0;
		}

		//WAIT TIME INTERVAL
		wait1Msec(timeInterval);
	}
}
task DRIVE (){
	int lowThreshold = 40;
	int highThreshold = 80;

	int lowSpeed = 100;
	int highSpeed = 500;
	startTask(DRIVETRAIN_LEFT_PID);
	startTask(DRIVETRAIN_RIGHT_PID);

	while(true){

		//LEFT SIDE SET VAULES
		if(vexRT[Ch3] > highThreshold){
			DRIVETRAIN_LEFT_REQUESTED = highSpeed;
		}
		else if(vexRT[Ch3] > lowThreshold && vexRT[Ch3] <= highThreshold ){
			DRIVETRAIN_LEFT_REQUESTED = lowSpeed;
		}
		else if(vexRT[Ch3]>= -lowThreshold && vexRT[Ch3]<= lowThreshold){
			DRIVETRAIN_LEFT_REQUESTED = 0;
		}
		else if(vexRT[Ch3] < -lowThreshold && vexRT[Ch3] >= -highThreshold){
			DRIVETRAIN_LEFT_REQUESTED = -lowSpeed;
		}
		else if(vexRT[Ch3] < -highThreshold ){
			DRIVETRAIN_LEFT_REQUESTED = -highSpeed;
		}

		//RIGHT SIDE SET VALUES
		if(vexRT[Ch2] > highThreshold){
			DRIVETRAIN_RIGHT_REQUESTED = highSpeed;
		}
		else if(vexRT[Ch2] > lowThreshold && vexRT[Ch2] <= highThreshold ){
			DRIVETRAIN_RIGHT_REQUESTED = lowSpeed;
		}
		else if(vexRT[Ch2]>= -lowThreshold && vexRT[Ch2]<= lowThreshold){
			DRIVETRAIN_RIGHT_REQUESTED = 0;
		}
		else if(vexRT[Ch2] < -lowThreshold && vexRT[Ch2] >= -highThreshold){
			DRIVETRAIN_RIGHT_REQUESTED = -lowSpeed;
		}
		else if(vexRT[Ch2] < -highThreshold ){
			DRIVETRAIN_RIGHT_REQUESTED = -highSpeed;
		}

	}
}
task NORMAL_DRIVE(){
	int threshold = 60;
	int highSpeed = 125;
	int stoptime = 20;
	int speedIncrement = 25;
	int speedValueLeft;
	int speedValueRight;

	//slave motors
	slaveMotor(rightDrive2, rightDrive);
	slaveMotor(leftDrive2, leftDrive);

	while(true){

		//left side
		if((vexRT[Ch3] > threshold)||(vexRT[Ch3Xmtr2] > threshold)){
			if(speedValueLeft <= highSpeed){
				speedValueLeft += speedIncrement;
				wait1Msec(stoptime);
			}
		}
		else if((vexRT[Ch3] < -threshold)||(vexRT[Ch3Xmtr2] < -threshold)){
			if(speedValueLeft >= -highSpeed){
				speedValueLeft -= speedIncrement;
				wait1Msec(stoptime);
			}
		}
		else{
			speedValueLeft = 0;
		}
		motor[leftDrive] = speedValueLeft;

		//right side
		if((vexRT[Ch2] > threshold)||(vexRT[Ch2Xmtr2] > threshold)){
			if(speedValueRight <=highSpeed){
				speedValueRight += speedIncrement;
				wait1Msec(stoptime);
			}
		}
		else if((vexRT[Ch2] < -threshold)||(vexRT[Ch2Xmtr2] < -threshold)){
			if(speedValueRight >= -highSpeed){
				speedValueRight -= speedIncrement;
				wait1Msec(stoptime);
			}
		}
		else{
			speedValueRight = 0;
		}
		motor[rightDrive] = speedValueRight;
	}
}
