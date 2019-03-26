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
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/srchctrl.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
//*)
#include "BookDB.h"
#include "ContactDialog.h"

class BookFrame: public wxFrame
{
    public:

        BookFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~BookFrame();

    private:

        //(*Handlers(BookFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSplitterWindow1SashPosChanging(wxSplitterEvent& event);
        void OnToolBarItem1Clicked(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(BookFrame)
        static const long ID_SEARCHCTRL1;
        static const long ID_LISTBOX1;
        static const long ID_TEXTCTRL1;
        static const long ID_SPLITTERWINDOW1;
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long idNewContact;
        static const long idUpdateContact;
        static const long idDeleteContact;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(BookFrame)
        wxListBox* ListBox1;
        wxMenuItem* MenuItem3;
        wxSearchCtrl* SearchCtrl1;
        wxSplitterWindow* SplitterWindow1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxToolBar* ToolBar1;
        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem3;
        //*)
        BookDB m_BookDB;
        DECLARE_EVENT_TABLE()
};

#endif // BOOKMAIN_H
