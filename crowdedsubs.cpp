#include<bits/stdc++.h>
#include "srtparser.h"

using namespace std;

struct subinfo{
  int start,finish,wordcount;
  string thesub;
};

int main(int argc, char** argv){
  SubtitleParserFactory *subParserFactory = new SubtitleParserFactory(argv[1]);
  SubtitleParser *parser = subParserFactory->getParser();
  vector<SubtitleItem*> sub = parser->getSubtitles();
  vector<subinfo> v;
  for(SubtitleItem * element : sub){
        subinfo current;
        current.start = element->getStartTime();
        current.finish = element->getEndTime();
        current.thesub = element->getText();
        current.wordcount = element->getWordCount();
        v.push_back(current);
  }
  int range = atoi(argv[2])*1000;
  string thetype = argv[3];
  int startindex,endindex,index = 0,currentmax = 0,currentscore = 0;
  for(int i = 0; i < v.size(); i ++){
    while(index < v.size()){
      if(v[index].finish - v[i].start <= range){
        if(thetype == "sub") currentscore ++;
        else if(thetype == "word") currentscore += v[index].wordcount;
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
  }
  cout << currentmax << endl;
}
