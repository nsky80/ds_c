#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//////////////////////////////////
// this set function applicable with english alphabets i.e. special characters not considered
// since set is an unordered array so it is.
//////////////////////////////////

char *set(char *str){
    int char_set[27] = {0}; // array for english alphabets    
    int n = strlen(str), i;
    int set_count = 0;      // it contains the number of distinct characters in the set
    char current;            // it holds the current alphabet
    char *ans;              // pointer to the set i.e. answered array

    for(i=0; i<n; i++){
        current = str[i];
        if(!char_set[current - 96])    // if this is zero i.e. alphabet not included in set
        {
            char_set[current - 96] = 1;
            set_count += 1;
        }
    }
    ans = (char *)malloc(set_count*sizeof(char));

    n = -1; // used to track the length of set array i.e. ans[]
    // creating set sorted by alphabetically

    for(i=1; i<27; i++){
        if(char_set[i]){
            ans[++n] = (char) (96 + char_set[i]);
        }
    }
    return ans;

}

int main(void) {
	// your code goes here
	char str[20] /*set_ans*/;
    // printf("Enter string: ");
    scanf("%s", str);
    printf("Lenght: %I64d", strlen(str));
    // fflush(stdin);
            // printf("\n Here");
    // set_ans = set(str);
    // printf("\nset is: %s", set(str));
    // free(set_ans);                          // To avoid memory leaks
    printf("program executed succesfully........");
    
    return 0;
}