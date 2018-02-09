#define CURL_STATICLIB
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


void retrieveFile(string name)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;

    string baseurl= "https://smite.guru/stats/";
    string final = baseurl + name;

    const char *url = final.c_str();    

    curl = curl_easy_init();
    if (curl)
    {
      fp = fopen("testing.txt","wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);//opens the said url
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);//Follows redirect
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);//Disable ssl
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);//checks for errors
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

string delUnnecessary(string &str)
{
    int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' && str[i+1] == ' ')
            {
                str.erase(str.begin() + i);
            }
            else if(str[0]== ' ')
            {
                str.erase(str.begin());
            }
            else if(str[i] == '\0' && str[i-1]== ' ')
            {
                str.erase(str.end() - 1);
            }
        }
    }
    return str;
}

bool is_number(const std::string& s)
{
    return( strspn( s.c_str(), "%,-.0123456789" ) == s.size() );
}

vector<string> retrievePlayerInfo(string playerName)
{
//conquest rank - 184, elo - 191, played - 203, win% - 209
//joust rank - 244, elo - 251, played - 263, win% - 269
//casual mmr - 1311
  vector<string> answer(9);
  string joustRank, conquestRank, line;
  int joustElo, joustPlayed, joustWinPercent, conquestElo, conquestPlayed, conquestWinPercent, casualMMR, lineCount, lineTracker, i;
  int positions[] = {183,190,202,208,243,250,262,268,1310};
  string::size_type s = 0;
  string deliminators[] = {"<small>", "</small>", "<strong>", "</strong>", "<br>", "</div>", "<h3 class=\"widget-content-light\">", "<div class=\"widget-simple themed-background-dark\">", "<div class=\"text-muted\">","<small style=\"font-style: italic;\">Free Agent"};
  lineTracker = 0;
  lineCount = 0;

  ifstream playerFile;
  playerFile.open("testing.txt");

  cout << playerName << endl;
  while(!playerFile.eof())
  {
    while(getline(playerFile, line))
    {
      if(line.compare("                        SmiteGuru <strong>Score</strong>") == 0)//Finds the casual mmr.
      {
        positions[lineTracker] = lineCount + 7;
      }

      if(lineCount == positions[lineTracker])
      {
        for(i = 0; i != 10; i++)
        {
          if((s = line.find(deliminators[i],s)) != string::npos)
          {
            line.erase(s,deliminators[i].size());
          }
          s = 0;
        }
        line = delUnnecessary(line);
        if(line.empty() && (lineTracker == 0 || lineTracker == 4))
        {
          line = "Unranked";
        }
        else if(line.empty())
        {
          line = "N/A";
        }
        else if(!is_number(line) && (lineTracker == 1 || lineTracker == 2 || lineTracker == 3 || lineTracker == 5 || lineTracker == 6 || lineTracker == 7))
        {
          line = "N/A";
        }
        answer[lineTracker] = line;
        lineTracker++;
      }
      lineCount++;
    }
  }
  return answer;
}

int main(int argc, char const *argv[])
{
  vector<string> niggers;
  int i;

  retrieveFile("hellokittylink");
  niggers = retrievePlayerInfo("hellokittylink");

  for(i = 0; i != 9; i++)
  {
   cout << niggers[i] << endl;
  }
  system("PAUSE");
  return 0;
}