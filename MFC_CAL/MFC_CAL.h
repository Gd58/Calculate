
// MFC_CAL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_CALApp: 
// �йش����ʵ�֣������ MFC_CAL.cpp
//

class CMFC_CALApp : public CWinApp
{
public:
	CMFC_CALApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_CALApp theApp;