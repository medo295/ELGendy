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
    ===================================================================================
in void
    // cout<<p<<endl; // true (address)
    // cout<<*p<<endl  // error (value)
    // cout<<*(double*)p<<endl; // true (value)
    // cout<<(double*)p<<endl; // true (address)
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
Fifth
    arr[2] == *(arr + 2) == ptr[i] == *(ptr+i)
    arr[i][j] == *(*(a + i) + j)
    arr[1][2] == *(a[1] + 2)
============================
    i[arr] == arr[i][j]
    exp.
    arr[2][3]
    1[arr] == arr[1][3]
============================
    int arr[]={1,2,3,4,5};
    int *ptr = arr++; // erorrrrrrrr
    int *ptr = arr + 1; // true
==========================================================================================
sixth 
    can subtract only(no add,no multilply , no divided) two pointers if in same memory
    int arr[]={1,2,3,4,5];
    int *ptr1 = arr;
    int *ptr2 = arr+2;
   cout<< ptr2-ptr1 // result is 2
    
