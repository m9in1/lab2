#ifndef CSVREADER_H
#define CSVREADER_H
#include <QString>
#include <fstream>
#include <iostream>

#include<les.h>

class csvreader
{
    std::ifstream fin;
public:
    csvreader(const QString &filename);
    ~csvreader();

    bool is_open() const{return fin.is_open();}
    std::vector <les> readall();
};

#endif // CSVREADER_H
