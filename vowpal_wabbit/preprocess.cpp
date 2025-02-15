#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char **argv)
{
  std::ifstream tweetFile;
  std::ofstream outFile;
  std::string tmpStr, fullStr, outFileStr;


  tweetFile.open(argv[1]);
  //  outFile.open("nolines_tweet_data.txt.tmp");
  //outFile.open("first_data_set.txt");
  outFileStr = argv[1];
  outFileStr += ".processed";
  outFile.open(outFileStr.c_str());
  std::cout << "Outputting to " << outFileStr << "\n";
  if(tweetFile.is_open() && outFile.is_open())
    {
      while(!tweetFile.eof())
	{
	nextline:
	  getline(tweetFile, tmpStr);

	  /*	  if(strcmp(tmpStr.c_str(), "*|*|*") == 0)
	    {
	      outFile << fullStr << "\n*|*|*\n";
	      fullStr = "";
	    }
	  else
	    {
	      fullStr += tmpStr + " ";
	      } */
	  if(strcmp(tmpStr.c_str(), "*|*|*") != 0)
	    {
	      
	    
	      for(int i = 0; i < tmpStr.size(); i++)
		{
		  if(!isascii(tmpStr.at(i)))
		    {
		      goto nextline;
		    }

		  if(strncmp(tmpStr.substr(i,7).c_str(), "http://", 7) == 0)
		    {

		      while(!isspace(tmpStr.at(i)) && i < tmpStr.size() - 1)
			{
			  i++;
			}
		      if(i == tmpStr.size()-1)
			{
			  break;
			}
		    }



		  if(!isalnum(tmpStr.at(i)) && tmpStr.at(i) != '@' && tmpStr.at(i) != '|' && tmpStr.at(i) != '_' && tmpStr.at(i) != '#') // checks for punctuation and replaces them with spaces
		    {
		      tmpStr.replace(i,1, " ");
		    }

		  tmpStr.at(i) = tolower(tmpStr.at(i)); // makes all characters lowercase

		}
	      
	      fullStr += tmpStr + " ";


	    }
	  else
	    {
	      if(fullStr.size() > 0)
		{
		  outFile << fullStr << "\n";
		  fullStr = "";
		}
	    }
	  


	}

      tweetFile.close();
      outFile.close();

    }
  else
    {
      std::cout << "Error opening files.\n";
      return 1;
    }

}
