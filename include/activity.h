#pragma once

#include <string>
#include "Image.h"
class actParse{
public:
    actParse();
    ~actParse();

    
    ImgListRef iconsact;

 int linesCount;
	char ***lines;//lines[i][1]-������� lines[vybor_moods2][0]-� ������

   

protected:
    void loadact();
  }; 