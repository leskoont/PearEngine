#ifndef PVECTORS_H
#define PVECTORS_H

#include "PPoints.h"

// Класс для работы с 2D векторами
class Vector2D {
public:
    Point2D coordinates;

    // Конструктор по умолчанию
    Vector2D() : coordinates() {}

    // Конструктор с параметрами
    Vector2D(double x, double y) : coordinates(x, y) {}

    // Метод для вычисления длины вектора
    double length() const {
        return std::sqrt(std::pow(coordinates.x, 2) + std::pow(coordinates.y, 2));
    }

    // Метод для вычисления скалярного произведения двух векторов
    double dotProduct(const Vector2D& other) const {
        return coordinates.x * other.coordinates.x + coordinates.y * other.coordinates.y;
    }
};

// Класс для работы с 3D векторами
class Vector3D {
public:
    Point3D coordinates;

    // Конструктор по умолчанию
    Vector3D() : coordinates() {}

    // Конструктор с параметрами
    Vector3D(double x, double y, double z) : coordinates(x, y, z) {}

    // Метод для вычисления длины вектора
    double length() const {
        return std::sqrt(std::pow(coordinates.x, 2) + std::pow(coordinates.y, 2) + std::pow(coordinates.z, 2));
    }

    // Метод для вычисления скалярного произведения двух векторов
    double dotProduct(const Vector3D& other) const {
        return coordinates.x * other.coordinates.x + coordinates.y * other.coordinates.y + coordinates.z * other.coordinates.z;
    }

    // Метод для вычисления векторного произведения двух векторов
    Vector3D crossProduct(const Vector3D& other) const {
        return Vector3D(
            coordinates.y * other.coordinates.z - coordinates.z * other.coordinates.y,
            coordinates.z * other.coordinates.x - coordinates.x * other.coordinates.z,
            coordinates.x * other.coordinates.y - coordinates.y * other.coordinates.x
        );
    }
};

// Класс для работы с 4D векторами
class Vector4D {
public:
    Point4D coordinates;

    // Конструктор по умолчанию
    Vector4D() : coordinates() {}

    // Конструктор с параметрами
    Vector4D(double x, double y, double z, double w) : coordinates(x, y, z, w) {}

    // Метод для вычисления длины вектора
    double length() const {
        return std::sqrt(std::pow(coordinates.x, 2) + std::pow(coordinates.y, 2) + std::pow(coordinates.z, 2) + std::pow(coordinates.w, 2));
    }

    // Метод для вычисления скалярного произведения двух векторов
    double dotProduct(const Vector4D& other) const {
        return coordinates.x * other.coordinates.x + coordinates.y * other.coordinates.y + coordinates.z * other.coordinates.z + coordinates.w * other.coordinates.w;
    }
};

#endif // PVECTORS_H
