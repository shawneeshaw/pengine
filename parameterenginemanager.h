#ifndef PARAMETERENGINEMANAGER_H
#define PARAMETERENGINEMANAGER_H

class ParameterEngineManager {

public:
    /** Get the Instance of ParameterEngineManager */
    static ParameterEngineManager * New();
    
    /** Delete */
    void Delete();

public:
    //get input read right.    
    IParameterEngineReadRight* GetInputReadRight() { 
        return (IParameterEngineReadRight*)inPE; 
    }

    //get input write right.    
    IParameterEngineWriteRight* GetInputWriteRight() { 
        return (IParameterEngineWriteRight*)inPE; 
    }

    //get input check right.    
    IParameterEngineCheckRight* GetInputCheckRight() { 
        return (IParameterEngineCheckRight*)inPE; 
    }

    //get output read right.    
    IParameterEngineReadRight* GetOutputReadRight() { 
        return (IParameterEngineReadRight*)outPE; 
    }

    //get output write right.    
    IParameterEngineWriteRight* GetOutputWriteRight() { 
        return (IParameterEngineWriteRight*)outPE; 
    }

    //get output check right.    
    IParameterEngineCheckRight* GetOuputCheckRight() { 
        return (IParameterEngineCheckRight*)outPE; 
    }

public:
    /** get input parameter buffer */
    ParameterBuffer* GetInputParamBuffer() {
        return this->inPE->GetParamBuffer(); 
    }

    /** get output parameter buffer */
    ParameterBuffer* GetOutputParamBuffer() {
        return this->outPE->GetParamBuffer();
    }

protected:
    /** Constructor */
    ParameterEngineManager();

    /** Destructor */
    virtual ~ParameterEngineManager();

    /** input parameterEngine */
    ParameterEngine* inPE;

    /** output parameterEngine */
    ParameterEngine* outPE;
};

#endif //PARAMETERENGINEMANAGER_H
