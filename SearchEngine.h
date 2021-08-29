#ifndef SearchEngine_H
#define SearchEngine_H

#include"File.h"
#include"IndexBool.h"
#include"IndexFrequence.h"
#include<vector>

class SearchEngine
{
    
    public:
        SearchEngine();
        ~SearchEngine();
        void recherche_indexe_boolean(string word);
        void recherche_indexe_frequence(string word);
        void openDirectory();

    private:
        vector<File*> liste_fichier;
        vector<Index*> list_index;
        vector<IndexBool*> list_indexBool;
        vector<IndexFrequence*> list_indexFrequence;
        string motRecherche;
        vector<File> liste_fichierResultat;
        
         
};
#endif