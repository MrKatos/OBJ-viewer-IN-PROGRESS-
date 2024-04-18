#pragma once
#include "Mat4.h"
#include "Vec4.h"

class OBJ
{
private:
	
	float scale = 1.f;
	Vec4 translation;

	std::vector<float> bufor;
	Vec4 bufor_1;
	std::vector<Vec4> bufor_2;

	std::vector<Vec4> v;
	std::vector<Vec4> vn;

	std::vector<std::vector<Vec4>> f;
	std::vector<sf::VertexArray> mesh;
public:
	OBJ(std::string path);
	void SetScale(float sacle);
	void RotateMesh(MatrixType type, float angle);
	void MoveMesh(Direction d, float value);
	void CreateMesh();
	float GetMeshSize();
	std::vector<sf::VertexArray> GetMesh();
};

