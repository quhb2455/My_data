
// IMG_SCJ_0721Doc.h: CIMGSCJ0721Doc 클래스의 인터페이스
//


#pragma once


class CIMGSCJ0721Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CIMGSCJ0721Doc() noexcept;
	DECLARE_DYNCREATE(CIMGSCJ0721Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:

	BITMAPFILEHEADER dibHf;    // 비트맵 파일헤드 구조체
	BITMAPINFOHEADER dibHi;    // 비트맵 영상헤드 구조체
	RGBQUAD palRGB[256];        // 팔레트 정보 구조체 배열
	//1번자리 이미지헤더
	
	BITMAPFILEHEADER dibHf2;    // 비트맵 파일헤드 구조체
	BITMAPINFOHEADER dibHi2;    // 비트맵 영상헤드 구조체
	RGBQUAD palRGB2[256];
	//2번자리 이미지헤더

	BITMAPFILEHEADER dibHf3;    // 비트맵 파일헤드 구조체
	BITMAPINFOHEADER dibHi3;    // 비트맵 영상헤드 구조체
	RGBQUAD palRGB3[256];
	// 3번자리 이미지 헤더

	BITMAPFILEHEADER dibHf4;    // 비트맵 파일헤드 구조체
	BITMAPINFOHEADER dibHi4;    // 비트맵 영상헤드 구조체
	RGBQUAD palRGB4[256];

	virtual ~CIMGSCJ0721Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	// 입력 영상을 위한 포인터
	//input buffer
	unsigned char* m_InputImage;
	// 입력 영상의 가로축 크기
	int m_width;
	// 입력 영상의 세로축 크기
	int m_height;
	// 입력 영상의 전체크기
	int m_size;
	// //입력 영상을 위한 포인터
	unsigned char* m_OutputImage;
	// //입력 영상의 가로축 크기
	int m_Re_width;
	int m_Re_height;
	int m_Re_size;
	void OnDownSampling();
	void OnUpSampling();
	void OnQuantization();
	void OnSumConstant();
	afx_msg void OnSubConstant();
	afx_msg void OnMulConstant();
	afx_msg void OnDivConstant();
	afx_msg void OnAndOperate();
	afx_msg void OnOrOperate();
	afx_msg void OnXorOperate();
	afx_msg void OnNegaTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnStressTransform();
	afx_msg void OnHistoStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
	afx_msg void OnEmbossing();
	double** OnMaskProcess(unsigned char* Target, double Mask[3][3]);
	double** OnScale(double **Target, int height, int width);
	double** Image2DMem(int height, int width);
	double** m_tempImage;
	unsigned char* m_BackImage;
	unsigned char* m_TempImage;
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
	afx_msg void OnSharpening();
	afx_msg void OnHpfSharp();
	afx_msg void OnLpfSharp();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	double DoubleABS(double X);
	afx_msg void OnLaplacian();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMedianSub();
	void OnBubleSort(double* A, int MAX);
	void OnSwap(double* a, double* b);
	afx_msg void OnMeanSub();
	afx_msg void OnTranslation();
	afx_msg void OnMirrorHor();
	afx_msg void OnMirrorVer();
	afx_msg void OnRotation();
	afx_msg void OnFrameOr();
	afx_msg void OnFrameAnd();
	void OnOpenOtherPic();
	void OnFrameOr2();
	ULONGLONG File_length;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};
