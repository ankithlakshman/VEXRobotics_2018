void downArm(){
	slaveMotor(leftArm, rightArm);
	motor[rightArm] = 120;
	wait1Msec(1000);
	motor[rightArm] = 0;
}
void upArm(){
	slaveMotor(leftArm, rightArm);
	motor[rightArm] = -120;
	wait1Msec(1000);
	motor[rightArm] = 0;
}
task ARM()
{
	slaveMotor(leftArm, rightArm);
	int brakeSpeed = 0;
	while(true){
		if(vexRT[Btn5U] == 1){
			motor[rightArm] = -120;
			//grab();
		}
		else if(vexRT[Btn5D] == 1){
			motor[rightArm] = 127;
			//load();
		}
		else{
			motor[rightArm] = brakeSpeed;
		}
	}
}
