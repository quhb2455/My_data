// CDownSamplingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_LJS_200721.h"
#include "CDownSamplingDlg.h"
#include "afxdialogex.h"


// CDownSamplingDlg 대화 상자

IMPLEMENT_DYNAMIC(CDownSamplingDlg, CDialogEx)

CDownSamplingDlg::CDownSamplingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_DownSampleRate(0)
{

}

CDownSamplingDlg::~CDownSamplingDlg()
{
}

void CDownSamplingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DownSampleRate);
	DDV_MinMaxInt(pDX, m_DownSampleRate, 1, 32);
}


BEGIN_MESSAGE_MAP(CDownSamplingDlg, CDialogEx)
END_MESSAGE_MAP()


// CDownSamplingDlg 메시지 처리기
