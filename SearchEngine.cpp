#include"SearchEngine.h"
#include"File.h"
#include"IndexBool.h"
#include"IndexFrequence.h"
#include <fstream>
#include <dirent.h>
#include <algorithm>//for find


SearchEngine::SearchEngine()
{
    openDirectory();
    cout<<"Enter a word"<<endl;
    string word;
    cin>>word;
    motRecherche=word;
    cout<<"searching for the word "<<word<<endl;
    recherche_indexe_boolean(motRecherche);
    recherche_indexe_frequence(motRecherche);
    cout<<"\nend of searching"<<endl;

}

SearchEngine::~SearchEngine()
{}

void SearchEngine::openDirectory()
{
       DIR* rep = opendir("./files");
    

    if ( rep != NULL )
    {
        struct dirent* ent;

        while ( (ent = readdir(rep) ) != NULL )
        {
        
            File *F=new File(0,".txt",ent->d_name,"./files/"+(string)ent->d_name);
            liste_fichier.push_back(F);
        }
        closedir(rep);
        
        cout<<"Start Indexing ....."<<endl;
        for(vector<File*>::iterator it=liste_fichier.begin();it!=liste_fichier.end();it++)//iterator est un pointeur sur le vecteur
        {
            Index* i=new Index(*it);//it est un pointeur sur le vecteur, *it est l'element du vecteur (qui est dans ce cas un pointeur file)
            IndexBool* i1=new IndexBool(*it);// (*it) est de type File*
            list_indexBool.push_back(i1);
            IndexFrequence* i2=new IndexFrequence(*it);
            list_indexFrequence.push_back(i2);
        }
        cout<<"indexing Complete...."<<endl;
        cout<<liste_fichier.size()-2<<"  files found"<<endl;

    }
}

void SearchEngine::recherche_indexe_boolean(string word)
{
    cout<<"Boolean Indexing ..."<<endl;
    for(vector<IndexBool*>::iterator it=list_indexBool.begin();it!=list_indexBool.end();it++)
    {
        //(**it) est de type IndexBool
        vector<string> list_word_in_index=(**it).get_mots_indexe_complete();
        for(vector<string>::iterator it1=list_word_in_index.begin();it1!=list_word_in_index.end();it1++) //(**it) ==> c'est l'element Index     
        {
            vector<string>::iterator it2;
            it2=find (list_word_in_index.begin(), list_word_in_index.end(), word);
            if (it2 !=list_word_in_index.end())
                {
                    cout<<"\nthis word exists in the file: "<<endl;
                    (**it).get_indexed_file();
                    break;
                }
        }
    }

}

void SearchEngine::recherche_indexe_frequence(string word)
{
    cout<<"Frequenciel Indexing ...."<<endl;
    for(vector<IndexFrequence*>::iterator it=list_indexFrequence.begin();it!=list_indexFrequence.end();it++)
    {
        //(**it) est de type IndexBool
        map<string,int> list_word_in_index=(**it).get_mots_indexe_complete();
        for(map<string,int>::iterator it1=list_word_in_index.begin();it1!=list_word_in_index.end();it1++) //(**it) ==> c'est l'element Index     
        {
            map<string,int>::iterator it2;
            it2=list_word_in_index.find (word);
            if (it2 !=list_word_in_index.end())
                {
                    cout<<"\nthis word exists in the file: "<<endl;
                    (**it).get_indexed_file();
                    cout<<"this word occurs "<<it1->second<<" times";
                    break;
                }
        }
    }

}