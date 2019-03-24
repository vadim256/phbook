/***************************************************************
 * Name:      BookApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "BookApp.h"

//(*AppHeaders
#include "BookMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(BookApp);

bool BookApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	BookFrame* Frame = new BookFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
