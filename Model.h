#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "PPoints.h"
#include "PVectors.h"

// Структура для описания полигона
struct Polygon {
    std::vector<int> vertexIndices; // Индексы вершин полигона
    std::vector<int> normalIndices; // Индексы нормалей полигона
};

// Класс для описания 3D модели
class Model {
public:
    std::vector<Point3D> vertices; // Вершины модели
    std::vector<Vector3D> normals; // Нормали модели
    std::vector<Polygon> polygons; // Полигоны модели

    // Метод для загрузки модели из файла формата OBJ
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
                    polygon.vertexIndices.push_back(vertexIndex - 1); // OBJ индексы начинаются с 1
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
