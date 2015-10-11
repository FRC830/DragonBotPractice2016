#include "WPILib.h"

#include "../utils/830utilities.h"

class Robot: public IterativeRobot
{
private:
	static const int EYE_PWM = 0;
	static const int FRONT_LEFT_PWM = 1;
	static const int FRONT_RIGHT_PWM = 2;
	static const int BACK_LEFT_PWM = 3;
	static const int BACK_RIGHT_PWM = 4;
	static const int SMOKE_CANNON_PWM = 5;
	static const int JAW_MOTOR_PWM = 6;
	static const int HEAD_MOTOR_PWM = 7;
	static const int WING_FLAP_PWM = 8;
	static const int WING_FOLD_PWM = 9;

	RobotDrive *drive;
	GamepadF310 *pilot;
	GamepadF310 *copilot;
	DigitalOutput *sounds[10];
	void RobotInit()
	{

		pilot = new GamepadF310(0);

		copilot = new GamepadF310(1);

		drive = new RobotDrive(
			new Victor(FRONT_LEFT_PWM),
			new Victor(BACK_LEFT_PWM),
			new Victor(FRONT_RIGHT_PWM),
			new Victor(BACK_RIGHT_PWM)
		);
		drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		for (int i = 0; i < 10; i++)
			sounds[i]= new DigitalOutput(i);
	}


	void PlaySound (int id) {
		for (int i = 0; i < 10; i++)
			sounds[i]->Set(i != id);
	}
	void StopSound () {
		for (int i = 0; i < 10; i++)
			sounds[i]->Set(1);
	}

	void DisabledInit(){
		StopSound();
	}
	void DisabledPeriodic(){}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		PlaySound(1);
		if(pilot ->DPadX()==1){
			PlaySound(8);
		}
		else {
			StopSound();
		}
		float speed=3;
		if(pilot->ButtonState(F310Buttons::LeftStick))
			speed=1.25;
		drive->MecanumDrive_Cartesian(
				pilot->LeftX()/speed,
				-pilot->LeftY()/speed,
				pilot->RightX()/speed

		);
	}

};

START_ROBOT_CLASS(Robot);
