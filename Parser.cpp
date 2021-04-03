#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <map>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Parser.h"

using namespace std;

/**
 * @brief Tokenizes the given string into a vector of tokens
 * @param s The given string
 * @param delim The delimiter for tokenization
 * @return The vector of tokens
 */
vector< string > tokenize(string s, string delim)
{

    vector< string > tok;
    if(s == "")
        return tok;
    int found = 0;
    while(1)
    {
        int f = s.find(delim, found);
        if(f == string::npos)
        {
            string n = s.substr(found, s.size() - found);
            if(n.size() > 0)
                tok.push_back(n);
            break;
        }
        else
        {
            tok.push_back(s.substr(found, f - found));
            found = f + delim.size();
        }
    }
    return tok;
}

/**
 * @brief Tokenizes the given file by newlines and each line by spaces
 * @param file [description]
 * @return The vector of vector of strings representing the lines and words
 */
vector< vector < string > > makeTokens(string file)
{
    vector < vector < string > > result;
    ifstream f;
    f.open(file);
    string temp;
    while(getline(f, temp))
    {
        vector<string> tok = tokenize(temp, " ");
        result.push_back(tok);
    }
    return result;
}

/**
 * @brief Convenience function. Makes a face tuple from the tokens
 * @param toks A vector of tokens from a face line of an obj file
 * @param Mat The material name to be used for this face
 * @return A face tuple
 */
tuple< pair<int, int>, pair<int, int>, pair<int, int>, string > make_face(vector<string> toks, string Mat)
{
    auto split1 = tokenize(toks[1], "//"); //assuming no textures present
    auto pair1 = make_pair(stoi(split1[0]), stoi(split1[1]));
    auto split2 = tokenize(toks[2], "//");
    auto pair2 = make_pair(stoi(split2[0]), stoi(split2[1]));
    auto split3 = tokenize(toks[3], "//");
    auto pair3 = make_pair(stoi(split3[0]), stoi(split3[1]));
    return make_tuple(pair1, pair2, pair3, Mat);
}

Model::Model(string objfile, string mtlfile)
{
    vector< vector < string > > objToks = makeTokens(objfile); //loading files
    vector< vector < string > > mtlToks = makeTokens(mtlfile);
    map< string, tuple< float, float, float > > colorMap;
    vector< string > temp;
    for(auto toks: mtlToks) //creating material to color map
    {
        if(toks.size() == 0)
            continue;
        if(toks[0] == "newmtl")
            temp.push_back(toks[1]);
        if(toks[0] == "Kd")
            colorMap[temp.back()] = make_tuple(stof(toks[1]), stof(toks[2]), stof(toks[3]));
    }
    vector< tuple < float, float, float > > allvertices;
    vector< tuple < float, float, float > > allnormals;
    vector< tuple < pair<int, int>, pair<int, int>, pair<int, int>, string > > faces;
    string currMat;
    for(auto toks: objToks) //making the vertices, normals and faces list
    {
        if(toks.size() == 0)
            continue;
        if(toks[0] == "v")
            allvertices.push_back(make_tuple(stof(toks[1]), stof(toks[2]), stof(toks[3])));
        if(toks[0] == "vn")
            allnormals.push_back(make_tuple(stof(toks[1]), stof(toks[2]), stof(toks[3])));
        if(toks[0] == "usemtl")
            currMat = toks[1];
        if(toks[0] == "f")
            faces.push_back(make_face(toks, currMat));
    }
    for(auto face: faces) //finally storing all faces as triangles, colors and normals
    {
        auto vertex1 = allvertices[get<0>(face).first - 1];
        auto vertex2 = allvertices[get<1>(face).first - 1];
        auto vertex3 = allvertices[get<2>(face).first - 1];
        auto normal1 = allnormals[get<0>(face).second - 1];
        auto normal2 = allnormals[get<1>(face).second - 1];
        auto normal3 = allnormals[get<2>(face).second - 1];
        auto color = colorMap[get<3>(face)];
        vertices.push_back(vertex1);
        vertices.push_back(vertex2);
        vertices.push_back(vertex3);
        normals.push_back(normal1);
        normals.push_back(normal2);
        normals.push_back(normal3);
        colors.push_back(color);
    }
}

void Model::draw()
{



    glBegin(GL_TRIANGLES);
    for(int i = 0; i < colors.size(); i++) //drawing each triangle separately
    {
        //glColor3f(get<0>(colors[i]), get<1>(colors[i]), get<2>(colors[i]));
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glShadeModel(GL_SMOOTH);
        GLfloat mat_specular[] = {get<0>(colors[i]), get<1>(colors[i]), get<2>(colors[i])};
        GLfloat mat_diffuse[] = {get<0>(colors[i]), get<1>(colors[i]), get<2>(colors[i])};
        GLfloat mat_ambient[] = {get<0>(colors[i]), get<1>(colors[i]), get<2>(colors[i])};
        GLfloat mat_shininess = 5.0;
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

        glNormal3f(get<0>(normals[3*i]), get<1>(normals[3*i]), get<2>(normals[3*i]));
        glVertex3f(get<0>(vertices[3*i]), get<1>(vertices[3*i]), get<2>(vertices[3*i]));
        glNormal3f(get<0>(normals[3*i + 1]), get<1>(normals[3*i + 1]), get<2>(normals[3*i + 1]));
        glVertex3f(get<0>(vertices[3*i + 1]), get<1>(vertices[3*i + 1]), get<2>(vertices[3*i + 1]));
        glNormal3f(get<0>(normals[3*i + 2]), get<1>(normals[3*i + 2]), get<2>(normals[3*i + 2]));
        glVertex3f(get<0>(vertices[3*i + 2]), get<1>(vertices[3*i + 2]), get<2>(vertices[3*i + 2]));
    }
    glEnd();

    glPopAttrib();
}
