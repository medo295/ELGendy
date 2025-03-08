1LL in ( * ) to transfer from int to ll
1LL in ( + ) to transfer from int to ll


    int arr1[3][3],arr2[3][3],arr3[3][3]={0};
    for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           cin>>arr1[i][j];
       }
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin>>arr2[i][j];
        }
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
