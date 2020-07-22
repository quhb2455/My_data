
// IMP_LJS_200721Doc.cpp: CIMPLJS200721Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMP_LJS_200721.h"
#endif

#include "IMP_LJS_200721Doc.h"
#include "CDownSamplingDlg.h"
#include "CUpSampleDlg.h"
#include "CQuantizationDlg.h"
#include <math.h>
#include <propkey.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIMPLJS200721Doc

IMPLEMENT_DYNCREATE(CIMPLJS200721Doc, CDocument)

BEGIN_MESSAGE_MAP(CIMPLJS200721Doc, CDocument)
END_MESSAGE_MAP()


// CIMPLJS200721Doc 생성/소멸

CIMPLJS200721Doc::CIMPLJS200721Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CIMPLJS200721Doc::~CIMPLJS200721Doc()
{
}

BOOL CIMPLJS200721Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CIMPLJS200721Doc serialization

void CIMPLJS200721Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CIMPLJS200721Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CIMPLJS200721Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CIMPLJS200721Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CIMPLJS200721Doc 진단

#ifdef _DEBUG
void CIMPLJS200721Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIMPLJS200721Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CIMPLJS200721Doc 명령


BOOL CIMPLJS200721Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CFile File; // 파일 객체 선언

	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary); // 파일 열기 대화상자에서 선택한 파일을 지정하고 읽기 모드 선택

	// 이 책에서는 영상의 크기 256*256, 512*512, 640*480만을 사용한다. 
	if (File.GetLength() == 256 * 256) // RAW 파일의 크기 결정 
	{
		m_height = 256;
		m_width = 256;
	}
	else if (File.GetLength() == 512 * 512) // RAW 파일의 크기 결정 
	{
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640 * 480) // RAW 파일의 크기 결정 
	{
		m_height = 480;
		m_width = 640;
	}
	else
	{
		AfxMessageBox(L"Not Support Image Size");// 해당 크기가 없는 경우 && 예외처리
		return 0;
	}
	m_size = m_width * m_height; // 영상의 크기 계산 

	m_InputImage = new unsigned char[m_size];// 입력 영상의 크기에 맞는 메모리 할당
	// 이미지는 2차원 배열인데 이거를 1차원 배열에 넣는 다는 느낌. 

	for (int i = 0; i < m_size; i++)
	{
		m_InputImage[i] = 255; //초기화
		//2차원을 1차원으로 바꿨을때의 크기가 정해 졌고 안에 있는 값을 모두 255로 변경
	}

	File.Read(m_InputImage, m_size); //file을 읽는데 이때 m_inputimage의 시작점을 주고, 두번째 파라미터에는 m_inputimage의 크기를 준다.
	//그리고 View 클래스로 이동해서 찍어냄,
	File.Close();


	return TRUE;
}


void CIMPLJS200721Doc::OnDownSampling()
{
	// TODO: 여기에 구현 코드 추가.
	int i, j; 
	CDownSamplingDlg dlg; 
	if (dlg.DoModal() == IDOK) // 대화상자의 활성화 여부 
							   //Modal프로세스를 그냥 점유해서 다른쪽으로 못넘어감.
	{ 
		m_Re_height = m_height / dlg.m_DownSampleRate; // 축소 영상의 세로 길이를 계산 
		m_Re_width = m_width / dlg.m_DownSampleRate; // 축소 영상의 가로 길이를 계산
		m_Re_size = m_Re_height * m_Re_width; // 축소 영상의 크기를 계산 
		m_OutputImage = new unsigned char [m_Re_size];     // 축소 영상을 위한 메모리 할당 
		for(i=0 ; i<m_Re_height ; i++)
		{ 
			for(j=0 ; j<m_Re_width ; j++)
			{ 
				m_OutputImage[i*m_Re_width + j] = m_InputImage[(i*dlg.m_DownSampleRate*m_width)+dlg.m_DownSampleRate*j]; // 축소 영상을 생성
			} 
		} 
	}
}


void CIMPLJS200721Doc::OnUpSampling()
{
	// TODO: 여기에 구현 코드 추가.
	int i, j; 
	CUpSampleDlg dlg; 
	if (dlg.DoModal() == IDOK) 
	{ // DoModal 대화상자의 활성화 여부 
		m_Re_height = m_height * dlg.m_UpSampleRate; // 확대 영상의 세로 길이 계산 
		m_Re_width = m_width * dlg.m_UpSampleRate; // 확대 영상의 가로 길이 계산 
		m_Re_size = m_Re_height * m_Re_width; // 확대 영상의 크기 계산 
		m_OutputImage = new unsigned char[m_Re_size]; // 확대 영상을 위한 메모리 할당 
		for(i=0 ; i<m_Re_size ; i++) 
			m_OutputImage[i] = 0; // 초기화 

		for(i=0 ; i<m_height ; i++)
		{ 
			for(j=0 ; j<m_width ; j++)
			{
				m_OutputImage[i*dlg.m_UpSampleRate*m_Re_width + dlg.m_UpSampleRate*j]= m_InputImage[i*m_width + j]; 
			} // 재배치하여 영상 확대 
		} 
	}
}


void CIMPLJS200721Doc::OnQuantization()
{
	// TODO: 여기에 구현 코드 추가.
	CQuantizationDlg dlg;
	if (dlg.DoModal() == IDOK) // 양자화 비트 수를 결정하는 대화상자의 활성화 여부 
	{ 
		int i, j, value, LEVEL; 
		double HIGH, *TEMP; 
		
		m_Re_height = m_height; 
		m_Re_width = m_width; 
		m_Re_size = m_Re_height * m_Re_width; 
		
		m_OutputImage = new unsigned char[m_Re_size]; // 양자화 처리된 영상을 출력하기 위한 메모리 할당
		TEMP = new double [m_size]; // 입력 영상 크기(m_size)와 동일한 메모리 할당 
		LEVEL=256; // 입력 영상의 양자화 단계(28=256)
		HIGH=256.; 
		value = (int)pow(2, dlg.m_QuantBit); // 양자화 단계 결정(예 : 24=16) 
		for(i=0 ; i<m_size ; i++)
		{ 
			for(j=0 ; j<value ; j++)
			{ 
				if(m_InputImage[i] >=(LEVEL/value)*j && m_InputImage[i]<(LEVEL/value)*(j+1))
				{ 
					TEMP[i]=(double)(HIGH/value)*j; // 양자화 수행 
				} 
			} 
		} 
		for(i=0 ; i<m_size ; i++)
		{
			m_OutputImage[i] = (unsigned char)TEMP[i]; // 결과 영상 생성 
		} 
	}

}
