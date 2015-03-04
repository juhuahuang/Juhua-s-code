

#ifndef __afl_dtwWrapper_h__
#define __afl_dtwWrapper_h__


#include "afl_dtw.h"


/*----------------------------------------------------------------------------*/

extern "C" AFL_API AFL_ReturnCode __stdcall
DTW__Wrapper(
    void *  pCOMIF,
    void ** pParamPtr,
    int     paramCnt )
{
    if (paramCnt != 3)
    {
        return AFL_BadParamCount;
    }

    IDTWAFL * pIfc = (IDTWAFL *)pCOMIF;

    hana::PrivateData__ data0;
    data0.representation = pParamPtr[0];
    data0.syncBack = false;
    hana::SharedTableViewer param0(&data0);

    hana::PrivateData__ data1;
    data1.representation = pParamPtr[1];
    data1.syncBack = false;
    hana::SharedTableViewer param1(&data1);

    hana::PrivateData__ data2;
    data2.representation = pParamPtr[2];
    data2.syncBack = true;
    hana::SharedTable param2(&data2);

    pIfc->DTW(
               param0
             , param1
             , param2
             );

    return AFL_OK;
}


#endif // __afl_dtwWrapper_h__

