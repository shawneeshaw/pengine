#include "parameterengineincludes.h"

//-----------------------------------------------------------------------------
// class ParameterEngine
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
int ParameterEngine::PrepareRead() {
    //@@preconditions
    assert(this->writeFlag == 0);
    //@@end precondition

    if (this->writeFlag == 0) {
        this->readFlag = 1;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::EndRead() {
    this->readFlag = 0;
    return 1;
}

//-----------------------------------------------------------------------------
int ParameterEngine::PrepareWrite() {
    //@@preconditions
    assert(this->readFlag == 0);
    //@@end preconditions

    if(this->readFlag == 0) {
        this->writeFlag = 1;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::EndWrite() {
    this->writeFlag = 0;

    /** This only used when debug */
    /** to avoid possible errors in programming */
    /** when release, it is no use */
    this->parBuffer.CheckContinueStorage();
    return 1;
}

//-----------------------------------------------------------------------------
int ParameterEngine::Clear() {
    //@@preconditions
	assert(this->writeFlag != 1);
	assert(this->readFlag != 1);
    //@@end preconditions

    this->parBuffer.Clear();
    return 1;
}

//-----------------------------------------------------------------------------
int ParameterEngine::PrepareCheck() {
    //@@preconditions
    assert(this->writeFlag == 0);
    //@@end preconditions

    if (this->writeFlag == 0) {
        this->readFlag = 1;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::EndCheck() {
    //@@preconditions
    assert(this->readFlag == 1);
    //@@end preconditions

    this->readFlag = 0;
    return 1;
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsINT(int index, int data) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) &data, 1, AtomINTEGER);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsINT(int index, int data, char* vdecl) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) &data, 1, AtomINTEGER, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsINTArray(int index,int *data, int num) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomINTEGERArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsINTArray(int index,int *data, int num, char* vdecl) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomINTEGERArray, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsIDArray(int index,int *data, int num) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomIDArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsIDArray(int index,int *data, int num, char* vdecl) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomIDArray, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsREAL(int index, float data) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) &data, 1, AtomFLOAT);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsREAL(int index, float data, char* vdecl) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) &data, 1, AtomFLOAT, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsREALArray(int index,float *data, int num) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomFLOATArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsREALArray(int index,float *data, int num, char* vdecl) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomFLOATArray, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsSTRING(int index,char *data) {
    //@@preconditions
    assert(index >=0);
    //@@end preconditions

    if (data == NULL) {
        return parBuffer.SetParameter(index, (void *) &data, 0, AtomSTRING);
    }
    else {
        return parBuffer.SetParameter(index, (void *) &data, 1, AtomSTRING);
    }    
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsSTRING(int index,char *data, char* vdecl) {
    //@@preconditions
    assert(index >=0);
    //@@end preconditions

    if (data == NULL) {
        return parBuffer.SetParameter(index, (void *) &data, 0, AtomSTRING, vdecl);
    }
    else {
        return parBuffer.SetParameter(index, (void *) &data, 1, AtomSTRING, vdecl);
    }    
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsSTRINGArray(int index, char **data, int num) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomSTRINGArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsSTRINGArray(int index, char **data, int num, char* vdecl) {
    //@@preconditions
    assert(index >=0);
    assert(num >= 0);
    //@@end preconditions

    return parBuffer.SetParameter(index, (void *) data, num, AtomSTRINGArray, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsVOID(int index, void * data) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions
    
    return parBuffer.SetParameter(index, (void *) data, sizeof(void*), AtomVOID);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsVOID(int index, void * data, char* vdecl) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions
    
    return parBuffer.SetParameter(index, (void *) data, sizeof(void*), AtomVOID, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsFUNC(int index, ParamFunc data) {
    //@@preconditions
    assert(index >= 0);
    //assert(data.Func != NULL);
    //@@end preconditions
    
    return parBuffer.SetParameter(index, (void*)& data, sizeof(ParamFunc), AtomFUNC);
}

//-----------------------------------------------------------------------------
int ParameterEngine::SetParamAsFUNC(int index, ParamFunc data, char* vdecl) {
    //@@preconditions
    assert(index >= 0);
    //assert(data.Func != NULL);
    //@@end preconditions
    
    return parBuffer.SetParameter(index, (void*)& data, sizeof(ParamFunc), AtomFUNC, vdecl);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsINT(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomINTEGER);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsINTArray(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomINTEGERArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsIDArray(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomIDArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsREAL(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomFLOAT);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsREALArray(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomFLOATArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsSTRING(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomSTRING);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsSTRINGArray(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    return parBuffer.CheckType(index, AtomSTRINGArray);
}

//-----------------------------------------------------------------------------
int ParameterEngine::CheckParamAsVOID(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions
    
    return parBuffer.CheckType(index, AtomVOID);
}

//-----------------------------------------------------------------------------
ParameterBuffer* ParameterEngine::GetParamBuffer() {
    return &this->parBuffer;
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamNumber(int &num) {
    return parBuffer.GetNumber(num);
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamType(int index) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    AtomDataTypeEnum dataType;
    return parBuffer.GetType(index, dataType);
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsINT(int index, int& data) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    int *idata = NULL;
    int len = 0;

    if (parBuffer.GetParameter(index, (void *&)idata, len, AtomINTEGER) == 1) {
        data = *idata;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsINT(int index, int& data, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    int *idata = NULL;
    int len = 0;

    if (parBuffer.GetParameter(index, (void *&)idata, len, AtomINTEGER,vdecl) == 1) {
        data = *idata;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsINTArray(int index,int *& data, int& num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions
    
    int *idata = NULL;
    int inum = 0;

    if (parBuffer.GetParameter(index, (void *&)idata, inum, AtomINTEGERArray) == 1) {
        data = idata;
        num = inum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsINTArray(int index,int *& data, int& num, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions
    
    int *idata = NULL;
    int inum = 0;

    if (parBuffer.GetParameter(index, (void *&)idata, inum, AtomINTEGERArray,vdecl) == 1) {
        data = idata;
        num = inum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsIDArray(int index,int *& data, int& num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    int *idata = NULL;
    int inum = 0;

    if (parBuffer.GetParameter(index, (void *&)idata, inum, AtomIDArray) == 1) {
        data = idata;
        num = inum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsIDArray(int index,int *& data, int& num, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    int *idata = NULL;
    int inum = 0;

    if (parBuffer.GetParameter(index, (void *&)idata, inum, AtomIDArray,vdecl) == 1) {
        data = idata;
        num = inum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsREAL(int index, float & data) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    float *fdata = NULL;
    int len = 0;

    if(parBuffer.GetParameter(index, (void *&)fdata, len, AtomFLOAT) == 1) {
        data = *fdata;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsREAL(int index, float & data, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions

    float *fdata = NULL;
    int len = 0;

    if(parBuffer.GetParameter(index, (void *&)fdata, len, AtomFLOAT,vdecl) == 1) {
        data = *fdata;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsREALArray(int index,float *& data, int &num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    float *fdata = NULL;
    int fnum;

    if(parBuffer.GetParameter(index, (void *&)fdata, fnum, AtomFLOATArray) == 1) {
        data = fdata;
        num = fnum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsREALArray(int index,float *& data, int &num, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    float *fdata = NULL;
    int fnum;

    if(parBuffer.GetParameter(index, (void *&)fdata, fnum, AtomFLOATArray,vdecl) == 1) {
        data = fdata;
        num = fnum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsSTRING(int index,char *& data) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    char **cdata = NULL;
    int len = 0;

    if(parBuffer.GetParameter(index, (void *&)cdata, len, AtomSTRING) == 1 && len > 0) {
        data = *cdata;
        return 1;
    }
    else {
        data = NULL;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsSTRING(int index,char *& data, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    char **cdata = NULL;
    int len = 0;

    if(parBuffer.GetParameter(index, (void *&)cdata, len, AtomSTRING,vdecl) == 1 && len > 0) {
        data = *cdata;
        return 1;
    }
    else {
        data = NULL;
        return 0;
    }
}


//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsSTRINGArray(int index, char **& data, int &num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    char **cdata = NULL;
    int cnum;

    if (parBuffer.GetParameter(index, (void *&)cdata, cnum, AtomSTRINGArray) == 1) {
        data = cdata;
        num = cnum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsSTRINGArray(int index, char **& data, int &num, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions

    char **cdata = NULL;
    int cnum;

    if (parBuffer.GetParameter(index, (void *&)cdata, cnum, AtomSTRINGArray, vdecl) == 1) {
        data = cdata;
        num = cnum;
        return 1;
    }
    else {
        data = NULL;
        num = 0;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsVOID(int index, void * & data) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions
    
    void * cdata = NULL;
    int len = 0;
    
    if (parBuffer.GetParameter(index, (void * &) cdata, len, AtomVOID) == 1) {
        data = cdata;
        return 1;
    }
    else {
        data = NULL;
        return 0;
    }
}


//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsVOID(int index, void * & data, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    //@@end preconditions
    
    void * cdata = NULL;
    int len = 0;
    
    if (parBuffer.GetParameter(index, (void * &) cdata, len, AtomVOID, vdecl) == 1) {
        data = cdata;
        return 1;
    }
    else {
        data = NULL;
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsFUNC(int index, ParamFunc& data) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions
    
    void * cdata = NULL;
    int len = 0;
    
    if (parBuffer.GetParameter(index, (void * &) cdata, len, AtomFUNC) == 1) {
        data.Func = ((ParamFunc*)cdata)->Func;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::GetParamAsFUNC(int index, ParamFunc& data, char*& vdecl) {
    //@@preconditions
    assert(index >= 0);
    //@@end preconditions
    
    void * cdata = NULL;
    int len = 0;
    
    if (parBuffer.GetParameter(index, (void * &) cdata, len, AtomFUNC, vdecl) == 1) {
        data.Func = ((ParamFunc*)cdata)->Func;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterEngine::IsWriting() {
    return this->writeFlag;
}

//-----------------------------------------------------------------------------
int ParameterEngine::IsReading() {
    return this->readFlag;
}

//-----------------------------------------------------------------------------
ParameterEngine::ParameterEngine() {    
    /** not in writing */
    this->writeFlag = 0; 
    
    /** not in reading */
    this->readFlag = 0; 
}

//-----------------------------------------------------------------------------
ParameterEngine::~ParameterEngine() {
}
