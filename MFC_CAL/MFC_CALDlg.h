
// MFC_CALDlg.h : ͷ�ļ�
//

#pragma once


// CMFC_CALDlg �Ի���
class CMFC_CALDlg : public CDialogEx
{
// ����
public:
	CMFC_CALDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_CAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

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
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
