#ifndef CAMERA_SETUP_H
#define CAMERA_SETUP_H

#pragma once
#include <WebServer.h>

extern WebServer server;

bool initCamera();
void startCameraServer();

#endif