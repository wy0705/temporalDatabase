//
// Created by andilyliao on 16-11-14.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

//读取文件中的内容
int fputcget(char* buf)
{
    FILE *fp;
    //int ch;

    if ( (fp = fopen("/home/wy/CLionProjects/temporalDatabase/role.txt", "a+")) == NULL) {
        perror("Open file file2\n");
        exit(1);
    }
//    while ( (ch = fgetc(stdin)) != '0'){
   /* while ( (ch = getchar()) != '0'){
        fputc(ch, fp);
    }
    rewind(fp);*/
    /*while ( (ch = fgetc(fp)) != EOF) {
        //putchar(ch);
        //fputc(ch,stdout);
        fgets(buf,100,fp);
    }*/
    fread(buf,1024,1,fp);
    int res=fclose(fp);
    if(res<0){
        perror("error!!!!!");
        cout<<strerror(errno)<<"\t"<<errno<<endl;
        exit(1);
    }

    cout<<"ok"<<endl;
    return 0;
}
