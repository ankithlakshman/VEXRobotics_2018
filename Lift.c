#define PID_DRIVE_MAX       127
#define PID_DRIVE_MIN     (-127)

#define PID_INTEGRAL_LIMIT  50

int POSITION_REQUESTED;

float  pid_Kp = 5.0;//2.0
float  pid_Ki = 0.04;//0.04
float  pid_Kd = 0.0;

int rightliftdrive;

task RIGHT_PID(){

	float  pidSensorCurrentValue;

	float  pidError;
	float  pidLastError;
	float  pidIntegral;
	float  pidDerivative;

	// Initiate the variables
	pidLastError  = 0;
	pidIntegral   = 0;

	while( true )
	{
		// Read the sensor value and scale
		pidSensorCurrentValue = SensorValue(LIFT_RIGHT_ENCODER);

		// calculate error
		pidError = -(pidSensorCurrentValue - POSITION_REQUESTED);

		// integral - if Ki is not 0
		if( pid_Ki != 0 )
		{
			// If we are inside controlable window then integrate the error
			if( abs(pidError) < PID_INTEGRAL_LIMIT )
				pidIntegral = pidIntegral + pidError;
			else
				pidIntegral = 0;
		}
		else
			pidIntegral = 0;

		// calculate the derivative
		pidDerivative = pidError - pidLastError;
		pidLastError  = pidError;

		// calculate drive
		rightliftdrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

		// limit drive
		if( rightliftdrive > PID_DRIVE_MAX )
			rightliftdrive = PID_DRIVE_MAX;
		if( rightliftdrive < PID_DRIVE_MIN )
			rightliftdrive = PID_DRIVE_MIN;

		// send to motor
		motor[rightLift] = rightliftdrive;
		// Run at 50Hz
		wait1Msec( 25 );
	}

}

task LEFT_PID(){

	float  pidSensorCurrentValue;

	float  pidError;
	float  pidLastError;
	float  pidIntegral;
	float  pidDerivative;
	float  pidDrive;

	// Initiate the variables
	pidLastError  = 0;
	pidIntegral   = 0;

	while( true )
	{
		// Read the sensor value and scale
		pidSensorCurrentValue = SensorValue(LIFT_LEFT_ENCODER);

		// calculate error
		pidError = -(pidSensorCurrentValue - POSITION_REQUESTED);

		// integral - if Ki is not 0
		if( pid_Ki != 0 )
		{
			// If we are inside controlable window then integrate the error
			if( abs(pidError) < PID_INTEGRAL_LIMIT )
				pidIntegral = pidIntegral + pidError;
			else
				pidIntegral = 0;
		}
		else
			pidIntegral = 0;

		// calculate the derivative
		pidDerivative = pidError - pidLastError;
		pidLastError  = pidError;

		// calculate drive
		pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

		// limit drive
		if( pidDrive > PID_DRIVE_MAX )
			pidDrive = PID_DRIVE_MAX;
		if( pidDrive < PID_DRIVE_MIN )
			pidDrive = PID_DRIVE_MIN;

		// send to motor
		motor[leftLift] = pidDrive;
		// Run at 50Hz
		wait1Msec( 25 );
	}

}

task LIFT_PID(){
	int highlimit = 160;
	int lowlimit = 0;

	int positionIncrement = 5;
	int waitTime = 60;

	POSITION_REQUESTED = 0;
	startTask(RIGHT_PID);
	startTask(LEFT_PID);
	while(true){
		if(vexRT[Btn6U] == 1){
			if(POSITION_REQUESTED < highlimit){
				POSITION_REQUESTED+=positionIncrement;
				wait1Msec(waitTime);
			}
			else{
				POSITION_REQUESTED=POSITION_REQUESTED;
			}
		}
		else if(vexRT[Btn6D] == 1){
			if(POSITION_REQUESTED > lowlimit){
				POSITION_REQUESTED-=positionIncrement;
				wait1Msec(waitTime);
			}
			else{
				POSITION_REQUESTED=POSITION_REQUESTED;
			}
		}
	}
}
void liftAutoSetup(){
	startTask(RIGHT_PID);
	startTask(LEFT_PID);
}
void pLift(int count){
	POSITION_REQUESTED = count;
}
void setLift(int count){
	if(SensorValue(LIFT_LEFT_ENCODER) < count){
		motor[rightLift] = 125;
		motor[leftLift] = 125;
		waitUntil(SensorValue(LIFT_LEFT_ENCODER) >= count);
		motor[rightLift] = 10;
		motor[leftLift] = 10;
	}
	else if(SensorValue(LIFT_LEFT_ENCODER) > count){
		motor[rightLift] = -125;
		motor[leftLift] = -125;
		waitUntil(SensorValue(LIFT_LEFT_ENCODER) <= count);
		motor[rightLift] = 10;
		motor[leftLift] = 10;
	}
}
task LIFT(){
	int liftSpeed = 125;
	while(true){
		if(vexRT[Btn6U] == 1){
			//if(SensorValue(liftPotentiometer) > highlimit)
				motor[rightLift] = liftSpeed;
				motor[leftLift] = liftSpeed;
		}
		else if(vexRT[Btn6D] == 1){
			//if(SensorValue(liftPotentiometer) < lowlimit)
				motor[rightLift] = -liftSpeed;
				motor[leftLift] = -liftSpeed;
		}
		else{
				motor[rightLift] = 5;
				motor[leftLift] = 5;

		}
	}
}
