
// IMG_SCJ_0721Doc.cpp: CIMGSCJ0721Doc 클래스의 구현
//


#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMG_SCJ_0721.h"
#endif

#include "IMG_SCJ_0721Doc.h"
#include <propkey.h>
#include "CDownSampleDlg.h"
#include "CUpSampleDlg.h"
#include "CQuantizationDlg.h"
#include "math.h"
#include "CConstantDlg.h"
#include "CStressTransformDlg.h"

double m_HIST[256];
double m_Sum_Of_HIST[256];
unsigned char m_Scale_HIST[256];

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMGSCJ0721Doc

IMPLEMENT_DYNCREATE(CIMGSCJ0721Doc, CDocument)

BEGIN_MESSAGE_MAP(CIMGSCJ0721Doc, CDocument)
//	ON_COMMAND(ID_SUB_CONTANT, &CIMGSCJ0721Doc::OnSubContant)
ON_COMMAND(ID_SUB_CONSTANT, &CIMGSCJ0721Doc::OnSubConstant)
ON_COMMAND(ID_MUL_CONSTANT, &CIMGSCJ0721Doc::OnMulConstant)
ON_COMMAND(ID_DIV_CONSTANT, &CIMGSCJ0721Doc::OnDivConstant)
ON_COMMAND(ID_AND_OPERATE, &CIMGSCJ0721Doc::OnAndOperate)
ON_COMMAND(ID_OR_OPERATE, &CIMGSCJ0721Doc::OnOrOperate)
ON_COMMAND(ID_XOR_OPERATE, &CIMGSCJ0721Doc::OnXorOperate)
ON_COMMAND(ID_NEGA_TRANSFORM, &CIMGSCJ0721Doc::OnNegaTransform)
ON_COMMAND(ID_GAMMA_CORRECTION, &CIMGSCJ0721Doc::OnGammaCorrection)
ON_COMMAND(ID_BINARIZATION, &CIMGSCJ0721Doc::OnBinarization)
ON_COMMAND(ID_STRESS_TRANSFORM, &CIMGSCJ0721Doc::OnStressTransform)
ON_COMMAND(ID_HISTO_STRETCH, &CIMGSCJ0721Doc::OnHistoStretch)
ON_COMMAND(ID_END_IN_SEARCH, &CIMGSCJ0721Doc::OnEndInSearch)
ON_COMMAND(ID_HISTOGRAM, &CIMGSCJ0721Doc::OnHistogram)
ON_COMMAND(ID_HISTO_EQUAL, &CIMGSCJ0721Doc::OnHistoEqual)
ON_COMMAND(ID_HISTO_SPEC, &CIMGSCJ0721Doc::OnHistoSpec)
ON_COMMAND(ID_EMBOSSING, &CIMGSCJ0721Doc::OnEmbossing)
ON_COMMAND(ID_BLURR, &CIMGSCJ0721Doc::OnBlurr)
ON_COMMAND(ID_GAUSSIAN_FILTER, &CIMGSCJ0721Doc::OnGaussianFilter)
ON_COMMAND(ID_SHARPENING, &CIMGSCJ0721Doc::OnSharpening)
ON_COMMAND(ID_HPF_SHARP, &CIMGSCJ0721Doc::OnHpfSharp)
ON_COMMAND(ID_LPF_SHARP, &CIMGSCJ0721Doc::OnLpfSharp)
ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CIMGSCJ0721Doc::OnDiffOperatorHor)
ON_COMMAND(ID_HOMOGEN_OPERATOR, &CIMGSCJ0721Doc::OnHomogenOperator)
ON_COMMAND(ID_LAPLACIAN, &CIMGSCJ0721Doc::OnLaplacian)
ON_COMMAND(ID_NEAREST, &CIMGSCJ0721Doc::OnNearest)
ON_COMMAND(ID_BILINEAR, &CIMGSCJ0721Doc::OnBilinear)
ON_COMMAND(ID_MEDIAN_SUB, &CIMGSCJ0721Doc::OnMedianSub)
ON_COMMAND(ID_MEAN_SUB, &CIMGSCJ0721Doc::OnMeanSub)
ON_COMMAND(ID_TRANSLATION, &CIMGSCJ0721Doc::OnTranslation)
ON_COMMAND(ID_MIRROR_HOR, &CIMGSCJ0721Doc::OnMirrorHor)
ON_COMMAND(ID_MIRROR_VER, &CIMGSCJ0721Doc::OnMirrorVer)
ON_COMMAND(ID_ROTATION, &CIMGSCJ0721Doc::OnRotation)
ON_COMMAND(ID_FRAME_OR, &CIMGSCJ0721Doc::OnFrameOr)
ON_COMMAND(ID_FRAME_AND, &CIMGSCJ0721Doc::OnFrameAnd)
END_MESSAGE_MAP()


// CIMGSCJ0721Doc 생성/소멸

CIMGSCJ0721Doc::CIMGSCJ0721Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CIMGSCJ0721Doc::~CIMGSCJ0721Doc()
{
}

BOOL CIMGSCJ0721Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CIMGSCJ0721Doc serialization

void CIMGSCJ0721Doc::Serialize(CArchive& ar)
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
void CIMGSCJ0721Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CIMGSCJ0721Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CIMGSCJ0721Doc::SetSearchContent(const CString& value)
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

// CIMGSCJ0721Doc 진단

#ifdef _DEBUG
void CIMGSCJ0721Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIMGSCJ0721Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CIMGSCJ0721Doc 명령


BOOL CIMGSCJ0721Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CFile File;

	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
	File.Read(&dibHf, sizeof(BITMAPFILEHEADER));

	//BMP파일인지 검사 
	if (dibHf.bfType != 0x4D42)
	{
		AfxMessageBox(L"Not BMP file!!");
		return FALSE;
	}

	//헤더 읽기
	File.Read(&dibHi, sizeof(BITMAPINFOHEADER));

	//8비트 혹은 24비트가 아닐 경우
	if (dibHi.biBitCount != 8 && dibHi.biBitCount != 24)                                //8,24비트가 아닐경우
	{
		AfxMessageBox(L"Gray/True Color Possible!!");
		return FALSE;
	}

	//8비트의 경우 팔레트를 생성해 주어야 한다. 총 256가지 색이므로 그 길이만큼 읽어들인다
	if (dibHi.biBitCount == 8)
		File.Read(palRGB, sizeof(RGBQUAD) * 256);

	
	//영상의 크기 읽기
	m_size = dibHi.biSizeImage;

	//영상 가로,세로 길이 저장
	m_height = dibHi.biHeight;
	m_width = dibHi.biWidth;

	File_length = File.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER);

	//이미지를 저장, 출력할 배열생성.
	m_InputImage = new unsigned char[File_length];
	m_OutputImage = new unsigned char[m_size];
	File.Read(m_InputImage, File_length);
	File.Close();

	return TRUE;
}

void CIMGSCJ0721Doc::OnDownSampling()
{
	// TODO: 여기에 구현 코드 추가.
	int i, j;
	CDownSampleDlg dlg;
	if (dlg.DoModal() == IDOK) // 대화상자의 활성화 여부
	{
		m_Re_height = m_height / dlg.m_DownSampleRate;
		// 축소 영상의 세로 길이를 계산
		m_Re_width = m_width / dlg.m_DownSampleRate;
		// 축소 영상의 가로 길이를 계산
		m_Re_size = m_Re_height * m_Re_width;
		// 축소 영상의 크기를 계산
		m_OutputImage = new unsigned char[m_Re_size];
		// 축소 영상을 위한 메모리 할당
		for (i = 0; i < m_Re_height; i++) {
			for (j = 0; j < m_Re_width; j++) {
				m_OutputImage[i * m_Re_width + j]
					= m_InputImage[(i * dlg.m_DownSampleRate * m_width) + dlg.m_DownSampleRate * j];
				// 축소 영상을 생성
			}
		}
	}
}


void CIMGSCJ0721Doc::OnUpSampling()
{
	// TODO: 여기에 구현 코드 추가.
	int i, j;
	CUpSampleDlg dlg;
	if (dlg.DoModal() == IDOK) { // DoModal 대화상자의 활성화 여부
		m_Re_height = m_height * dlg.m_UpSampleRate;
		// 확대 영상의 세로 길이 계산
		m_Re_width = m_width * dlg.m_UpSampleRate;
		// 확대 영상의 가로 길이 계산
		m_Re_size = m_Re_height * m_Re_width;
		// 확대 영상의 크기 계산
		m_OutputImage = new unsigned char[m_Re_size];
		// 확대 영상을 위한 메모리 할당
		for (i = 0; i < m_Re_size; i++)
			m_OutputImage[i] = 0; // 초기화
		for (i = 0; i < m_height; i++) {
			for (j = 0; j < m_width; j++) {
				m_OutputImage[i * dlg.m_UpSampleRate * m_Re_width +
					dlg.m_UpSampleRate * j] = m_InputImage[i * m_width + j];
			} // 재배치하여 영상 확대
		}
	}

}



void CIMGSCJ0721Doc::OnQuantization()
{
	// TODO: 여기에 구현 코드 추가.
	CQuantizationDlg dlg;
	if (dlg.DoModal() == IDOK)
		// 양자화 비트 수를 결정하는 대화상자의 활성화 여부
	{
		int i, j, value, LEVEL;
		double HIGH, * TEMP;
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;
		m_OutputImage = new unsigned char[m_Re_size];
		// 양자화 처리된 영상을 출력하기 위한 메모리 할당
		TEMP = new double[m_size];
		// 입력 영상 크기(m_size)와 동일한 메모리 할당
		LEVEL = 256; // 입력 영상의 양자화 단계(28=256)
		HIGH = 256.;
		value = (int)pow(2, dlg.m_QuantBit);
		// 양자화 단계 결정(예 : 24=16)
 		for (i = 0; i < m_size; i++) {		
			for (j = 0; j < value; j++) {
				if (m_InputImage[i] >= (LEVEL / value) * j && m_InputImage[i] < (LEVEL / value) * (j + 1)) {
					TEMP[i] = (double)(HIGH / value) * j; // 양자화 수행
				}
			}
		}
		for (i = 0; i < m_size; i++) {
			m_OutputImage[i] = (unsigned char)TEMP[i];
			// 결과 영상 생성
		}
	}
}


void CIMGSCJ0721Doc::OnSumConstant()
{
	CConstantDlg dlg; // 상수 값을 입력받는 대화상자
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] + dlg.m_Constant >= 255)
				m_OutputImage[i] = 255;
			// 출력 값이 255보다 크면 255 출력
			else
				m_OutputImage[i] = (unsigned char)(m_InputImage[i] + dlg.m_Constant);
			// 상수 값과 화소 값과의 덧셈
		}
	}
}


void CIMGSCJ0721Doc::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] - dlg.m_Constant < 0)
				m_OutputImage[i] = 0; // 출력 값이 255보다 크면 255를 출력
			else
				m_OutputImage[i]
				= (unsigned char)(m_InputImage[i] - dlg.m_Constant);
			// 상수 값과 화소 값과의 뺄셈
		}
	}

}


void CIMGSCJ0721Doc::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] * dlg.m_Constant > 255)
				m_OutputImage[i] = 255;
			else if (m_InputImage[i] * dlg.m_Constant < 0)
				m_OutputImage[i] = 0;
			else
				m_OutputImage[i]
				= (unsigned char)(m_InputImage[i] * dlg.m_Constant);
		}
	}
}


void CIMGSCJ0721Doc::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_width];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] / dlg.m_Constant > 255)
				m_OutputImage[i] = 255;
			else if (m_InputImage[i] / dlg.m_Constant < 0)
				m_OutputImage[i] = 0;
			else
				m_OutputImage[i]
				= (unsigned char)(m_InputImage[i] / dlg.m_Constant);
		}
	}
}

void CIMGSCJ0721Doc::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) >= 255) { m_OutputImage[i] = 255; }
			else if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) < 0) { m_OutputImage[i] = 0; }
			else { m_OutputImage[i] = (m_InputImage[i] & (unsigned char)dlg.m_Constant); }
		}
	}
}


void CIMGSCJ0721Doc::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) >= 255) {
				m_OutputImage[i] = 0;
			}
			else if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) < 0) {
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] | (unsigned char)dlg.m_Constant);
			}
		}
	}
}


void CIMGSCJ0721Doc::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			// 비트 단위 XOR 연산
			if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) >= 255) {
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) < 0) {
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i]
					^ (unsigned char)dlg.m_Constant);
			}
		}
	}

}


void CIMGSCJ0721Doc::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_size; i++)
	{
		m_OutputImage[i] = 255 - m_InputImage[i];
	}
}


void CIMGSCJ0721Doc::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	
	int i;
	double temp;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			temp = pow(m_InputImage[i], 1 / dlg.m_Constant);
			// 감마 값 계산
			if (temp < 0)
				m_OutputImage[i] = 0;
			else if (temp > 255)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = (unsigned char)temp;
		}
	}
}


void CIMGSCJ0721Doc::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] >= dlg.m_Constant)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = 0;
		}
	}
}


void CIMGSCJ0721Doc::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CStressTransformDlg dlg;
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		for (i = 0; i < m_size; i++) {
			if (m_InputImage[i] >= dlg.m_StartPoint &&
				m_InputImage[i] <= dlg.m_EndPoint)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = m_InputImage[i];
		}
	}
}


void CIMGSCJ0721Doc::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i;
	unsigned char LOW, HIGH, MAX, MIN;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	MIN = m_InputImage[0];
	MAX = m_InputImage[0];

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] < MIN)
			MIN = m_InputImage[i];
	}
	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] > MAX)
			MAX = m_InputImage[i];
	}

	m_OutputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_size; i++)
		m_OutputImage[i] = (unsigned char)((m_InputImage[i] - MIN) * HIGH / (MAX - MIN));
}


void CIMGSCJ0721Doc::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i;
	unsigned char LOW, HIGH, MAX, MIN;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	MIN = m_InputImage[0];
	MAX = m_InputImage[0];

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] < MIN)
			MAX = m_InputImage[i];
	}

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] > MAX)
			MAX = m_InputImage[i];
	}

	m_OutputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_size; i++) {
		if (m_InputImage[i] <= MIN) {
			m_OutputImage[i] = 0;
		}
		else if (m_InputImage[i] >= MAX) {
			m_OutputImage[i] = 255;
		}
		else
			m_OutputImage[i] = (unsigned char)((m_InputImage[i] - MIN) * HIGH / (MAX - MIN));
	}
}


void CIMGSCJ0721Doc::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, value;
	unsigned char LOW, HIGH;
	double MAX, MIN, DIF;

	m_Re_height = 256;
	m_Re_width = 256;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;

	for (i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
	}

	MAX = m_HIST[0];
	MIN = m_HIST[0];

	for (i = 0; i < 256; i++) {
		if (m_HIST[i] > MAX)
			MAX = m_HIST[i];
	}

	for (i = 0; i < 256; i++) {
		if (m_HIST[i] < MIN)
			MIN = m_HIST[i];
	}

	DIF = MAX - MIN;

	for (i = 0; i < 256; i++)
		m_Scale_HIST[i]
		= (unsigned char)((m_HIST[i] - MIN) * HIGH / DIF);

	m_OutputImage = new unsigned char[m_Re_size + (256 * 20)];

	for (i = 0; i < m_Re_size; i++)
		m_OutputImage[i] = 255;

	for (i = 0; i < 256; i++) {
		for (j = 0; j < m_Scale_HIST[i]; j++) {
			m_OutputImage[m_Re_width * (m_Re_height - j - 1) + i] = 0;
		}
	}

	for (i = m_Re_height; i < m_Re_height + 5; i++) {
		for (j = 0; j < 256; j++) {
			m_OutputImage[m_Re_height * i + j] = j;
		}
	}

	for (i = m_Re_height + 5; i < m_Re_height + 20; i++) {
		for (j = 0; j < 256; j++) {
			m_OutputImage[m_Re_height * i + j] = j;
		}
	}

	m_Re_height = m_Re_height + 20;
	m_Re_size = m_Re_height * m_Re_width;
}


void CIMGSCJ0721Doc::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, value;
	unsigned char LOW, HIGH, Temp;
	double SUM = 0.0;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	LOW = 0;
	HIGH = 255;
	// 초기화
	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;
	// 빈도 수 조사
	for (i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
	}
	// 누적 히스토그램 생성
	for (i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
	}
	m_OutputImage = new unsigned char[m_Re_size];
	// 입력 영상을 평활화된 영상으로 출력
	for (i = 0; i < m_size; i++) {
		Temp = m_InputImage[i];
		m_OutputImage[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
	}

}


void CIMGSCJ0721Doc::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, value, Dvalue, top, bottom, DADD;
	unsigned char* m_DTEMP, m_Sum_Of_ScHIST[256], m_TABLE[256];
	unsigned char LOW, HIGH, Temp, * m_Org_Temp;
	double m_DHIST[256], m_Sum_Of_DHIST[256], SUM = 0.0, DSUM = 0.0;
	double DMAX, DMIN;
	top = 255;
	bottom = top - 1;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_Org_Temp = new unsigned char[m_size];
	m_DTEMP = 0;
	CFile File;
	CFileDialog OpenDlg(TRUE);
	if (OpenDlg.DoModal() == IDOK) {
		File.Open(OpenDlg.GetPathName(), CFile::modeRead);
		if (File.GetLength() == (unsigned)m_size) {
			m_DTEMP = new unsigned char[m_size];
			File.Read(m_DTEMP, m_size);
			File.Close();
		}
		else {
			AfxMessageBox(L"Image size not matched");
			// 같은 크기의 영상을 대상으로 함
			return;
		}
	}
	LOW = 0;
	HIGH = 255;
	// 초기화
	for (i = 0; i < 256; i++) {
		m_HIST[i] = LOW;
		m_DHIST[i] = LOW;
		m_TABLE[i] = LOW;
	}
	for (i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
		Dvalue = (int)m_DTEMP[i];
		m_DHIST[Dvalue]++;
	}
	// 누적 히스토그램 조사
	for (i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
		DSUM += m_DHIST[i];
		m_Sum_Of_DHIST[i] = DSUM;
	}
	// 원본 영상의 평활화
	for (i = 0; i < m_size; i++) {
		Temp = m_InputImage[i];
		m_Org_Temp[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
	}
	// 누적 히스토그램에서 최소값과 최대값 지정
	DMIN = m_Sum_Of_DHIST[0];
	DMAX = m_Sum_Of_DHIST[255];
	for (i = 0; i < 256; i++) {
		m_Sum_Of_ScHIST[i] = (unsigned char)((m_Sum_Of_DHIST[i]
			- DMIN) * HIGH / (DMAX - DMIN));
	}
	// 룩업테이블을 이용한 명세화
	for (; ; ) {
		for (i = m_Sum_Of_ScHIST[bottom];
			i <= m_Sum_Of_ScHIST[top]; i++) {
			m_TABLE[i] = top;
		}
		top = bottom;
		bottom = bottom - 1;
		if (bottom < -1)
			break;
	}
	for (i = 0; i < m_size; i++) {
		DADD = (int)m_Org_Temp[i];
		m_OutputImage[i] = m_TABLE[DADD];
	}

}


void CIMGSCJ0721Doc::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double EmboMask[3][3] = { {-1.,0.,0.},{0.,0.,0.},{0.,0.,1.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, EmboMask);
	
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_tempImage[i][j] += 128;
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}

}


double** CIMGSCJ0721Doc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
{
	// TODO: 여기에 구현 코드 추가.
	int i, j, n, m;
	double** tempInputImage, ** tempOutputImage, S = 0.0;

	tempInputImage = Image2DMem(m_height + 2, m_width + 2);
	tempOutputImage = Image2DMem(m_height, m_width);

	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			tempInputImage[i + 1][j + 1]
				= (double)Target[i * m_width + j];
		}
	}

	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			for (n = 0; n < 3; n++) {
				for (m = 0; m < 3; m++) {
					S += Mask[n][m] * tempInputImage[i + n][j + m];
				}
			} // 회선 마스크의 크기 만큼 이동하면서 값을 누적
			tempOutputImage[i][j] = S; // 누적된 값을 출력 메모리에 저장
			S = 0.0; // 다음 블록으로 이동하면 누적 값을 초기화
		}
	}
	return tempOutputImage; // 결과 값 반환
}


double** CIMGSCJ0721Doc::OnScale(double **Target, int height, int width)
{
	// TODO: 여기에 구현 코드 추가.
	int i, j;
	double min, max;
	min = max = Target[0][0];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] <= min)
				min = Target[i][j];
		}
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] >= max)
				max = Target[i][j];
		}
	}
	max = max - min;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			Target[i][j] = (Target[i][j] - min) * (255. / max);
		}
	}
	return Target;
}


double** CIMGSCJ0721Doc::Image2DMem(int height, int width)
{
	// TODO: 여기에 구현 코드 추가.
	double** temp;
	int i, j;
	temp = new double* [height];
	for (i = 0; i < height; i++) {
		temp[i] = new double[width];
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			temp[i][j] = 0.0;
		}
	} // 할당된 2차원 메모리를 초기화
	return temp;
}


void CIMGSCJ0721Doc::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double BlurrMask[3][3] = { {1. / 9,1. / 9,1. / 9.}, {1. / 9,1. / 9,1. / 9.},(1. / 9,1. / 9,1. / 9.) };

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_InputImage, BlurrMask);
	
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double GaussianMask[3][3] = { {1. / 16,1. / 8,1. / 16.},{1. / 8.,1. / 4.,1. / 8},{1. / 16.,1. / 8.,1. / 16.} };

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, GaussianMask);

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double SharpeningMask[3][3] = { {0.,-1.,0.},{-1.,5.,-1.},{0.,-1.,0.} };
	
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, SharpeningMask);

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double HpfSharpMask[3][3] = { {-1. / 9.,-1. / 9.,-1. / 9.},{-1. / 9.,8. / 9.,-1. / 9.},{-1. / 9.,-1. / 9.,-1. / 9.} };

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, HpfSharpMask);

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg; // 상수를 입력받으려고 대화상자 선언
	int i, j, alpha;
	double LpfSharpMask[3][3] = { {1. / 9., 1. / 9., 1. / 9.},
	{1. / 9., 1. / 9., 1. / 9.}, {1. / 9., 1. / 9., 1. / 9.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	if (dlg.DoModal() == IDOK) {
		alpha = (int)dlg.m_Constant;
		// 대화상자를 이용하여 상수를 입력받는다.
	}
	m_tempImage = OnMaskProcess(m_InputImage, LpfSharpMask);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (alpha * m_InputImage
				[i * m_width + j]) - (unsigned char)m_tempImage[i][j];
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double DiffHorMask[3][3]
		= { {0., -1., 0.}, {0., 1., 0.}, {0., 0., 0.} };
	// 수평 필터 선택
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_InputImage, DiffHorMask);
	// m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, n, m;
	double max, ** tempOutputImage;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = Image2DMem(m_height + 2, m_width + 2);
	tempOutputImage = Image2DMem(m_Re_height, m_Re_width);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i + 1][j + 1] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			max = 0.0; // 블록이 이동할 때마다 최대값 초기화
			for (n = 0; n < 3; n++) {
				for (m = 0; m < 3; m++) {
					if (DoubleABS(m_tempImage[i + 1][j + 1] -
						m_tempImage[i + n][j + m]) >= max)
						// 블록의 가운데 값 - 블록의 주변 픽셀 값의 절대 값
						// 중에서 최대값을 찾는다.
						max = DoubleABS(m_tempImage[i + 1]
							[j + 1] - m_tempImage[i + n][j + m]);
				}
			}
			tempOutputImage[i][j] = max; // 찾은 최대값을 출력 값으로 지정
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (tempOutputImage[i][j] > 255.)
				tempOutputImage[i][j] = 255.;
			if (tempOutputImage[i][j] < 0.)
				tempOutputImage[i][j] = 0.;
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)tempOutputImage[i][j];
		}
	}
}


double CIMGSCJ0721Doc::DoubleABS(double X)
{
	// TODO: 여기에 구현 코드 추가.
	if (X >= 0)
		return X;
	else
		return -X;
}


void CIMGSCJ0721Doc::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	double LaplacianMask[3][3] = { {0., 1., 0.}, {1., -4., 1.}, {0., 1., 0.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_InputImage, LaplacianMask);
	// m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	int ZoomRate = 2; // 영상 확대 배율
	double** tempArray;
	m_Re_height = int(ZoomRate * m_height); // 확대된 영상의 높이
	m_Re_width = int(ZoomRate * m_width); // 확대된 영상의 너비
	m_Re_size = m_Re_height * m_Re_width;
	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	m_OutputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			tempArray[i][j] = m_tempImage[i / ZoomRate][j / ZoomRate];
			// 이웃한 화소를 이용한 보간
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)tempArray[i][j];
		}
	}
}


void CIMGSCJ0721Doc::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, point, i_H, i_W;
	unsigned char newValue;
	double ZoomRate = 2.0, r_H, r_W, s_H, s_W;
	double C1, C2, C3, C4;
	m_Re_height = (int)(m_height * ZoomRate); // 확대된 영상의 높이
	m_Re_width = (int)(m_width * ZoomRate); // 확대된 영상의 너비
	m_Re_size = m_Re_height * m_Re_width;
	m_tempImage = Image2DMem(m_height, m_width);
	m_OutputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			r_H = i / ZoomRate;
			r_W = j / ZoomRate;
			i_H = (int)floor(r_H);
			i_W = (int)floor(r_W);
			s_H = r_H - i_H;
			s_W = r_W - i_W;
			if (i_H < 0 || i_H >= (m_height - 1) || i_W < 0
				|| i_W >= (m_width - 1))
			{
				point = i * m_Re_width + j;
				m_OutputImage[point] = 255;
			}
			else
			{
				C1 = (double)m_tempImage[i_H][i_W];
				C2 = (double)m_tempImage[i_H][i_W + 1];
				C3 = (double)m_tempImage[i_H + 1][i_W + 1];
				C4 = (double)m_tempImage[i_H + 1][i_W];
				newValue = (unsigned char)(C1 * (1 - s_H) * (1 - s_W)
					+ C2 * s_W * (1 - s_H) + C3 * s_W * s_H + C4 * (1 - s_W) * s_H);
				point = i * m_Re_width + j;
				m_OutputImage[point] = newValue;
			}
		}
	}
}


void CIMGSCJ0721Doc::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, n, m, M = 2, index = 0; // M = 서브 샘플링 비율
	double* Mask, Value;
	Mask = new double[M * M]; // 마스크의 크기 결정
	m_Re_height = (m_height + 1) / M;
	m_Re_width = (m_width + 1) / M;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = Image2DMem(m_height + 1, m_width + 1);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_height - 1; i = i + M) {
		for (j = 0; j < m_width - 1; j = j + M) {
			for (n = 0; n < M; n++) {
				for (m = 0; m < M; m++) {
					Mask[n * M + m] = m_tempImage[i + n][j + m];
					// 입력 영상을 블록으로 잘라 마스크 배열에 저장
				}
			}
			OnBubleSort(Mask, M * M); // 마스크에 저장된 값을 정렬
			Value = Mask[(int)(M * M / 2)]; // 정렬된 값 중 가운데 값을 선택
			m_OutputImage[index] = (unsigned char)Value;
			// 가운데 값을 출력
			index++;
		}
	}
}


void CIMGSCJ0721Doc::OnBubleSort(double* A, int MAX)
{
	// TODO: 여기에 구현 코드 추가.
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX - 1; j++) {
			if (A[j] > A[j + 1]) {
				OnSwap(&A[j], &A[j + 1]);
			}
		}
	}
}


void CIMGSCJ0721Doc::OnSwap(double* a, double* b)
{
	// TODO: 여기에 구현 코드 추가.
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void CIMGSCJ0721Doc::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, n, m, M = 3, index = 0, k; // M = 서브 샘플링 비율
	double* Mask, Value, Sum = 0.0;
	Mask = new double[M * M];
	m_Re_height = (m_height + 1) / M;
	m_Re_width = (m_width + 1) / M;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = Image2DMem(m_height + 1, m_width + 1);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_height - 1; i = i + M) {
		for (j = 0; j < m_width - 1; j = j + M) {
			for (n = 0; n < M; n++) {
				for (m = 0; m < M; m++) {
					Mask[n * M + m] = m_tempImage[i + n][j + m];
				}
			}
			for (k = 0; k < M * M; k++)
				Sum = Sum + Mask[k];
			// 마스크에 저장된 값을 누적
			Value = (Sum / (M * M)); // 평균을 계산
			m_OutputImage[index] = (unsigned char)Value;
			// 평균값을 출력
			index++;
			Sum = 0.0;
		}
	}
}


void CIMGSCJ0721Doc::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	int h_pos = 30, w_pos = 130;
	double** tempArray;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_height - h_pos; i++) {
		for (j = 0; j < m_width - w_pos; j++) {
			tempArray[i + h_pos][j + w_pos] = m_tempImage[i][j];
			// 입력 영상을 h_pos, w_pos만큼 이동
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)tempArray[i][j];
		}
	}
	delete[] m_tempImage;
	delete[] tempArray;
}


void CIMGSCJ0721Doc::OnMirrorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_height; j++) {
			m_OutputImage[i * m_width + m_width - j - 1] = m_InputImage[i * m_width + j];
		}
	}
}


void CIMGSCJ0721Doc::OnMirrorVer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_OutputImage[(m_height - i - 1) * m_width + j]
				= m_InputImage[i * m_width + j];
		}
	}
}


void CIMGSCJ0721Doc::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, CenterH, CenterW, newH, newW, degree = 45;
	// degree = 회전할 각도
	double Radian, PI, ** tempArray, Value;
	m_Re_height = m_height; // 회전된 영상의 높이
	m_Re_width = m_width; // 회전된 영상의 너비
	m_Re_size = m_Re_height * m_Re_width;
	m_OutputImage = new unsigned char[m_Re_size];
	PI = 3.14159265358979; // 회전각을 위한 PI 값
	Radian = (double)degree * PI / 180.0;
	// degree 값을 radian으로 변경
	CenterH = m_height / 2; // 영상의 중심 좌표
	CenterW = m_width / 2; // 영상의 중심 좌표
	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			// 회전 변환 행렬을 이용하여 회전하게 될 좌표 값 계산
			newH = (int)((i - CenterH) * cos(Radian)
				- (j - CenterW) * sin(Radian) + CenterH);
			newW = (int)((i - CenterH) * sin(Radian)
				+ (j - CenterW) * sin(Radian) + CenterW);
			if (newH < 0 || newH >= m_height) {
				// 회전된 좌표가 출력 영상을 위한 배열 값을 넘어갈 때
				Value = 0;
			}
			else if (newW < 0 || newW >= m_width) {
				// 회전된 좌표가 출력 영상을 위한 배열 값을 넘어갈 때
				Value = 0;
			}
			else {
				Value = m_tempImage[newH][newW];
			}
			tempArray[i][j] = Value;
		}
	}
	for (i = 0; i < m_Re_height; i++) {
		for (j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j]
				= (unsigned char)tempArray[i][j];
		}
	}
	delete[] m_tempImage;
	delete[] tempArray;
}


void CIMGSCJ0721Doc::OnFrameOr()
{
	CFile File;
	CFileDialog OpenDlg(TRUE);

	int i,j;
	unsigned char* temp;

	
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	
	if (OpenDlg.DoModal() == IDOK) {
		File.Open(OpenDlg.GetPathName(), CFile::modeRead);
		File.Read(&dibHf3, sizeof(BITMAPFILEHEADER));
		File.Read(&dibHi3, sizeof(BITMAPINFOHEADER));

		if (dibHi3.biBitCount != 8 && dibHi3.biBitCount != 24)                                //8,24비트가 아닐경우
		{
			AfxMessageBox(L"Gray/True Color Possible!!");
			return;
		}

		File_length = File.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER) - sizeof(RGBQUAD)*256;
		m_TempImage = new unsigned char[File_length*3];


		if (dibHi3.biBitCount == 8)
			File.Read(palRGB3, sizeof(RGBQUAD)*256);

		if (dibHi3.biWidth*dibHi3.biHeight == (unsigned)m_Re_size) {
			temp = new unsigned char[File_length * 3];

			File.Read(temp, File_length*3);
			File.Close();
			for (i = 0; i < m_height; i++) {
				for (j = 0; j < m_width; j++) {

					
					m_TempImage[i*m_width*3+j*3]
						= (unsigned char)(m_InputImage[i*m_width*3 + j*3] | temp[i*m_width + j]);

					m_TempImage[i*m_width * 3 + j * 3 + 1]
						= (unsigned char)(m_InputImage[i*m_width * 3 + j * 3+1] | temp[i*m_width + j]);

					m_TempImage[i*m_width * 3 + j * 3 + 2]
						= (unsigned char)(m_InputImage[i*m_width * 3 + j * 3+2] | temp[i*m_width + j]);
				}
			}

		}
		else {
			AfxMessageBox(L"Image size not mached");
			return;
		}

		//inputimage 델리트,(oi=ii) outputimage 위치재정의
		for (i = 0; i < File_length*3; i++) {
			m_InputImage[i] = (unsigned char)m_TempImage[i];
		}
	}
	delete[] m_TempImage;
}


void CIMGSCJ0721Doc::OnFrameAnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size*3];


	for (i = 0; i < m_Re_size*3; i++) {
		m_OutputImage[i] = (unsigned char)(m_InputImage[i] & m_BackImage[i]);
	}

	for (i = 0; i < m_Re_size*3; i++) {
		m_BackImage[i] = (unsigned char)(m_OutputImage[i]);
	}
	delete[] m_OutputImage;

}
//배경 이미지 output 위치에서 출력할 함수
void CIMGSCJ0721Doc::OnOpenOtherPic()
{
	CFile File;
	CFileDialog OpenDlg(TRUE);


	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;


/*
	for (int i = 0; i < File_length; i++)
		m_BackImage[i] = 255; // 초기화
*/


	if (OpenDlg.DoModal() == IDOK) {

		File.Open(OpenDlg.GetPathName(), CFile::modeRead);

		File_length = File.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER);
		m_BackImage = new unsigned char[File_length];
	
		File.Read(&dibHf2, sizeof(BITMAPFILEHEADER));
		File.Read(&dibHi2, sizeof(BITMAPINFOHEADER));

		if (dibHi2.biBitCount != 8 && dibHi2.biBitCount != 24)                                //8,24비트가 아닐경우
		{
			AfxMessageBox(L"Gray/True Color Possible!!");
			return;
		}

		if (dibHi2.biBitCount == 8)
			File.Read(palRGB2, sizeof(RGBQUAD) * 256);


		if (dibHi2.biWidth*dibHi2.biHeight == (unsigned)m_Re_size) {
			File.Read(m_BackImage, File_length);
			File.Close();
		}
		else {
			AfxMessageBox(L"Image size not matched");
			// 같은 크기의 영상을 대상으로 함
			return;
		}
	}
}

void CIMGSCJ0721Doc::OnFrameOr2()
{
	CFile File;
	CFileDialog OpenDlg(TRUE);

	int i, j;
	unsigned char* temp;


	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	if (OpenDlg.DoModal() == IDOK) {
		File.Open(OpenDlg.GetPathName(), CFile::modeRead);
		File.Read(&dibHf4, sizeof(BITMAPFILEHEADER));
		File.Read(&dibHi4, sizeof(BITMAPINFOHEADER));

		if (dibHi4.biBitCount != 8 && dibHi4.biBitCount != 24)                                //8,24비트가 아닐경우
		{
			AfxMessageBox(L"Gray/True Color Possible!!");
			return;
		}

		File_length = File.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER) - sizeof(RGBQUAD) * 256;
		m_TempImage = new unsigned char[File_length * 3];
		

		if (dibHi4.biBitCount == 8)
			File.Read(palRGB4, sizeof(RGBQUAD)*256);

		if (dibHi4.biWidth*dibHi4.biHeight == (unsigned)m_Re_size) {
			temp = new unsigned char[File_length * 3];

			File.Read(temp, File_length * 3);
			File.Close();
			for (i = 0; i < m_height; i++) {
				for (j = 0; j < m_width; j++) {


					m_TempImage[i*m_width * 3 + j * 3]
						= (unsigned char)(m_BackImage[i*m_width * 3 + j * 3] | temp[i*m_width + j]);

					m_TempImage[i*m_width * 3 + j * 3 + 1]
						= (unsigned char)(m_BackImage[i*m_width * 3 + j * 3 + 1] | temp[i*m_width + j]);

					m_TempImage[i*m_width * 3 + j * 3 + 2]
						= (unsigned char)(m_BackImage[i*m_width * 3 + j * 3 + 2] | temp[i*m_width + j]);
				}
			}

		}
		else {
			AfxMessageBox(L"Image size not mached");
			return;
		}

		//inputimage 델리트,(oi=ii) outputimage 위치재정의
		for (i = 0; i < File_length * 3; i++) {
			m_BackImage[i] = (unsigned char)m_TempImage[i];
		}
	}
	delete[] m_TempImage;
	/*
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFile File;
	CFileDialog OpenDlg2(TRUE);
	int i;
	unsigned char* temp;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_TempImage = new unsigned char[m_Re_size];

	if (OpenDlg2.DoModal() == IDOK) {
		File.Open(OpenDlg2.GetPathName(), CFile::modeRead);
		File.Read(&dibHf2, sizeof(BITMAPFILEHEADER));
		File.Read(&dibHi2, sizeof(BITMAPINFOHEADER));

		if (dibHi2.biBitCount != 8 && dibHi2.biBitCount != 24)                                //8,24비트가 아닐경우
		{
			AfxMessageBox(L"Gray/True Color Possible!!");
			return;
		}

		if (dibHi2.biBitCount == 8)
			File.Read(palRGB2, sizeof(RGBQUAD) * 256);


		if (dibHi2.biWidth*dibHi2.biHeight == (unsigned)m_Re_size) {
			temp = new unsigned char[m_Re_size];

			File.Read(temp, m_Re_size);
			File.Close();

			for (i = 0; i < m_Re_size; i++) {
				m_TempImage[i]
					= (unsigned char)(m_BackImage[i] | temp[i]);
			}
		}
		else {
			AfxMessageBox(L"Image size not mached");
			return;
		}
		//inputimage 델리트,(oi=ii) outputimage 위치재정의
		for (i = 0; i < m_Re_size; i++) {
			m_BackImage[i] = (unsigned char)m_TempImage[i];
		}
	}
	delete[] m_TempImage;
	*/
}

BOOL CIMGSCJ0721Doc::OnSaveDocument(LPCTSTR lpszPathName)
{
#define FALSE false
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CFile File;
	CFileDialog SaveDlg(FALSE, NULL, NULL, OFN_HIDEREADONLY);

	if (SaveDlg.DoModal() == IDOK)
	{
		File.Open(SaveDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);
		File.Write(&dibHf2, sizeof(BITMAPFILEHEADER));
		File.Write(&dibHi2, sizeof(BITMAPINFOHEADER));
		File.Write(palRGB2, sizeof(RGBQUAD));
		File.Write(m_BackImage, File_length);
		File.Close();
	}
	return CDocument::OnSaveDocument(lpszPathName);

}
