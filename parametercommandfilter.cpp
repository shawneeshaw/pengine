#include "parameterengineincludes.h"

//global parameter command filter.
static ParameterCommandFilter globalParameterFilter;

//-----------------------------------------------------------------------------
// class ParameterCommandFilter
//-----------------------------------------------------------------------------
//

ParameterCommandFilter * ParameterCommandFilter::instance = NULL;

//-----------------------------------------------------------------------------
ParameterCommandFilter * ParameterCommandFilter::Instance() {
    if (ParameterCommandFilter::instance == NULL) {
        ParameterCommandFilter::instance = new ParameterCommandFilter();
    }
    return ParameterCommandFilter::instance;
}

//-----------------------------------------------------------------------------
void ParameterCommandFilter::Delete() {
    if(ParameterCommandFilter::instance) {
        delete ParameterCommandFilter::instance;
        ParameterCommandFilter::instance = NULL;
    }
}

//-----------------------------------------------------------------------------
ParameterCommandFilter::ParameterCommandFilter() {
    this->intDataStor = NULL;
    this->charDataStor = NULL;
    this->floatDataStor = NULL;

    //automatic register.
    ParameterCommandFilter::instance = this;
}

//-----------------------------------------------------------------------------
ParameterCommandFilter::~ParameterCommandFilter() {
    if(this->intDataStor) delete[] this->intDataStor;
    if(this->floatDataStor) delete[] this->floatDataStor;
    if(this->charDataStor) delete[] this->charDataStor;
}

//-----------------------------------------------------------------------------
int ParameterCommandFilter::GetParCommandType(char *cmdString, int &type) {
    //@@preconditions
    assert(cmdString != NULL);
    //@@end preconditions
    
    int len = strlen(cmdString);
    type = 0;

    if (len == 7) {
        if(strcmp(cmdString, "PAR_INT")==0) 
            type = 1; /** INTEGER */
    }
    else if(len == 9) {
        if(strcmp(cmdString, "PAR_FLOAT")==0) 
            type = 2; /** FLOAT */
    }
    else if(len == 10) {
        if(strcmp(cmdString, "PAR_STRING")==0) 
            type = 3; /** STRING */
    }
            
    if (type == 0)  {
        return 0;
    }
    else { 
        return 1;
    }
}

//-----------------------------------------------------------------------------
int ParameterCommandFilter::ConvertParCommandINTEGER(char *cmdString, int *& data, int &num) {
    //@@preconditions
    assert(cmdString != NULL);
    assert(data == NULL);
    //@@end preconditions
    
    char *str = cmdString;
    int len;
    int reallen = 0;
    char *temps = NULL;

    if(this->intDataStor) {
        delete[] this->intDataStor;
        this->intDataStor = NULL;
    }

    LineEatWhite(&str);
    len = strlen(str);
    this->intDataStor = new int[len];

    temps = LineReadString(&str);   
    while(temps != NULL){
        this->intDataStor[reallen] = atoi(temps);
        reallen++;
        delete[] temps;
        temps = NULL;
        LineEatWhite(&str);
        temps = LineReadString(&str);   
    }
    if(reallen > 0) {
        num = reallen;
        data = this->intDataStor;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterCommandFilter::ConvertParCommandREAL(char *cmdString, float *& data, int &num) {
    //@@preconditions
    assert(cmdString != NULL);
    assert(data == NULL);
    //@@end preconditions

    char *str = cmdString;
    int len;
    int reallen = 0;
    char *temps = NULL;

    if(this->floatDataStor) {
        delete[] this->floatDataStor;
        this->floatDataStor = NULL;
    }

    LineEatWhite(&str);
    len = strlen(str);
    this->floatDataStor = new float[len];

    temps = LineReadString(&str);   
    while(temps != NULL){
        this->floatDataStor[reallen] = atof(temps);
        reallen++;
        delete[] temps;
        temps = NULL;
        LineEatWhite(&str);
        temps = LineReadString(&str);   
    }
    if(reallen > 0) {
        num = reallen;
        data = this->floatDataStor;
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int ParameterCommandFilter::ConvertParCommandSTRING(char *cmdString, char *& data, int &num) {
    //@@preconditions
    assert(cmdString != NULL);
    assert(data == NULL);
    //@@end preconditions

    char *str = cmdString;
    int len;

    if (this->charDataStor) {
        delete[] this->charDataStor;
        this->charDataStor = NULL;
    }

    LineEatWhite(&str);
    len = strlen(str);
    this->charDataStor = new char[len-1];

    if((str[0] == '"') &&(str[len-1] == '"')) {
        for(int i=0;i<len-2;i++) {
            this->charDataStor[i] = str[i+1];
        }
        this->charDataStor[len-2] = '\0';
        num = len-2;
        data = this->charDataStor;
        return 1;
    }
    else {
        return 0;
    }
}
