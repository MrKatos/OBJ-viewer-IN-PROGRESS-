//#include <cstdlib>
//#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
//#include <time.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include<math.h>
#include <vector>
#include <string>
#include <algorithm>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Dwmapi.h> //Umo¿liwia stworzenie przezroczystego marginesu 
#pragma comment (lib, "Dwmapi.lib")

struct Vector3f
{
    float x = 0, y = 0, z = 0, w = 1;
    Vector3f(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    Vector3f() {}
};
struct Matrix4f
{
    float m[4][4] = { 0 };
};

struct MatRotX
{
    float mrX[4][4] = { 0 };
    float fi = 0;
    MatRotX(float fi_) : fi(fi_)
    {
        float radians = fi * M_PI / 180.0; // Deg to Rad
        mrX[0][0] = 1.0f;
        mrX[0][1] = 0.0f;
        mrX[0][2] = 0.0f;
        mrX[0][3] = 0.0f;

        mrX[1][0] = 0.0f;
        mrX[1][1] = cos(radians);
        mrX[1][2] = (-1.f) * (sin(radians));
        mrX[1][3] = 0.0f;

        mrX[2][0] = 0.0f;
        mrX[2][1] = sin(radians);
        mrX[2][2] = cos(radians);
        mrX[2][3] = 0.0f;

        mrX[3][0] = 0.0f;
        mrX[3][1] = 0.0f;
        mrX[3][2] = 0.0f;
        mrX[3][3] = 1.0f;
    }
    MatRotX()
    {
        float radians = fi * M_PI / 180.0; // Deg to Rad
        mrX[0][0] = 1.0f;
        mrX[0][1] = 0.0f;
        mrX[0][2] = 0.0f;
        mrX[0][3] = 0.0f;

        mrX[1][0] = 0.0f;
        mrX[1][1] = cos(radians);
        mrX[1][2] = (-1.f) * (sin(radians));
        mrX[1][3] = 0.0f;

        mrX[2][0] = 0.0f;
        mrX[2][1] = sin(radians);
        mrX[2][2] = cos(radians);
        mrX[2][3] = 0.0f;

        mrX[3][0] = 0.0f;
        mrX[3][1] = 0.0f;
        mrX[3][2] = 0.0f;
        mrX[3][3] = 1.0f;
    }
};
struct MatRotY
{
    float mrY[4][4] = { 0 };
    float fi = 0;
    MatRotY(float fi_) : fi(fi_)
    {
        float radians = fi * M_PI / 180.0; // Deg to Rad
        mrY[0][0] = cos(radians);
        mrY[0][1] = 0.0f;
        mrY[0][2] = sin(radians);
        mrY[0][3] = 0.0f;

        mrY[1][0] = 0.0f;
        mrY[1][1] = 1.0f;
        mrY[1][2] = 0.0f;
        mrY[1][3] = 0.0f;

        mrY[2][0] = (-1.0f) * (sin(radians));
        mrY[2][1] = 0.0f;
        mrY[2][2] = cos(radians);
        mrY[2][3] = 0.0f;

        mrY[3][0] = 0.0f;
        mrY[3][1] = 0.0f;
        mrY[3][2] = 0.0f;
        mrY[3][3] = 1.0f;
    }
    MatRotY()
    {
        float radians = fi * M_PI / 180.0; // Deg to Rad
        mrY[0][0] = cos(radians);
        mrY[0][1] = 0.0f;
        mrY[0][2] = sin(radians);
        mrY[0][3] = 0.0f;

        mrY[1][0] = 0.0f;
        mrY[1][1] = 1.0f;
        mrY[1][2] = 0.0f;
        mrY[1][3] = 0.0f;

        mrY[2][0] = (-1.0f) * (sin(radians));
        mrY[2][1] = 0.0f;
        mrY[2][2] = cos(radians);
        mrY[2][3] = 0.0f;

        mrY[3][0] = 0.0f;
        mrY[3][1] = 0.0f;
        mrY[3][2] = 0.0f;
        mrY[3][3] = 1.0f;
    }
};
struct MatRotZ
{
    float mrZ[4][4] = { 0 };
    float fi = 0;
    MatRotZ(float fi_) : fi(fi_)
    {
        float radians = fi * M_PI / 180.0; // Deg to Rad
        mrZ[0][0] = cos(radians);
        mrZ[0][1] = (-1.0f) * (sin(radians));
        mrZ[0][2] = 0.0f;
        mrZ[0][3] = 0.0f;

        mrZ[1][0] = (sin(radians));
        mrZ[1][1] = cos(radians);
        mrZ[1][2] = 0.0f;
        mrZ[1][3] = 0.0f;

        mrZ[2][0] = 0.0f;
        mrZ[2][1] = 0.0f;
        mrZ[2][2] = 1.0f;
        mrZ[2][3] = 0.0f;

        mrZ[3][0] = 0.0f;
        mrZ[3][1] = 0.0f;
        mrZ[3][2] = 0.0f;
        mrZ[3][3] = 1.0f;
    }
    MatRotZ()
    {
        float radians = fi * M_PI / 180.0; // Deg to Rad
        mrZ[0][0] = cos(radians);
        mrZ[0][1] = (-1.0f) * (sin(radians));
        mrZ[0][2] = 0.0f;
        mrZ[0][3] = 0.0f;

        mrZ[1][0] = (sin(radians));
        mrZ[1][1] = cos(radians);
        mrZ[1][2] = 0.0f;
        mrZ[1][3] = 0.0f;

        mrZ[2][0] = 0.0f;
        mrZ[2][1] = 0.0f;
        mrZ[2][2] = 1.0f;
        mrZ[2][3] = 0.0f;

        mrZ[3][0] = 0.0f;
        mrZ[3][1] = 0.0f;
        mrZ[3][2] = 0.0f;
        mrZ[3][3] = 1.0f;
    }
};

enum MatrixType {RotX, RotY, RotZ};
enum Direction { X, Y, Z };
//namespace DIR
//{
//	enum Direction { LEFT, RIGHT, UP, DOWN, STOP };
//}
//
//namespace DEAD
//{
//	enum Dead_Reason { WALL, TAIL, UNKNOWN };
//}
