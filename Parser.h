#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;
/**
 * @brief Class that loads texture-less models from .obj files
 * @param objfile The path to the .obj file
 * @param mtlfile The path to the .mtl file
 */
class Model
{
public:
    vector< tuple< float, float, float > > vertices;
    vector< tuple< float, float, float > > colors;
    vector< tuple< float, float, float > > normals;
    Model(string objfile, string mtlfile);
    /**
     * @brief Draws the model in openGL space
     */
    void draw();
};
#endif
