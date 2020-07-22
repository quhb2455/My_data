#pragma once


// CDownSamplingDlg 대화 상자

class CDownSamplingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDownSamplingDlg)

public:
	CDownSamplingDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDownSamplingDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif  

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_DownSampleRate;
};
