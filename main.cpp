#include <iostream>
#include <fstream>
using namespace std;

void deleteLine();
void replaceLine();
void copyFile();

int main(){
    string Function;    //changed from int to string to stop infinite loop
    string again;       //Keep while loop going if user replies with "yes"

    do{

        do{
            cout << "What would you like to do? " << endl;
            cout << "[1] Create a file " << endl;
            cout << "[2] Display a file " << endl;
            cout << "[3] Search a file " << endl;
            cout << "[4] Remove lines from file " << endl;
            cout << "[5] Replace lines from file " << endl;
            cout << "[6] copy a file " << endl;
            cout << "[9] Exit " << endl;
            cin >> Function;
        } while(Function != "1" && Function != "2" && Function != "3" && Function != "4" && Function != "5" && Function != "6" && Function != "9"); //Only numbers 1,2,3,9 are allowed, other inputs result in question again
        

        if(Function == "1"){
            string Answer = "yes";
            
            cout << "Please Enter File Name: ";
            string Filename;
            cin >> Filename;

            ofstream outfile(Filename + ".txt"); //opens the file created by user
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

                outfile.open(Filename + ".txt", std::ios::app); //opens file and writes at the end of the text file(ios:app)(append)
                outfile << "Website: " << Sitename << endl;
                outfile << "Username: " << Username << endl;
                outfile << "Password: " << Password << endl << endl;
                outfile.close();

                cout << "Would you like to add more data? " << endl;
                cin >> Answer;

                while(Answer != "yes" && Answer != "no"){ //repeats question if user doesn't provide correct arugements yes/no
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
                    cout << openfile.rdbuf(); //prints all contents of textfile
                }
                cout << endl;
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
                if(pos != string::npos){ //if postion doesnt equal no postion meaning it was found
                    cout << "Found" << endl;
                    cout << "Line: " << line << endl; //prints entire line
                }
            }
        }

        if(Function == "4"){
            deleteLine();
        }

        if(Function == "5"){
            replaceLine();
        }

        if(Function == "6"){
            copyFile();
        }

        if(Function == "9"){
            break;
        }

        
        do{
            cout << "Would you like to return to menu?" << endl;
            cin >> again;
        }while(again != "yes" && again != "no"); //repeats question if user doesn't provide correct arugements yes/no
    

    }while(again == "yes");
}

//Opens file and deletes the lines that user no longer wants
void deleteLine(){
    string deletePhrase;
    string line;

    cout << "Which file would you like to delete lines in?" << endl;
    string file;
    cin >> file;

    ifstream openfile(file + ".txt");
    ofstream tempfile("tempfile.txt");

    cout << "which line would you like to remove?" << endl;
    cin >> deletePhrase;


    while(openfile >> line){
        if(line != deletePhrase){
            tempfile << line << endl;
        }
    }
    rename("tempfile.txt", "LinesDeleted.txt");
    remove((file + ".txt").c_str());
}

//replaces lines that user doesnt want anymore with "replaced"
void replaceLine(){
    string replacePhrase;
    string newPhrase;
    string line;

    cout << "Which file would you like to replace lines in" << endl;
    string file;
    cin >> file;

    ifstream openfile(file + ".txt");
    ofstream tempfile("tempfile.txt");

    cout << "Which line would you like to replace?" << endl;
    cin >> replacePhrase;

    cout << "What would you like to replace the line with?" << endl;
    cin >> newPhrase;


    while(openfile >> line){

        if(line == replacePhrase){
            tempfile << "REPLACED"; // if line has the user input then they are replaced
        }
        else{
            tempfile << line; //if not the lines are just copied over
        }
        tempfile << endl;
    }
    rename("tempfile.txt", "LinesReplaced.txt");
    //remove((file + ".txt").c_str());
}

void copyFile() {
    string line;
    string copy;

    cout << "Which file would you like to copy?" << endl;
    string file;
    cin >> file;

    ifstream openfile(file + ".txt");
    ofstream tempfile("tempfile.txt");

    if(openfile.is_open()){
        while(getline(openfile, line)){ //while loop to read each line of the file
        tempfile << line << endl;       //print each line into a new temp file
        }
    }

    cout << "What would you like to name the copy?" << endl;
    cin >> copy;

    rename("tempfile.txt", (copy + ".txt").c_str()); //c_str to allow rename to work

}