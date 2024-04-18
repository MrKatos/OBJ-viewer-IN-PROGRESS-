#pragma once
#include "Vec4.h"

class Mat4
{
private:
	float matrix[4][4] = { 0 };
public:
	Mat4();
	Mat4(MatrixType type);
	Mat4(MatrixType type, float angle);

	void Clear();
	void MatMultiply(Mat4& m1);
	void TransByVector(Vec4& v);

	Mat4 operator*(const Mat4& other) const;
	Vec4 operator*(Vec4& vector) const;
	//friend Vec4 operator*(Vec4& vector);
	friend std::ostream& operator<<(std::ostream& os, const Mat4& mat);
};

