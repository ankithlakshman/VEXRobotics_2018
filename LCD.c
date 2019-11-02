const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
int direction;
//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------


task autonomousLCD(){
	int count = 0;

	clearLCDLine(0);
	clearLCDLine(1);

	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "24 Point - Left");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 9;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 1;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "24 Point - Right");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 0;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 2;
			}
			break;
		case 2:
			//Display second choice
			displayLCDCenteredString(0, "14 Point - Left");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 1;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 3;
			}
			break;
		case 3:
			//Display second choice
			displayLCDCenteredString(0, "14 Point - Right");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 2;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 4;
			}
			break;
			case 4:
			//Display second choice
			displayLCDCenteredString(0, "9 Point - Left");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 5;
			}
			break;
			case 5:
			//Display second choice
			displayLCDCenteredString(0, "9 Point - Right");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 4;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 6;
			}
			break;
			case 6:
			//Display second choice
			displayLCDCenteredString(0, "ST+MB - Left");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 5;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 7;
			}
			break;
			case 7:
			//Display second choice
			displayLCDCenteredString(0, "ST+MB - Right");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 6;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 8;
			}
			break;
			case 8:
			//Display second choice
			displayLCDCenteredString(0, "RAM");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 7;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 9;
			}
			break;
			case 9:
			//Display second choice
			displayLCDCenteredString(0, "DO NOTHING");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 8;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		}
	}

	direction = count;
	while(true){
		//Clear LCD
		clearLCDLine(0);
		clearLCDLine(1);
		//Switch Case that actually runs the user choice
		switch(count){
		case 0:
			//If count = 0, run the code correspoinding with choice 1
			displayLCDCenteredString(0, "24 Point - Left");
			displayLCDCenteredString(1, "is running!");
			break;
		case 1:
			//If count = 1, run the code correspoinding with choice 2
			displayLCDCenteredString(0, "24 Point - Right");
			displayLCDCenteredString(1, "is running!");
			break;
		case 2:
			//If count = 2, run the code correspoinding with choice 3
			displayLCDCenteredString(0, "14 Point - Left");
			displayLCDCenteredString(1, "is running!");
			break;
		case 3:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "14 Point - Right");
			displayLCDCenteredString(1, "is running!");
			break;
		case 4:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "9 Point - Left");
			displayLCDCenteredString(1, "is running!");
			break;
		case 5:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "9 Point - Right");
			displayLCDCenteredString(1, "is running!");
			break;
		case 6:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "ST+MB - Left");
			displayLCDCenteredString(1, "is running!");
			break;
		case 7:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "ST+MB - Right");
			displayLCDCenteredString(1, "is running!");
			break;
		case 8:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "RAM");
			displayLCDCenteredString(1, "is running!");
			break;
		case 9:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "DO NOTHING");
			displayLCDCenteredString(1, "is running!");
			break;
		}
	}
}
