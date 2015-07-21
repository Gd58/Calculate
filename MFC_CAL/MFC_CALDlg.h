
// MFC_CALDlg.h : 头文件
//

#pragma once


// CMFC_CALDlg 对话框
class CMFC_CALDlg : public CDialogEx
{
// 构造
public:
	CMFC_CALDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_CAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:



	double nFirst;

	double nSecond;
	
	bool FirstState;
	bool SecondState;

	bool SignState;

	UINT SignType;

	double Result;

	bool FirstEdit;

	CString Str;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedThree();
	afx_msg void OnBnClickedFour();
	afx_msg void OnBnClickedFive();
	afx_msg void OnBnClickedSix();
	afx_msg void OnBnClickedSeven();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedNine();
	afx_msg void OnBnClickedZero();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMiute();
	afx_msg void OnBnClickedMultiple();
	afx_msg void OnBnClickedDevision();
	afx_msg void OnBnClickedEqual();
};
