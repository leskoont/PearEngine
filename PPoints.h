#ifndef PPOINTS_H
#define PPOINTS_H

#include <cmath>

// ��������� ��� 2D �����
struct Point2D {
    double x, y;

    // ����������� �� ���������
    Point2D() : x(0.0), y(0.0) {}

    // ����������� � �����������
    Point2D(double xVal, double yVal) : x(xVal), y(yVal) {}

    // ����� ��� ���������� ���������� ����� ����� �������
    double distanceTo(const Point2D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

// ��������� ��� 3D �����
struct Point3D {
    double x, y, z;

    // ����������� �� ���������
    Point3D() : x(0.0), y(0.0), z(0.0) {}

    // ����������� � �����������
    Point3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

    // ����� ��� ���������� ���������� ����� ����� �������
    double distanceTo(const Point3D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
    }
};

// ��������� ��� 4D �����
struct Point4D {
    double x, y, z, w;

    // ����������� �� ���������
    Point4D() : x(0.0), y(0.0), z(0.0), w(0.0) {}

    // ����������� � �����������
    Point4D(double xVal, double yVal, double zVal, double wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

    // ����� ��� ���������� ���������� ����� ����� �������
    double distanceTo(const Point4D& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2) + std::pow(w - other.w, 2));
    }
};

#endif // PPOINTS_H
