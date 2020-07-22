
// IMP_LJS_200721View.cpp: CIMPLJS200721View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMP_LJS_200721.h"
#endif

#include "IMP_LJS_200721Doc.h"
#include "IMP_LJS_200721View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMPLJS200721View

IMPLEMENT_DYNCREATE(CIMPLJS200721View, CView)

BEGIN_MESSAGE_MAP(CIMPLJS200721View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMPLJS200721View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_IMAGEPROCESSING_DOWNSAMPLE, &CIMPLJS200721View::OnImageprocessingDownsample)
	ON_COMMAND(ID_UP_SAMPLING, &CIMPLJS200721View::OnUpSampling)
//	ON_UPDATE_COMMAND_UI(ID_UP_SAMPLING, &CIMPLJS200721View::OnUpdateUpSampling)
ON_COMMAND(ID_QUANTIZATION, &CIMPLJS200721View::OnQuantization)
END_MESSAGE_MAP()

// CIMPLJS200721View 생성/소멸

CIMPLJS200721View::CIMPLJS200721View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CIMPLJS200721View::~CIMPLJS200721View()
{
}

BOOL CIMPLJS200721View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CIMPLJS200721View 그리기

void CIMPLJS200721View::OnDraw(CDC* pDC)
{
	CIMPLJS200721Doc* pDoc = GetDocument(); // Document 클래스에 접근 가능 & 객체 사용가능.
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	unsigned char R,G,B;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for(int i = 0; i < pDoc->m_height; i++)
		for (int j = 0; j < pDoc->m_width; j++)
		{
			R = G = B = pDoc->m_InputImage[i * pDoc->m_width + j];
			// RGB는 빛의 삼원색. RGB값이 255,255,255 면 흰색, 빛이 다 모이면 흰색 이므로
			// 0,0,0은 빛이 없다는 것이므로 검은색. 그럼 RGB값이 전부 동일한 값을 가지고 동일하게 커지고 줄어들고 하면 흰색->검은색으로 변함
			//그래서 여기서 회색으로 보이는거
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}


	// 축소된 영상 출력 
	for(int i = 0 ; i<pDoc->m_Re_height ; i++)
	{ 
		for(int j = 0 ; j<pDoc->m_Re_width ; j++)
		{ 
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width+j];
			G = B = R;
			pDC->SetPixel(j+pDoc->m_width+10, i+5, RGB(R, G, B)); 
		} 
	}

	// 확대된 영상 출력
	for (int i = 0; i < pDoc->m_Re_height; i++)
	{
		for (int j = 0; j < pDoc->m_Re_width; j++)
		{
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

}


// CIMPLJS200721View 인쇄


void CIMPLJS200721View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMPLJS200721View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CIMPLJS200721View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CIMPLJS200721View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CIMPLJS200721View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMPLJS200721View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMPLJS200721View 진단

#ifdef _DEBUG
void CIMPLJS200721View::AssertValid() const
{
	CView::AssertValid();
}

void CIMPLJS200721View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMPLJS200721Doc* CIMPLJS200721View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMPLJS200721Doc)));
	return (CIMPLJS200721Doc*)m_pDocument;
}
#endif //_DEBUG


// CIMPLJS200721View 메시지 처리기


void CIMPLJS200721View::OnImageprocessingDownsample()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//AfxMessageBox(L"Hi Hello My name is sub");// 해당 크기가 없는 경우 && 예외처리
	CIMPLJS200721Doc* pDoc = GetDocument(); // Doc 클래스 참조 
	ASSERT_VALID(pDoc);
	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출 
	Invalidate(TRUE); // 화면 갱신
}


void CIMPLJS200721View::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPLJS200721Doc* pDoc = GetDocument(); // Doc 클래스 참조 
	ASSERT_VALID(pDoc);
	pDoc->OnUpSampling(); // Doc 클래스에 OnDownSampling 함수 호출 
	Invalidate(TRUE); // 화면 갱신
}




void CIMPLJS200721View::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPLJS200721Doc* pDoc = GetDocument(); // Doc 클래스 참조 
	ASSERT_VALID(pDoc);
	pDoc->OnQuantization(); // Doc 클래스에 OnDownSampling 함수 호출 
	Invalidate(TRUE); // 화면 갱신
}
