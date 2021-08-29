#include"IndexBool.h"
#include <algorithm>//for find

string MakeLowercase(string);

IndexBool::IndexBool()
:Index()
{}
IndexBool::IndexBool(File* file)
:Index(file)
{
    get_mots_indexe();
}
IndexBool::~IndexBool()
{}
vector<string> IndexBool::getList()
{
    return liste_mots;
}

//*******************************Traitement de l'index de type booleean****************************************

vector<string> IndexBool::get_mots_indexe()
{
    for(vector<string>::iterator it=liste_mots.begin();it!=liste_mots.end();it++)
    {
        int trouve=0;
        string word=((*it));
        word=MakeLowercase(word);
        if(word=="the" or word=="and" or word=="a" or word=="what" or word=="is" or word=="in" or word=="of" or word=="or" or word=="with" or word=="from" or word=="to" or word=="but" or word=="as" or word=="that" or word=="s" or word=="be" or word=="so" or word=="her" or word=="his")
        {
            trouve=1;
        }
        if(trouve==0)
        {
            mots_indexe.push_back((*it));

        } 
    }
    eliminateRedondancy(mots_indexe);
    return mots_indexe;
}

void IndexBool::eliminateRedondancy(vector<string> mots_indexe)
{
    vector<string> listSansRedondance;
    for(vector<string>::iterator it=mots_indexe.begin();it!=mots_indexe.end();it++)
    {
        string word=MakeLowercase( (*it) );
        vector<string>::iterator it1;
        it1 = find (listSansRedondance.begin(), listSansRedondance.end(), word);
        if (it1 !=listSansRedondance.end())
        {
                listSansRedondance.push_back((word));
        }

    }
    mots_indexe=listSansRedondance;
}

void IndexBool::get_liste_mots()
{
    for(vector<string>::iterator it=mots_indexe.begin();it!=mots_indexe.end();it++)
    {
            cout<<(*it)<<" ";
    }
    cout<<endl;
}

vector<string> IndexBool::get_mots_indexe_complete()
{
    return mots_indexe;
}