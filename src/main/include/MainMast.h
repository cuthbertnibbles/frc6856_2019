/**
 * Control of the main mast system
 */

#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motion/TrajectoryPoint.h>
#include "Pneumatics.h"


class MainMast
{
    public:
    MainMast();
    ~MainMast();

    void MainMastInit();

    //Lowers the mast until it hits the lower limit switch
    void MastHome();

    void flightStage(int stage);

    void MastTestInit();

    void MastTest(double targotPos);

    void MastManualControl(double targetPower);

    void updateLimitSwitches();

    void goToSwitch(int switchNo);

    void brakeMast();

    void coastMast();

    void nukeControllers();

    bool getLimitSwitch(int limIndex);

    int getLimitSwitch();

    private:
    //Mast Motor Controller
    TalonSRX* m_pMainMastMotor;
    TalonSRX* m_pMainMastMotorSlave;

    //Mast Homing/Limit Switches
    frc::DigitalInput* m_pLimitSwitchObjects[10];

    //Pneumatic Brake for Mast
    PneumaticActuator* m_pBrakePneumatic;

    //PWM Pin for Servo Brake
    frc::PWM* m_pBrakeServo;

    //Mast Limit Switch states
    bool m_pLimitSwitchState[10];

    /**
     * Track which stage of a mast flight maneuver the robot is in
     * 0 = HALT/E-STOP (motor coast/rest, brake off)
     * 1 = HOLD (motor coast, brake on)
     * 2 = CRUISE (motor 100% up, brake on)
     * 3 = FLYOVER (target limit switch is pressed but motor is not disabled)
     * 4 = APPROACH (target limit has been released, motor power is reversed and reduced)
     * 5 = LOCK (On target, set state 1)
     * 6 = FLYUNDER (overshot target, motor )
     */
    int m_pFlightStage;

};