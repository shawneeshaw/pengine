#include "parameterengineincludes.h"

//-----------------------------------------------------------------------------
// class ParameterEngineManager
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
ParameterEngineManager * ParameterEngineManager::New() {
    return new ParameterEngineManager;
}

//-----------------------------------------------------------------------------
void ParameterEngineManager::Delete() {
    delete this;
}

//-----------------------------------------------------------------------------
ParameterEngineManager::ParameterEngineManager(){
    this->inPE  = new ParameterEngine;
    this->outPE = new ParameterEngine;
}

//-----------------------------------------------------------------------------
ParameterEngineManager::~ParameterEngineManager(){
    delete this->inPE;
    delete this->outPE;
}
