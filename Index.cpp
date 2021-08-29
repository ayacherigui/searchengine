#include"Index.h"
#include<fstream>
#include <algorithm>//for_each
#include <cctype>//tolower()
#include <bits/stdc++.h>//pour le split

string MakeLowercase(string);
vector<string> split(string line);

Index::Index()
{
    indexed_file=new File();
}

Index::Index(File *file)
{
    indexed_file=new File();
    indexed_file->set_path(file->get_path());
    indexed_file->set_type(file->get_type());
    indexed_file->set_id(file->get_id());
    indexed_file->set_name(file->get_name());
    setFichier(*indexed_file);
}
Index::~Index()
{
    delete indexed_file;
}
//*********************************Traitement de l'index pere***************************************************

void Index::setFichier(File file) //read the file then set :indexed_file(f) liste_mots
{
    string filePath=file.get_path();
    //parcourir tout le fichier et ceer "liste_mots" qui contient tout les mots dans le fichier

    ifstream actual_file(filePath,ios::in);
            if(actual_file)//if the actual file has opened
            {
                string line;
                getline(actual_file,line);
                //il faut remarquer que le fichier qu'on dispose est composé d'une seule ligne
                //maintenant on a pris tous les mots (avec les espaces et avec les redondances et avec les mots inutles "le la de dans") et on va les mettres dans liste_mots
                //now we're gonna creat the liste_mots for each file and we're gonne put it in list_index
                liste_mots=split(line);
            }
    actual_file.close();
}

//*************************Afficher l'index pere**********************************************************

void Index::get_liste_mots()
{
    for(vector<string>::iterator it=liste_mots.begin();it!=liste_mots.end();it++)
    {
            cout<<(*it)<<" ";
    }
    cout<<endl;
}

File Index::get_indexed_file()
{
    indexed_file->display_file();
    return *indexed_file;
}

//******************************************FonctionsSecondaire**********************************************

vector<string> split(string line)
{
    stringstream ss(line);
    string word;
    vector<string> list;
    while (ss >> word)
    {
        list.push_back(word);
    }
    return list;
}

string MakeLowercase(string word)
{
    int tolower ( int c );
    for_each(word.begin(), word.end(), [](char & c){c = ::tolower(c);});

    return word;
}