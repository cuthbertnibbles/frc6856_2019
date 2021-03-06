#pragma once
/*

CAMERA PROGRAMMING, INCLUDES INIT, STREAMING, AND SETTING RES

TODO: This code does not use a class and therefore the constructors aren't best practice.
This should be separated into a CameraStream.cpp and CameraStream.h
*/
#include <iostream>
#include <frc/WPILib.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "cscore.h"
#include <sstream>
#include <cameraserver/CameraServer.h>

//INITITATES / CONNECTS THE CAMERAS TO THE RIO, IF NO VALUES ARE SPECIFIED, DEFUALT CONSTRUCOTR WILL BE USED

// namespace botVideo
namespace botVideo
{
//STREAMS THE CAMERA(S) TO THE DRIVER STATION
void StreamBotCameras(int resWidth, int resHeight, int fps)
{
   //instantiaing CS_Core USB camera | MAKE SURE THIS CAMERA IS PLUGGED INTO THE FIRST PORT!
    cs::UsbCamera mainCamera {"frontCamera", 0};
    //setting res
    mainCamera.SetResolution(resWidth, resHeight);
    //setting fps
    mainCamera.SetFPS(fps);
    //streaming camera...hopefully to dashboard
    mainCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
}

//SECOND CONSTRUCTOR | USES DEFAULT VALUES
void StreamBotCameras()
{
    //instantiaing CS_Core USB camera | MAKE SURE THIS CAMERA IS PLUGGED INTO THE FIRST PORT!
    cs::UsbCamera mainCamera {"frontCamera", 0};
    //setting res
    mainCamera.SetResolution(640, 480);
    //setting fps
    mainCamera.SetFPS(15);
    //streaming camera to dashboard. Currently set for dual camera
    mainCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    mainCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
}

} // namespace botVideo
