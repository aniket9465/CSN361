#include<bits/stdc++.h> 
using namespace std;  
char findClass(string str) 
{ 
    char arr[4]; 
    int i = 0; 
    while (str[i] != '.') 
    { 
        arr[i] = str[i]; 
        i++; 
    } 
    i--; 
    int ip = 0, j = 1; 
    while (i >= 0) 
    { 
        ip = ip + (str[i] - '0') * j; 
        j = j * 10; 
        i--; 
    } 
    if (ip >=1 && ip <= 126) 
        return 'A'; 
    if (ip >= 128 && ip <= 191) 
        return 'B'; 
    if (ip >= 192 && ip <= 223) 
        return 'C'; 
    if(ip >= 224 && ip <= 239) 
        return 'D'; 
    return 'E'; 
} 
  
void separate(string str, char ipClass) 
{ 
    // Initializing network and host array to NULL 
    char network[12], host[12]; 
    for (int k = 0; k < 12; k++) 
        network[k] = host[k] = '\0'; 
  
    // for class A, only first octet is Network ID 
    // and rest are Host ID 
    if (ipClass == 'A') 
    { 
        int i = 0, j = 0; 
        while (str[j] != '.') 
            network[i++] = str[j++]; 
        i = 0; 
        j++; 
        while (str[j] != '\0') 
            host[i++] = str[j++]; 
        printf("Network ID is %s\n", network); 
        printf("Host ID is %s\n", host); 
    } 
  
    // for class B, first two octet are Network ID 
    // and rest are Host ID 
    else if (ipClass == 'B') 
    { 
        int i = 0, j = 0, dotCount = 0; 
  
        // storing in network[] up to 2nd dot 
        // dotCount keeps track of number of 
        // dots or octets passed 
        while (dotCount < 2) 
        { 
            network[i++] = str[j++]; 
            if (str[j] == '.') 
                dotCount++; 
        } 
        i = 0; 
        j++; 
  
        while (str[j] != '\0') 
            host[i++] = str[j++]; 
  
        printf("Network ID is %s\n", network); 
        printf("Host ID is %s\n", host); 
    } 
  
    // for class C, first three octet are Network ID 
    // and rest are Host ID 
    else if (ipClass == 'C') 
    { 
        int i = 0, j = 0, dotCount = 0; 
  
        // storing in network[] up to 3rd dot 
        // dotCount keeps track of number of 
        // dots or octets passed 
        while (dotCount < 3) 
        { 
            network[i++] = str[j++]; 
            if (str[j] == '.') 
                dotCount++; 
        } 
  
        i = 0; 
        j++; 
  
        while (str[j] != '\0') 
            host[i++] = str[j++]; 
  
        printf("Network ID is %s\n", network); 
        printf("Host ID is %s\n", host); 
    } 
  
    // Class D and E are not divided in Network 
    // and Host ID 
    else
        printf("In this Class, IP address is not"
           " divided into Network and Host ID\n"); 
} 
  
int main() 
{ 
    string str;
    cout<<"Enter the ip : ";
    cin>>str; 
    char ipClass = findClass(str); 
    printf("Given IP address belongs to Class %c\n",ipClass); 
    separate(str, ipClass); 
    return 0; 
} 