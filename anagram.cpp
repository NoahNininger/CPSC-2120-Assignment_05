/*
 * Name: Noah Nininger
 * Date Submitted: 03/16/23
 * Assignment Name: Single-Word Anagram Finder
 */

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> loadWordlist(string filename)
{
    string word;
    vector<string> words;   // vector that will hold words

    ifstream in;
    in.open(filename);
    if(in.is_open())
    {
        while(getline(in,word)) // reads each line
        {
            if(word.length() > 0)
                { words.push_back(word); }  // pushes word in vector
        }
        in.close();
    }

    return words;
}

vector<string> anagram(string word, vector<string> wordlist)
{
    string item;
    vector<string> anagramVector;
        
 // loops through each item in wordlist
    for(long unsigned int i = 0; i < wordlist.size(); i++)
    {
     // remove item from wordlist
        item = wordlist[i];
        
     // initialize unordered map to match number of characters in both strings
        unordered_map<char,int> map;

        if(word.length() != item.length())  // not an anagram
            { continue; }
        
     // increase key values for characters in string word
        for(long unsigned int j = 0; j < word.length(); j++)
            { map[word[j]]++; }
        
        for(long unsigned int j = 0; j < item.length(); j++)
        {
            if(map.find(item[j])==map.end())    // not an anagram
                { break; }
            else
            {
             // decrease key values for characters in string item
                map[item[j]]--;

             // if all characters are zero, map is empty
                if(map[item[j]]==0)
                    { map.erase(item[j]); }
            }
        }

        if(map.size() == 0)     // empty map
            { anagramVector.push_back(item); }    
    } 

  return anagramVector;
}
