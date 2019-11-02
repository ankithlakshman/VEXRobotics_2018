int clawtime = 500;
void intake(){
	motor[rollerClaw] = 100;
	wait1Msec(clawtime);
	motor[rollerClaw] = 60;
}
void outtake(){
	motor[rollerClaw] = -100;
	wait1Msec(clawtime);
	motor[rollerClaw] = 0;
}
task CLAW(){
	while(true){
		if(vexRT[Btn8D ] == 1){
			intake();
		}
		else if(vexRT[Btn8R] == 1){
			outtake();
		}
	}
}
