#include<bits/stdc++.h> // includes all the standard c++ libraries
#include "srtparser.h" // includes srtparser made by Saurabh Shrivastava

using namespace std;

// made another struct to store subtitle info cuz I don't like dealing with pointers and stuff
struct subinfo{
  int start,finish,wordcount,charcount;
  string thesub;
};

int main(int argc, char** argv){

  if(argc < 4){
    cout << "Too few arguments\n";
    return 0;
  }

  SubtitleParserFactory *subParserFactory = new SubtitleParserFactory(argv[1]); // Initializing SrtParser Factory object
  SubtitleParser *parser = subParserFactory->getParser(); // Snippet picked from srtparser readme file, idk what it means as well

  vector<SubtitleItem*> sub = parser->getSubtitles();
  vector<subinfo> v;
  // Adding all the required subtitle info to a vector
  for(SubtitleItem * element : sub){
        subinfo current;
        current.start = element->getStartTime();
        current.finish = element->getEndTime();
        current.thesub = element->getText();
        current.wordcount = element->getWordCount();
        current.charcount = current.thesub.length();
        v.push_back(current);
  }
  int range = atoi(argv[2])*1000; // range in milli seconds
  string thetype = argv[3];

  // Using 2-pointer technique to calculate the answer
  int startindex,endindex,index = 0,currentmax = 0,currentscore = 0;
  for(int i = 0; i < v.size(); i ++){
    while(index < v.size()){
      if(v[index].finish - v[i].start <= range){
        if(thetype == "sub") currentscore ++;
        else if(thetype == "word") currentscore += v[index].wordcount;
        else if(thetype == "character") currentscore += v[index].charcount;
        index ++;
      }
      else break;
    }
    if(currentscore > currentmax){
      currentmax = currentscore;
      startindex = i;
      endindex = index-1;
    }
    if(thetype == "sub") currentscore --;
    else if(thetype == "word")currentscore -= v[i].wordcount;
    else if(thetype == "character")currentscore -= v[i].charcount;
  }
  // ------------------------------------------------

  // Now is just the printing stuff

  cout << "The " << atoi(argv[2]) << " seconds range with most amount of " << thetype << "s has " << currentmax << " " << thetype << "s." << endl;

  cout << "Type 1 if you want to see the list of subs: " << flush;

  char inputforsubshowing; cin >> inputforsubshowing;
  if(inputforsubshowing != '1') return 0;



  for(int i = startindex; i != endindex; i ++){
    cout << v[i].start << " - " << v[i].finish << " : " << v[i].thesub << endl;
  }
}
