
#include<iostream>
#include <ctime>
#include "ttime.h"
using namespace std;

TTime::TTime()
{
    now = time(0);
    ltm=localtime(&now);
    seconds= ltm->tm_sec;
    minutes=ltm->tm_min;
    hour=ltm->tm_hour;
}
 TTime::TTime(int hour, int minutes,int seconds )
 {
    this->seconds=seconds;
    this->minutes=minutes;
    this->hour=hour;
}
TTime::TTime( int hour,int minutes )
 {
    this->seconds=0;
    this->minutes=minutes;
    this->hour=hour;
}
void TTime::set_seconds(int day)
{
    this->seconds=seconds;
}
void TTime::set_minutes(int month)
{
    this->minutes=minutes;
}
void TTime::set_hour(int year)
{
    this->hour=hour;
}
void TTime::print()
{
    //cout <<hour  <<":"<<minutes<<":"<<seconds<< endl;
    printf("%02d:%02d:%02d\n", hour, minutes, seconds);
}


void TTime::load(ifstream& file)
{
   string line;
    string value;
    pos position;
    getline(file,line);
    value=parseLine(line,&position);
    while((line.find("</Time>") == -1)){
         if(!value.compare("Hour"))
        {

        string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
         this->hour = atoi(sub_value.c_str());
         //ut<<this->hour<<endl;
        }
        else if(!value.compare("Minute"))
        {
            string sub_value=line.substr(position.startpos+value.size()+1,position.endpos-position.startpos-value.size()-3);
            this->minutes =atoi(sub_value.c_str());
             //ut<<this->minutes<<endl;
        }
            getline(file,line);
            value=parseLine(line,&position);


    }
    this->seconds = 0;
}

string TTime::parseLine(string line, pos *position)
{
    string value;
    position->startpos=line.find("<");
    position->endpos=line.find(">");
    value=line.substr(position->startpos+1,position->endpos-position->startpos-1);
    position->startpos=line.find(value);
    position->endpos=line.find(value,  position->startpos+1);
    return value;
}
