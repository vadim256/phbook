/***************************************************************
 * Name:      BookMain.h
 * Purpose:   Defines Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef BOOKMAIN_H
#define BOOKMAIN_H

//(*Headers(BookFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class BookFrame: public wxFrame
{
    public:

        BookFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~BookFrame();

    private:

        //(*Handlers(BookFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(BookFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(BookFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BOOKMAIN_H
