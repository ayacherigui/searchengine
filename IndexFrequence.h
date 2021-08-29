#ifndef IndexFrequence_H
#define IndexFrequence_H

#include<map>
#include"Index.h"

class IndexFrequence:public Index
{
    public:
        IndexFrequence();
        IndexFrequence(File*);
        ~IndexFrequence();
        void get_liste_mots(); //polymorphism
        map<string,int> get_mots_indexe();
        int calcul_frequence(string word);
        map<string,int> get_mots_indexe_complete();
        void add_word(string word,int frequency);// chaque colonne contient un mot et son nbre d'occurence
        


    private:
        map<string,int> mots_indexe;
};
#endif