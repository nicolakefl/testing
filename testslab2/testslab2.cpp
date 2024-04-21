#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
# define M_PI 3.14159265358979323846

using namespace std;

double rectangleArea(double length, double width) {
    return length * width;
}

double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

double circleArea(double radius) {
    return M_PI * radius * radius;
}

double rectangularPrismVolume(double length, double width, double height) {
    return length * width * height;
}

double pyramidVolume(double baseArea, double height) {
    return (1.0 / 3) * baseArea * height;
}

double sphereVolume(double radius) {
    return (4.0 / 3) * M_PI * pow(radius, 3);
}

double cubeSurfaceArea(double side) {
    return 6 * side * side;
}

double prismSurfaceArea(double side, double height) {
    return 4 * side * height;
}

double cylinderSurfaceArea(double radius, double height) {
    return 2 * M_PI * radius * (radius + height);
}

double cylinderVolume(double radius, double height) {
    return M_PI * radius * radius * height;
}

// Unit tests

TEST(RectangleAreaTest, PositiveValues) {
    EXPECT_EQ(0, rectangleArea(0, 3.0));
    EXPECT_EQ(12.0, rectangleArea(4.0, 3.0));
}

TEST(TriangleAreaTest, PositiveValues) {
    EXPECT_EQ(6.0, triangleArea(4.0, 3.0));
    EXPECT_EQ(0, triangleArea(4.0, 0));
}

TEST(CircleAreaTest, PositiveValues) {
    EXPECT_DOUBLE_EQ(12.566370614359172, circleArea(2.0));
    EXPECT_DOUBLE_EQ(0, circleArea(0));
}

TEST(RectangularPrismVolumeTest, PositiveValues) {
    EXPECT_EQ(24.0, rectangularPrismVolume(4.0, 3.0, 2.0));
    EXPECT_EQ(0, rectangularPrismVolume(4.0, 0, 2.0));
}

TEST(PyramidVolumeTest, PositiveValues) {
    EXPECT_EQ(4, pyramidVolume(6.0, 2.0));
    EXPECT_EQ(0, pyramidVolume(0, 2.0));
}

TEST(SphereVolumeTest, PositiveValues) {
    EXPECT_DOUBLE_EQ(33.510321638291124, sphereVolume(2.0));
    EXPECT_DOUBLE_EQ(0, sphereVolume(0));
}

TEST(CubeSurfaceAreaTest, PositiveValues) {
    EXPECT_EQ(0, cubeSurfaceArea(0));
    EXPECT_EQ(54.0, cubeSurfaceArea(3.0));
}

TEST(PrismSurfaceAreaTest, PositiveValues) {
    EXPECT_EQ(0, prismSurfaceArea(3.0, 0));
    EXPECT_EQ(48.0, prismSurfaceArea(3.0, 4.0));
}

TEST(CylinderSurfaceAreaTest, PositiveValues) {
    EXPECT_DOUBLE_EQ(62.831853071795862, cylinderSurfaceArea(2.0, 3.0));
    EXPECT_DOUBLE_EQ(0, cylinderSurfaceArea(0, 3.0));
}

TEST(CylinderVolumeTest, PositiveValues) {
  EXPECT_DOUBLE_EQ(37.69911184307752, cylinderVolume(2.0, 3.0));
  EXPECT_DOUBLE_EQ(0, cylinderVolume(2.0, 0));
}


int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    int choice;
    double length, width, height, radius, baseArea, side;

    cout << "Выберите действие:\n";
    cout << "1. Площадь прямоугольника\n";
    cout << "2. Площадь треугольника\n";
    cout << "3. Площадь круга\n";
    cout << "4. Объем параллелепипеда\n";
    cout << "5. Объем пирамиды\n";
    cout << "6. Объем шара\n";
    cout << "7. Площадь боковой поверхности куба\n";
    cout << "8. Площадь боковой поверхности призмы\n";
    cout << "9. Площадь поверхности цилиндра\n";
    cout << "10. Объем цилиндра\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите длину и ширину прямоугольника: ";
        cin >> length >> width;
        cout << "Площадь прямоугольника: " << rectangleArea(length, width) << endl;
        break;
    case 2:
        cout << "Введите основание и высоту треугольника: ";
        cin >> length >> height;
        cout << "Площадь треугольника: " << triangleArea(length, height) << endl;
        break;
    case 3:
        cout << "Введите радиус круга: ";
        cin >> radius;
        cout << "Площадь круга: " << circleArea(radius) << endl;
        break;
    case 4:
        cout << "Введите длину, ширину и высоту параллелепипеда: ";
        cin >> length >> width >> height;
        cout << "Объем параллелепипеда: " << rectangularPrismVolume(length, width, height) << endl;
        break;
    case 5:
        cout << "Введите площадь основания и высоту пирамиды: ";
        cin >> baseArea >> height;
        cout << "Объем пирамиды: " << pyramidVolume(baseArea, height) << endl;
        break;
    case 6:
        cout << "Введите радиус шара: ";
        cin >> radius;
        cout << "Объем шара: " << sphereVolume(radius) << endl;
        break;
    case 7:
        cout << "Введите длину ребра куба: ";
        cin >> side;
        cout << "Площадь боковой поверхности куба: " << cubeSurfaceArea(side) << endl;
        break;
    case 8:
        cout << "Введите длину ребра и высоту призмы: ";
        cin >> side >> height;
        cout << "Площадь боковой поверхности призмы: " << prismSurfaceArea(side, height) << endl;
        break;
    case 9:
        cout << "Введите радиус и высоту цилиндра: ";
        cin >> radius >> height;
        cout << "Площадь поверхности цилиндра: " << cylinderSurfaceArea(radius, height) << endl;
        break;
    case 10:
        cout << "Введите радиус и высоту цилиндра: ";
        cin >> radius >> height;
        cout << "Объем цилиндра: " << cylinderVolume(radius, height) << endl;
        break;
    default:
        cout << "Ошибка! Неверный выбор.\n";
    }
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
