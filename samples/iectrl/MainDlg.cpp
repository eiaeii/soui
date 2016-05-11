// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"
#include "SDocHostUIHandler.h"
#include <helper/mybuffer.h>

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
} 

CMainDlg::~CMainDlg()
{
}


BOOL CMainDlg::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    SIECtrl *pIECtrl = FindChildByName2<SIECtrl>(L"iectrl_demo");
    IDocHostUIHandler *pDocHostUIHandler = new SDocHostUIHandler;
    pIECtrl->SetExternalUIHandler(pDocHostUIHandler);
    pDocHostUIHandler->Release();

    wchar_t szPath[MAX_PATH];
    GetModuleFileNameW(NULL,szPath,MAX_PATH);
    SStringW strUrl = SStringW(L"res://") + szPath + L"/test.htm";

    pIECtrl->GetIEObject()->Navigate(bstr_t(strUrl),NULL,NULL,NULL,NULL);
    return 0;
}

void CMainDlg::OnBtnCallJS()
{
    SIECtrl *pIECtrl = FindChildByName2<SIECtrl>(L"iectrl_demo");
    
    SArray<SStringW> params;
    params.Add(L"param1");
    ExecuteScript(pIECtrl->GetIEObject(),L"Test",params);
}

