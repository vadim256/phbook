#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(ContactDialog)
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(ContactDialog)
#include <wx/statline.h>
//*)
#include <wx/valtext.h>
#include <wx/string.h>
#include <wx/tokenzr.h>


#include "BookContact.h"


class ContactDialog: public wxDialog
{
	public:

		ContactDialog(wxWindow* parent);
		virtual ~ContactDialog();
		void SetContact(const Contact &);
        const Contact & GetContact();
		//(*Declarations(ContactDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxStaticLine* StaticLine1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(ContactDialog)
		//*)

	private:

		//(*Handlers(ContactDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		//*)
		void InitTmpVar();
		void TransferAndValidateInput();
        wxString m_FullName,
                 m_PhoneNumber,
                 m_City;

        Contact m_PrepareContact;

		DECLARE_EVENT_TABLE()

};

#endif
