//
// Created by wy on 2021/9/23.
//

#include <hash_map>
#include <iostream>
#include <cstring>
#include "fputcget.cpp"
using namespace std;


/*int main()
{
    __gnu_cxx::hash_map<char*, int> hmap;
    hmap["root"]=1;
    hmap["user"]=2;
    if (hmap.find("root")!=hmap.end()){
        hmap["root"]++;
        cout<<hmap["root"]<<endl;
    }

    return 0;
   *//* __gnu_cxx::hash_map<int, string> mymap;
    mymap[9527]="唐伯虎点秋香";
    mymap[1000000]="百万富翁的生活";
    mymap[10000]="白领的工资底线";
    if(mymap.find(10000) != mymap.end()){
        cout<<mymap[10000]<<endl;
    }*//*
}*/
//区分字符串
vector<string> split(string str,string pattern) {
    string::size_type pos;
    vector<string> result;
    str+=pattern;  //扩展字符串以方便操作
    int size=str.size();
    for(int i=0;i<size;i++) {
        pos=str.find(pattern,i);
        if(pos<size) {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}
/***将字符串转成int***/
int char2int(const char* str) {
    const char* p = str;
    bool neg = false;
    int res = 0;
    if (*str == '-' || *str == '+') {
        str++;
    }

    while (*str != 0) {
        if (*str < '0' || *str > '9') {
            break;
        }
        res = res * 10 + *str - '0';
        str++;
    }

    if (*p == '-') {
        res = -res;
    }
    return res;
}
int toHash_map(char* buffer,__gnu_cxx::hash_map<char*, int> *hmap){
    string s=buffer;
    vector<string> vector=split(s,"\n");
    char *argv[vector.size()];
    char* c;
    for (int i = 0; i < vector.size(); ++i) {
        const int len=vector[i].length();
        c=new char[len+1];
        strcpy(c,vector[i].c_str());
        argv[i]=c;
    }
    for (int i = 0; i < vector.size(); ++i) {
        printf(" %s  %s",argv[i],argv[i+1]);
        //redisCommand(conn,"set %s %s",argv[i],argv[i+1]);
        hmap->insert(pair<char*,int>(argv[i],char2int(argv[i+1])));
        //(*hmap)[argv[i]]=char2int(argv[i+1]);
        printf("\nset ok!");
        char* key=argv[i];
        char* key1="root";
        if (!strncmp(key,key1,sizeof(key))){
            cout<<"222222"<<endl;
        }
        if (hmap->find(key)!=hmap->end()){
            cout<<"root:"<<endl;
            cout<<(*hmap)[key]<<endl;
        }
        i++;
    }
}
int main() {
    char* buf=(char *)malloc(1024);
    fputcget(buf);
    printf("11111\n%s",buf);
    __gnu_cxx::hash_map<char*, int> *hmap=new __gnu_cxx::hash_map<char*, int>();
    toHash_map(buf,hmap);
    __gnu_cxx::hash_map<char*, int>::iterator it;
    char* key="root";
     if (hmap->count(key)){
         it=hmap->find("root");
         char* role=it->first;
         int n=it->second;
         cout<<role<<endl;
         cout<<n<<endl;
     } else{
         cout<<"not find"<<endl;
     }
    return 0;
}