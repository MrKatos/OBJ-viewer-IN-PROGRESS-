#include "stdafx.h"

void Blur(std::vector<sf::CircleShape>& vector, sf::RenderWindow& window, float precision, int R, int G, int B, float visibility)
{
    if (precision > 100)
    {
        precision = 100;
    }
    else if (precision < 0)
    {
        precision = 1;
    }

    if (visibility > 1)
    {
        visibility = 1;
    }
    else if (visibility < 0)
    {
        visibility = 0;
    }

    float blur_diff = visibility / precision;
    for (float i = 0; i < precision; ++i)
    {
        // Tworzymy kształt koła
        sf::CircleShape circle;
        circle.setRadius(100.f); // Ustawiamy promień koła
        circle.setOrigin(sf::Vector2f(100.f, 100.f));
        circle.setScale(window.getSize().x/200.f - (window.getSize().x / 200.f)*i*(1/precision) + 0.8f, window.getSize().y / 200.f - (window.getSize().y / 200.f) * i * (1 / precision) + 0.6f); // Szerokość 50%, wysokość 100% window.getSize().y/ 10.f
        circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Ustawiamy pozycję koła
        circle.setFillColor(sf::Color(R, G, B, 255*visibility - 255*blur_diff*i)); // Ustawiamy kolor wypełnienia koła
        vector.push_back(circle);
    }   
}


struct Vector3f
{
    float x = 0, y = 0, z = 0, w = 1;
    Vector3f(float x_, float y_, float z_) : x(x_), y(y_), z(z_){}
    Vector3f(){}
};

struct Matrix4f
{
    float m[4][4] = { 0 };
};

//Function for Multiplying Vectors by Matrix
Vector3f MatxVec(Matrix4f& m, Vector3f& i)
{
    Vector3f v;
    v.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + i.w * m.m[3][0];
    v.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + i.w * m.m[3][1];
    v.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + i.w * m.m[3][2];
    v.w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + i.w * m.m[3][3];
    return v;
}

Matrix4f MatrixMultiply(Matrix4f& m1, Matrix4f& m2)
{
    Matrix4f matrix;
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++)
            matrix.m[r][c] = m1.m[r][0] * m2.m[0][c] + m1.m[r][1] * m2.m[1][c] + m1.m[r][2] * m2.m[2][c] + m1.m[r][3] * m2.m[3][c];
    return matrix;
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    std::vector<Vector3f> points = {
        Vector3f(10, 0, 100),
        Vector3f(60, 0, 100),
        Vector3f(60, 50, 100),
        Vector3f(10, 50, 100)
    };

    Vector3f vector1(10, 0, 100);

    // Utworzenie nowej macierzy 4x4
    Matrix4f matrix;

    // Wypełnienie macierzy ręcznie
    matrix.m[0][0] = 1.0f;
    matrix.m[0][1] = 0.0f;
    matrix.m[0][2] = 0.0f;
    matrix.m[0][3] = 15.0f;

    matrix.m[1][0] = 0.0f;
    matrix.m[1][1] = 1.0f;
    matrix.m[1][2] = 0.0f;
    matrix.m[1][3] = 5.0f;

    matrix.m[2][0] = 0.0f;
    matrix.m[2][1] = 0.0f;
    matrix.m[2][2] = 1.0f;
    matrix.m[2][3] = 7.0f;

    matrix.m[3][0] = 0.0f;
    matrix.m[3][1] = 0.0f;
    matrix.m[3][2] = 0.0f;
    matrix.m[3][3] = 1.0f;

    std::cout << "Elementy macierzy:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matrix.m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector < sf::Vector2f> New_Points_pos;

    // Przetworzenie każdego punktu
    for (int i = 0; i < 4; ++i) {
        // Przetransformuj punkt do układu kamerys
        Vector3f point_camera_space = MatxVec(matrix, points[i]);

        // Rzut punktu na płaszczyznę 2D (rzutowanie perspektywiczne)
        // W tym miejscu należy zastosować odpowiednie równania rzutowania

        // W wyniku otrzymujemy współrzędne punktu na płaszczyźnie 2D
        std::cout << "Wspolrzędne punktow 3D po rzucie na płaszczyznę 2D: (" << point_camera_space.x << ", " << point_camera_space.y << ")" << std::endl;
        New_Points_pos.push_back(sf::Vector2f(point_camera_space.x, point_camera_space.y));
    }

    // Background
    std::vector<sf::CircleShape> blur;
    Blur(blur, window, 100, 110, 110, 110, 0.04);

    // Tworzymy kwadrat
    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray a(sf::LineStrip, 5);

    // define the position of the triangle's points
    for (size_t i = 0; i < New_Points_pos.size(); ++i)
    {
        a[i].position = New_Points_pos[i];
    }
    a[4].position = New_Points_pos[0];

    // define the color of the triangle's points
    a[0].color = sf::Color::Red;
    a[1].color = sf::Color::Blue;
    a[2].color = sf::Color::Green;
    a[3].color = sf::Color::Black;
    a[4].color = sf::Color::Cyan;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color(59, 59, 59));

        // draw everything here...
        for (size_t i = 0; i < blur.size(); ++i)
        {
            window.draw(blur[i]);
        }
        window.draw(a);

        // end the current frame
        window.display();
    }

    return 0;
}