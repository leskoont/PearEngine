#ifndef PVECTORS_H
#define PVECTORS_H

#include "PPoints.h"

// ����� ��� ������ � 2D ���������
class Vector2D {
public:
    Point2D coordinates;

    // ����������� �� ���������
    Vector2D() : coordinates() {}

    // ����������� � �����������
    Vector2D(double x, double y) : coordinates(x, y) {}

    // ����� ��� ���������� ����� �������
    double length() const {
        return std::sqrt(std::pow(coordinates.x, 2) + std::pow(coordinates.y, 2));
    }

    // ����� ��� ���������� ���������� ������������ ���� ��������
    double dotProduct(const Vector2D& other) const {
        return coordinates.x * other.coordinates.x + coordinates.y * other.coordinates.y;
    }
};

// ����� ��� ������ � 3D ���������
class Vector3D {
public:
    Point3D coordinates;

    // ����������� �� ���������
    Vector3D() : coordinates() {}

    // ����������� � �����������
    Vector3D(double x, double y, double z) : coordinates(x, y, z) {}

    // ����� ��� ���������� ����� �������
    double length() const {
        return std::sqrt(std::pow(coordinates.x, 2) + std::pow(coordinates.y, 2) + std::pow(coordinates.z, 2));
    }

    // ����� ��� ���������� ���������� ������������ ���� ��������
    double dotProduct(const Vector3D& other) const {
        return coordinates.x * other.coordinates.x + coordinates.y * other.coordinates.y + coordinates.z * other.coordinates.z;
    }

    // ����� ��� ���������� ���������� ������������ ���� ��������
    Vector3D crossProduct(const Vector3D& other) const {
        return Vector3D(
            coordinates.y * other.coordinates.z - coordinates.z * other.coordinates.y,
            coordinates.z * other.coordinates.x - coordinates.x * other.coordinates.z,
            coordinates.x * other.coordinates.y - coordinates.y * other.coordinates.x
        );
    }
};

// ����� ��� ������ � 4D ���������
class Vector4D {
public:
    Point4D coordinates;

    // ����������� �� ���������
    Vector4D() : coordinates() {}

    // ����������� � �����������
    Vector4D(double x, double y, double z, double w) : coordinates(x, y, z, w) {}

    // ����� ��� ���������� ����� �������
    double length() const {
        return std::sqrt(std::pow(coordinates.x, 2) + std::pow(coordinates.y, 2) + std::pow(coordinates.z, 2) + std::pow(coordinates.w, 2));
    }

    // ����� ��� ���������� ���������� ������������ ���� ��������
    double dotProduct(const Vector4D& other) const {
        return coordinates.x * other.coordinates.x + coordinates.y * other.coordinates.y + coordinates.z * other.coordinates.z + coordinates.w * other.coordinates.w;
    }
};

#endif // PVECTORS_H
