// Problema 1)
// #include <algorithm>
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <map>
// using namespace std;
//
// int main()
// {
//     ifstream inFile("input.txt");
//
//     int no_problems, no_doctors;
//     string name,spec;
//     vector<string> nameProb, specProb, nameDoc, specDoc;
//     inFile >> no_problems;
//
//     for (int i = 0; i < no_problems; i++)
//        {
//            inFile >> name;
//            inFile >> spec;
//             nameProb.emplace_back(name);
//             specProb.emplace_back(spec);
//        }
//
//     inFile >> no_doctors;
//
//     for (int i = 0; i < no_doctors; i++)
//        {
//            inFile >> name;
//            inFile >> spec;
//            nameDoc.emplace_back(name);
//            specDoc.emplace_back(spec);
//        }
//
//     for (int i = 0; i < no_problems; i++) {
//         auto foundDoc = find(specDoc.begin(), specDoc.end(),specProb[i]);
//         if (foundDoc != specDoc.end()) {
//             int foundDoctor = static_cast<int>(distance(specDoc.begin(), foundDoc));
//             cout << nameDoc[foundDoctor] << " " << nameProb[i] <<endl;
//             specDoc.erase(specDoc.begin()+foundDoctor,specDoc.begin()+foundDoctor+1);
//             nameDoc.erase(nameDoc.begin()+foundDoctor,nameDoc.begin()+foundDoctor+1);
//         }
//     }
//     return 0;
// }
//_______________________________________________________________________________________________________________________________________
// Bonus
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// int main() {
//     ifstream inFile("input4_bonus.txt");
//     int nrProb,nrDoc,timeProb;
//     string name,spec;
//     vector<string> nameProb,specProb,nameDoc,specDoc;
//     vector <vector <string>> medicProbs;
//     vector<int> timeDoc;
//     inFile >> nrProb;
//
//     for (int i = 0; i < nrProb; i++)
//     {
//         inFile >> name >> spec >> timeProb;
//         nameProb.emplace_back(name);
//         specProb.emplace_back(spec);
//         timeDoc.emplace_back(timeProb);
//     }
//     inFile >> nrDoc;
//     int timeArray[nrDoc];
//     for (int i = 0; i < nrDoc; i++)
//     {
//        inFile >> name;
//        inFile >> spec;
//        nameDoc.emplace_back(name);
//        specDoc.emplace_back(spec);
//     }
//     for (int i = 0; i < nrProb; i++) {
//         bool foundDr = false;
//         while(!foundDr) {
//             auto foundDoc = find(specDoc.begin(), specDoc.end(),specProb[i]);
//             if (foundDoc != specDoc.end()) {
//                 int foundDoctor = static_cast<int>(distance(specDoc.begin(), foundDoc));
//                 if(timeArray[foundDoctor] < 8) {
//                     // cout << nameDoc[foundDoctor] << " " << timeArray[foundDoctor] << " " << nameProb[i] <<endl;
//                     // timeArray[foundDoctor]+=timeDoc[foundDoctor];
//                     // foundDr = true;
//                     medicProbs[foundDoctor].emplace_back(specProb[i]);
//                     timeArray[foundDoctor] += timeDoc[i];
//                     foundDr = true;
//                 } else {
//                     specDoc.erase(specDoc.begin()+foundDoctor,specDoc.begin()+foundDoctor+1);
//                     nameDoc.erase(nameDoc.begin()+foundDoctor,nameDoc.begin()+foundDoctor+1);
//                 }
//             }
//             else foundDr=true;
//         }
//     }
//     for(int i = 0; i < nrDoc; i++) {
//         cout << nameDoc[i] << " " << timeDoc[i] << " ";
//         for(int j = 0; j < medicProbs.size(); j++)
//             cout << medicProbs[i][j] << " ";
//         cout << endl;
//     }
//
// }
//Optional:
class Doctor {
    public:
        Doctor(string name,string spec) {
            id = name;
            drSpec = spec;
        }
        vector<string> solvedProb;
        int timeRemain=0;
        int nrProb=0;
        string id,drSpec;
};
class Problem {
    public:
        Problem(string idProb,string idSpec,int time) {
            id=idProb;
            probSpec=idSpec;
            timeReq=time;
        }
        string id,probSpec;
        int timeReq;
};

int main() {
    ifstream inFile("input4_bonus.txt");

    int nrProb,nrDoc,time;
    string name,spec;
    vector<Problem> problems;
    vector<Doctor> doctors;
    inFile >> nrProb;

    for (int i = 0; i < nrProb; i++)
    {
        inFile >> name >> spec >> time;
        Problem problem(name,spec,time);
        problems.emplace_back(problem);
    }

    inFile >> nrDoc;
    for (int i = 0; i < nrDoc; i++)
    {
        inFile >> name >> spec;
        Doctor doctor(name,spec);
        doctors.emplace_back(doctor);
    }

    for (Problem  problem : problems) {
        auto foundDr = find_if(doctors.begin(), doctors.end(), [&problem](const Doctor& doctor) {
            return doctor.drSpec == problem.probSpec && doctor.timeRemain < 8 ;
        });
        if (foundDr != doctors.end()) {
            foundDr -> timeRemain += problem.timeReq;
            foundDr -> nrProb++;
            foundDr -> solvedProb.emplace_back(problem.id);
        }
    }
    for (const Doctor& doctor : doctors) {
        cout << doctor.id << " " << doctor.nrProb << " ";
        for (const string& prob : doctor.solvedProb) {
            cout << prob << " ";
        }
        cout << endl;
    }
}
