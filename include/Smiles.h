#pragma once

#include "Image.h"
#include "basetypes.h"

class BNode {
public:
    BNode();
    ~BNode();
    BNode * bTrue;
    BNode * bFalse;
    int sIndex;
    char nodeChar;
};

class SmileParser {
public:
    SmileParser();
    ~SmileParser();

    int findSmile(LPCTSTR *pstr);
    ImgListRef icons;

    StringVector smileAscii;

    bool hasSmiles(){return root!=NULL;}

protected:
    void loadSmiles();
    BNode* root;

    void addSmile(const char *smile, uint index);
};


class SmileBox {
private:
    SmileBox(){};
    //~SmileBox();
public:
    static void showSmileBox(HWND editBoxWnd, int x, int y, HWND parents,SmileParser *parser);
   int num;
private:
    HWND thisHwnd;
    HWND editBoxWnd;

    int nwidth;

    RECT clientRect; 

    SmileParser *parser;

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    static ATOM windowClass;
    static ATOM RegisterWindowClass();
};