//---------------------------------------------------------------------------

#ifndef dmuH
#define dmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IBBase.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
//---------------------------------------------------------------------------
class Tdm : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDGUIxWaitCursor *FDGUIxWaitCursor1;
	TFDPhysFBDriverLink *FDPhysFBDriverLink1;
	TFDStoredProc *spReg;
	TFDQuery *quAdminShow;
	TIntegerField *quAdminShowID;
	TWideStringField *quAdminShowLOGIN;
	TWideStringField *quAdminShowPW;
	TWideStringField *quAdminShowTHENAME;
	TWideStringField *quAdminShowSURNAME;
	TWideStringField *quAdminShowPATRONYMIC;
	TFDStoredProc *spAccDel;
	TFDStoredProc *spLogDel;
	TFDTable *FDTable1;
	TFMTBCDField *quAdminShowMONEY;
	TFDStoredProc *spMoneyUpd;
	TFDQuery *quLogin;
	TFDQuery *quBalanceShow;
	TFDQuery *quTransf;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall FDConnection1BeforeConnect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tdm(TComponent* Owner);
	void RegIns(UnicodeString aName, UnicodeString aSurname, UnicodeString aPatronymic,
		 UnicodeString aLogin, UnicodeString aPW);
	void LogDelete(int ID);
	void AccDelete(int ID);
	void plusMoney(int ID, double money);
	void minusMoney(int ID, double money);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
//---------------------------------------------------------------------------
#endif
