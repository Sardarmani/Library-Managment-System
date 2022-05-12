#include"header.hpp"


void add(){
    ofstream fwr;

    int n,id;
    cout<<"Enter Number of Books Records you want to add";
    cin>>n;
    
    arr=new lms[n];
    fwr.open("library.bin",ios::binary|ios::app);
    
    for(int i=0;i<n;i++)
    {
    cout<<"Enter Book Name"<<endl;
    cin.ignore();
    cin.getline(arr[i].title,30);
    cout<<"Enter Publication year ";
    cin>>arr[i].pub_year;
    cout<<"Enter Publication month ";
    cin.ignore();
    cin.getline(arr[i].pub_month,30);
    cout<<"Enter Author Name ";
    cin.getline(arr[i].author,30);
    cout<<"Enter unique ID";
    cin>>arr[i].id;
    
    }
    
    fwr.write((const char*)arr,n*sizeof(lms));
    fwr.close();
    delete []arr;    
    
    }


void addcomm(){
    ofstream fwr;
    int n=1;
    
    arr=new lms[n];
    fwr.open(arg[1],ios::binary|ios::app);
    
    for(int i=0;i<n;i++)
    {
    strcpy(arr[i].author,arg[3]);
    strcpy(arr[i].title,arg[4]);
    arr[i].id=atoi(arg[5]);
    arr[i].pub_year=atoi(arg[6]);
    strcpy(arr[i].pub_month,arg[7]);
    }
    fwr.write((const char*)arr,n*sizeof(lms));
    fwr.close();
    delete []arr;    
}

int search_by_name(char name[]){
    ifstream fr;
    if(Argc==1)
    {
    fr.open("library.bin",ios::binary);
    }
    
    else
    {
    fr.open(arg[1],ios::binary|ios::app);
    }

    if(fr.is_open())
    {   
    fr.seekg(0,ios::end);
    int n=fr.tellg();
    fr.seekg(0);
    int n_vals=n/sizeof(lms);

    arr=new lms[n_vals];
       
    (fr.read((char*)arr,n_vals*sizeof(lms)));
    
    for(int i=0;i<n_vals;i++)
    {
    if(strcmp(name,arr[i].title)==0)
    {
    cout<<"Book with this title is present "<<endl;
    cout<<"Here is details "<<endl;
    cout<<"ID "<<arr[i].id<<endl;
    cout<<"Title "<<arr[i].title<<endl;
    cout<<"Author "<<arr[i].author<<endl;
    cout<<"Publication Month "<<arr[i].pub_month<<endl;
    cout<<"Publication Year "<<arr[i].pub_year<<endl;
    }
    
    delete []arr;   
    fr.close();
    return i;
       
    }
            
      
    }
    else
    {
        cout<<"File does Not exist to search "<<endl;
    }
    return -1;
    }


int search_by_author(char name[]){
    ifstream fr;

    if(Argc==1)
    {
    fr.open("library.bin",ios::binary);
    }

    else
    {
    fr.open(arg[1],ios::binary|ios::app);
    } 
    
    if(fr.is_open())
    {   
    fr.seekg(0,ios::end);
    int n=fr.tellg();
    fr.seekg(0);
    int n_vals=n/sizeof(lms);

    arr=new lms[n_vals];
      
    (fr.read((char*)arr,n_vals*sizeof(lms)));
    for(int i=0;i<n_vals;i++)
    {
    if(strcmp(name,arr[i].author)==0)
    {
    cout<<"Book with this Author is present "<<endl;
    cout<<"Here is details "<<endl;
    cout<<"ID "<<arr[i].id<<endl;
    cout<<"Title "<<arr[i].title<<endl;
    cout<<"Author "<<arr[i].author<<endl;
    cout<<"Publication Month "<<arr[i].pub_month<<endl;
    cout<<"Publication Year "<<arr[i].pub_year<<endl;
    }
    
    delete []arr;   
    fr.close();
    return i;
        
    }
      
    }
    else
    {
        cout<<"File does Not exist to search "<<endl;
    }

    return -1;
 
    }

int search_by_ID(int id){
   ifstream fr;
    if(Argc==1)
    {
    fr.open("library.bin",ios::binary);
    }

    else
    {
    fr.open(arg[1],ios::binary|ios::app);
    } 

   if(fr.is_open())
   {   
    fr.seekg(0,ios::end);
    int n=fr.tellg();
    fr.seekg(0);
    int n_vals=n/sizeof(lms);

    arr=new lms[n_vals];
       
    (fr.read((char*)arr,n_vals*sizeof(lms)));
    
    for(int i=0;i<n_vals;i++)
    {
    if(id==arr[i].id)
    {
    cout<<"Book with this ID is present "<<endl;
    cout<<"Here is details "<<endl;
    cout<<"ID "<<arr[i].id<<endl;
    cout<<"Title "<<arr[i].title<<endl;
    cout<<"Author "<<arr[i].author<<endl;
    cout<<"Publication Month "<<arr[i].pub_month<<endl;
    cout<<"Publication Year "<<arr[i].pub_year<<endl;
    }
    
    delete []arr;   
    fr.close();
    return i;
       
    }
            
      
    }
    
    else
    {
        cout<<"File does Not exist to search "<<endl;
    }
    return -1;
    }



    void delete_book(char *titl){
    ifstream fr;
    if(Argc==1)
    {
    fr.open("library.bin",ios::binary);
    }

    else
    {
    fr.open(arg[1],ios::binary|ios::app);
    } 

    int n_vals;
    int flag=0;
    lms obj;
    fstream temp;
    temp.open("temp.bin",ios::binary|ios::out);

    while(fr.read((char *)&obj,sizeof(obj)))
    {
        if(strcmp(obj.title,titl)==0)
        {
        flag++;
        continue;
        }
        temp.write((char *)&obj,sizeof(obj));
    }
    
    remove("library.bin");
    rename("temp.bin","library.bin");

    if(flag==1)
    {
    cout<<"Record Deleted "<<endl;
    }
    else
    {
    cout<<"Record not Found "<<endl;
    }
     
    }
    void modify(char *name)

    {  
    ifstream fr;
    if(Argc==1)
    {
    fr.open("library.bin",ios::binary);
    }

    else
    {
    fr.open(arg[1],ios::binary|ios::app);
    } 

    char titl[20];
    int indicator=0;
    lms obj;
    fstream temp,file;
 
    temp.open("temp.bin",ios::binary|ios::out);

    while(fr.read((char *)&obj,sizeof(lms)))
    {
        if(strcmp(obj.title,name)==0)
        {   
            indicator++;
            cout<<"Enter New ID ";
            cin>>obj.id;
            cout<<"Enter new name ";
            cin>>obj.title;
            
        }
            temp.write((char *)&obj,sizeof(lms));
    }
  
    remove("library.bin");

    rename("temp.bin","library.bin");

    if(indicator!=1)
    {
    cout<<"Record Not found "<<endl;
    }
    
     
    }

void list()
    {
    ifstream fr;
    if(Argc==1)
    {
    fr.open("library.bin",ios::binary);
    }

    else
    {
    fr.open(arg[1],ios::binary|ios::app);
    } 

    if(fr.is_open())
    {   
    lms *arr;
    fr.seekg(0,ios::end);
    int n=fr.tellg();
    fr.seekg(0);
    int n_vals=n/sizeof(lms);

    arr=new lms[n_vals];
    fr.read((char*)arr,n_vals*sizeof(lms));
    
    for(int i=0;i<n_vals;i++)

    {
    cout<<"Book "<<i+1<<endl;
    cout<<"Title "<<arr[i].title<<endl;
    cout<<"Author "<<arr[i].author<<endl;
    cout<<"Publication Year "<<arr[i].pub_year<<endl;
    cout<<"Publication Month "<<arr[i].pub_month<<endl;
    cout<<"ID "<<arr[i].id<<endl;
    }
    
    cout<<"Total Books are "<<n_vals<<endl;
    fr.close();
    delete []arr;   
    }
    
    else
    {
    cout<<"First Add detail";
    }
   
    }
