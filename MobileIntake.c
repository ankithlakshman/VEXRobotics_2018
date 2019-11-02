void moveMobileIntake(){
	int lowPoint = 360;
	int midPoint = 1520;
	int highPoint = 2300;
	if(SensorValue(mobilePot) > midPoint){
	 motor[mobileIntake] = -127;
	 waitUntil(SensorValue(mobilePot) < lowPoint+10);
	 motor[mobileIntake] = 0;
	}
	else if(SensorValue(mobilePot) < midPoint){
		motor[mobileIntake] = 120;
		waitUntil(SensorValue(mobilePot) > midPoint);
		motor[mobileIntake] = 50;
		waitUntil(SensorValue(mobilePot) > highPoint-10);
		motor[mobileIntake] = 20;
	}
}
task MOBILE_GOAL_INTAKE(){
	while(true){
		if((vexRT[Btn7D] == 1) || (vexRT[Btn5UXmtr2] == 1)){
			moveMobileIntake();
		}
		else if(vexRT[Btn6UXmtr2] == 1){
			motor[mobileIntake] = 127;
		}
		else if(vexRT[Btn6DXmtr2] == 1){
			motor[mobileIntake] = -127;
		}
		else{
			motor[mobileIntake] = 0;
		}
	}
}
