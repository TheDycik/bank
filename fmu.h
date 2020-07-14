//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TTabItem *tiAuth;
	TTabItem *tiBalance;
	TTabItem *tiPay;
	TTabItem *tiAdminPanel;
	TLabel *Label1;
	TEdit *edAuthLogin;
	TEdit *edAuthPw;
	TLabel *Label2;
	TTabItem *tiRegistration;
	TToolBar *tbReg;
	TButton *buToLogin;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *edRegLogin;
	TEdit *edRegName;
	TLabel *Label5;
	TEdit *edRegPw;
	TLabel *Label6;
	TEdit *edRegSurname;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *edRegPatronymic;
	TButton *buToReg;
	TLabel *Label9;
	TButton *Button1;
	TToolBar *tbAuth;
	TLabel *Label10;
	TToolBar *tbAuthReg;
	TButton *buDeleteUser;
	TToolBar *ToolBar1;
	TLabel *Label11;
	TGrid *grAdmin;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB1;
	TButton *buLogin;
	TButton *Button2;
	TButton *Button4;
	TLabel *laUserID;
	TLinkPropertyToField *LinkPropertyToFieldText;
	TStyleBook *StyleBook1;
	TButton *buPushMoney;
	TEdit *edMoneyAmmount;
	TButton *buPullMoney;
	TLabel *laUserMoney;
	TLinkPropertyToField *LinkPropertyToFieldText2;
	TLabel *laSum;
	TLinkControlToProperty *LinkControlToPropertyText;
	TToolBar *tbBalance;
	TLabel *laWelcome;
	TButton *buBalanceQuit;
	TBindSourceDB *BindSourceDB2;
	TLabel *Label12;
	TLabel *laFIO;
	TLabel *laMoney;
	TLabel *Label14;
	TLabel *lausname;
	TLabel *laUsername;
	TToolBar *ToolBar2;
	TButton *buPayOps;
	TToolBar *ToolBar3;
	TLabel *Label13;
	TLabel *Label15;
	TLabel *laOpsId;
	TButton *Button3;
	TButton *Button5;
	TLabel *Label16;
	TEdit *edIDPay;
	TEdit *edMoneyPay;
	TButton *buTransfer;
	void __fastcall buToRegClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buToLoginClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall buDeleteUserClick(TObject *Sender);
	void __fastcall buPushMoneyClick(TObject *Sender);
	void __fastcall buPullMoneyClick(TObject *Sender);
	void __fastcall edMoneyAmmountKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift);
	void __fastcall buLoginClick(TObject *Sender);
	void __fastcall buBalanceQuitClick(TObject *Sender);
	void __fastcall buPayOpsClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall buTransferClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
