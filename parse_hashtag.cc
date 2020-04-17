//
// File: parse_hashtags.cc
// Author: David W. Juedes
//
// Purpose: Prints out the hashtags associated with specific tweets
//
// This code is based off an example here:
// rapidjson/example/simpledom/simpledom.cpp
// But, it has been heavily modified!!!!
//
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>
using namespace rapidjson;
using namespace std;
int main(int argc, char *argv[]) {

  int i=0;
  while (!cin.eof()) {
    string line;
    getline(cin,line);
    if (!cin.fail()) {
      Document d;
      d.Parse(line.c_str());
      
      if (d.HasMember("text")) {
	//cout << "Tweet " << i << d["text"].GetString() << endl;
	i++;
      }
      if (d.HasMember("entities")) { // Or twitter_entities
	//cout << "Has entities" << endl;
	Value& a = d["entities"];
	if (a.HasMember("hashtags")) {
	  //cout << "Has hashtags" << endl;
	  Value& a1 = a["hashtags"];
	  
	  if (a1.IsArray()) {
	    for (SizeType j = 0; j < a1.Size(); j++) {
	      if (a1[j].HasMember("text")) {
		Value& a2 = a1[j]["text"];
		
		if (a2.IsString()) {
		  cout << "Hashtag " << a2.GetString() << endl;
		}
	      }
	    }
	  }
	}
	
      }
    }
  }
}

