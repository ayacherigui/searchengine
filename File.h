#ifndef File_H
#define File_H

#include<iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<vector>

using namespace std;

class File
{
    
    public:

        File();
        File(int id, string type, string title,string path);
        ~File();

        string get_type();
        string get_path();
        string get_name();
        int get_id();

        bool set_type(string type);
        void set_path(string path);
        void set_name(string name);
        void set_id(int id);

        void read_file();
        void display_file();


    private:
        string Path;
        string Type;
        string Name;
        int Id;


};
#endif