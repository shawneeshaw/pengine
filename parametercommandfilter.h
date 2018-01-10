#ifndef PARAMTERCOMMANDFILTER_H
#define PARAMTERCOMMANDFILTER_H

class ParameterCommandFilter {
public:    
    /** create functions */
    static ParameterCommandFilter * Instance();

    /** Delete */
    void Delete();

    /** Check if it is a  parameter command and which type */
    int GetParCommandType(char *comdString, int &type);

    /** Convert to integer */
    int ConvertParCommandINTEGER(char *cmdString, int *& data, int &num);

    /** Convert to float */
    int ConvertParCommandREAL(char *cmdString, float *& data, int &num);

    /** Convert to string */
    int ConvertParCommandSTRING(char *cmdString, char *& data, int &num);

public:
    /**constructor. */
    ParameterCommandFilter();

    /**destructor. */
    ~ParameterCommandFilter();

private:
    /** singleton instance */
    static ParameterCommandFilter * instance;
    
    /** Storage of data */
    int *intDataStor;
    float *floatDataStor;
    char *charDataStor;
};

//-----------------------------------------------------------------------------
inline int uIsWhite(char c) {
    return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\0');
}

//-----------------------------------------------------------------------------
inline void LineEatWhite(char **pos) {
   while (**pos && (**pos == ' ' || **pos == '\t' || **pos == '\r' || **pos == '\n')) {
     (*pos)++;
   }
}

//-----------------------------------------------------------------------------
inline void LineEatRightWhite(char * string) {
    int len = strlen(string);
    for (int i = len-1; i >= 0; i--) {
        if (uIsWhite(string[i])) {
            string[i]= '\0';
        }
        else {
            break;
        }        
    }
}

//-----------------------------------------------------------------------------
inline char *LineReadString(char **pos) {
   char *start = *pos;
   char *buffer = NULL;
   
   while (**pos&&!uIsWhite(**pos)) (*pos)++;
   
   if((*pos-start)==0) return NULL;

   buffer = new char [(*pos - start) + 1];
   strncpy(buffer, start, *pos - start);
   buffer[*pos - start] = '\0';

   return buffer;
}

//-----------------------------------------------------------------------------
inline void LineGetLeftAndRightString(char* origString, char*& leftString, char*& rightString) {
    //@@preconditions
    assert(origString != NULL);
    assert(strlen(origString) > 0);
    assert(leftString  == NULL);
    assert(rightString == NULL);
    //@@end preconditions

    int origLen = strlen(origString);
   	char* copyString = new char[origLen + 1];
    char* pBakString = copyString;

    strncpy(copyString, origString, origLen);    
    copyString[origLen] = '\0';
    LineEatRightWhite(copyString);
    
    //get left string.
	LineEatWhite(&copyString);
	leftString = LineReadString(&copyString);

    //get right string.
	LineEatWhite(&copyString);
	int len = strlen(copyString);
	rightString = new char[len+1];
	strcpy(rightString, copyString);
	rightString[len] = '\0';

    //release orig string.
    delete[] pBakString;    

    //@@postconditions
    assert(leftString  != NULL);
    assert(rightString != NULL);
    //@@end postconditions
}

#endif //PARAMTERCOMMANDFILTER_H
