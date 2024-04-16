#pragma once

class OBJ
{
private:
	std::vector<float> bufor;
	std::vector<std::vector<float>> bufor_2;

	std::vector<std::vector<float>> v;
	std::vector<std::vector<float>> vn;
	std::vector<std::vector<std::vector<float>>> f;
public:
	OBJ(std::string path);
};

