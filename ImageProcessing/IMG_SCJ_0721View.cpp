
// IMG_SCJ_0721View.cpp: CIMGSCJ0721View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMG_SCJ_0721.h"
#endif

#include "IMG_SCJ_0721Doc.h"
#include "IMG_SCJ_0721View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMGSCJ0721View

IMPLEMENT_DYNCREATE(CIMGSCJ0721View, CView)

BEGIN_MESSAGE_MAP(CIMGSCJ0721View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMGSCJ0721View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_IIIII_LJK, &CIMGSCJ0721View::OnIiiiiLjk)
	ON_COMMAND(ID_UP_SAMPLING, &CIMGSCJ0721View::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CIMGSCJ0721View::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CIMGSCJ0721View::OnSumConstant)
	ON_COMMAND(ID_SUB_CONTANT, &CIMGSCJ0721View::OnSubConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CIMGSCJ0721View::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CIMGSCJ0721View::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CIMGSCJ0721View::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CIMGSCJ0721View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CIMGSCJ0721View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CIMGSCJ0721View::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CIMGSCJ0721View::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CIMGSCJ0721View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CIMGSCJ0721View::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CIMGSCJ0721View::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CIMGSCJ0721View::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CIMGSCJ0721View::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CIMGSCJ0721View::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CIMGSCJ0721View::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CIMGSCJ0721View::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CIMGSCJ0721View::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CIMGSCJ0721View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CIMGSCJ0721View::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CIMGSCJ0721View::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CIMGSCJ0721View::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CIMGSCJ0721View::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CIMGSCJ0721View::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CIMGSCJ0721View::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CIMGSCJ0721View::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CIMGSCJ0721View::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CIMGSCJ0721View::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CIMGSCJ0721View::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CIMGSCJ0721View::OnMeanSub)
	ON_COMMAND(ID_TRANSLATION, &CIMGSCJ0721View::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CIMGSCJ0721View::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CIMGSCJ0721View::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CIMGSCJ0721View::OnRotation)
	ON_COMMAND(ID_FRAME_OR, &CIMGSCJ0721View::OnFrameOr)
	ON_COMMAND(ID_FRAME_AND, &CIMGSCJ0721View::OnFrameAnd)
	ON_COMMAND(ID_OTHERPIC, &CIMGSCJ0721View::OnOpenOtherpic)
	ON_COMMAND(ID_FRAMEOR2, &CIMGSCJ0721View::OnFrameOr2)
END_MESSAGE_MAP()

// CIMGSCJ0721View 생성/소멸

CIMGSCJ0721View::CIMGSCJ0721View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CIMGSCJ0721View::~CIMGSCJ0721View()
{
}

BOOL CIMGSCJ0721View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CIMGSCJ0721View 그리기

void CIMGSCJ0721View::OnDraw(CDC* pDC)
{

#define WIDTHBYTES(bits)   (((bits)+31)/32*4);

	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	int i, j;
	int rwsize;

	if (pDoc->m_InputImage == NULL)
		return;

	//입력 영상 출력
	//24비트 영상일 경우
	if (pDoc->dibHi.biBitCount == 24) {
		unsigned char R, G, B;
		/*BmInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFOHEADER) + 512*sizeof(RGBQUAD));

		rwsize = WIDTHBYTES(pDoc->dibHi.biBitCount * pDoc->dibHi.biWidth);
		BmInfo->bmiHeader = pDoc->dibHi;
		SetDIBitsToDevice(pDC->GetSafeHdc(), 5, 5, pDoc->m_width, pDoc->m_height, 0, 0, 0, pDoc->m_height, pDoc->m_InputImage, BmInfo, DIB_RGB_COLORS);*/
		for (int i = 0; i < pDoc->m_height; i++)
			for (int j = 0; j < pDoc->m_width; j++)
			{
				B = pDoc->m_InputImage[i * pDoc->m_width * 3 + j * 3];
				G = pDoc->m_InputImage[i * pDoc->m_width * 3 + j * 3 + 1];
				R = pDoc->m_InputImage[i * pDoc->m_width * 3 + j * 3 + 2];
				pDC->SetPixel(j, pDoc->dibHi.biHeight-i-1, RGB(R, G, B));
			}

	}
	//8비트 영상일 경우
	else {

		int index;
		//영상의 가로 길이를 4byte의 배수로 만듦
		rwsize = WIDTHBYTES(pDoc->dibHi.biBitCount * pDoc->dibHi.biWidth);


		//팔레트를 읽어들이며 반복출력
		for (int i = 0; i < pDoc->dibHi.biHeight; i++)
			for (int j = 0; j < pDoc->dibHi.biWidth; j++) {
				index = pDoc->m_InputImage[i * rwsize + j];
				BYTE R = pDoc->palRGB[index].rgbRed;
				BYTE G = pDoc->palRGB[index].rgbGreen;
				BYTE B = pDoc->palRGB[index].rgbBlue;

				//pDC->SetPixel(j,i,RGB(R,G,B));

				 //영상 반전출력
				pDC->SetPixel(j, pDoc->dibHi.biHeight - i - 1, RGB(R, G, B));

			}
	}


	//2번 위치 입력 영상 출력[배경]
	//24비트 영상일 경우
	if (pDoc->dibHi2.biBitCount == 24) {
		unsigned char R, G, B;
		/*BmInfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFOHEADER) + 512*sizeof(RGBQUAD));

		rwsize = WIDTHBYTES(pDoc->dibHi.biBitCount * pDoc->dibHi.biWidth);
		BmInfo->bmiHeader = pDoc->dibHi;
		SetDIBitsToDevice(pDC->GetSafeHdc(), 5, 5, pDoc->m_width, pDoc->m_height, 0, 0, 0, pDoc->m_height, pDoc->m_InputImage, BmInfo, DIB_RGB_COLORS);*/
		for (int i = 0; i < pDoc->m_height; i++)
			for (int j = 0; j < pDoc->m_width; j++)
			{
				B = pDoc->m_BackImage[i * pDoc->m_width * 3 + j * 3];
				G = pDoc->m_BackImage[i * pDoc->m_width * 3 + j * 3 + 1];
				R = pDoc->m_BackImage[i * pDoc->m_width * 3 + j * 3 + 2];
				pDC->SetPixel(pDoc->dibHi2.biWidth+j+15, pDoc->dibHi2.biHeight - i - 1, RGB(R, G, B));
			}
	}
	//8비트 영상일 경우
	else {
		int index;
		//영상의 가로 길이를 4byte의 배수로 만듦
		rwsize = WIDTHBYTES(pDoc->dibHi2.biBitCount * pDoc->dibHi2.biWidth);


		//팔레트를 읽어들이며 반복출력
		for (int i = 0; i < pDoc->dibHi2.biHeight; i++)
			for (int j = 0; j < pDoc->dibHi2.biWidth; j++) {
				index = pDoc->m_BackImage[i * rwsize + j];
				BYTE R = pDoc->palRGB2[index].rgbRed;
				BYTE G = pDoc->palRGB2[index].rgbGreen;
				BYTE B = pDoc->palRGB2[index].rgbBlue;

				//pDC->SetPixel(j,i,RGB(R,G,B));

				 //영상 반전출력
				pDC->SetPixel(pDoc->m_width + j + 10, pDoc->dibHi2.biHeight - i - 1, RGB(R, G, B));

			}

	}
	/*
	//3번 위치 입력 영상 출력[최종결과]
	//24비트 영상일 경우
	if (pDoc->dibHi3.biBitCount == 24) {
		rwsize = WIDTHBYTES(pDoc->dibHi3.biBitCount * pDoc->dibHi3.biWidth);
		BmInfo3->bmiHeader = pDoc->dibHi3;
		SetDIBitsToDevice(pDC->GetSafeHdc(), pDoc->m_width + pDoc->m_Re_width + 15, 5, pDoc->m_width, pDoc->m_height, 0, 0, 0, pDoc->m_height, pDoc->m_OutputImage, BmInfo3, DIB_RGB_COLORS);
	}
	else
	{

		int index;
		//영상의 가로 길이를 4byte의 배수로 만듦
		rwsize = WIDTHBYTES(pDoc->dibHi3.biBitCount * pDoc->dibHi3.biWidth);


		//팔레트를 읽어들이며 반복출력
		for (int i = 0; i < pDoc->dibHi3.biHeight; i++)
			for (int j = 0; j < pDoc->dibHi3.biWidth; j++) {
				index = pDoc->m_OutputImage[i * rwsize + j];
				BYTE R = pDoc->palRGB3[index].rgbRed;
				BYTE G = pDoc->palRGB3[index].rgbGreen;
				BYTE B = pDoc->palRGB3[index].rgbBlue;

				//pDC->SetPixel(j,i,RGB(R,G,B));

				 //영상 반전출력
				pDC->SetPixel(pDoc->m_width + pDoc->m_Re_width + 15, pDoc->dibHi3.biHeight - i - 1, RGB(R, G, B));

			}

	}*/
}


// CIMGSCJ0721View 인쇄


void CIMGSCJ0721View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMGSCJ0721View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CIMGSCJ0721View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CIMGSCJ0721View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CIMGSCJ0721View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMGSCJ0721View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMGSCJ0721View 진단

#ifdef _DEBUG
void CIMGSCJ0721View::AssertValid() const
{
	CView::AssertValid();
}

void CIMGSCJ0721View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMGSCJ0721Doc* CIMGSCJ0721View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMGSCJ0721Doc)));
	return (CIMGSCJ0721Doc*)m_pDocument;
}
#endif //_DEBUG


// CIMGSCJ0721View 메시지 처리기


void CIMGSCJ0721View::OnIiiiiLjk()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신

}


void CIMGSCJ0721View::OnDownSampling ()
{
	CIMGSCJ0721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신

}


void CIMGSCJ0721View::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출
	Invalidate(TRUE); // 화면 갱신

}




void CIMGSCJ0721View::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출
	Invalidate(TRUE); // 화면 갱신
}




void CIMGSCJ0721View::OnSumConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	pDoc->OnSumConstant();
	Invalidate(TRUE);
	
}



void CIMGSCJ0721View::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnSubConstant();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMulConstant();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnDivConstant();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnAndOperate();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnOrOperate();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnNegaTransform();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGammaCorrection();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBinarization();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnStressTransform();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoStretch();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEndInSearch();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistogram();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHistoSpec();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnEmbossing();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBlurr();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnGaussianFilter();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnSharpening();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHpfSharp();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLpfSharp();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnDiffOperatorHor();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnHomogenOperator();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnLaplacian();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnNearest();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnBilinear();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMedianSub();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMeanSub();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnTranslation();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnMirrorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorHor();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnMirrorVer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorVer();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnRotation();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnFrameOr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameOr();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnFrameAnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameAnd();
	Invalidate(TRUE);
}

void CIMGSCJ0721View::OnOpenOtherpic()
{
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnOpenOtherPic();
	Invalidate(TRUE);
}


void CIMGSCJ0721View::OnFrameOr2()
{
	CIMGSCJ0721Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnFrameOr2();
	Invalidate(TRUE);
}
