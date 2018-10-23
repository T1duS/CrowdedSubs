# CrowdedSubs
Calculates the part of the srt file which is no longer than a particular amount of time and contains the most amount of subtitles/words/characters

## Using it
* First clone the repository : `git clone https://github.com/T1duS/CrowdedSubs.git`
* Compile the program : `g++ crowdedsubs.cpp -o a`
* Run the program : `./a FILE_PATH TIMERANGE_IN_SECONDS CRITERIA(word/sub/character)`
## Examples
1: `./a tbbt.srt 120 sub` This will calculate the part of the srt file which is shorter than 2 minutes in length and contains the most amount of subtitles. <br>
2: `./a rickandmorty.srt 100 word` This will calculate the part of the srt file which is shorter than 100 seconds in length and contains the most amount of words. <br>
3: `./a sherlock.srt 42 character` This will calculate the part of the srt file which is shorter than 42 seconds in length and contains the most amount of characters. <br>
