#ifndef Archivo_H
#define Archivo_H
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

class Files
{
private:
    string name;

public:
    Files()
    {
        this->name = "palabras.txt";
    }
    vector<string> read();
    int numberOfWords(const char* word);
};

vector<string>Files::read()
{
    ifstream file;
    vector<string> words;
    file.open(name.c_str(), ios::in | ios::binary);
    
    string word;
    
    	while(!file.eof())
		{
    		file >> word;
    		words.push_back(word);
		}
  
    file.close();


    return words;
}




#endif // Archivos_H
