
      //*using library function 
// #include<iostream>
// #include<cstring>
// using namespace std;
// int main(){
//     char str1[100],str2[50];
//     cout<<"Enter first string: ";
//     cin.getline(str1,100);
//     cout<<"Enter second string: ";
//     cin.getline(str2,50);

//     strcat(str1, str2);
//     cout<<"concatenated string: "<< str1;
//     return 0;
// }


      //*without using library function
// #include<iostream>
// using namespace std;
// int main(){
//     string str1,str2;
//     cout<<"Enter first string: ";
//     getline(cin,str1);
//     cout<<"Enter second string: ";
//     getline(cin,str2);
     
//     for (int j = 0; j < str2.length(); j++) {
//         str1.push_back(str2[j]);   
//     }

//    cout<<"Concatenated string: "<<str1;
//    return 0;
// }