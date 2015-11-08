#include "WPILib.h"
#include "stdlib.h"

#include "../utils/830utilities.h"
#include "Wing.h"
#include "Head.h"

class Robot: public IterativeRobot {
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
	static const int NUM_SOUNDS = 8;

	static const int WING_FOLD_PWM = 9;

	static const int EYE_LIGHT_DIO = 8;
	RobotDrive *drive;
	GamepadF310 *pilot;
	GamepadF310 *copilot;
	Head *head;
	Wing * wing;

	DigitalOutput *sounds[NUM_SOUNDS];
	void RobotInit()
	{

		pilot = new GamepadF310(0);

		copilot = new GamepadF310(1);

		head = new Head(
			new Victor (JAW_MOTOR_PWM),
			new Victor (HEAD_MOTOR_PWM),
			new DigitalOutput (EYE_LIGHT_DIO),
			new Servo(EYE_PWM)
		);

		wing = new Wing(
			new Victor(WING_FLAP_PWM),
			new Victor(WING_FOLD_PWM)
		);

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

		head->reset();
	}


	void PlaySound (int id) {
		for (int i = 0; i < NUM_SOUNDS; i++)
			sounds[i]->Set(i != id);
	}
	void StopSound () {
		for (int i = 0; i < NUM_SOUNDS; i++)
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
		wing -> update();
		if(copilot->ButtonState(F310Buttons::Start)){
			wing->extend();
		}
		else if(copilot->ButtonState(F310Buttons::Back)){
			wing->retract();
		}
		wing->flap(copilot->RightTrigger() / 2.0);
		PlaySound(1);
		if(pilot ->DPadX()==1){
			PlaySound(4);
		}
		else if(pilot ->DPadX()==-1){
			PlaySound(1);
		}
		else if(pilot ->DPadY()==1){
			PlaySound(2);
		}
		else if(pilot ->DPadY()==-1){
			PlaySound(3);
		}
		else {
			StopSound();
		}

		head->reset();
		if (copilot->LeftY() == -1.0){
			head->Jaw_down();
		} else if (copilot -> LeftY() == 1.0){
			head->Jaw_up();
		}
		if (copilot->RightY() == 1.0){
			head->Head_up();
		} else if (copilot -> RightY() == -1.0){
			head->Head_down();
		}

		GamepadF310::ButtonEvent e;
		while (copilot->GetButtonEvent(&e)) {
			if (e.button == F310Buttons::B && e.pressed) {
				head->toggle_eyes();
			}
		}

		static int flickerStage = 0;
		static int finalStage = 0;
		flickerStage++;
		if(flickerStage >= finalStage && copilot->ButtonState(F310Buttons::A)){
			head->toggle_eyes();
			flickerStage = 0;
			finalStage = rand() % 10 + 1;
		}

		if(copilot->ButtonState(5)){//left bumper
			head->setEyesPosition(0);
		} else if(copilot->ButtonState(6)){//right bumper
			head->setEyesPosition(1);
		} else{
			head->setEyesPosition(0.5);
		}

		SmartDashboard::PutNumber("LeftY", copilot->LeftY());
		float speed=3;
		if(pilot->ButtonState(F310Buttons::LeftStick))
			speed=1.25;
		drive->MecanumDrive_Cartesian(
				pilot->LeftX()/speed,
				-pilot->LeftY()/speed,
				pilot->RightX()/speed	);
	}

};

START_ROBOT_CLASS(Robot);
