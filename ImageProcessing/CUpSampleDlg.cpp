// CUpSampleDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_LJS_200721.h"
#include "CUpSampleDlg.h"
#include "afxdialogex.h"


// CUpSampleDlg 대화 상자

IMPLEMENT_DYNAMIC(CUpSampleDlg, CDialogEx)

CUpSampleDlg::CUpSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_UpSampleRate(0)
{

}

CUpSampleDlg::~CUpSampleDlg()
{
}

void CUpSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUpSampleDlg, CDialogEx)
END_MESSAGE_MAP()


// CUpSampleDlg 메시지 처리기
