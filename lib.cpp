#include"definition.hpp"

int main(int argc, char *argv[])
{   
    arg=argv;
    Argc=argc;
    int op,id;
    char name[30];
        
    if(argc==1)
    {       ofstream fw("library.bin",ios::binary|ios::app);

            cout<<"Enter From the following "<<endl;
            cout<<"0.Exit"<<endl;
            cout<<"1.Add"<<endl;
            cout<<"2.Search by name"<<endl;
            cout<<"3.Search by author"<<endl;
            cout<<"4.Search by ID"<<endl;
            cout<<"5.Delete Book "<<endl;
            cout<<"6.Modify Details of Book "<<endl;
            cout<<"7.List of existing books "<<endl;
            cin>>op;

            cout<<"Usage of functions through command line arguments "<<endl;
            cout<<"For Addition-> File_name add author_name title ID pub_year pub_month "<<endl;
            cout<<"For Search -> File_name search_by_name book_name"<<endl;
            cout<<"For Search -> File_name search_by_ID ID Number"<<endl;
            cout<<"For Search -> File_name search_by_author author_name"<<endl;
            cout<<"For Delete -> File_name delete book_name"<<endl;
            cout<<"For Modifying Certain book -> File_name modify book_name"<<endl;
            cout<<"For displaying all Books-> File_name list  "<<endl;

            
            
            switch(op)
            {
                case 0:
                break;

                case 1:
                add();
                break;

                case 2:
                cout<<"Enter Book Name to search ";
                cin>>name;
                if(search_by_name(name)==-1)
                {
                cout<<"Not Present ";
                }
                else
                {
                cout<<" Present";
                }
                break;

                case 3:
                cout<<"Enter Author Name ";
                cin>>name;
                if(search_by_author(name)==1)
                cout<<"present ";
                break;
                
                case 4:
                cout<<"Enter ID to search ";
                cin>>id;
                if(search_by_ID(id)==1)
                cout<<"present ";
                break;
                
                case 5:
                cout<<"Enter Book to delete ";
                cin>>name;
                delete_book(name);
                break;

                case 6:
                cout<<"Enter Book Name whose details you want to modify ";
                cin>>name;
                modify(name);
                break;

                case 7:
                list();
                break;

                
                default:
                cout<<"Enter Correct Option";

            }
    }
    else
    {
     ofstream fw(argv[1],ios::binary|ios::app);

    if(strcmp(argv[2],"add")==0)
    { 
        addcomm();
    }      
    else if(strcmp(argv[2],"search_by_name")==0)
    { 
        search_by_name(argv[3]);
    }
    else if(strcmp(argv[2],"search_by_ID")==0)
    { 
        search_by_ID(atoi(argv[3]));
    }
    else if(strcmp(argv[2],"search_by_author")==0)
    { 
        search_by_author(argv[3]);
    }      
    else if(strcmp(argv[2],"delete")==0)
    { 
        delete_book(argv[3]);
    }
    
    else if(strcmp(argv[2],"modify")==0)
    { 
       modify(argv[3]);
    }

    else if(strcmp(argv[2],"list")==0)
    { 
       list();
    }
    
    }
       
}
