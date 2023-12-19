bool isValid(char* s) {
    int n = strlen(s);
    int arr[n];
    int index =0;

    for(int i=0;i<n;i++){
        char ch = s[i];

        if(ch=='(' || ch=='{' || ch=='['){
            arr[index++]=ch;
        }

        else if(index!=0 && 
        ((ch==')' && arr[index-1]=='(') || 
        (ch==']' && arr[index-1]=='[') || 
        (ch=='}' && arr[index-1]=='{') )) {
            index--;
        }
        else return false;
    }
    return index==0;
}


