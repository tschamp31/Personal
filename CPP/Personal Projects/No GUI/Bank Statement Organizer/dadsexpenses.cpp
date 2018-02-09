#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {
  string line;
  int costcount;
  costcount = 0;
  double cost[341], total;
  string states[50] = {"AL","AK","AR","CA","CO","CT","DE","DC","FL","GA","HI","ID","IL","IN","IA","KS","KY","LA","ME","MD","MA","MI","MN","MS","MO","MT","NE","NV","NH","NJ","NM","NY","NC","ND","OH","OK","OR","PA","RI","SC","SD","TN","TX","UT","VT","VA","WA","WV","WI","WY"};
  string bankstatement[8] = {"C:/Users/Dope/Desktop/eStmt_2013-09-25.txt","C:/Users/Dope/Desktop/eStmt_2013-12-26.txt","C:/Users/Dope/Desktop/eStmt_2013-10-28.txt","C:/Users/Dope/Desktop/eStmt_2013-07-26.txt","C:/Users/Dope/Desktop/eStmt_2013-11-25.txt","C:/Users/Dope/Desktop/eStmt_2014-01-28.txt","C:/Users/Dope/Desktop/eStmt_2014-02-25.txt","C:/Users/Dope/Desktop/eStmt_2013-08-27.txt"};
  ofstream newfile, monitor;
  string::size_type sz;
  newfile.open("C:/Users/Dope/Desktop/dadspent.txt");
  monitor.open("C:/Users/Dope/Desktop/Monitor.txt");
  for (int m = 0; m < 8; m++)
  {
  ifstream myfile (bankstatement[m].c_str());
  if (myfile.is_open())
  {
    while (getline(myfile,line) )
    {
      for(int i = 0; i < 50; i++)
      {
        if(line.find(states[i]) != string::npos && !(line.find("WWW.NEWEGG.COM") != string::npos) && !(line.find("17017 E DE ANZA DR") != string::npos) && !(line.find("Change of address") != string::npos) && !(line.find("SAN FRANCISO") != string::npos) && !(line.find("To help you") != string::npos) && !(line.find("DEPOSIT") != string::npos) && !(line.find("FOUNTAIN") != string::npos) && !(line.find("CHAMPAGNE") != string::npos) && !(line.find("AZ") != string::npos) && !(line.find("LISA") != string::npos) && !(line.find("KEEP") != string::npos) && !(line.find("IMPORTANT") != string::npos) && !(line.find("BANK") != string::npos) && !(line.find("Wilmington") != string::npos) && !(line.find("Tampa") != string::npos) && !(line.find("SPRINT") != string::npos) && !(line.find("SYX*TIGERDIRECT.COM") != string::npos) && !(line.find("SYX*TIGERDIRECT.COM") != string::npos))
        {
          newfile << line << endl;
          cout << line << '\n';
          getline(myfile,line);
          if(atof(line.c_str()) == 0)
          {
          }
          else
          {
          cost[costcount] = atof(line.c_str());
          newfile << cost[costcount] << endl;
          cout << line << '\n';
          costcount++;
          }
        }
      }
    }
    newfile << endl;
    newfile << "----------------------------"<< bankstatement[m] << "----------------------------" << endl;
    newfile << endl;
    myfile.close();
  }
  else cout << "Unable to open file"; 
  }
  while(costcount >= 0)
  {
    if(cost[costcount] < 10000)
    {
      total += cost[costcount];
      costcount--;
    }
    else
    {
      costcount--;
    }
  }
  newfile << total << endl;
  cout << total << endl;
  cin.get();
  return 0;
}