#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;

    vector<string> doctors;
    vector<string> namePacient;
    vector<string> pacients;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        namePacient.push_back(name);
        inFile >> speciality;
        pacients.push_back(speciality);
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctors.push_back(speciality);
    }
    for(auto i = 0;i<pacients.size() ;i++) {
        int ok=1;
        for(auto j = 0;j<doctors.size() ;j++) {
            if(pacients[i] == doctors[j]) {
                cout<<namePacient[i]<<" ADMIS"<<endl;
                ok=0;
                break;
            }
        }
        if(ok) cout<<namePacient[i]<<" RESPINS"<<endl;
    }
    return 0;
}