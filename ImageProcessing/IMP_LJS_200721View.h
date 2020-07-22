
// IMP_LJS_200721View.h: CIMPLJS200721View 클래스의 인터페이스
//

#pragma once


class CIMPLJS200721View : public CView
{
protected: // serialization에서만 만들어집니다.
	CIMPLJS200721View() noexcept;
	DECLARE_DYNCREATE(CIMPLJS200721View)

// 특성입니다.
public:
	CIMPLJS200721Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CIMPLJS200721View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnImageprocessingDownsample();
	afx_msg void OnUpSampling();
//	afx_msg void OnUpdateUpSampling(CCmdUI* pCmdUI);

	afx_msg void OnQuantization();
};

#ifndef _DEBUG  // IMP_LJS_200721View.cpp의 디버그 버전
inline CIMPLJS200721Doc* CIMPLJS200721View::GetDocument() const
   { return reinterpret_cast<CIMPLJS200721Doc*>(m_pDocument); }
#endif

