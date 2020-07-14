//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
#include "dmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;
//---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buToRegClick(TObject *Sender)
{
	tc->ActiveTab = tiRegistration;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::FormCreate(TObject *Sender)
{
	tc->ActiveTab = tiAuth;
	tc->TabPosition = TTabPosition::None;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buToLoginClick(TObject *Sender)
{
	tc->ActiveTab = tiAuth;
    edAuthLogin->Text = "";
	edAuthPw->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button1Click(TObject *Sender)
{
	dm->RegIns(
		edRegName->Text,
		edRegSurname->Text,
		edRegPatronymic->Text,
		edRegLogin->Text,
		edRegPw->Text);
	ShowMessage("Вы успешно зарегестрированны!");
	tc->GotoVisibleTab(tiAuth->Index);
	edRegName->Text = "";
	edRegSurname->Text = "";
	edRegPatronymic->Text = "";
	edRegLogin->Text = "";
	edRegPw->Text = "";

}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button2Click(TObject *Sender)
{
//	tc->ActiveTab = tiAdminPanel;
//	dm->quAdminShow->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button4Click(TObject *Sender)
{
	tc->ActiveTab = tiAuth;
	dm->quAdminShow->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buDeleteUserClick(TObject *Sender)
{
	int ID = StrToInt(laUserID->Text);
	dm->quAdminShow->Delete();
	dm->AccDelete(ID);
	dm->LogDelete(ID);

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buPushMoneyClick(TObject *Sender)
{
	double money = StrToFloat(laSum->Text);
	int ID = StrToInt(laUserID->Text);
	dm->quAdminShow->Edit();
	dm->plusMoney(ID, money);
	dm->quAdminShow->Post();
	edMoneyAmmount->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buPullMoneyClick(TObject *Sender)
{
	double money = StrToFloat(laSum->Text);
	int ID = StrToInt(laUserID->Text);
	dm->quAdminShow->Edit();
	dm->minusMoney(ID, money);
	dm->quAdminShow->Post();
	edMoneyAmmount->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall Tfm::edMoneyAmmountKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	double sum = StrToFloat(edMoneyAmmount->Text) + StrToFloat(laUserMoney->Text);
	laSum->Text = FloatToStr(sum);

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buLoginClick(TObject *Sender)
{
	UnicodeString login = edAuthLogin->Text;
	UnicodeString pw = edAuthPw->Text;

	dm->quLogin->Close();
	dm->quLogin->SQL->Clear();
	dm->quLogin->SQL->Add("SELECT * FROM LOGINUSER, ACCPROFILES WHERE LOGINUSER.LOGIN = '" + login + "' AND LOGINUSER.PW = '" + pw + "' AND LOGINUSER.ID = ACCPROFILES.ID");
	dm->quLogin->Open();
	UnicodeString x = dm->quLogin->FieldByName("LOGIN")->AsString;

	UnicodeString thename = dm->quLogin->FieldByName("THENAME")->AsString;



	if (login == "dyc" && pw == "pypyc")
	{
		tc->ActiveTab = tiAdminPanel;
		dm->quAdminShow->Active = true;
	}
	else if(dm->quLogin->IsEmpty()){

		ShowMessage("Введены неверные данные!");
	}
	else if((login == dm->quLogin->FieldByName("LOGIN")->AsString) &&
			(pw == dm->quLogin->FieldByName("PW")->AsString)){

		tc->ActiveTab = tiBalance;
		laWelcome->Text = "Добро пожаловать," + thename;
//		+ thename;
		laFIO->Text = dm->quLogin->FieldByName("SURNAME")->AsString + " " + dm->quLogin->FieldByName("THENAME")->AsString;
		laMoney->Text = dm->quLogin->FieldByName("MONEY")->AsString + " руб.";
		laUsername->Text = dm->quLogin->FieldByName("LOGIN")->AsString;
		laOpsId->Text = dm->quLogin->FieldByName("ID")->AsString;


	}
}

//---------------------------------------------------------------------------

void __fastcall Tfm::buBalanceQuitClick(TObject *Sender)
{
	tc->ActiveTab = tiAuth;
	edAuthLogin->Text = "";
	edAuthPw->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall Tfm::buPayOpsClick(TObject *Sender)
{
	tc->ActiveTab = tiPay;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::Button3Click(TObject *Sender)
{
	tc->ActiveTab = tiBalance;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall Tfm::buTransferClick(TObject *Sender)
{
//	int opsId = StrToInt(laOpsId->Text);
//	int trId = StrToInt(edIDPay->Text);
//	double trMoney = StrToFloat(edMoneyPay->Text);
//
//
//	if(StrToFloat(laMoney->Text) >= trMoney){
//		dm->quTransf->Edit();
//		dm->plusMoney(opsId, trMoney);
//		dm->minusMoney(trId, trMoney);
//		dm->quTransf->Post();
//		dm->quLogin->Refresh();
//		dm->quAdminShow->Refresh();
//	}else{
//		ShowMessage("Недостаточно средств!");
//	}
}
//---------------------------------------------------------------------------

