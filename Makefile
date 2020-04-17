# Starterkit makefile for homework #7
# You may need to add -I flag to parse_hashtag compile command if you use your own rapidjson installation.
all:parse_tags parse_time
parse_tags: parse_hashtag.cc
	g++ -o pht parse_hashtag.cc
parse_time: time_parse.cc
	g++ -o tp time_parse.cc
