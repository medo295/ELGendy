1LL in ( * ) to transfer from int to ll
1LL in ( + ) to transfer from int to ll

    int n;
    cin >> n;
    int b=n-1;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b ; j++) {
            arr[i][j] = 2;
        }
        b--;
    }
    b=n-1;
    for (int i = 1; i < n; i++) {
        for (int j = b; j < n ; j++) {
            arr[i][j] = 1;
        }
        b--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
