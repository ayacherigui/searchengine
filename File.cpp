#include"File.h"

File::File()
{
    Id=0;
    Path="";
    Name="";
    Type="0";
}

File::File(int id, string type, string name,string path)
{
    set_id(id);
    set_path(path);
    set_type(type);
    set_name(name);

    if(set_type(type)==false)
    {
        cout<<"type invalide veuillez reconstruire votre fichier"<<endl;
        abort();
    }
    
}

File::~File()
{}
string File::get_type()
{
    return Type;
}
string File::get_path()
{
    return Path;
}
int File::get_id()
{
    return Id;
}
string File::get_name()
{
    return Name;
}

bool File::set_type(string type)
{
    if(type==".txt" || type==".pdf" || type==".rtf" )
    {
        Type=type;
        return true;
    }
    else
    {
        
        return false;
    }
}
void File::set_path(string path)
{
    Path=path;
}
void File::set_name(string name)
{
    Name=name;
}

void File::set_id(int id)
{
    Id=id;
}
void File::display_file()
{
    cout<<"Name: "<<Name<<endl;
    cout<<"ID: "<<Id<<endl;
    cout<<"Type: "<<Type<<endl;
    cout<<"Path: "<<Path<<endl;

}
