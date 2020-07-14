object dm: Tdm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 395
  Width = 458
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=D:\mobile\git1\bankHW\db\BANK.FDB'
      'User_Name=SYSDBA'
      'Password=masterkey'
      'CharacterSet=UTF8'
      'DriverID=FB')
    Connected = True
    LoginPrompt = False
    BeforeConnect = FDConnection1BeforeConnect
    Left = 176
    Top = 56
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'FMX'
    Left = 64
    Top = 56
  end
  object FDPhysFBDriverLink1: TFDPhysFBDriverLink
    Left = 64
    Top = 104
  end
  object spReg: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'REG_INS'
    Left = 176
    Top = 160
    ParamData = <
      item
        Position = 1
        Name = 'THENAME'
        DataType = ftWideString
        ParamType = ptInput
        Size = 50
      end
      item
        Position = 2
        Name = 'SURNAME'
        DataType = ftWideString
        ParamType = ptInput
        Size = 50
      end
      item
        Position = 3
        Name = 'PATRONYMIC'
        DataType = ftWideString
        ParamType = ptInput
        Size = 50
      end
      item
        Position = 4
        Name = 'LOGIN'
        DataType = ftWideString
        ParamType = ptInput
        Size = 10
      end
      item
        Position = 5
        Name = 'PW'
        DataType = ftWideString
        ParamType = ptInput
        Size = 10
      end>
  end
  object quAdminShow: TFDQuery
    CachedUpdates = True
    Connection = FDConnection1
    UpdateOptions.AssignedValues = [uvEDelete]
    SQL.Strings = (
      'select '
      '    loginuser.id,'
      '    loginuser.login,'
      '    loginuser.pw,'
      '    accprofiles.thename,'
      '    accprofiles.surname,'
      '    accprofiles.patronymic,'
      '    accprofiles.money'
      'from loginuser,'
      'accprofiles'
      'where '
      '   ('
      '      (loginuser.id <> 1)'
      '   and '
      '      (accprofiles.id <> 1)'
      '   and'
      '      (loginuser.id = accprofiles.id)'
      '   )')
    Left = 176
    Top = 104
    object quAdminShowID: TIntegerField
      FieldName = 'ID'
      Origin = 'ID'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object quAdminShowLOGIN: TWideStringField
      FieldName = 'LOGIN'
      Origin = 'LOGIN'
      Required = True
      Size = 10
    end
    object quAdminShowPW: TWideStringField
      FieldName = 'PW'
      Origin = 'PW'
      Required = True
      Size = 10
    end
    object quAdminShowTHENAME: TWideStringField
      AutoGenerateValue = arDefault
      FieldName = 'THENAME'
      Origin = 'THENAME'
      ProviderFlags = []
      ReadOnly = True
      Size = 50
    end
    object quAdminShowSURNAME: TWideStringField
      AutoGenerateValue = arDefault
      FieldName = 'SURNAME'
      Origin = 'SURNAME'
      ProviderFlags = []
      ReadOnly = True
      Size = 50
    end
    object quAdminShowPATRONYMIC: TWideStringField
      AutoGenerateValue = arDefault
      FieldName = 'PATRONYMIC'
      Origin = 'PATRONYMIC'
      ProviderFlags = []
      ReadOnly = True
      Size = 50
    end
    object quAdminShowMONEY: TFMTBCDField
      AutoGenerateValue = arDefault
      FieldName = 'MONEY'
      Origin = 'MONEY'
      ProviderFlags = []
      ReadOnly = True
      Precision = 18
      Size = 2
    end
  end
  object spAccDel: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'ACCPROFILES_DEL'
    Left = 240
    Top = 160
    ParamData = <
      item
        Position = 1
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
      end>
  end
  object spLogDel: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'ACCPROFILES_DEL'
    Left = 304
    Top = 160
    ParamData = <
      item
        Position = 1
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
      end>
  end
  object FDTable1: TFDTable
    Connection = FDConnection1
    Left = 240
    Top = 56
  end
  object spMoneyUpd: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'ACCPROFILES_UPD'
    Left = 368
    Top = 160
    ParamData = <
      item
        Position = 1
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'MONEY'
        DataType = ftFMTBcd
        Precision = 15
        NumericScale = 2
        ParamType = ptInput
        Value = 0.000000000000000000
      end>
  end
  object quLogin: TFDQuery
    Connection = FDConnection1
    Left = 240
    Top = 104
  end
  object quBalanceShow: TFDQuery
    Connection = FDConnection1
    Left = 304
    Top = 104
  end
  object quTransf: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'select '
      '    accprofiles.id,'
      '    accprofiles.money'
      'from accprofiles')
    Left = 368
    Top = 104
  end
end
