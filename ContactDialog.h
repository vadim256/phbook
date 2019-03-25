#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ContactDialog)
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(ContactDialog)
//*)

class ContactDialog: public wxDialog
{
	public:

		ContactDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ContactDialog();

		//(*Declarations(ContactDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		//*)

	protected:

		//(*Identifiers(ContactDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_PANEL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(ContactDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
