#pragma once

class CFormatMsgDlg : public SHostDialog
{
public:
    CFormatMsgDlg(void);
    ~CFormatMsgDlg(void);
    
    void OnOK();
    
    SStringT m_strMsg;
    
    EVENT_MAP_BEGIN()
        EVENT_ID_COMMAND(IDOK,OnOK)
        CHAIN_EVENT_MAP(SHostDialog)
    EVENT_MAP_END()
        
};

