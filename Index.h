#ifndef Index_H
#define Index_H

#include<iostream>
#include<string.h>
#include"File.h"

using namespace std;

class Index
{
    public:
        Index();
        Index(File *file);//file est le fichier à indexer
        ~Index();
        File get_indexed_file();//va retourner le nom du fichier
        void setFichier(File file);
        void get_liste_mots();

    protected:
        File* indexed_file;//fichier à indexer (son chemin)
        vector<string> liste_mots;/*vecteur qui contient tous les mots d'un fichier(sans espace) pour pouvoir parcourir seulement l'index
                                    lors du traitement de l'index final au lieu de rentrer dans le fichier*/

};
#endif