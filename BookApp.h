/***************************************************************
 * Name:      BookApp.h
 * Purpose:   Defines Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef BOOKAPP_H
#define BOOKAPP_H

#include <wx/app.h>

class BookApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // BOOKAPP_H
