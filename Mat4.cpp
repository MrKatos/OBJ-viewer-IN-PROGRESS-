#include "stdafx.h"
#include "Mat4.h"

Mat4::Mat4()
{
    this->matrix[0][0] = 1.0f;
    this->matrix[0][1] = 0.0f;
    this->matrix[0][2] = 0.0f;
    this->matrix[0][3] = 0.0f;

    this->matrix[1][0] = 0.0f;
    this->matrix[1][1] = 1.0f;
    this->matrix[1][3] = 0.0f;
    this->matrix[1][2] = 0.0f;

    this->matrix[2][0] = 0.0f;
    this->matrix[2][1] = 0.0f;
    this->matrix[2][2] = 1.0f;
    this->matrix[2][3] = 0.0f;

    this->matrix[3][0] = 0.0f;
    this->matrix[3][1] = 0.0f;
    this->matrix[3][2] = 0.0f;
    this->matrix[3][3] = 1.0f;
}

Mat4::Mat4(MatrixType type)
{
    float radians = 0; // Deg to Rad
    switch (type)
    {
    case RotX:
        this->matrix[0][0] = 1.0f;
        this->matrix[0][1] = 0.0f;
        this->matrix[0][2] = 0.0f;
        this->matrix[0][3] = 0.0f;

        this->matrix[1][0] = 0.0f;
        this->matrix[1][1] = cos(radians);
        this->matrix[1][2] = (-1.f) * (sin(radians));
        this->matrix[1][3] = 0.0f;

        this->matrix[2][0] = 0.0f;
        this->matrix[2][1] = sin(radians);
        this->matrix[2][2] = cos(radians);
        this->matrix[2][3] = 0.0f;

        this->matrix[3][0] = 0.0f;
        this->matrix[3][1] = 0.0f;
        this->matrix[3][2] = 0.0f;
        this->matrix[3][3] = 1.0f;
        break;

    case RotY:
        this->matrix[0][0] = cos(radians);
        this->matrix[0][1] = 0.0f;
        this->matrix[0][2] = sin(radians);
        this->matrix[0][3] = 0.0f;

        this->matrix[1][0] = 0.0f;
        this->matrix[1][1] = 1.0f;
        this->matrix[1][2] = 0.0f;
        this->matrix[1][3] = 0.0f;

        this->matrix[2][0] = (-1.0f) * (sin(radians));
        this->matrix[2][1] = 0.0f;
        this->matrix[2][2] = cos(radians);
        this->matrix[2][3] = 0.0f;

        this->matrix[3][0] = 0.0f;
        this->matrix[3][1] = 0.0f;
        this->matrix[3][2] = 0.0f;
        this->matrix[3][3] = 1.0f;
        break;

    case RotZ:
        this->matrix[0][0] = cos(radians);
        this->matrix[0][1] = (-1.0f) * (sin(radians));
        this->matrix[0][2] = 0.0f;
        this->matrix[0][3] = 0.0f;

        this->matrix[1][0] = (sin(radians));
        this->matrix[1][1] = cos(radians);
        this->matrix[1][2] = 0.0f;
        this->matrix[1][3] = 0.0f;

        this->matrix[2][0] = 0.0f;
        this->matrix[2][1] = 0.0f;
        this->matrix[2][2] = 1.0f;
        this->matrix[2][3] = 0.0f;

        this->matrix[3][0] = 0.0f;
        this->matrix[3][1] = 0.0f;
        this->matrix[3][2] = 0.0f;
        this->matrix[3][3] = 1.0f;
        break;

    default:
        std::cout << "Bledny typ macierzy" << std::endl;
        break;
    }
}

Mat4::Mat4(MatrixType type, float angle)
{
    float radians = angle * M_PI / 180.0; // Deg to Rad
    switch (type)
    {
    case RotX:
        this->matrix[0][0] = 1.0f;
        this->matrix[0][1] = 0.0f;
        this->matrix[0][2] = 0.0f;
        this->matrix[0][3] = 0.0f;

        this->matrix[1][0] = 0.0f;
        this->matrix[1][1] = cos(radians);
        this->matrix[1][2] = (-1.f) * (sin(radians));
        this->matrix[1][3] = 0.0f;

        this->matrix[2][0] = 0.0f;
        this->matrix[2][1] = sin(radians);
        this->matrix[2][2] = cos(radians);
        this->matrix[2][3] = 0.0f;

        this->matrix[3][0] = 0.0f;
        this->matrix[3][1] = 0.0f;
        this->matrix[3][2] = 0.0f;
        this->matrix[3][3] = 1.0f;
        break;

    case RotY:
        this->matrix[0][0] = cos(radians);
        this->matrix[0][1] = 0.0f;
        this->matrix[0][2] = sin(radians);
        this->matrix[0][3] = 0.0f;

        this->matrix[1][0] = 0.0f;
        this->matrix[1][1] = 1.0f;
        this->matrix[1][2] = 0.0f;
        this->matrix[1][3] = 0.0f;

        this->matrix[2][0] = (-1.0f) * (sin(radians));
        this->matrix[2][1] = 0.0f;
        this->matrix[2][2] = cos(radians);
        this->matrix[2][3] = 0.0f;

        this->matrix[3][0] = 0.0f;
        this->matrix[3][1] = 0.0f;
        this->matrix[3][2] = 0.0f;
        this->matrix[3][3] = 1.0f;
        break;

    case RotZ:
        this->matrix[0][0] = cos(radians);
        this->matrix[0][1] = (-1.0f) * (sin(radians));
        this->matrix[0][2] = 0.0f;
        this->matrix[0][3] = 0.0f;

        this->matrix[1][0] = (sin(radians));
        this->matrix[1][1] = cos(radians);
        this->matrix[1][2] = 0.0f;
        this->matrix[1][3] = 0.0f;

        this->matrix[2][0] = 0.0f;
        this->matrix[2][1] = 0.0f;
        this->matrix[2][2] = 1.0f;
        this->matrix[2][3] = 0.0f;

        this->matrix[3][0] = 0.0f;
        this->matrix[3][1] = 0.0f;
        this->matrix[3][2] = 0.0f;
        this->matrix[3][3] = 1.0f;
        break;

    default:
        std::cout << "Bledny typ macierzy" << std::endl;
        break;
    }
}

// FUNCTIONS

void Mat4::Clear()
{
    this->matrix[0][0] = 1.0f;
    this->matrix[0][1] = 0.0f;
    this->matrix[0][2] = 0.0f;
    this->matrix[0][3] = 0.0f;

    this->matrix[1][0] = 0.0f;
    this->matrix[1][1] = 1.0f;
    this->matrix[1][3] = 0.0f;
    this->matrix[1][2] = 0.0f;

    this->matrix[2][0] = 0.0f;
    this->matrix[2][1] = 0.0f;
    this->matrix[2][2] = 1.0f;
    this->matrix[2][3] = 0.0f;

    this->matrix[3][0] = 0.0f;
    this->matrix[3][1] = 0.0f;
    this->matrix[3][2] = 0.0f;
    this->matrix[3][3] = 1.0f;
}

void Mat4::MatMultiply(Mat4& m2)
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.matrix[i][j] = this->matrix[0][j] * m2.matrix[i][0] + this->matrix[1][j] * m2.matrix[i][1] + this->matrix[2][j] * m2.matrix[i][2] + this->matrix[3][j] * m2.matrix[i][3];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            this->matrix[i][j] = result.matrix[i][j];
}

void Mat4::TransByVector(Vec4& v)
{
    this->matrix[0][3] += v.GetX();
    this->matrix[1][3] += v.GetY();
    this->matrix[2][3] += v.GetZ();
}

Mat4 Mat4::operator*(const Mat4& other) const
{
    Mat4 m;
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++)
            m.matrix[c][r] = this->matrix[0][r] * other.matrix[c][0] + this->matrix[1][r] * other.matrix[c][1] + this->matrix[2][r] * other.matrix[c][2] + this->matrix[3][r] * other.matrix[c][3];
    return m;
}

Vec4 Mat4::operator*(Vec4& vector) const
{
    Vec4 v;
    v.SetX(vector.GetX() * this->matrix[0][0] + vector.GetY() * this->matrix[0][1] + vector.GetZ() * this->matrix[0][2] + vector.GetW() * this->matrix[0][3]);
    v.SetY(vector.GetX() * this->matrix[1][0] + vector.GetY() * this->matrix[1][1] + vector.GetZ() * this->matrix[1][2] + vector.GetW() * this->matrix[1][3]);
    v.SetZ(vector.GetX() * this->matrix[2][0] + vector.GetY() * this->matrix[2][1] + vector.GetZ() * this->matrix[2][2] + vector.GetW() * this->matrix[2][3]);
    v.SetW(vector.GetX() * this->matrix[3][0] + vector.GetY() * this->matrix[3][1] + vector.GetZ() * this->matrix[3][2] + vector.GetW() * this->matrix[3][3]);
    return v;
}

std::ostream& operator<<(std::ostream& os, const Mat4& mat)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            os << mat.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
