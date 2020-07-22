// CQuantizationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_LJS_200721.h"
#include "CQuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg 대화 상자

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialogEx)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_QuantBit(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantBit);
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialogEx)
END_MESSAGE_MAP()


// CQuantizationDlg 메시지 처리기
