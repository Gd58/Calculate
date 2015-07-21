
// MFC_CALDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_CAL.h"
#include "MFC_CALDlg.h"
#include "afxdialogex.h"
#include <string.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_CALDlg 对话框



CMFC_CALDlg::CMFC_CALDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CALDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	nFirst = 0;//the value of the first number
	 
	nSecond = 0;//the value of the second number
	
	FirstState = false;//the state of the first number

	SecondState = false;//the state of the second mumber

	SignState = false;//the state of the sign

	Result = 0;//结果//result

	SignType = 0;
	FirstEdit = false;
}

void CMFC_CALDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_CALDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ONE, &CMFC_CALDlg::OnBnClickedOne)
	ON_BN_CLICKED(IDC_TWO, &CMFC_CALDlg::OnBnClickedTwo)
	ON_BN_CLICKED(IDC_THREE, &CMFC_CALDlg::OnBnClickedThree)
	ON_BN_CLICKED(IDC_FOUR, &CMFC_CALDlg::OnBnClickedFour)
	ON_BN_CLICKED(IDC_FIVE, &CMFC_CALDlg::OnBnClickedFive)
	ON_BN_CLICKED(IDC_SIX, &CMFC_CALDlg::OnBnClickedSix)
	ON_BN_CLICKED(IDC_SEVEN, &CMFC_CALDlg::OnBnClickedSeven)
	ON_BN_CLICKED(IDC_EIGHT, &CMFC_CALDlg::OnBnClickedEight)
	ON_BN_CLICKED(IDC_NINE, &CMFC_CALDlg::OnBnClickedNine)
	ON_BN_CLICKED(IDC_ZERO, &CMFC_CALDlg::OnBnClickedZero)
	ON_BN_CLICKED(IDC_PLUS, &CMFC_CALDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MIUTE, &CMFC_CALDlg::OnBnClickedMiute)
	ON_BN_CLICKED(IDC_MULTIPLE, &CMFC_CALDlg::OnBnClickedMultiple)
	ON_BN_CLICKED(IDC_DEVISION, &CMFC_CALDlg::OnBnClickedDevision)
	ON_BN_CLICKED(IDC_EQUAL, &CMFC_CALDlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// CMFC_CALDlg 消息处理程序

BOOL CMFC_CALDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_CALDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_CALDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_CALDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_CALDlg::OnBnClickedOne()
{
	// TODO:  在此添加控件通知处理程序代码

	if (SignState)
	{
		
		nSecond = nSecond * 10 + 1;
		Str += "1";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		
			nFirst = nFirst * 10 + 1;
			Str += "1";
			SetDlgItemText(IDC_EDIT, Str);

			FirstState = true;
	
	}
}


void CMFC_CALDlg::OnBnClickedTwo()
{
	// TODO:  在此添加控件通知处理程序代码

	if (SignState)
	{
		nSecond = nSecond * 10 + 2;
		Str += "2";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 2;
		Str += "2";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
}


void CMFC_CALDlg::OnBnClickedThree()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 3;
		Str += "3";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 3;
		Str += "3";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedFour()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 4;
		Str += "4";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 4;
		Str += "4";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedFive()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 5;
		Str += "5";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 5;
		Str += "5";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedSix()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 6;
		Str += "6";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}

		nFirst = nFirst * 10 + 6;
		Str += "6";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedSeven()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 7;
		Str += "7";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 7;
		Str += "7";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedEight()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 8;
		Str += "8";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 8;
		Str += "8";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedNine()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 9;
		Str += "9";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 9;
		Str += "9";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedZero()
{
	if (SignState)
	{
		nSecond = nSecond * 10 + 0;
		Str += "0";
		SetDlgItemText(IDC_EDIT, Str);
		SecondState = true;
	}
	else
	{
		if (FirstEdit == false)
		{
			FirstEdit = true;
			Str.Empty();

		}
		nFirst = nFirst * 10 + 0;
		Str += "0";
		SetDlgItemText(IDC_EDIT, Str);

		FirstState = true;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedPlus()
{
	if (FirstState)
	{

		SignState = true;

		Str += "+";

		SignType = 1;

		SetDlgItemText(IDC_EDIT, Str);
	}

	else
	{
		nFirst = Result;

		SignState = true;

		Str.Empty();

		Str.Format(_T("%6lf"), Result);

		Str += "+";

		

		SignType = 1;

		SetDlgItemText(IDC_EDIT, Str);
	}
		
	
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC_CALDlg::OnBnClickedMiute()
{
	// TODO:  在此添加控件通知处理程序代码

	if (FirstState)
	{

		SignState = true;

		Str += "-";

		SignType = 2;

		SetDlgItemText(IDC_EDIT, Str);
	}
	else
	{
		nFirst = Result;

		SignState = true;

		Str.Empty();

		Str.Format(_T("%6lf"), Result);

		Str += "-";



		SignType = 2;

		SetDlgItemText(IDC_EDIT, Str);
	}
}


void CMFC_CALDlg::OnBnClickedMultiple()
{
	// TODO:  在此添加控件通知处理程序代码
	if (FirstState)
	{
		
		SignState = true;

		Str += "*";

		SignType = 3;

		SetDlgItemText(IDC_EDIT, Str);
	}
	else
	{
		nFirst = Result;
		SignState = true;

		Str.Empty();

		Str.Format(_T("%6lf"), Result);

		Str += "*";



		SignType = 3;

		SetDlgItemText(IDC_EDIT, Str);
	}
}


void CMFC_CALDlg::OnBnClickedDevision()
{
	// TODO:  在此添加控件通知处理程序代码
	
	if (FirstState)
	{

		SignState = true;

		Str += "/";

		SignType = 4;

		SetDlgItemText(IDC_EDIT, Str);
	}
	else
	{
		nFirst = Result;
		SignState = true;

		Str.Empty();

		Str.Format(_T("%6lf"), Result);

		Str += "/";



		SignType = 4;

		SetDlgItemText(IDC_EDIT, Str);
	}
}


void CMFC_CALDlg::OnBnClickedEqual()
{
	// TODO:  在此添加控件通知处理程序代码
	/*
	CString FirstStr;
	CString SecondStr;

	FirstStr.Format(_T("%6lf"), nFirst);
	SecondStr.Format(_T("%6lf"), nSecond);

	MessageBox(FirstStr, SecondStr, 1);
	*/

	//
	//

	switch (SignType)
	{
	case 1:
	{

			  Result = nFirst + nSecond;
			  Str.Empty();


			  Str.Format(_T("%6lf"), Result);

			  SetDlgItemText(IDC_EDIT, Str);
	}
	
		break;
		

	case 2:
	{

			  Result = nFirst - nSecond;

			  Str.Empty();
			  Str.Format(_T("%6lf"), Result);
			  SetDlgItemText(IDC_EDIT, Str);
	}

		break;
	case 3:
	{

			  Result = nFirst * nSecond;

			  Str.Empty();
			  Str.Format(_T("%6lf"), Result);
			  SetDlgItemText(IDC_EDIT, Str);
	}

			break;
	case 4:
	{
			  if (nSecond)
			  {

				  Result = nFirst / nSecond;

				  Str.Empty();
				  Str.Format(_T("%6lf"), Result);
				  SetDlgItemText(IDC_EDIT, Str);
			  }
			  else
			  {
				  MessageBox(TEXT("Erro"), TEXT("THE SECOND CANNOT　BE ZERO"), 0);

			  }
	}
		break;
	}

	FirstState = false;

	SecondState = false;

	SignState = false;

	nFirst = 0;

	FirstEdit = false;
	nSecond = 0;
}
