//---------------------------------------------------------------------------


#pragma hdrstop

#include "dmu.h"
#include "fmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "FMX.Controls.TControl"
#pragma resource "*.dfm"
Tdm *dm;
//---------------------------------------------------------------------------
__fastcall Tdm::Tdm(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void Tdm::RegIns(UnicodeString aName, UnicodeString aSurname, UnicodeString aPatronymic, UnicodeString aLogin, UnicodeString aPW){

	spReg->ParamByName("THENAME")->Value = aName;
	spReg->ParamByName("SURNAME")->Value = aSurname;
	spReg->ParamByName("PATRONYMIC")->Value = aPatronymic;
	spReg->ParamByName("LOGIN")->Value = aLogin;
	spReg->ParamByName("PW")->Value = aPW;
	spReg->ExecProc();

}
void __fastcall Tdm::DataModuleCreate(TObject *Sender)
{
	FDConnection1->Connected = True;
	quAdminShow->Active = false;

	
}
void Tdm::LogDelete(int ID){

	spLogDel->ParamByName("ID")->Value = ID;
	spLogDel->ExecProc();

}
void Tdm::AccDelete(int ID){

	spLogDel->ParamByName("ID")->Value = ID;
	spLogDel->ExecProc();

}
////---------------------------------------------------------------------------
void Tdm::plusMoney(int ID, double money){

	spMoneyUpd->ParamByName("MONEY")->Value += money;
	spMoneyUpd->ParamByName("ID")->Value = ID;
	spMoneyUpd->ExecProc();
}
void Tdm::minusMoney(int ID, double money){

	spMoneyUpd->ParamByName("MONEY")->Value -= money;
	spMoneyUpd->ParamByName("ID")->Value = ID;
	spMoneyUpd->ExecProc();

}


void __fastcall Tdm::FDConnection1BeforeConnect(TObject *Sender)
{
	FDConnection1->Params->Values["DataBase"] = "..\\..\\db\\BANK.FDB";
}
//---------------------------------------------------------------------------

