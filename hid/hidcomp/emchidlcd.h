#ifndef __EMCHIDLCD_H__
#define __EMCHIDLCD_H__

#include "emclcditem.h"

class LineChanges
{
    unsigned int m_nChangeLow;
    unsigned int m_nChangeHigh;
    bool m_bChanges;

public:
    LineChanges()
    {
	m_bChanges = false;
    }
    void Change(unsigned int i)
    {
	if ( !m_bChanges )
	{
	    m_bChanges = true;
	    m_nChangeLow = i;
	    m_nChangeHigh = i;
	}
	else if ( i < m_nChangeLow )
	    m_nChangeLow = i;
	else if ( i > m_nChangeHigh )
	    m_nChangeHigh = i;
    }
    bool Changed() const { return m_bChanges; }
    unsigned int Low() const { return m_nChangeLow; }
    unsigned int High() const { return m_nChangeHigh; }
    void Reset() { m_bChanges = false; }
};

class EMCHIDLCD : public EMCHIDItem
{
public:
    EMCHIDLCD(const QString &sPinPrefix, HIDItem *pCfgItem, HID_CollectionPath_t *pCollection );
    virtual ~EMCHIDLCD(void);

    virtual bool CheckOutputs();
    void Refresh( HIDDevice *pDevice );
    void Initialise(HIDDevice *pDevice);

private:
    HID_CollectionPath_t *m_pCollection;
    unsigned int m_nFirsDataIndex;
    QList<QString> m_Display;
    QList<LineChanges> m_Changes;
    int m_nPage;
    bool m_bInitialised;
    bool m_bFirst;
    unsigned int m_nRows;
    unsigned int m_nColumns;
    QList<EMCLCDPage *> m_Pages;
    HID_ReportItem_t *m_pClearDisplayItem;
    HID_ReportItem_t *m_pRowItem;
    HID_ReportItem_t *m_pColItem;
    QVarLengthArray<byte> m_Report;
    int m_nReportIdSpace;
    QTime m_timer;
    int m_nRefreshPeriodMS;

    bool WriteLCDBuffer( unsigned int nRow, int unsigned nCol, const QString &s );
    void ClearLCDBuffer();
    void OutputHIDLCD( HIDDevice *pDevice, unsigned int nRow, unsigned int nCol, const QString &s, unsigned int nPos, unsigned int nLen, bool bClearDisplay );
    void HIDQueryDisplayParmeters( HIDDevice *pDevice );
};


#endif
