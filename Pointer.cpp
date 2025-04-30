First
    int i=7;
    const int * p = &i; // i is constant
    int *const q = &i; // pointer is constant
    *p=8; // not valid
    *q=8; // Valid
    p=q; // Valid 
    q=p; // not valid
   ============================================
