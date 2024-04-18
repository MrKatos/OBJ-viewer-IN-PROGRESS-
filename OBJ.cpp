#include "stdafx.h"
#include "OBJ.h"
#include "Mat4.h"

OBJ::OBJ(std::string path)
{
    this->bufor.clear();
    std::ifstream file(path);
    // Sprawdzanie, czy uda³o siê otworzyæ plik
    if (!file.is_open())
    {
        std::cerr << "Nie mo¿na otworzyæ pliku!" << std::endl;
    }

    // Czytanie pliku linia po linii
    std::string line;
    while (std::getline(file, line))
    {
        //std::cout << line << std::endl;
        if (line[0] == 'v' && line[1] == 'n')
        {
            std::istringstream iss(line);
            std::string token;
            iss >> token;
            while (iss >> token) {
                try
                {
                    float value = std::stof(token);
                    this->bufor.push_back(value);
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Blad konwersji na float: " << e.what() << std::endl;
                }
            }
            bufor_1.SetX(bufor[0]);
            bufor_1.SetY(bufor[1]);
            bufor_1.SetZ(bufor[2]);
            this->vn.push_back(this->bufor_1);
            this->bufor.clear();
        }
        else if (line[0] == 'v')
        {
            std::istringstream iss(line);
            std::string token;
            iss >> token;
            while (iss >> token) {
                try
                {
                    float value = std::stof(token);
                    this->bufor.push_back(value);
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Blad konwersji na float: " << e.what() << std::endl;
                }
            }
            bufor_1.SetX(bufor[0]);
            bufor_1.SetY(bufor[1]);
            //bufor_1.SetZ(bufor[2]);
            this->v.push_back(bufor_1);
            this->bufor.clear();
        }
        else if (line[0] == 'f')
        {
            std::istringstream iss(line);
            std::string token;
            iss >> token;
            while (iss >> token)
            {
                try 
                {
                    std::string value = token;
                    int v_num = token[0] - '0'; // char to int
                    this->bufor_2.push_back(this->v[v_num - 1]);
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Blad konwersji na float: " << e.what() << std::endl;
                }
            }
            this->f.push_back(this->bufor_2);
            this->bufor_2.clear();
        }
    }
}

void OBJ::SetScale(float sacle)
{
    for (size_t i = 0; i < f.size(); ++i)
    {
        for (size_t j = 0; j < f[i].size(); ++j)
        {
            f[i][j] = f[i][j] * sacle;
        }
    }
}

void OBJ::RotateMesh(MatrixType type, float angle)
{
    Mat4 mat(type, angle);
    for (size_t i = 0; i < f.size(); ++i)
    {
        for (size_t j = 0; j < 3; ++j)
        {
            f[i][j] = mat * f[i][j];
        }
    }
    this->CreateMesh();
}

void OBJ::MoveMesh(Direction d, float value)
{
    Vec4 v(d, value);
    this->translation = this->translation + v;
    this->CreateMesh();
}

void OBJ::CreateMesh()
{
    std::vector<std::vector<Vec4>> f_copy = f;
    this->mesh.clear();
    if (!this->translation.IsZEROS())
    {
        for (size_t i = 0; i < f_copy.size(); ++i)
        {
            for (size_t j = 0; j < f_copy[i].size(); ++j)
            {
                f_copy[i][j] = f_copy[i][j] + this->translation;
            }
        }
    }
    for (int i = 0; i < f_copy.size(); ++i)
    {
        float sum = 0.0f;
        for (size_t j = 0; j < f_copy[i].size(); ++j)
        {
            sum += f_copy[i][j].GetZ();
        }
        float avr = sum / 3.f;
        
        for (size_t j = 0; j < f_copy[i].size(); ++j)
        {
            f_copy[i][j].SetZ(avr);
        }
    }
    for (size_t i = 0; i < f_copy.size() - 1; ++i)
    {
        for (size_t j = 0; j < f_copy.size() - i - 1; ++j)
        {
            if (f_copy[j][0].GetW() > f_copy[j + 1][0].GetW())
            {
                std::vector<Vec4> temp = f_copy[j];

                f_copy[j] = f_copy[j + 1];

                f_copy[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < f_copy.size(); ++i)
    {
        sf::VertexArray box(sf::Triangles, 4);
        box[0].color = sf::Color::Red;
        box[1].color = sf::Color::Green;
        box[2].color = sf::Color::Blue;

        for (int j = 0; j < f_copy[i].size(); ++j)
        {
            box[j].position = sf::Vector2f(f_copy[i][j].GetX(), f_copy[i][j].GetY());
        }
        this->mesh.push_back(box);
    }
    for (size_t i = 0; i < f_copy.size(); ++i)
    {
        for (size_t j = 0; j < f_copy[i].size(); ++j)
        {
            f_copy[i][j].SetW(1.f);
        }
    }
}

float OBJ::GetMeshSize()
{
    return mesh.size();
}

std::vector<sf::VertexArray> OBJ::GetMesh()
{
    return this->mesh;
}

