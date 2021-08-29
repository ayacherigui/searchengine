#ifndef IndexBool_H
#define IndexBool_H

#include"Index.h"

class IndexBool:public Index
{
    public:
        IndexBool();
        IndexBool(File*);
        ~IndexBool();
        void get_liste_mots();//polymorphism car elle retourne la liste des mots indexé selon l'indexBool
        vector<string> get_mots_indexe();
        vector<string> getList();
        vector<string> get_mots_indexe_complete();
        void eliminateRedondancy(vector<string>);


    private:
        vector<string> mots_indexe;//colonne reduite de tous les mots(apres nettoyage)
};
#endif