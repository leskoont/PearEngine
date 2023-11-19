#ifndef PMATRICES_H
#define PMATRICES_H

#include "PVectors.h"
#include <cmath>

// ����� ��� 2D ������� ��������������
class Matrix2D {
public:
    // �������� ������� 2x2
    double m[2][2];

    // ����������� �� ���������
    Matrix2D() {
        identity();
    }

    // ����� ��� ��������� ������� � ���������
    void identity() {
        m[0][0] = 1.0; m[0][1] = 0.0;
        m[1][0] = 0.0; m[1][1] = 1.0;
    }

    // ����� ��� ��������� ������� �� ������
    Vector2D transform(const Vector2D& vector) const {
        Vector2D result;
        result.coordinates.x = m[0][0] * vector.coordinates.x + m[0][1] * vector.coordinates.y;
        result.coordinates.y = m[1][0] * vector.coordinates.x + m[1][1] * vector.coordinates.y;
        return result;
    }

    // ����� ��� ��������� ������� �� ������ �������
    Matrix2D multiply(const Matrix2D& other) const {
        Matrix2D result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.m[i][j] = m[i][0] * other.m[0][j] + m[i][1] * other.m[1][j];
            }
        }
        return result;
    }
};

// ����� ��� 3D ������� ��������������
class Matrix3D {
public:
    // �������� ������� 3x3
    double m[3][3];

    // ����������� �� ���������
    Matrix3D() {
        identity();
    }

    // ����� ��� ��������� ������� � ���������
    void identity() {
        m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0;
        m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0;
        m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0;
    }

    // ����� ��� ��������� ������� �� ������
    Vector3D transform(const Vector3D& vector) const {
        Vector3D result;
        result.coordinates.x = m[0][0] * vector.coordinates.x + m[0][1] * vector.coordinates.y + m[0][2] * vector.coordinates.z;
        result.coordinates.y = m[1][0] * vector.coordinates.x + m[1][1] * vector.coordinates.y + m[1][2] * vector.coordinates.z;
        result.coordinates.z = m[2][0] * vector.coordinates.x + m[2][1] * vector.coordinates.y + m[2][2] * vector.coordinates.z;
        return result;
    }

    // ����� ��� ��������� ������� �� ������ �������
    Matrix3D multiply(const Matrix3D& other) const {
        Matrix3D result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.m[i][j] = m[i][0] * other.m[0][j] + m[i][1] * other.m[1][j] + m[i][2] * other.m[2][j];
            }
        }
        return result;
    }
};

// ����� ��� 4D ������� ��������������
class Matrix4D {
public:
    // �������� ������� 4x4
    double m[4][4];

    // ����������� �� ���������
    Matrix4D() {
        identity();
    }

    // ����� ��� ��������� ������� � ���������
    void identity() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                m[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    // ����� ��� ��������� ������� �� ������
    Vector4D transform(const Vector4D& vector) const {
        Vector4D result;
        for (int i = 0; i < 4; ++i) {
            result.coordinates.x += m[0][i] * vector.coordinates.x;
            result.coordinates.y += m[1][i] * vector.coordinates.y;
            result.coordinates.z += m[2][i] * vector.coordinates.z;
            result.coordinates.w += m[3][i] * vector.coordinates.w;
        }
        return result;
    }

    // ����� ��� ��������� ������� �� ������ �������
    Matrix4D multiply(const Matrix4D& other) const {
        Matrix4D result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.m[i][j] = m[i][0] * other.m[0][j] + m[i][1] * other.m[1][j] + m[i][2] * other.m[2][j] + m[i][3] * other.m[3][j];
            }
        }
        return result;
    }
};

#endif // PMATRICES_H
