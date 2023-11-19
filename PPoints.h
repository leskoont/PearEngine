#ifndef PPOINTS_H
#define PPOINTS_H

#include <cmath>

// Структура для 2D точек
struct Point2D {
    double x, y;

    // Конструктор по умолчанию
    Point2D() : x(0.0), y(0.0) {}

    // Конструктор с параметрами
    Point2D(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Метод для вычисления расстояния между двумя точками
    double distanceTo(const Point2D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

// Структура для 3D точек
struct Point3D {
    double x, y, z;

    // Конструктор по умолчанию
    Point3D() : x(0.0), y(0.0), z(0.0) {}

    // Конструктор с параметрами
    Point3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    // Метод для вычисления расстояния между двумя точками
    double distanceTo(const Point3D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
    }
};

// Структура для 4D точек
struct Point4D {
    double x, y, z, w;

    // Конструктор по умолчанию
    Point4D() : x(0.0), y(0.0), z(0.0), w(0.0) {}

    // Конструктор с параметрами
    Point4D(double xVal, double yVal, double zVal, double wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

    // Метод для вычисления расстояния между двумя точками
    double distanceTo(const Point4D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2) + std::pow(w - other.w, 2));
    }
};

#endif // PPOINTS_H
