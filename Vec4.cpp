#include "stdafx.h"
#include "Vec4.h"

Vec4::Vec4(Direction d, float value)
{
	switch (d)
	{
	case X:
		this->x = value;
		break;
	case Y:
		this->y = value;
		break;
	case Z:
		this->z = value;
		break;
	default:
		std::cout << "bledny kierunek" << std::endl;
		break;
	}
}

void Vec4::SetX(float x_)
{
	this->x = x_;
}

void Vec4::SetY(float y_)
{
	this->y = y_;
}

void Vec4::SetZ(float z_)
{
	this->z = z_;
}

void Vec4::SetW(float w_)
{
	this->w = w_;
}

float Vec4::GetX()
{
	return this->x;
}

float Vec4::GetY()
{
	return this->y;
}

float Vec4::GetZ()
{
	return this->z;
}

float Vec4::GetW()
{
	return this->w;
}

bool Vec4::IsZEROS()
{
	if (this->x == 0.f && this->y == 0.f && this->z == 0.f)
	{
		return true;
	}
	return false;
}

Vec4 Vec4::operator+(const Vec4& other) const
{
	return Vec4(x + other.x, y + other.y, z + other.z);
}

Vec4 Vec4::operator*(float scalar) const
{
	return Vec4(x * scalar, y * scalar, z * scalar);
}

std::ostream& operator<<(std::ostream& os, const Vec4& vec)
{
	os << "[" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "]";
	return os;
}
