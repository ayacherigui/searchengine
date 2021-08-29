#include"IndexFrequence.h"
#include<map>


string MakeLowercase(string);


IndexFrequence::IndexFrequence()
:Index()
{}
IndexFrequence::IndexFrequence(File* file)
:Index(file)
{
    get_mots_indexe();
}

IndexFrequence::~IndexFrequence()
{

}

map<string,int> IndexFrequence::get_mots_indexe()
{
    map<string,int>::iterator it1;
    for(vector<string>::iterator it=liste_mots.begin();it!=liste_mots.end();it++)
    {
        int trouve=0;
        string word=((*it));
        MakeLowercase(word);
        if(word=="the" or word=="and" or word=="a" or word=="what" or word=="is" or word=="in" or word=="of" or word=="or" or word=="with" or word=="from" or word=="to" or word=="but" or word=="as" or word=="that" or word=="s" or word=="be")
        {
            trouve=1;
        }
        if(trouve==0)
        {
            it1=mots_indexe.find((*it));
            if(it1==mots_indexe.end())//si it1 n'existe pas dans mots_indexe, on a atteint la fin du map
            {
                mots_indexe[(*it)]=calcul_frequence((*it));

            }

        }
    }
    return mots_indexe;
}

void IndexFrequence::get_liste_mots()
{
    cout<<"indexation frequentielle"<<endl;
    for(map<string,int>::iterator it=mots_indexe.begin();it!=mots_indexe.end();it++)
    {
            cout<<it->first<<" : "<<it->second<<" ";
    }
    cout<<"endl";

}

void set_mot_indexe()
{


}
int IndexFrequence::calcul_frequence(string word)
{
    int nbOccurence=1;
    MakeLowercase(word);
    for(vector<string>::iterator it=liste_mots.begin();it!=liste_mots.end();it++)
    {
        string wordocc=MakeLowercase((*it));
        if(word==wordocc)
        {
          nbOccurence++;  
        }

    }
    return nbOccurence;

}

map<string,int> IndexFrequence::get_mots_indexe_complete()
{
    return mots_indexe;
}