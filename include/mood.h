#pragma once

#include <string>
#include "Image.h"
class moodParse{
public:
    moodParse();
    ~moodParse();

   
    ImgListRef iconsMood;

 int linesCount;
	char ***lines;//lines[i][1]-������� lines[vybor_moods2][0]-� ������

   

protected:
    void loadMood();
  }; 
