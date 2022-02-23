#include "csvreader.h"
#include <QString>
#include <iostream>
csvreader::csvreader(const QString &filename){
    fin.open(filename.toLatin1().data());

}

csvreader::~csvreader(){
    fin.close();
}

std::vector<QString> split(QString &str, char zn);

std::vector<les> csvreader::readall(){
    std::vector<les> allinfo;
    if(fin.is_open()){
           while(!fin.eof()){
              QString line;
              std::string line_str = line.toUtf8().data();
              std::getline(fin,line_str);
              line = QString::fromStdString(line_str);
              if(line==""){
                  break;
              }
              auto v = split(line,';');
              les ls;
              ls.numb = v[0].toInt();
              ls.lesname = v[1];
              ls.type_of_les = v[2];
              ls.lesaud = v[3].toInt();
              allinfo.push_back(ls);
           }
        }else{
            std::cout<<"File corrupt! ";
        }
    return allinfo;
}

std::vector<QString> split(QString &str, char zn){
    std::vector<QString> temply;
    int zero=0;
    for(int i =0; i < str.length();i++){
        if(str[i]==zn){
            temply.push_back(str.mid(zero, i-zero));
            //std::cout<<temply[0].toUtf8().data()<<std::endl;
            zero = i+1;
        }
    }
    return temply;
}
