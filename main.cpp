#include "stdafx.h"



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

// X axis rotation matrix
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
        mrX[1][2] = (-1.f)*(sin(radians));
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

Matrix4f MatRotXFUN(MatRotX &m) 
{
    Matrix4f matrix;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            matrix.m[i][j] = m.mrX[i][j];
        }
    }
    return matrix;
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

Matrix4f MatRotYFUN(MatRotY& m)
{
    Matrix4f matrix;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            matrix.m[i][j] = m.mrY[i][j];
        }
    }
    return matrix;
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
        circle.setScale(window.getSize().x / 200.f - (window.getSize().x / 200.f) * i * (1 / precision) + 0.8f, window.getSize().y / 200.f - (window.getSize().y / 200.f) * i * (1 / precision) + 0.6f); // Szerokość 50%, wysokość 100% window.getSize().y/ 10.f
        circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Ustawiamy pozycję koła
        circle.setFillColor(sf::Color(R, G, B, 255 * visibility - 255 * blur_diff * i)); // Ustawiamy kolor wypełnienia koła
        vector.push_back(circle);
    }
}

//Function for Multiplying Vectors by Matrix
Vector3f MatxVec(Matrix4f& m, Vector3f& i)
{
    Vector3f v;
    v.x = i.x * m.m[0][0] + i.y * m.m[0][1] + i.z * m.m[0][2] + i.w * m.m[0][3];
    v.y = i.x * m.m[1][0] + i.y * m.m[1][1] + i.z * m.m[1][2] + i.w * m.m[1][3];
    v.z = i.x * m.m[2][0] + i.y * m.m[2][1] + i.z * m.m[2][2] + i.w * m.m[2][3];
    v.w = i.x * m.m[3][0] + i.y * m.m[3][1] + i.z * m.m[3][2] + i.w * m.m[3][3];
    return v;
}

Matrix4f MatxMat(Matrix4f& m1, Matrix4f& m2)
{
    Matrix4f matrix;
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++)
            matrix.m[c][r] = m1.m[0][r] * m2.m[c][0] + m1.m[1][r] * m2.m[c][1] + m1.m[2][r] * m2.m[c][2] + m1.m[3][r] * m2.m[c][3];
    return matrix;
}

void TransByVector(Matrix4f& m, Vector3f& v)
{
    m.m[0][3] += v.x;
    m.m[1][3] += v.y;
    m.m[2][3] += v.z;
}

Vector3f VecPLUSvec(Vector3f& v1, Vector3f& v2)
{
    Vector3f new_vector;
    new_vector.x = v1.x + v2.x;
    new_vector.y = v1.y + v2.y;
    new_vector.z = v1.z + v2.z;
    return new_vector;
}

void UPDATE(Matrix4f& matrix, std::vector<Vector3f>& points, Vector3f& translacja, std::vector<sf::VertexArray>& BOX)
{
    //-------------------------------------------
    MatRotX rotX(0.25f);
    Matrix4f matX = MatRotXFUN(rotX);

    MatRotY rotY(0.25f);
    Matrix4f matY = MatRotYFUN(rotY);

    matrix = MatxMat(matrix, matX);
    matrix = MatxMat(matrix, matY);

    std::vector < sf::Vector2f> New_Points_pos;

    // reeorienting box's points possition
    for (int i = 0; i < 12; ++i) 
    {

        Vector3f point_camera_space = MatxVec(matrix, points[i]);

        point_camera_space = VecPLUSvec(point_camera_space, translacja);

        //std::cout << "Wspolrzedne punktow 3D po rzucie na plaszczyzne 2D: (" << point_camera_space.x << ", " << point_camera_space.y << ")" << std::endl;
        New_Points_pos.push_back(sf::Vector2f(point_camera_space.x, point_camera_space.y));
    }

    // define the position of box points
    for (int i = 0; i < 3; ++i)
    {
        sf::VertexArray box(sf::Quads, 4);
        for (int j = 0; j < 4; j++)
        {
            box[j].position = New_Points_pos[j];
            box[j].color = sf::Color(150 * i + 50, 200 * i + 50, 200 * i + 50);
        }
        New_Points_pos.erase(New_Points_pos.begin(), New_Points_pos.begin() + 4);
        BOX.push_back(box);
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // Background
    std::vector<sf::CircleShape> blur;
    Blur(blur, window, 100, 110, 110, 110, 0.04);

    Vector3f translacja(400.f, 300.f, 0.0f);

    std::vector<Vector3f> points = {
        Vector3f(-25, -25, 25),
        Vector3f(25, -25, 25),
        Vector3f(25, 25, 25),
        Vector3f(-25, 25, 25),

        Vector3f(-25, -25, -25),
        Vector3f(25, -25, -25),
        Vector3f(25, 25, -25),
        Vector3f(-25, 25, -25),

        Vector3f(-25, -25, 25),
        Vector3f(25, -25, 25),
        Vector3f(25, -25, -25),
        Vector3f(-25, -25, -25)
    };

    // Utworzenie nowej macierzy 4x4
    Matrix4f matrix;

    // Create BOX
    std::vector<sf::VertexArray> BOX;

    // Wypełnienie macierzy ręcznie
    matrix.m[0][0] = 1.0f;
    matrix.m[0][1] = 0.0f;
    matrix.m[0][2] = 0.0f;
    matrix.m[0][3] = 0.0f;

    matrix.m[1][0] = 0.0f;
    matrix.m[1][1] = 1.0f;
    matrix.m[1][2] = 0.0f;
    matrix.m[1][3] = 0.0f;

    matrix.m[2][0] = 0.0f;
    matrix.m[2][1] = 0.0f;
    matrix.m[2][2] = 1.0f;
    matrix.m[2][3] = 0.0f;

    matrix.m[3][0] = 0.0f;
    matrix.m[3][1] = 0.0f;
    matrix.m[3][2] = 0.0f;
    matrix.m[3][3] = 1.0f;

    
    bool pawel = true;
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

        UPDATE(matrix, points, translacja, BOX);
        for (size_t i = 0; i < BOX.size(); ++i)
        {
            window.draw(BOX[i]);
        }
        BOX.clear();
        // end the current frame
        window.display();
    }

    return 0;
}