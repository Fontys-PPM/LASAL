//<NewSigmatekCFileOptimize/>
// +----------------------------------------------------------------------------------------------+
// +-[   copyright ] Sigmatek GmbH & CoKG                                                         |
// +-[      author ] kolott                                                                       |
// +-[        date ] 26.07.2019                                                                   |
// +-[ description ]------------------------------------------------------------------------------+
// |                                                                                              |
// |                                                                                              |
// +----------------------------------------------------------------------------------------------+

#include "SigCLib.h"

static const unsigned char TabBase64Encode[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const unsigned char TabBase64Decode[] = { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                                 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                                 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3E,0xFF,0xFF,0xFF,0x3F,
                                                 0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                                 0xFF,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,
                                                 0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0xFF,0xFF,0xFF,0xFF,0xFF,
                                                 0xFF,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
                                                 0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0xFF,0xFF,0xFF,0xFF,0xFF};

// ************************************************************************************************
// ************************************************************************************************
// utf8
// ************************************************************************************************
// ************************************************************************************************

unsigned long sigclib_str16_to_utf8(void *dst, const void *src)
{
  unsigned long  retcode = 0;
  unsigned short *ps = (unsigned short*)src;
  unsigned char  *pd = (unsigned char*)dst;

  while(*ps)
  {
    unsigned short chr = *ps++;
    if(chr < 0x0080)
    {
      *pd++    = *(unsigned char*)&chr;
      retcode += 1;
    }
    else if(chr < 0x0800)
    {
      *pd++    = (unsigned char)(0x00C0 | (chr >> 6));
      *pd++    = (unsigned char)(0x0080 | (chr & 0x003F));
      retcode += 2;
    }
    else
    {
      *pd++    = (unsigned char)(0x00E0 | (chr >> 12));
      *pd++    = (unsigned char)(0x0080 | ((chr >> 6) & 0x003F));
      *pd++    = (unsigned char)(0x0080 | (chr & 0x003F));
      retcode += 3;
    }
  }
  *pd = 0;
  
  return retcode;
}

unsigned long sigclib_utf8_to_str16(void *dst, const void *src)
{
  unsigned long retcode = 0;
  unsigned char  *ps = (unsigned char*)src;
  unsigned short *pd = (unsigned short*)dst;
  unsigned long  follow;

  while(*ps)
  {
    unsigned short chr = *ps++;
    if(chr & 0x0080)
    {
      follow = 0;
      
      if((chr & 0x00E0) == 0x00C0)
      {
        follow = 1; // 1 folgebyte
        chr    = chr & 0x001F;
      }
      else if((chr & 0x00F0) == 0x00E0)
      {
        follow = 2; // 2 folgebytes
        chr    = chr & 0x000F;
      }
      else if((chr & 0x00F8) == 0x00F0)
      {
        follow = 3; // 3 folgebytes
        chr    = chr & 0x0007;
      }
      
      while(follow--)
      {
        if((*ps & 0xC0) == 0x80)
        {
          chr = ((chr << 6) | ((*ps++) & 0x3F));
          if(follow == 0)
          {
            *pd++ = chr;
            retcode ++;
          }
        }
      }
    }
    else
    {
      *pd++ = chr;
      retcode ++;
    }
  }
  *pd = 0;

  return retcode;
}

unsigned long sigclib_ascii_to_utf8(void *dst, const void *src)
{
  unsigned long retcode = 0;
  unsigned char *ps = (unsigned char*)src;
  unsigned char *pd = (unsigned char*)dst;

  while(*ps)
  {
    unsigned char chr = *ps++;
    if(chr < 0x0080)
    {
      *pd++    = *(unsigned char*)&chr;
      retcode += 1;
    }
    else 
    {
      *pd++    = (unsigned char)(0x00C0 | (chr >> 6));
      *pd++    = (unsigned char)(0x0080 | (chr & 0x003F));
      retcode += 2;
    }
  }
  *pd = 0;
  
  return retcode;
}

unsigned long sigclib_utf8_to_ascii(void *dst, const void *src)
{
  unsigned long retcode = 0;
  unsigned char *ps = (unsigned char*)src;
  unsigned char *pd = (unsigned char*)dst;
  unsigned long follow;

  while(*ps)
  {
    unsigned short chr = *ps++;
    if(chr & 0x0080)
    {
      follow = 0;
      
      if((chr & 0x00E0) == 0x00C0)
      {
        follow = 1; // 1 folgebyte
        chr    = chr & 0x001F;
      }
      else if((chr & 0x00F0) == 0x00E0)
      {
        follow = 2; // 2 folgebytes
        chr    = chr & 0x000F;
      }
      else if((chr & 0x00F8) == 0x00F0)
      {
        follow = 3; // 3 folgebytes
        chr    = chr & 0x0007;
      }
      
      while(follow--)
      {
        if((*ps & 0xC0) == 0x80)
        {
          chr = ((chr << 6) | ((*ps++) & 0x3F));
          if(follow == 0)
          {
            *pd++ = (unsigned char)((chr < 256)? chr : '?');
            retcode ++;
          }
        }
      }
    }
    else
    {
      *pd++ = (unsigned char)chr;
      retcode ++;
    }
  }
  *pd = 0;

  return retcode;
}


// ************************************************************************************************
// ************************************************************************************************
// Base64
// ************************************************************************************************
// ************************************************************************************************

unsigned long sigclib_base64_encode_size(unsigned long srcsize)
{
  unsigned long iteration = (srcsize + 2) / 3;
  return 4 * iteration;
}

unsigned long sigclib_base64_encode(unsigned char *dst, unsigned long dstsize, void *src0, unsigned long srcsize)
{
  if((srcsize > 0) && (src0 != NULL) && (dst != NULL))
  {
    unsigned char *src      = (unsigned char*)src0;
    unsigned long iteration = (srcsize + 2) / 3;
    unsigned long retcode   = (4 * iteration);
    long srclen             = (long)srcsize;
    
    if(dstsize >= retcode)
    {
      while(iteration--)
      {
        unsigned char byte, rest, idx;
        
        byte   = *src++;
        *dst++ = TabBase64Encode[byte >> 2];
        rest   = byte & 0x03;
        srclen --;
    
        byte = (srclen > 0)? *src++ : 0;
        *dst++ = TabBase64Encode[(rest << 4) | (byte >> 4)];
        rest = byte & 0x0F;
        srclen --;

        byte = (srclen > 0)? *src++ : 0;
        idx = (rest << 2) | (byte >> 6);
        rest = byte & 0x3F;
        *dst++ = (srclen > -1)? TabBase64Encode[idx] : '=';
        srclen --;

        *dst++ = (srclen > -1)? TabBase64Encode[rest] : '=';
      }
      
      return retcode;
    }
  }
  
  return 0;
}

unsigned long sigclib_base64_decode(void *dst0, unsigned long dstsize, const unsigned char *src, unsigned long srcsize)
{
  unsigned long retcode = 0;
  if((srcsize > 0) && (src != NULL) && (dst0 != NULL))
  {
    unsigned char *dst = (unsigned char*)dst0;
        
    unsigned char code[4];
    unsigned long idx = 0;
    
    while(srcsize--)
    {
      unsigned char byte = *src++;
      if((byte != '\n') && (byte != '=')) // werden ignoriert
      {
        if(byte >= sizeof(TabBase64Decode))
        {
          return 0; // something wrong with sourcedata
        }
        
        unsigned char tmp = TabBase64Decode[byte];
        
        if(tmp == 0xFF)
        {
          return 0; // something wrong with sourcedata
        }
        
        code[idx] = tmp;
        idx = (idx + 1) & 0x03;
      
        if(idx == 0)
        {
          if(dstsize < 3)
          {
            return 0;
          }
          dst[0] = (code[0] << 2) | (code[1] >> 4);
          dst[1] = (code[1] << 4) | (code[2] >> 2);
          dst[2] = (code[2] << 6) | (code[3]);
          dst += 3;
          retcode += 3;
          dstsize -= 3;
        }
      }
    }
    
    if(idx > 1)
    {
      if(dstsize < 1)
      {
        return 0;
      }
      dst[0] = (code[0] << 2) | (code[1] >> 4);
      retcode++;
      dstsize--;

      if(idx > 2)
      {
        if(dstsize < 1)
        {
          return 0;
        }
        dst[1] = (code[1] << 4) | (code[2] >> 2);
        retcode++;
        dstsize--;
      }
    }
  }
  
  return retcode;
}


// ************************************************************************************************
// ************************************************************************************************
// binary en/decode
// ************************************************************************************************
// ************************************************************************************************

void sigclib_intern_shuffle(unsigned char *pa, unsigned long size, unsigned long key);
void sigclib_intern_code(unsigned char *p, unsigned long size, unsigned long key);

void sigclib_decode_bin(void *p0, unsigned long bytesize, unsigned long key)
{
  if((p0 != NULL) && (bytesize > 0))
  {
    sigclib_intern_shuffle((unsigned char*)p0, bytesize, key);
    sigclib_intern_code((unsigned char*)p0, bytesize, key);
  }
}

void sigclib_encode_bin(void *p0, unsigned long bytesize, unsigned long key)
{
  if((p0 != NULL) && (bytesize > 0))
  {
    sigclib_intern_code((unsigned char*)p0, bytesize, key);
    sigclib_intern_shuffle((unsigned char*)p0, bytesize, key);
  }
}


// ************************************************************************************************
// ************************************************************************************************
// text en/decode
// ************************************************************************************************
// ************************************************************************************************

void sigclib_intern_decode_txt(unsigned char *p, unsigned long bytesize, unsigned long key);
void sigclib_intern_encode_txt(unsigned char *p, unsigned long bytesize, unsigned long key);

void sigclib_decode_txt(void *p0, unsigned long bytesize, unsigned long key)
{
  if((p0 != NULL) && (bytesize > 0))
  {
    sigclib_intern_decode_txt((unsigned char*)p0, bytesize, key);
  }
}

void sigclib_encode_txt(void *p0, unsigned long bytesize, unsigned long key)
{
  if((p0 != NULL) && (bytesize > 0))
  {
    sigclib_intern_encode_txt((unsigned char*)p0, bytesize, key);
  }
}
