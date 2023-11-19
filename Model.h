#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "PPoints.h"
#include "PVectors.h"

// ��������� ��� �������� ��������
struct Polygon {
    std::vector<int> vertexIndices; // ������� ������ ��������
    std::vector<int> normalIndices; // ������� �������� ��������
};

// ����� ��� �������� 3D ������
class Model {
public:
    std::vector<Point3D> vertices; // ������� ������
    std::vector<Vector3D> normals; // ������� ������
    std::vector<Polygon> polygons; // �������� ������

    // ����� ��� �������� ������ �� ����� ������� OBJ
    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            if (type == "v") {
                Point3D vertex;
                iss >> vertex.x >> vertex.y >> vertex.z;
                vertices.push_back(vertex);
            }
            else if (type == "vn") {
                Vector3D normal;
                iss >> normal.coordinates.x >> normal.coordinates.y >> normal.coordinates.z;
                normals.push_back(normal);
            }
            else if (type == "f") {
                Polygon polygon;
                char separator;
                int vertexIndex, normalIndex;
                while (iss >> vertexIndex >> separator >> separator >> normalIndex) {
                    polygon.vertexIndices.push_back(vertexIndex - 1); // OBJ ������� ���������� � 1
                    polygon.normalIndices.push_back(normalIndex - 1);
                }
                polygons.push_back(polygon);
            }
        }

        file.close();
        return true;
    }
};

#endif // MODEL_H
