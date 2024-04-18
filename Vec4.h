#pragma once
class Vec4
{
private:
	float x = 0, y = 0, z = 0, w = 1;

public:
	Vec4() {};
	Vec4(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {};
	Vec4(Direction d, float value);

	void SetX(float x_);
	void SetY(float y_);
	void SetZ(float z_);
	void SetW(float w_);

	float GetX();
	float GetY();
	float GetZ();
	float GetW();

	bool IsZEROS();

	Vec4 operator+(const Vec4& other) const;
	Vec4 operator*(float scalar) const;
	friend std::ostream& operator<<(std::ostream& os, const Vec4& vec);
};

