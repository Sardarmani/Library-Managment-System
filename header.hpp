#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

using namespace std;

struct lms
{
    char author[30];
    char title[30];
    char pub_month[10];
    int pub_year;
    int id;
};

char **arg;
int Argc;
lms *arr;

void add();
int search_by_name(char *);
int search_by_author(char *);
int search_by_ID(int);
void delete_book(char *);
void modify(char *);
void list();
void addcomm();
