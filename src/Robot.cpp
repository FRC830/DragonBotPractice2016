#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
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

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
	}

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

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
