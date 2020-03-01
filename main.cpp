#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string Function;
    string again;

    do{

        do{
            cout << "What would you like to do? " << endl;
            cout << "[1] Create a file " << endl;
            cout << "[2] Display a file " << endl;
            cout << "[3] Search a file " << endl;
            cout << "[9] Exit " << endl;
            cin >> Function;
        } while(Function != "1" && Function != "2" && Function != "3" && Function != "9");
        

        if(Function == "1"){
            string Answer = "yes";
            
            cout << "Please Enter File Name: ";
            string Filename;
            cin >> Filename;

            ofstream outfile(Filename + ".txt");
            outfile.close();

            while(Answer == "yes"){
                cout << "Please Enter Site Name: ";
                string Sitename;
                cin >> Sitename;

                cout << "Pleas Enter Username: ";
                string Username;
                cin >> Username;

                cout << "Please Enter Password: ";
                string Password;
                cin >> Password;

                outfile.open(Filename + ".txt", std::ios::app);
                outfile << "Website: " << Sitename << endl;
                outfile << "Username: " << Username << endl;
                outfile << "Password: " << Password << endl << endl;
                outfile.close();

                cout << "Would you like to add more data? " << endl;
                cin >> Answer;

                while(Answer != "yes" && Answer != "no"){
                    cout << "Must be yes or no." << endl;
                    cin >> Answer;
                }
            }
            
            if(Answer == "no"){
                cout << "File Created" << endl;
            }

        }

        if(Function == "2"){
            cout << "Please Enter File Name: ";
            string Filename;
            cin >> Filename;

            ifstream openfile(Filename + ".txt");
            if(openfile.is_open()){
                if (openfile.is_open()){
                    cout << openfile.rdbuf();
                }
            }
            if(openfile.fail()){
                cout << "File does not exist" << endl;
            }
        }
        if(Function == "3"){
            string line;
            string search;

            cout << "Please Enter Search Term:" << endl;
            cin  >> search;
            
            cout << "Please Enter File Name: ";
            string Filename;
            cin >> Filename;
            
            ifstream openfile(Filename + ".txt");

            size_t pos;
            while(openfile.good()){
                getline(openfile, line);
                pos = line.find(search);
                if(pos != string::npos){
                    cout << "Found" << endl;
                    cout << "Line: " << line << endl;
                }
            }
        }

        if(Function == "9"){
            break;
        }

        
        do{
            cout << "Would you like to return to menu?" << endl;
            cin >> again;
        }while(again != "yes" && again != "no");
    

    }while(again == "yes");
}