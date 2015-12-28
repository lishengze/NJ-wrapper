BYTE to Unicode
//////////////
BYTE dwByte[200];
wchar_t dwcharw[200];
for(int i=0;i<200;i++)
{
dwcharw[i]=dwByte[i];
}

                                        (char--for--unicode)



Windows API GB2312/Unicode/UTF-8转换

 
/* 
 * GB2312/Unicode/UTF-8转换 
 * WLCIMS WorkStation 2008-09-08 
 * http://wlcims.cn 
 */ 
 
#ifndef __OCUGX_H__ 
#define __OCUGX_H__ 
 
class ocUgx{ 
  public: 
 
    // --------- UTF-8转Unicode，单字 ---------------- 
int cU8xU(wchar_t* pOut,char *pText)
{
  int ret = 0; 
  char* uchar = (char *)pOut; 
  unsigned cIn = (unsigned char)pText[0]; 
  if(cIn<0x80){ // ASCII 0x00 ~ 0x7f 
  pOut[0] = pText[0]; 
  }else if(cIn<0xdf){ 
  uchar[0] = (pText[0]<<6)|(pText[1]&0x3f); 
  uchar[1] = (pText[0]>>2)&0x0f; 
  ret = 1; 
  }else if(cIn<=0xef){ 
  uchar[0] = (pText[1]<<6)|(pText[2]&0x3f); 
  uchar[1] = (pText[0]<<4)|((pText[1]>>2)&0x0f); 
  ret = 2; 
  }else if(cIn<0xf7){ 
  uchar[0] = (pText[2]<<6)|(pText[3]&0x3f); 
  uchar[1] = (pText[1]<<4)|((pText[2]>>2)&0x0f); 
  uchar[2] = ((pText[0]<<2)&0x1c)|((pText[1]>>4)&0x03); 
  ret = 3; 
  } 
  return ret; 
}
 
    // ---------- Unicode转UTF-8，单字 ------------------ 
    int cUxU8(char* pOut,WCHAR* pText){ 
       int ret = 0; 
       unsigned char* pchar = (unsigned char *)pText; 
      if(pText[0]<=0x7f){         // ASCII  0x00 ~ 0x7f 
        pOut[0] = (char)pchar[0]; 
      }else if(pText[0]<=0x7ff){  // 0x080 ~ 0x7ff 
        pOut[0] = 0xc0|(pchar[1]<<2)|(pchar[0]>>6); 
        pOut[1] = 0x80|(pchar[0]&0x3f); 
        ret = 1; 
      }else{                      // 0x0800 ~ 0xFFFF 
         pOut[0] = 0xe0|(pchar[1]>>4); 
         pOut[1] = 0x80|((pchar[1]&0x0f)<<2)|(pchar[0]>>6); 
         pOut[2] = 0x80|(pchar[0]&0x3f); 
        ret = 2; 
      } 
      return ret; 
    } 
 
    // ----------- Unicode转GB2312，单字 ------------------ 
    int cUxG(char* pOut,WCHAR* pText){ 
      int ret = 0; 
      if(pText[0]<0x80){        // ASCII  0x00 ~ 0x7f 
        pOut[0] = (char)pText[0]; 
      }else{ 
        ::WideCharToMultiByte(CP_ACP,0,pText,1,pOut,sizeof(WCHAR),NULL,NULL); 
        ret = 1; 
      } 
      return ret; 
    } 
 
   // ----------- GB2312转Unicode，单字 ------------------ 
    int cGxU(WCHAR* pOut,char* pText){ 
      int ret = 0; 
      if((unsigned)pText[0]<0x80){        // ASCII  0x00 ~ 0x7f 
        pOut[0] = (WCHAR)pText[0]; 
      }else{ 
         ::MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,pText,2,pOut,1); 
         ret = 1; 
      } 
      return ret; 
    } 
 
   // ------------ UTF-8转Unicode，字符串 ---------------- 
    int sU8xU(WCHAR* pOut,char *pText,int Len){ 
      int i,j; 
      for(i=0,j=0;i<Len;i++,j++){ 
        i+=cU8xU(&pOut[j],&pText[i]); 
      } 
      return j; 
    } 
 
    // ------------ Unicode转UTF-8，字符串 ---------------- 
     int sUxU8(char* pOut,WCHAR* pText,int Len){ 
       int i,j; 
       for(i=0,j=0;i<Len;i++,j++){ 
         j+=cUxU8(&pOut[j],&pText[i]); 
       } 
       return j; 
     } 
 
    // ------------ Unicode转GB2312，字符串 ---------------- 
     int sUxG(char* pOut,WCHAR* pText,int Len){ 
       int i,j; 
       for(i=0,j=0;i<Len;i++,j++){ 
         j+=cUxG(&pOut[j],&pText[i]); 
       } 
       return j; 
     } 
 
    // ------------ GB2312转Unicode，字符串 ---------------- 
     int sGxU(WCHAR* pOut,char* pText,int Len){ 
       int i,j; 
       for(i=0,j=0;i<Len;i++,j++){ 
         i+=cGxU(&pOut[j],&pText[i]); 
       } 
       return j; 
     } 
 
    // ------------ GB2312转UTF-8，字符串 ------------------ 
     int sGxU8(char* pOut,char* pText,int Len){ 
       int i,j; 
       WCHAR buf; 
       for(i=0,j=0;i<Len;i++,j++){ 
         if((unsigned)pText[0]<0x80){       // ASCII  0x00 ~ 0x7f 
           pOut[j] = pText[i]; 
         }else{ 
           i += cGxU(&buf,&pText[i]); 
           j += cUxU8(&pOut[j],&buf); 
         } 
       } 
       return j; 
     } 
 
    // ------------ UTF-8转GB2312，字符串 ------------------ 
     int sU8xG(char* pOut,char* pText,int Len){ 
       int i,j; 
       WCHAR buf; 
       for(i=0,j=0;i<Len;i++,j++){ 
         if((unsigned)pText[i]<0x80){       // ASCII  0x00 ~ 0x7f 
           pOut[j] = pText[i]; 
         }else{ 
           i += cU8xU(&buf,&pText[i]); 
           j += cUxG(&pOut[j],&buf); 
         } 
       } 
       return j; 
     } 
     
     
 
}; 
 
#endif 
