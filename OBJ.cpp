#include "stdafx.h"
#include "OBJ.h"

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
            this->vn.push_back(this->bufor);
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
            this->v.push_back(this->bufor);
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
    for (const auto& vec1 : f) {
        for (const auto& vec2 : vec1) {
            for (float value : vec2) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
