First
    int i=7;
    const int * p = &i; // i is constant
    int *const q = &i; // pointer is constant
    *p=8; // not valid
    *q=8; // Valid
    p=q; // Valid 
    q=p; // not valid
===============================================
second
    double d;
    double *dp= &d;
    void *p= dp;
    // if store any pointer has datatype as double in void pointer you do (*not need*) to cast
    ======================================================================================
    double d;
    void *p= &d;
    // double *dp= p; // not valid
    double *dp=(double*)p; // valid
    // if store void pointer  in pointer has datatype as double you do (*need*) to cast
===========================================================================================
Third
    float* ptr,data;
    // ptr is pointer , data is normal variable
    float *ptr,data;
    // ptr is pointer , data is normal variable
===========================================================================================
Fourth
    (is valid)
    int n=120; 
    int *ptr;  
    ptr = &n;
    =========
    (Not Valid)
    int *ptr;
    ptr = &120;
===========================================================================================
